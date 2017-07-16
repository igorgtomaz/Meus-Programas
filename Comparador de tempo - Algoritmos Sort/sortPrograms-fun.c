#include "sortPrograms.h"

// Funções auxiliares

// Imprime os valores do vetor
void imprimeVetor(int vet[], int n, int c)
{
  int i;

  if (c == 0)
      printf("\nVetor antes de ordenar:\n");
  else
      printf("\nVetor depois de ordenar:\n");

  for (i = 0; i < n; i++)
  {
    if (i == (n-1))
      printf("%i", vet[i]);
    else
      printf("%i-", vet[i]);
  }
  printf("\n");
}

//Realiza a troca dos valores dos vetores
void troca(int *n1, int *n2)
{
  int aux = *n1;
  *n1 = *n2;
  *n2 = aux;
}

//Realiza a divisão do QuickSort
int divisao(int vet[], int menor, int maior)
{
  int pivot = vet[maior];
  int i = (menor - 1);
  int j;

  for (j = menor; j <= maior-1; j++)
  {
    if(vet[j] <= pivot)
    {
      i++;
      troca(&vet[i], &vet[j]);
    }
  }
  troca(&vet[i+1], &vet[maior]);
  return (i + 1);
}

//Conta o tempo do QuickSort
void count_quickSort(int vet[], int menor, int maior, double *tempo)
{
    clock_t c0, c1;

    c0 = clock();
    quickSort(vet, menor, maior);
    c1 = clock();

    *tempo = (double) (c1 - c0)/CLOCKS_PER_SEC;
}

//Merge, função auxiliar do MergeSort
void merge(int vet[], int e, int m, int d)
{
    int i, j, k;
    int n1 = m - e + 1;
    int n2 =  d - m;

    int E[n1], D[n2];

    for (i = 0; i < n1; i++)
        E[i] = vet[e + i];
    for (j = 0; j < n2; j++)
        D[j] = vet[m + 1+ j];

    i = 0;
    j = 0;
    k = e;

    while (i < n1 && j < n2)
    {
        if (E[i] <= D[j])
        {
            vet[k] = E[i];
            i++;
        }
        else
        {
            vet[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vet[k] = E[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vet[k] = D[j];
        j++;
        k++;
    }
}

//Função que conta o tempo do mergeSort
void count_mergeSort(int vet[], int e, int d, double *tempo)
{
  clock_t c0, c1;

  c0 = clock();
  mergeSort(vet, e, d);
  c1 = clock();

  *tempo = (double) (c1 - c0)/CLOCKS_PER_SEC;
}

//Insere valores aleatorios no vetor
void insereVetor(int vet[], int n, int maior)
{
  int i, j, verif, num;
  srand(time(NULL));

  for (i = 0; i < n;)
  {
    verif = 0;
    num = rand() % maior;

    for (j = 0; j <= i; j++)
      if (vet[j] == num)
        verif = 1;

    if (verif == 0 && (num > 0 && num <= maior))
      {
        vet[i] = num;
        i++;
      }
    }
}

//Menu
void programa()
{
  int num, i;
  /*
  temp[0] = bubble;
  temp[1] = insertion;
  temp[2] = selection;
  temp[3] = quick;
  temp[4] = merge
  */
  double temp[5];

  printf("Programa iniciado\n\n");

  printf("Digite quantos valores devem conter no vetor: ");
  scanf("%i", &num);

  int vet[num], vet_reser[num];

  insereVetor(vet, num, (num+1));

  for(i = 0; i < num; i++)
    vet_reser[i] = vet[i];

  bubbleSort(vet, num, &temp[0]);

  for(i = 0; i < num; i++)
    vet[i] = vet_reser[i];

  insertionSort(vet, num, &temp[1]);

  for(i = 0; i < num; i++)
    vet[i] = vet_reser[i];

  selectionSort(vet, num, &temp[2]);

  for(i = 0; i < num; i++)
    vet[i] = vet_reser[i];

  count_quickSort(vet, 0, num, &temp[3]);

  for(i = 0; i < num; i++)
    vet[i] = vet_reser[i];

  count_mergeSort(vet, 0, num-1, &temp[4]);

  printf("\n--------------------------------\n");
  printf("Método\t\t-\tTempo\n");
  printf("--------------------------------\n");
  printf("Bubble Sort\t-\t%lf\n", temp[0]);
  printf("Insertion Sort\t-\t%lf\n", temp[1]);
  printf("Selection Sort\t-\t%lf\n", temp[1]);
  printf("Quick Sort\t-\t%lf\n", temp[1]);
  printf("Merge Sort\t-\t%lf\n", temp[1]);
  printf("--------------------------------\n");
}

// Métodos de ordenação

// Método de ordenação InsertionSort
void insertionSort(int vet[], int n, double *tempo)
{
  int i, j, chave;
  clock_t c0, c1;

  c0 = clock();
  for (i = 1; i < n; i++)
  {
    chave = vet[i];
    j = i-1;

    while (j >= 0 && vet[j] > chave)
    {
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = chave;
  }
  c1 = clock();

  *tempo = (double) (c1 - c0)/CLOCKS_PER_SEC;
}

// Método de ordenação BubbleSort
void bubbleSort(int vet[], int n, double *tempo)
{
  int i, j;
  clock_t c0, c1;

  c0 = clock();
  for(i = 0; i < n-1; i++)
  {
    for (j = 0; j < n-i-1; j++)
      if (vet[j] > vet[j+1])
        troca(&vet[j], &vet[j+1]);
  }
  c1 = clock();

  *tempo = (double) (c1 - c0)/CLOCKS_PER_SEC;
}

// Método de ordenação SelectionSort
void selectionSort(int vet[], int n, double *tempo)
{
  int i, j, menor_indice;
  clock_t c0, c1;

  c0 = clock();
  for(i = 0; i < n-1; i++)
  {
    menor_indice = i;
    for(j = i+1; j < n; j++)
      if(vet[j] < vet[menor_indice])
        menor_indice = j;

    troca(&vet[menor_indice], &vet[i]);
  }
  c1 = clock();

  *tempo = (double) (c1 - c0)/CLOCKS_PER_SEC;
}

// Método de ordenação QuickSort
void quickSort(int vet[], int menor, int maior)
{
  if (menor < maior)
  {
    int di = divisao(vet, menor, maior);

    quickSort(vet, menor, di-1);
    quickSort(vet, di+1, maior);
  }
}

// Método de ordenação MergeSort
void mergeSort(int vet[], int e, int d)
{
  if (e < d)
  {
    int m = ((e+d)/2);

    mergeSort(vet, e, m);
    mergeSort(vet, m+1, d);

    merge(vet, e, m, d);
  }
}
