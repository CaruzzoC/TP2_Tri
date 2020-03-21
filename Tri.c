#include "Tri.h"
#include <stdlib.h>

//=====================================TriSelection================================

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

//=====================================TriFusion=============================
int* fusion(int *tab, int deb, int mid, int fin){
  int len = sizeof(tab)/sizeof(tab[0]) + 1;
  int *temp = malloc(len*sizeof(int));
  int i = 0; int i1 = tab[0]; int i2 = tab[len/2 + 1];
  while (i1 <= mid && i2 <= len){
    if (tab[i1] < tab[i2]) {
      temp[i] = tab[i1];
      i1++;
    }
    else{
      temp[i] = tab[i2];
      i2++;
    }
    i++;
  }
  if (i1 < mid + 1){
    for (int j = i1; j <= mid; j++){
      temp[i] = tab[j];
      i++;
    }
  }
  else{
    if(i2 < fin + 1){
      for (int j = i2; j <= fin; j++){
        temp[i] = tab[j];
        i++;
      }
    }
  }
  int k = 0;
  for(i = deb; i <= fin; i++){
    tab[i] = temp[k];
    k++;
  }
  return tab;
}

int* mergeSort(int *tab, int i, int j){
  if( i < j){
    mergeSort(tab, i, (i + j) / 2);
    mergeSort(tab, (i + j) / 2 + 1, j);
    fusion(tab, i, (i + j) / 2, j);
  }
  return tab;
}

int* TriFusion(int *tab){
  mergeSort(tab, 0, sizeof(tab)/sizeof(tab[0]) - 2);
  return tab;
}

//=====================Tri a Bulles===============

int* TriBulles(int *tab){
  int len = sizeof(tab)/sizeof(tab[0]) + 1;
  int temp = 0;
  for (int i = len - 1; i <= 1; i--){
    for (int j = 0; j <= i - 1; j++){
      if (tab[j + 1] < tab[j]){
        temp = tab[j + 1];
        tab[j + 1] = tab[j];
        tab[j] = temp;
      }
    }
  }
  return tab;
}