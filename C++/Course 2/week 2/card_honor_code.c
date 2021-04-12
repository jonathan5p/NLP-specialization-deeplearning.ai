#include <stdio.h>
#include <stdlib.h>

// suit in {'s','d','c',h'}, s == spades, d==diamonds, c==clubs, h=hearts

typedef struct card {int pips; char suit;} card;

void create_deck(card *deck){
    int i,j;
    char curr_suit;
    card curr_card; 
    for(i=0;i<4;i++){
        switch (i)
        {
        case 0: 
            curr_suit='s';
            break;
        case 1:
            curr_suit = 'd';
            break;
        case 2:
            curr_suit = 'c';
            break;
        case 3:
            curr_suit = 'h';
            break;
        }
        for(j=0;j<13;j++){
            deck[j+13*i].pips = j+1;
            deck[j+13*i].suit = curr_suit;
        }

    } 
}
void shuffle(card *array)
{
    int i;
    for (i = 0; i < 52-1; i++)
    {
        int j = i + rand() / (RAND_MAX / (52 - i) + 1);
        card t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
    
}

void check(card deal[]){
    int count[13] = {0}, i;

    for(i=0;i<7;i++){
        count[deal[i].pips]++;
    }
}
