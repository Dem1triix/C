#include <stdio.h>
#include <conio.h>

int main(){
    int n,no,flag,small,big,range;
    printf("Enter the range of numbers: ");
    scanf("%d",&range);

    while(n>0){
        printf("\nEnter number: ");
        scanf("%d",&no);

        if(flag==0){
            small=no=big;
            flag=1;
        }
        else{
            if(no<small)
                small=no;
            if(no>big)
                big=no;
        }
        n--;
    }
    if(small<0){
        range=small+big;}
    else{
        range=big-small;
    }
}
