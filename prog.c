#include <stdio.h>
// 1/11/25 Mr. Sachin Lohar

int Table()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Multiplication table for %d:\n", n);
    for (int i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}

int Arrays(){
    int arr[8];
    for(int i=0;i<7;i++){
        scanf("%d ",&arr[i]);
    }
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
}

int Minmax(){
    int arr[8]={5,86,170,58,36,8,25,625};
    int max=arr[0];
    int min=arr[0];

    for(int i=0;i<8;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("Max=%d\n Min=%d\n",max,min);
}

int Matrix(){
    int i,j, mat[3][3];
    for(i=0;i<3;i++){
        printf("Enter elements of row %d:\n",i+1);
        for(j=0;j<3;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int whileLoop(){
    int i=1;
    while(i<=10){
        printf("%d\n",i);
        i++;
    }
    return 0;
}

int multiplicationTable(){
    int num,i=1,res;
    printf("Enter an integer: ");
    scanf("%d",&num);
    while(i<=10){
        res = num * i;
        printf("%d x %d = %d\n", num, i, res);
        i++;   
    }
}

int doWhileLoop(){
    int i=1;
    do{
        printf("%d\n",i);
        i++;
    }while(i<=10);
    return 0;
}

//Q. Find difference do-while and while loop

int evenfrom1to100(){
    int i=1;
    printf("Even numbers from 1 to 100 are:\n");
    while(i<=100){
        if(i%2==0){
            printf("%d\n",i);
        }
        i++;
    }
    return 0;
}

int sumofNaturalNo(){
    int n,i,sum=0;
    printf("Enter a integer: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=i;
    }
    printf("Sum of first %d natural numbers is: %d\n",n,sum);
    return 0;
}

int factorial(){
    int n,i;
    long fact=1;
    printf("Enter an integer: ");
    scanf("%d",&n);
    if(n<0){
        printf("Error! Factorial of a negative number doesn't exist.\n");
    }else{
        for(i=1;i<=n;i++){
            fact*=i;
        }
        printf("Factorial of %d = %ld\n",n,fact);
    }
    return 0;
}

int mat(){
    int a[2][2],b[2][2],sum[2][2],i,j;
    printf("Enter elements of 1st matrix:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements of 2nd matrix:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Sum of the two matrices:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void main()
{
     /*
     Table();
     Arrays();
     Minmax();
     Matrix();
     whileLoop();
     multiplicationTable();
     doWhileLoop();
     evenfrom1to100();
     */
     //sumofNaturalNo();
     //factorial();
     mat();
}