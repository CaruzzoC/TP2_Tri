#include "Tri.h"

/**
*TriTest(la liste de Test, liste trié par l'algorithme)
*int *tabTrie - Liste qui est le résultat de la liste à trier
*
compare pour chaque valeur du tableau trié si il coréspond
*au résultat attendu
*/
int TriTest(int *tabTrie, int *tabAVerif){
  int n = sizeof(tabTrie)/sizeof(tabTrie[0]) + 1;
  int l = sizeof(tabAVerif)/sizeof(tabAVerif[0]) + 1;
  if (n != l){
    return -1;
  }
  for(int i = 0; i < n; i ++){
    if (tabAVerif[i] != tabTrie[i]){
      return -1;
    }
  }
  return 0;
}