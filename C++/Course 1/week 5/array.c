#include <stdio.h>
void main(void)
{
    FILE *myFile;
    myFile = fopen("elephant_seal_data.txt", "r");

    //read file into array
    const int n_sizes = 1000;
    double dn_sizes=1000;
    int numberArray[n_sizes];
    int i;
    double avg,sum=0; 

    for (i = 0; i < n_sizes; i++)
    {   
        fscanf(myFile, "%d", &numberArray[i]);
        sum+=numberArray[i];
    }
    avg = sum/dn_sizes;
    printf("The average over the sizes is: %lf \n",avg);

}