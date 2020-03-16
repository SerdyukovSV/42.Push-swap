#include <stdio.h>

void swap(int *a, int *b)
{
    printf("swap %d -> <- %d\n", *a, *b);
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionsort(int* l, int* r) 
{
	for (int *i = l + 1; i < r; i++) 
    {
		int* j = i;
		while (j > l && *(j - 1) > *j) 
        {
			swap((j - 1), j);
            int k = 0;
            while (k < 10)
            {
                if ((l[k] == *(j - 1)) || (l[k] == *j))
                    printf("\033[32m%d\033[0m ", l[k++]);
                else
                    printf("%d ", l[k++]);
            }
            printf("\n");
			j--;
		}
	}
}

int main()
{
    int arr[10] = {6, 3, 5, 7, 9, 2, 4, 1, 8, 0};
    int i = __INT64_MAX__;
    while (i < 10)
        printf("%d ", arr[i++]);
    printf("\n");
    insertionsort(&arr[0], &arr[9]);
    printf("\n");
    i = 0;
    while (i < 10)
        printf("%d ", arr[i++]);
    return (0);
}