/* Hostel Grades Manager - Do-While Menu (uses only <stdio.h>)
 *
 * Features:
 * - Manage up to 30 students
 * - Hardcoded sample students loaded at start
 * - Add student, list students, top student, recalc grades, save to CSV (simple),
 *   load from CSV (simple), exit
 *
 * NOTE: This program intentionally includes only <stdio.h>.
 *       Minimal string utilities are implemented manually.
 */

#include <stdio.h>

#define MAX_STUDENTS 30
#define NAME_LEN 40
#define LINE_LEN 256

typedef struct {
    int id;
    char name[NAME_LEN];
    float jap;
    float physics;
    float bcem;
    float total;
    char grade[3]; /* e.g., "A+", "B", "F" + '\0' */
} Student;

/* --- Minimal string helpers (no string.h) --- */
static int my_strlen(const char *s) {
    int n = 0;
    while (s && s[n]) n++;
    return n;
}

static void my_strcpy(char *dest, const char *src, int maxlen) {
    int i;
    for (i = 0; i < maxlen - 1 && src[i]; ++i) dest[i] = src[i];
    dest[i] = '\0';
}

/* trim trailing newline from fgets buffer */
static void trim_newline(char *s) {
    int i;
    for (i = 0; s && s[i]; ++i) {
        if (s[i] == '\n') { s[i] = '\0'; break; }
    }
}

/* clear remaining input up to newline */
static void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/* --- Core utilities --- */
static void calc_total_and_grade(Student *s) {
    if (!s) return;
    s->total = s->jap + s->physics + s->bcem;
    if (s->total >= 220.0f) { s->grade[0] = 'A'; s->grade[1] = '+'; s->grade[2] = '\0'; }
    else if (s->total >= 200.0f) { s->grade[0] = 'A'; s->grade[1] = '\0'; }
    else if (s->total >= 180.0f) { s->grade[0] = 'B'; s->grade[1] = '\0'; }
    else if (s->total >= 150.0f) { s->grade[0] = 'C'; s->grade[1] = '\0'; }
    else { s->grade[0] = 'F'; s->grade[1] = '\0'; }
}

static void print_header(void) {
    printf(" ID | %-*s | JAPANESE | PHYSIC |  BCEM  | TOTAL  | G\n", NAME_LEN - 1, "NAME");
    printf("----+-%.*s-+----------+--------+--------+--------+---\n", NAME_LEN - 1, "--------");
}

static void print_student(const Student *s) {
    if (!s) return;
    printf("%3d | %-*s | %7.1f | %7.1f | %7.1f | %7.1f | %2s\n",
           s->id, NAME_LEN - 1, s->name, s->jap, s->physics, s->bcem, s->total, s->grade);
}

/* --- Sample loader (deterministic values) --- */
static int load_sample_students(Student arr[], int max) {
    const char *names[] = {
        "Aanya Deshmukh","Rohan Mehta","Sana Khan","Vikram Patel",
        "Isha Sharma","Kunal Joshi","Priya Nair","Amit Verma",
        "Neha Gupta","Ravi Singh","Zara Sheikh","Aditya Rao",
        "Meera Iyer","Suhas Kulkarni","Tarun Chauhan","Nina Kapoor",
        "Arjun Roy","Kavya Menon","Dev Malhotra","Rhea Bose",
        "Omar Farooq","Lina Fernandes","Sameer Qureshi","Pooja Thakur",
        "Kiran Bhosle","Vivek Nair"
    };
    int names_count = sizeof(names) / sizeof(names[0]);
    int n = 0;
    for (int i = 0; i < names_count && n < max; ++i, ++n) {
        arr[n].id = n + 1;
        my_strcpy(arr[n].name, names[i], NAME_LEN);
        /* deterministic pseudo-scores to avoid rand() */
        arr[n].jap = 60.0f + ((i * 7) % 71);   /* range roughly 60-130 */
        arr[n].physics = 55.0f + ((i * 11) % 76);  /* range roughly 55-130 */
        arr[n].bcem = 50.0f + ((i * 13) % 81);     /* range roughly 50-130 */
        calc_total_and_grade(&arr[n]);
    }
    return n;
}

/* --- Menu actions --- */
static void list_students(const Student arr[], int count) {
    if (count == 0) { puts("No students to show."); return; }
    print_header();
    for (int i = 0; i < count; ++i) print_student(&arr[i]);
}

static void add_student(Student arr[], int *count) {
    if (!count || !arr) return;
    if (*count >= MAX_STUDENTS) { puts("Student array is full."); return; }
    Student s;
    s.id = (*count) + 1;
    printf("Enter name: ");
    if (!fgets(s.name, NAME_LEN, stdin)) { puts("Input error."); clear_input(); return; }
    trim_newline(s.name);
    if (my_strlen(s.name) == 0) my_strcpy(s.name, "Unknown", NAME_LEN);
    printf("Enter Japanese score (numeric): ");
    if (scanf("%f", &s.jap) != 1) { puts("Invalid number."); clear_input(); return; }
    printf("Enter Physics score (numeric): ");
    if (scanf("%f", &s.physics) != 1) { puts("Invalid number."); clear_input(); return; }
    printf("Enter BCEM score (numeric): ");
    if (scanf("%f", &s.bcem) != 1) { puts("Invalid number."); clear_input(); return; }
    clear_input();
    calc_total_and_grade(&s);
    arr[*count] = s;
    (*count)++;
    puts("Student added.");
}

