#include <stdio.h>

int findMax(int a[], int n, int i, int max)
{
    if (i == n)
        return max;

    if (a[i] > max)
        max = a[i];

    return findMax(a, n, i + 1, max);
}

int countMax(int a[], int n, int i, int max)
{
    if (i == n)
        return 0;

    if (a[i] == max)
        return 1 + countMax(a, n, i + 1, max);

    return countMax(a, n, i + 1, max);
}

int main()
{
    int a[100], n, i, max, count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n <= 0 || n > 100) {
        printf("Invalid array size.");
        return 0;
    }

    max = findMax(a, n, 0, a[0]);
    count = countMax(a, n, 0, max);

    printf("Maximum element = %d\n", max);
    printf("Occurrences = %d", count);

    return 0;
}