#include<stdio.h>

int merge(int arr[], int p, int mid, int q) {
    int i = p, j = mid + 1, k = p, b[q + 1];
    while (i <= mid && j <= q) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
        while (j <= q) {
            b[k] = arr[j];
            j++;
            k++;
        }
    else
        while (i <= mid) {
            b[k] = arr[i];
            i++;
            k++;
        }
    for (i = p; i <= q; i++)
        arr[i] = b[i];
}

void mergesort(int arr[], int p, int q) {
    if (p < q) {
        int mid = (p + q) / 2;
        mergesort(arr, p, mid);
        mergesort(arr, mid + 1, q);  // Fix here, change mid-1 to mid
        merge(arr, p, mid, q);
    }
}

int main() {
    int n, p, q, i, sz;
    printf("\n Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter %d elements into the array:\n ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sz = sizeof(arr) / sizeof(arr[0]);
    q = sz - 1;
    p = 0;
    printf("\n The entered array is...\n\n ");
    for (i = 0; i < sz; i++)
        printf("%d, ", arr[i]);
    mergesort(arr, p, q);
    printf("\n\n The Sorted array is...\n\n ");
    for (i = 0; i < sz; i++)
        printf("%d, ", arr[i]);

    return 0;
}
