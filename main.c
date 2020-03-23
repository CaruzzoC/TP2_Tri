#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tri.h"

int main(void) {
  printf("Hello World\n");

  //========================Tab de TEST==================

  int *TimeArrayTest = malloc(100*sizeof(int));
  int *TimeArrayTestCopy = malloc(100*sizeof(int));
  genTab(TimeArrayTest, 100);


  int *tabTrie = malloc(4*sizeof(int));
  tabTrie[0] = 8;
  tabTrie[1] = 10;
  tabTrie[2] = 23;
  tabTrie[3] = 505;

  int *tabTrie2 = malloc(5*sizeof(int));
  tabTrie2[0] = 0;
  tabTrie2[1] = 1;
  tabTrie2[2] = 1;
  tabTrie2[3] = 2;
  tabTrie2[4] = 2;

  //========================Tab de Trie==================

  int *tab = malloc(4*sizeof(int));
  tab[0] = 10;
  tab[1] = 23;
  tab[2] = 505;
  tab[3] = 8;

  int *tab2 = malloc(5*sizeof(int));
  tab2[0] = 1;
  tab2[1] = 2;
  tab2[2] = 0;
  tab2[3] = 1;
  tab2[4] = 2;

  //========================Test==========================

  //printf("\nTest de TriSelection : %i, %i\n",TriTest(TriSelection(tab,4), tabTrie),TriTest(TriSelection(tab2,4), tabTrie2));
  //printf("\nTest de TriFusion : %i, %i\n",TriTest(TriFusion(tab, 4), tabTrie),TriTest(TriFusion(tab2, 5), tabTrie2));
  //printf("\nTest de TriBulles : %i, %i\n",TriTest(TriBulles(tab,5), tabTrie),TriTest(TriBulles(tab2,5), tabTrie2));
  //printf("\nTest de TriRapide : %i, %i\n",TriTest(TriRapide(tab, 0, 3), tabTrie),TriTest(TriRapide(tab2, 0, 4), tabTrie2));

  //========================Main==========================

  
  //TriFusion(tab);
  /*
  for(int i=0;i<4;i++){
    printf("%i,",tab[i]);
  }
  */

  //printf("%f",triFusionPerf(TimeArrayTest, 100, 100));

  /*
  ResultPerf(100,100);
  for(int i=0;i<4;i++){
    printf("%f ",ResultPerf(100,100)[i]);
  }
  */

  create_result_csv("Result_Tri.csv", 1);

  free(TimeArrayTest);
  free(TimeArrayTestCopy);
  free(tabTrie);
  free(tabTrie2);
  free(tab);
  free(tab2);
  return 0;
}