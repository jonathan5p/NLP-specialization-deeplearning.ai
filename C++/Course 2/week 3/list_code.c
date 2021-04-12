#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

typedef struct list {int data ; struct list *next;} list;

int is_empty(const list *l){return (l==NULL);}

list* create_list(int value){
    list *head = malloc(sizeof(list));
    head -> data = value;
    head -> next = NULL;
    return head; 
}

list *add_to_front(int d, list *h){
    list *head = create_list(d);
    head -> next = h;
    return head;
}

list *array_to_list(int d[],int size){

    list *head = create_list(d[0]);
    int i; 
    for(i=1;i<size;i++){
        head = add_to_front(d[i],head);
    }
    return head; 
}

void print_list(list *h,char *title){
    printf("%s \n",title);
    int count=1;
    while(h!=NULL){
        printf("%d ",h->data);
        if (count% 5 == 0) {printf("\n");} 
        h = h->next;
        count++;
    }
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int data[]){
    int i,j;
    for(i=0;i<100;i++){
        for(j=100-1;j>i;j--){
            if(data[j-1]>data[j]){
                swap(&data[j-1],&data[j]);
            }
        }
    }
}

void main(){
    list *head;
    int d[100] = {0}, i,j;
    for (i = 0; i < 100; i++)
    {
        d[i] = rand()/1000000;
    }

    bubble_sort(d);
    head = array_to_list(d,100);
    print_list(head,"Lista ordenada: \n");

}

