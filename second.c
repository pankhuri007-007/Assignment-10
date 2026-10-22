#include <stdio.h>

void findLargest(int a[], int n, int i, int *max1, int *max2)
{
    if (i == n)
        return;

    if (a[i] > *max1) {
        *max2 = *max1;
        *max1 = a[i];
    }
    else if (a[i] < *max1 && a[i] > *max2) {
        *max2 = a[i];
    }

    findLargest(a, n, i + 1, max1, max2);
}

int main()
{
    int a[100], n, i;
    int max1 = -2147483647 - 1;
    int max2 = -2147483647 - 1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    findLargest(a, n, 0, &max1, &max2);

    if (max2 == -2147483647 - 1)
        printf("Second-largest distinct element does not exist.");
    else
        printf("Second-largest element = %d", max2);

    return 0;
}