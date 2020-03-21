#include <stdio.h>
#ifndef TRI_H
#define TRI_H


int TriTest(int *tabTrie, int *tabAVerif);


int* TriSelection(int *tab);
int* fusion(int *tab, int deb, int mid, int fin);
int* mergeSort(int *tab, int i, int j);
int* TriFusion(int *tab);
int* TriBulles(int *tab);

#endif