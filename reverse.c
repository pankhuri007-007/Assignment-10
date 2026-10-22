#include <stdio.h>

void reverse(int a[], int start, int end)
{
    if (start >= end)
        return;

    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;

    reverse(a, start + 1, end - 1);
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    reverse(a, 0, n - 1);

    printf("Reversed array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}