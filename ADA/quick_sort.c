#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1, temp;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    temp = a[i+1]; a[i+1] = a[high]; a[high] = temp;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
int count;
printf("Enter loop count: "); scanf("%d",&count);
srand(time(0));
for(int k=0;k<count;k++){
    //int n;
    //printf("Enter number of elements (>5000): ");
    //scanf("%d", &n);
    int  n = (rand()%20001)+5000;

    int *a = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 10000;

    clock_t start = clock();
    quickSort(a, 0, n - 1);
    clock_t end = clock();

    printf("Time taken to sort %5d elements = %f seconds\n",n,(double)(end - start) / CLOCKS_PER_SEC);

    free(a);
}
return 0;
}