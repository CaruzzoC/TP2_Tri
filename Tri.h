#include <stdio.h>
#ifndef TRI_H
#define TRI_H


int TriTest(int *tabTrie, int *tabAVerif);


int* TriSelection(int *tab, int n);

void fusion(int *tab, int deb, int mid, int fin);
void mergeSort(int *tab, int i, int j);
int* TriFusion(int *tab, int n);

int* TriBulles(int *tab, int n);

int Partition(int *tab, int deb, int fin);
int* TriRapide(int *tab, int deb, int fin);

void genTab(int *tab, int n);
void copyTab(int *tab1, int *tab2, int n);

double triSelectionPerf(int *tab, int n, int taille);
double triFusionPerf(int *tab, int n, int taille);
double triBullesPerf(int *tab, int n, int taille);
double triRapidePerf(int *tab, int n, int taille);
double* ResultPerf(int Precision, int taille);

void create_result_csv(char *filename, int count);

#endif