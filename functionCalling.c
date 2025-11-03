#include <stdio.h>
// addition of 3 numbers using functions and function calling
int calSum(int a, int b, int c);

void italy();
void bahrain();
void saudi_arabia();
void australia();
void China();
void azerbaijan();
void miami();
void spain();
void monaco();
void canada();
void austria();
void Silverstone();
void hungary();
void belgium();
void netherlands();
void Monza();
void singapore();
void japan();
void qatar();
void las_vegas_strip();
void mexico();
void Interlagos();
void abu_dhabi();
void Emilia_Romagna();
void Austin();

void australia() {
    printf("\nI am in Australia Function");
    China();
}

void China() {
    printf("\nI am in China Function");
    japan();
}
void japan() {
    printf("\nI am in Japan Function");
    bahrain();
}
void bahrain() {
     printf("\nI am in Bahrain Function");
     saudi_arabia(); 
}
void saudi_arabia() {
    printf("\nI am in Jeddah Circuit");
    miami();
}
void miami() {
    printf("\nI am in Miami International Autodrome");
    Emilia_Romagna();
}
void Emilia_Romagna() {
    printf("\nI am in Emilia Romagna Function");
    monaco();
}
void monaco() {
    printf("\nI am in Monaco Function");
    spain();
}
void spain() {
    printf("\nI am in Spain Function");
    canada();
}
void canada() {
    printf("\nI am in Canada Function");
    austria();
}
void austria() {
    printf("\nI am in Austria Function");
    Silverstone();
}
void Silverstone() {
    printf("\nI am in Great Britain Function");
    hungary();
}
void hungary() {
    printf("\nI am in Hungary Function");
    belgium();
}
void belgium() {
    printf("\nI am in Belgium Function");
    netherlands();
}
void netherlands() {
    printf("\nI am in Netherlands Function");
    Monza();
}
void Monza() {
    printf("\nI am in Monza Autodrome");
    azerbaijan();
}
void azerbaijan() {
    printf("\nI am in Baku Street Circuit");
    singapore();
}
void singapore() {
    printf("\nI am in Marina Bay Circuit");
    Austin();
}
void Austin(){
    printf("\nI am in USA Function");
    mexico();
}
void mexico() {
    printf("\nI am in Mexico Function");
    Interlagos();
}
void Interlagos() {
    printf("\nI am in Interlagos Circuit");
    las_vegas_strip();
}
void las_vegas_strip() {
    printf("\nI am in Las Vegas (USA) Circuit");
    qatar();
}
void qatar() {
    printf("\nI am in Qatar Function");
    abu_dhabi();
}
void abu_dhabi() {
    printf("\nI am in Abu Dhabi Function");
}
int main()
{
    int a, b, c;
    printf("\nI am in F1 Calender\n");
    bahrain();
    printf("\nBack to The Main Function\n");
    printf("Enter 3 numbers");
    scanf("%d %d %d", &a, &b, &c);
    printf("Sum of %d, %d and %d is: %d\n", a,b,c, calSum(a, b, c));
    return 0;
}

int calSum(int x, int y, int z) {
    int sum = x + y + z;
    return sum;
}