static void top_student(const Student arr[], int count) {
    if (count == 0) { puts("No students."); return; }
    int idx = 0;
    for (int i = 1; i < count; ++i) {
        if (arr[i].total > arr[idx].total) idx = i;
    }
    puts("Top student:");
    print_header();
    print_student(&arr[idx]);
}

/* Simple CSV save/load using stdio only.
   The load is permissive: it reads lines and tries to sscanf them.
*/
static void save_to_csv(const Student arr[], int count, const char *fname) {
    FILE *f = fopen(fname, "w");
    if (!f) { printf("Failed to open %s for writing.\n", fname); return; }
    fprintf(f, "ID,Name,Japanese,Physics,BCEM,Total,Grade\n");
    for (int i = 0; i < count; ++i) {
        /* wrap name in double quotes and escape nothing (simple) */
        fprintf(f, "%d,\"%s\",%.1f,%.1f,%.1f,%.1f,%s\n",
                arr[i].id, arr[i].name, arr[i].jap, arr[i].physics, arr[i].bcem, arr[i].total, arr[i].grade);
    }
    fclose(f);
    printf("Saved %d students to %s\n", count, fname);
}

static void load_from_csv(Student arr[], int *count, const char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) { printf("Failed to open %s for reading.\n", fname); return; }
    char line[LINE_LEN];
    int line_no = 0;
    int loaded = 0;
    while (fgets(line, LINE_LEN, f)) {
        line_no++;
        /* skip header */
        if (line_no == 1) continue;
        if (loaded >= MAX_STUDENTS) break;
        /* naive parse: ID,"Name",Chinese,Physics,BCEM,Total,Grade */
        int id = 0;
        char namebuf[NAME_LEN] = {0};
        float ch = 0.0f, ph = 0.0f, bc = 0.0f, tot = 0.0f;
        char gradebuf[8] = {0};
        /* Use sscanf to find ID and then attempt to find quoted name */
        char *p = line;
        /* parse ID */
        if (sscanf(p, "%d", &id) != 1) continue;
        /* find first double quote */
        char *q1 = NULL;
        for (char *t = p; *t; ++t) if (*t == '"') { q1 = t+1; break; }
        if (q1) {
            char *q2 = q1;
            int ni = 0;
            while (*q2 && *q2 != '"' && ni < NAME_LEN-1) { namebuf[ni++] = *q2++; }
            namebuf[ni] = '\0';
            /* advance pointer after closing quote */
            p = q2;
        }
        /* attempt to sscanf remaining numeric fields */
        if (sscanf(p, "\",%f,%f,%f,%f,%7s", &ch, &ph, &bc, &tot, gradebuf) < 4) {
            /* fallback: try simpler parse (comma separated without quote) */
            if (sscanf(line, "%d,%39[^,],%f,%f,%f,%f,%7s", &id, namebuf, &ch, &ph, &bc, &tot, gradebuf) < 4) {
                continue; /* unable to parse line */
            }
        }
        /* populate student */
        Student s;
        s.id = (loaded + 1); /* reassign sequential IDs on load */
        my_strcpy(s.name, namebuf, NAME_LEN);
        s.jap = ch;
        s.physics = ph;
        s.bcem = bc;
        calc_total_and_grade(&s);
        arr[loaded++] = s;
    }
    fclose(f);
    *count = loaded;
    printf("Loaded %d students from %s\n", loaded, fname);
}

/* Recalculate totals & grades for all students */
static void recalc_all(Student arr[], int count) {
    for (int i = 0; i < count; ++i) calc_total_and_grade(&arr[i]);
    puts("Recalculated totals and grades.");
}

/* --- Main (do-while menu) --- */
int main(void) {
    Student students[MAX_STUDENTS];
    int count = load_sample_students(students, MAX_STUDENTS);
    int choice = 0;
    char fname[80] = "students.csv";
    do {
        puts("");
        puts("=== Hostel Grades Manager (Do-While Menu) ===");
        puts("1. List students");
        puts("2. Add student");
        puts("3. Show top student");
        puts("4. Save to CSV");
        puts("5. Load from CSV");
        puts("6. Recalculate totals and grades");
        puts("7. Exit");
        printf("Choose an option (1-7): ");
        if (scanf("%d", &choice) != 1) {
            clear_input();
            puts("Invalid input. Please enter a number 1-7.");
            choice = 0;
            continue;
        }
        clear_input(); /* remove leftover newline */
        switch (choice) {
            case 1:
                list_students(students, count);
                break;
            case 2:
                add_student(students, &count);
                break;
            case 3:
                top_student(students, count);
                break;
            case 4:
                printf("Enter filename to save (or press Enter for default '%s'): ", fname);
                if (fgets(fname, sizeof(fname), stdin)) {
                    trim_newline(fname);
                    if (my_strlen(fname) == 0) my_strcpy(fname, "students.csv", sizeof(fname));
                }
                save_to_csv(students, count, fname);
                break;
            case 5:
                printf("Enter filename to load (or press Enter for default '%s'): ", fname);
                if (fgets(fname, sizeof(fname), stdin)) {
                    trim_newline(fname);
                    if (my_strlen(fname) == 0) my_strcpy(fname, "students.csv", sizeof(fname));
                }
                load_from_csv(students, &count, fname);
                break;
            case 6:
                recalc_all(students, count);
                break;
            case 7:
                puts("Goodbye.");
                break;
            default:
                puts("Please choose a valid option (1-7).");
                break;
        }
    } while (choice != 7);
    return 0;
}