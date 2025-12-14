#include<stdio.h>
int main(){
    // Out of 40 
    float m1 = 37; // marks of math 
    float m2 = 33; // marks of physics
    float m3 = 32; // marks of chemistry
    float m4 = 39; // marks of biology
    float p = ((m1+ m2 + m3 + m4)/4)*100/40 ;
    printf("Percentage of 4 subject is : %f",p);
    return 0;
}