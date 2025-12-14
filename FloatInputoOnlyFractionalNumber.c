#include<stdio.h>
int main(){
    float x;
    printf("Enter the Float value:");
    scanf("%f",&x);
    int y=x;
    printf("The Integer Value is : %d",y);
    float z = x - y;
    printf("\nThe Fractional Value is : %f",z);
    return 0;
}   