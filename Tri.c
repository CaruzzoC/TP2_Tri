#include "Tri.h"
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include<string.h>

//===================================Utilitaire===================================

/**
*Swap(case x, case y)
*int *x - case d'une liste a échanger
*int *y - case d'une liste a échanger
*
*Prend deux cases d'un tableau et les échange en utilisant une variable temporaire
*local "temp".
*/
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

/**
*genTab(liste a générer, longueur de la liste)
*int *tab - une liste
*int n - un entier égale a la longueur de la liste passé en paramètre
*
*Prend un tableau et sa taille en entrée, et y ajoute des valeurs entière
*aléatoire < 100 pour chaques cases de cette liste.
*/
void genTab(int *tab, int n){
  for (int i = 0; i < n; i++){
    int ran = rand() % 100;
    tab[i] = ran;
  }
}

/**
*copyTab(liste a copier, liste clone, longueur des listes)
*int *tab1 - La liste a recopier
*int *tab2 - La liste qui va servir de clone
*int n - entier égale à la longueur des deux listes
*
*Prend deux tableaux et leur tailles en entrée, Pour chaque valeur du tab1
*on recopie les valeurs dans le tab2
*/
void copyTab(int *tab1, int *tab2, int n){
  for (int i = 0; i < n; i++){
    tab2[i] = tab1[i];
  }
}

/**
*triSelectionPerf(liste a trier, précision, longueur de la liste )
*int *tab - La liste a trier
*int n - nombre de fois que la liste sera trié, représente donc la précision
*de la donné (plus le chiffre est grand meilleur sera la précision)
*int taille - entier égale à la longueur de la listes
*
*Calcule le temps de processe de l'algorithme TriSelection en l'ajoutant à
*une valeur SExeTime(sum) et return la moyenne du temps de process
*/
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

/**
*triFusionPerf(liste a trier, précision, longueur de la liste )
*int *tab - La liste a trier
*int n - nombre de fois que la liste sera trié, représente donc la précision
*de la donné (plus le chiffre est grand meilleur sera la précision)
*int taille - entier égale à la longueur de la listes
*
*Calcule le temps de processe de l'algorithme TriFusion en l'ajoutant à
*une valeur SExeTime(sum) et return la moyenne du temps de process
*/
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

/**
*triBullesPerf(liste a trier, précision, longueur de la liste )
*int *tab - La liste a trier
*int n - nombre de fois que la liste sera trié, représente donc la précision
*de la donné (plus le chiffre est grand meilleur sera la précision)
*int taille - entier égale à la longueur de la listes
*
*Calcule le temps de processe de l'algorithme TriBulles en l'ajoutant à
*une valeur SExeTime(sum) et return la moyenne du temps de process
*/
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

/**
*triRapidePerf(liste a trier, précision, longueur de la liste )
*int *tab - La liste a trier
*int n - nombre de fois que la liste sera trié, représente donc la précision
*de la donné (plus le chiffre est grand meilleur sera la précision)
*int taille - entier égale à la longueur de la listes
*
*Calcule le temps de processe de l'algorithme TriRapide en l'ajoutant à
*une valeur SExeTime(sum) et return la moyenne du temps de process
*/
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

/**
*ResultPerf(précision, longueur de la liste )
*int Precision - nombre de fois que la liste sera trié, représente donc la précision
*de la donné (plus le chiffre est grand meilleur sera la précision)
*int taille - entier égale à la longueur de la listes
*
*Stock dans une liste les 4 temps des 4 algorithme de Tri implémenté
*return une liste de 4 éléments (taille de 4 (int))
*/
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

/**
*create_result_csv(Nom du fichier, nombre de donnés a générer )
*char *filename - nom du fichier (mettre .csv en fin de nom pour l'enregistrer au bon format)
*int count - nombre de donnée que l'on veut générer, le nombre de donnée augmentera
*la précision des courbes créer à l'aide des données généré
*
*créer un fichier de manière "intéractive" avec une génération de donée au choix
*/
void create_result_csv(char *filename, int count){
FILE *fp;
int i = 0;

fp=fopen(filename,"w+");

fprintf(fp,"Tri Selection, Tri Fusion, Tri à Bulles, Tri Rapide\n");
printf("How many Result do you want to save? ");
scanf("%d", &count);

for(int i=0;i<count;i++){
  for(int j = 0; j < 4; j++){
    fprintf(fp,"%f, ",ResultPerf(100,(100*i)+100)[j]);
  }
  fprintf(fp,"\n");
}
fclose(fp);

printf("\n%s file created",filename);
}

//=====================================TriSelection================================

/**
*TriSelection(une liste, longueur de la liste )
*int *tab - La liste que l'on veut trier
*int n - longueur de la liste que l'on veut trier
*
*Trier une liste avec l'algorithme Tri par Selection
*à chaque itération mettre le plus petit élément à l'index auquel
*on a commencé.
*/
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

/**
*fusion(une liste, le début de la liste à fusioné, le milieu, et la fin )
*int *tab - La liste que l'on veut fusionner
*int deb - debut de la liste a fusionner
*int mid - milieu del al liste à fusionner
*int fin - fin de la liste à fusionner
*
*Fusionner une liste
*on utilise une liste temporaire que l'on tri, puis on fusionne le tout
*/
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

/**
*mergeSort(une liste, debut de la partition, fin de la partition )
*int *tab - La liste que l'on veut découper
*int i - début de la partition
*int j - fin de la partition
*
*fonction récursive qui découpe la liste en sous partie qui ont pour
*longueur la moitié de la partie précédente
*/
void mergeSort(int *tab, int i, int j){
  if(i < j){
    mergeSort(tab, i, (i + j) / 2);
    mergeSort(tab, ((i + j) / 2) + 1, j);
    fusion(tab, i, (i + j) / 2, j);
  }
}

/**
*TriFusion(la liste à trier, longueur de la liste)
*int *tab - La liste que l'on veut trier
*int n - longueure de la liste
*
*Trier une liste avec l'algorithme Tri Fusion
*lance le processus récursif, decouper en partion de longueur minimal, trier, puis fusionner
*/
int* TriFusion(int *tab, int n){
  mergeSort(tab, 0, n-1);
  return tab;
}

//=====================Tri a Bulles===============

/**
*TriFusion(la liste à trier, longueur de la liste)
*int *tab - La liste que l'on veut trier
*int n - longueure de la liste
*
*Trier une liste avec l'algorithme Tri à Bulles
*Compare les valeurs deux à deux, et ce, jusqu'à que la liste soit trié
*/
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

/**
*Partition(la liste à trier, le debut, la fin)
*int *tab - La liste que l'on veut trier
*int deb - debut de la partition
*int fin - fin de la partition
*
*parcour la partition si une valeur est inferieur à celle du pivot
*alors elle est trié
*/
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

/**
*TriRapide(la liste à trier, le debut, la fin)
*int *tab - La liste que l'on veut trier
*int deb - debut de la partition
*int fin - fin de la partition
*
*Trier une liste avec l'algorithme Tri Rapide
*Prend une valeur pivot, puis on charche la place du pivot dans la listes
*non trié, puis on trie toute les valeur sur sa gauche
*/
int* TriRapide(int *tab, int deb, int fin){
  if (deb < fin){
    int q = Partition(tab, deb, fin);
    TriRapide(tab, deb, q - 1);
    TriRapide(tab, q + 1, fin);
  }  
  return tab;
}