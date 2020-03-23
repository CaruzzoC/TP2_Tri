#include "Tri.h"
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include<string.h>

//===================================Utilitaire===================================
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void genTab(int *tab, int n){
  for (int i = 0; i < n; i++){
    int ran = rand() % 100;
    tab[i] = ran;
  }
}

void copyTab(int *tab1, int *tab2, int n){
  for (int i = 0; i < n; i++){
    tab2[i] = tab1[i];
  }
}

double triSelectionPerf(int *tab, int n, int taille){
  double SExeTime = 0;
  int *TimeArrayTestCopy = malloc(taille*sizeof(int));
  for (int i = 0; i < n; i++){
    copyTab(tab, TimeArrayTestCopy, taille);
    clock_t start, end;
    start = clock();
    TriSelection(TimeArrayTestCopy,taille);
    end = clock();
    SExeTime += (double)(end - start) / CLOCKS_PER_SEC * 100000;
  }
  free(TimeArrayTestCopy);
  double MExeTime = SExeTime / n;
  return MExeTime;
}

double triFusionPerf(int *tab, int n, int taille){
  double SExeTime = 0;
  int *TimeArrayTestCopy = malloc(taille*sizeof(int));
  for (int i = 0; i < n; i++){
    copyTab(tab, TimeArrayTestCopy, taille);
    clock_t start, end;
    start = clock();
    TriFusion(TimeArrayTestCopy,taille);
    end = clock();
    SExeTime += (double)(end - start) / CLOCKS_PER_SEC * 100000;
  }
  free(TimeArrayTestCopy);
  double MExeTime = SExeTime / n;
  return MExeTime;
}

double triBullesPerf(int *tab, int n, int taille){
  double SExeTime = 0;
  int *TimeArrayTestCopy = malloc(taille*sizeof(int));
  for (int i = 0; i < n; i++){
    copyTab(tab, TimeArrayTestCopy, taille);
    clock_t start, end;
    start = clock();
    TriBulles(TimeArrayTestCopy,taille);
    end = clock();
    SExeTime += (double)(end - start) / CLOCKS_PER_SEC * 100000;
  }
  free(TimeArrayTestCopy);
  double MExeTime = SExeTime / n;
  return MExeTime;
}

double triRapidePerf(int *tab, int n, int taille){
  double SExeTime = 0;
  int *TimeArrayTestCopy = malloc(taille*sizeof(int));
  for (int i = 0; i < n; i++){
    copyTab(tab, TimeArrayTestCopy, taille);
    clock_t start, end;
    start = clock();
    TriRapide(TimeArrayTestCopy, 0, taille);
    end = clock();
    SExeTime += (double)(end - start) / CLOCKS_PER_SEC * 100000;
  }
  free(TimeArrayTestCopy);
  double MExeTime = SExeTime / n;
  return MExeTime;
}

double* ResultPerf(int Precision, int taille){
  double *ResultPerfArray = malloc(4 * sizeof(double));
  int *TimeArrayTest = malloc(taille * sizeof(int));
  genTab(TimeArrayTest, taille);
  ResultPerfArray[0] = triSelectionPerf(TimeArrayTest, Precision, taille);
  ResultPerfArray[1] = triFusionPerf(TimeArrayTest, Precision, taille);
  ResultPerfArray[2] = triBullesPerf(TimeArrayTest, Precision, taille);
  ResultPerfArray[3] = triRapidePerf(TimeArrayTest, Precision, taille);
  
  return ResultPerfArray;
}


void create_result_csv(char *filename, int count){
  FILE *fp;
  fp=fopen(filename,"w+");
  fprintf(fp,"Tri Selection, Tri Fusion, Tri à Bulles, Tri Rapide");
  fclose(fp);
  printf("\n%s file created",filename);
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
  int i = 0; int i1 = deb; int i2 = mid + 1; int taille = fin - deb +1;
  int *temp = malloc(taille*sizeof(int));
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
  free(temp);
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