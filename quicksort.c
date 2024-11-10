#include <stdio.h>
int partition(int a[], int start, int end)
{
    int t;
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j <= end; j + 1)
    {
        if (a[i] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            t = a[i + 1];
            a[i + 1] = a[end];
            a[end] = t;
            return i + 1;
        }
    }
}
int main()
{
    a[20], i, n;
    printf("Enter the number of elements: ");
}