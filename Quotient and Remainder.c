#include<stdio.h>
int main(){
    int a,b,q,r;
    printf("Enter Dividend : ");
    scanf("%d",&a);
    printf("Enter Divisor : ");
    scanf("%d",&b);
    q = a/b;
    r = a - b*q;
    printf("The Quotient is : %d",q);
    printf("\nThe remainder is : %d",r);
    return 0;
}