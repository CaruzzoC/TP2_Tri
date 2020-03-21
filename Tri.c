#include "Tri.h"

int* TriSelection(int *tab){
  int i = sizeof(tab)/sizeof(tab[0]) + 1;
  while (i > 0){
    int max = 0;
    for(int j = 1;j <= i;j++){
      if (tab[j] > tab[max]){
        max = j;
      }
    }
    int tmp = tab[max];
    tab[max] = tab[i];
    tab[i] = tmp;
    i--;
  }
  return tab;
}

