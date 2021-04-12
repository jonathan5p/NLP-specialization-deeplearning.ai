#include <stdio.h>
#include <math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{
    double interval,abs_val;
    int i;
    for (i = 0; i < 30; i++)
    {
        interval = i / 10.0;
        abs_val = fabs(sin(interval));
        printf("sin(%lf) = %lf \t", interval, abs_val);
    }
    return 0;
}