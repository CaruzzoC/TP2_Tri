#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tri.h"

int main(void) {
  printf("Hello World\n");

  //========================Tab de TEST==================

  int *tabTrie = malloc(4*sizeof(int));
  tabTrie[0] = 8;
  tabTrie[1] = 10;
  tabTrie[2] = 23;
  tabTrie[3] = 505;

  int *tabTrie2 = malloc(4*sizeof(int));
  tabTrie2[0] = 0;
  tabTrie2[1] = 1;
  tabTrie2[2] = 1;
  tabTrie2[3] = 2;

  //========================Tab de Trie==================

  int *tab = malloc(4*sizeof(int));
  tab[0] = 10;
  tab[1] = 23;
  tab[2] = 505;
  tab[3] = 8;

  int *tab2 = malloc(4*sizeof(int));
  tab2[0] = 1;
  tab2[1] = 2;
  tab2[2] = 0;
  tab2[3] = 1;

  //========================Test==========================

  printf("\nTest de TriSelection : %i, %i\n",TriTest(TriSelection(tab), tabTrie),TriTest(TriSelection(tab2), tabTrie2));
  printf("\nTest de TriFusion : %i, %i\n",TriTest(TriFusion(tab), tabTrie),TriTest(TriFusion(tab2), tabTrie2));

  //========================Main==========================

  TriSelection(tab2);
  for(int i=0;i<4;i++){
    printf("%i,",tab2[i]);
  }
  printf("\n");

  TriFusion(tab);
  for(int i=0;i<4;i++){
    printf("%i,",tab[i]);
  }






  return 0;
}