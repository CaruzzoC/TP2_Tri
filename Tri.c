#include "Tri.h"
#include <stdlib.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

/*
for(int k=0;k<n;k++){
        printf("%i,",tab[k]);
      }
      printf("\n");
*/
//=====================================TriSelection================================

int* TriSelection(int *tab, int n){
  int min = tab[0];
  int index = 0;
  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j ++){
      if (tab[j] < min){
        min = tab[j];
        index = j;
      }
    }
    swap(&tab[i], &tab[index]);
  }
  return tab;
}

//=====================================TriFusion=============================
void fusion(int *tab, int deb, int mid, int fin){
  int len = sizeof(tab)/sizeof(tab[0]) + 1;
  int i = 0; int i1 = tab[0]; int i2 = tab[len/2 + 1];
  while (i1 <= mid && i2 <= len){
    if (tab[i1] < tab[i2]) {
      tab[i] = tab[i1];
      i1++;
    }
    else{
      tab[i] = tab[i2];
      i2++;
    }
    i++;
  }
  if (i1 < mid + 1){
    for (int j = i1; j <= mid; j++){
      tab[i] = tab[j];
      i++;
    }
  }
  else{
    if(i2 < fin + 1){
      for (int j = i2; j <= fin; j++){
        tab[i] = tab[j];
        i++;
      }
    }
  }
  int k = 0;
  for(i = deb; i <= fin; i++){
    tab[i] = tab[k];
    k++;
  }
}

void mergeSort(int *tab, int i, int j){
  if(i < j){
    mergeSort(tab, i, (i + j) / 2);
    mergeSort(tab, (i + j) / 2 + 1, j);
    fusion(tab, i, (i + j) / 2, j);
  }
}

int* TriFusion(int *tab){
  mergeSort(tab, 0, sizeof(tab)/sizeof(tab[0]) - 2);
  return tab;
}

//=====================Tri a Bulles===============

int* TriBulles(int *tab,int n){
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n - i - 1; j++){
      if(tab[j] < tab[j - 1]){
        swap(&tab[j-1], &tab[j]);
      }
    }
  }
  return tab;
}