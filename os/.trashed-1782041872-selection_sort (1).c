#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort Function
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
        arr[min_idx] = (arr[min_idx]+arr[i]) - (arr[i] = arr[min_idx]);
        //temp = arr[min_idx];
        //arr[min_idx] = arr[i];
        //arr[i] = temp;
    }
}

int main()
{
int count;
printf("Enter loop count: "); scanf("%d",&count);
srand(time(0));
for (int k=0;k<count;k++){
    int n, i;
    //printf("Enter number of elements (n > 5000): ");
    //scanf("%d", &n);
	n=(rand()%20001)+5000;
    int *arr = (int *)malloc(n * sizeof(int));

    // Generate random numbers
    for (i = 0; i < n; i++)
        arr[i] = rand();

    clock_t start, end;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements = %f seconds\n", n, time_taken);

    free(arr);
    
}
return 0;
}
