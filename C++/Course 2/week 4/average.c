#include <stdio.h>
#include <stdlib.h>

void read_file(FILE *f, int d[]){
    int i = 0;
    while(fscanf(f, "%d", &d[i])==1){
        i++;
    }
}

int maximum(int d[],int size){
    int curr_max=0,i;
    for(i=0;i<size;i++){
        if (d[i]>curr_max){
            curr_max=d[i];
        }
    }
    return curr_max;
}

double average(int d[],int size){
    double sum;
    int i;
    for(i=0;i<size;i++){
        sum+=d[i];
    }
    return(sum/((double)size));
}

void main(int argc , char *argv[]){
    FILE *ifp, *ofp;
    int size,i,max;
    double av;

    ifp = fopen(argv[1],"r+");
    ofp = fopen(argv[2],"w+");
    fscanf(ifp,"%d",&size);
    int data[size];
    read_file(ifp, data);

    av = average(data,size);
    printf("The average of the input data is: %lf \n", av);
    fprintf(ofp,"The average of the input data is: %lf \n",av);
    max = maximum(data,size);
    printf("The maximum value in the input data is: %d \n", max);
    fprintf(ofp,"The maximum value in the input data is: %d \n", max);

    fclose(ifp);
    fclose(ofp);
}