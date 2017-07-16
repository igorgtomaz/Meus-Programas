#include <time.h>
#define  MAX 7

//Funções auxiliares
void imprimeVetor(int vet[], int n, int c);
void troca(int *n1, int *n2);
int divisao(int vet[], int menor, int maior);
void count_quickSort(int vet[], int menor, int maior, double *tempo);
void merge(int vet[], int e, int m, int d);
void count_mergeSort(int vet[], int e, int d, double *tempo);
void insereVetor(int vet[], int n, int maior);
void programa();

//Funções sort
void bubbleSort(int vet[], int n, double *tempo);
void insertionSort(int vet[], int n, double *tempo);
void selectionSort(int vet[], int n, double *tempo);
void quickSort(int vet[], int menor, int maior);
void mergeSort(int vet[], int e, int d);
