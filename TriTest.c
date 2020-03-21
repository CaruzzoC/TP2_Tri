#include "Tri.h"

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