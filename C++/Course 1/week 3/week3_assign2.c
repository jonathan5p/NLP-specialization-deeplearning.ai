#include <stdio.h>
#include <math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{
    printf("---------------------------\n");
    printf("|   x   | sin(x) | cos(x) |\n");
    for (int i = 0; i < 30; i++)
    {
        double curr_value = i / 10.0;
        printf("| %.3lf | %.4lf | %.4lf |\n",curr_value,sin(curr_value),cos(curr_value));
    }

    printf("----------------------------\n");
    return 0;
}