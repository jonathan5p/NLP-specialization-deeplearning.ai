/*
    Sine of a number x 
    Mar. 7, 2020 
*/


#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("Input the number for which you want to apply the sine function: ");
    scanf("%lf",&x);
    double result =  sin(x);
    printf("The sine of %lf is: %lf \n",x,result);
    return 0;
}