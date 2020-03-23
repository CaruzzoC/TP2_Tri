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

#endif