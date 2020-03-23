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
  int i = 0; int i1 = deb; int i2 = mid + 1;
  int *temp = malloc(fin*sizeof(int));
  while (i1 <= mid && i2 <= fin){
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
}

void mergeSort(int *tab, int i, int j){
  if(i < j){
    mergeSort(tab, i, (i + j) / 2);
    mergeSort(tab, ((i + j) / 2) + 1, j);
    fusion(tab, i, (i + j) / 2, j);
  }
}

int* TriFusion(int *tab, int n){
  mergeSort(tab, 0, n-1);
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

//===================Tri Rapide==================

int Partition(int *tab, int deb, int fin){
  int x = tab[fin];
  int i = deb - 1;
  for (int j = deb; j <= fin - 1; j++){
    if (tab[j] <= x){
      i++;
      swap(&tab[i], &tab[j]);
    }
  }
  swap(&tab[i + 1], &tab[fin]);
  return i+1;
}


int* TriRapide(int *tab, int deb, int fin){
  if (deb < fin){
    int q = Partition(tab, deb, fin);
    TriRapide(tab, deb, q - 1);
    TriRapide(tab, q + 1, fin);
  }  
  return tab;
}