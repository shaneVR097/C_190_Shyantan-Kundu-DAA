#include <stdio.h>

int merge(int arr[], int p[], int d[], int jobNo[], int left, int mid, int right);
void mergesort(int arr[], int p[], int d[], int jobNo[], int left, int right);
void schedule_jobs(int d[], int p[], int n);

int main() {
    int n, i;
    printf("\nEnter the number of jobs: ");
    scanf("%d", &n);
    int d[n], p[n], jobNo[n];

    printf("\nEnter deadline and profit for jobs 1 to %d:\n", n);
    int d_max = 0; // Initialize d_max to 0
    for (i = 0; i < n; i++) {
        printf("\nEnter deadline and profit associated with job %c: ", 'a' + i);
        scanf("%d %d", &d[i], &p[i]);
        if (d[i] > d_max) { // Update d_max if a larger deadline is found
            d_max = d[i];
        }
        jobNo[i] = i; // Store original job numbers starting from 0
    }

    mergesort(p, jobNo, d, jobNo, 0, n - 1);

    printf("\n\nThe Sorted array is...\n\n");
    printf("\nJob no. : ");
    for (i = 0; i < n; i++)
        printf("J%d, ", jobNo[i]+1);

    printf("\nDeadline no. of days : ");
    for (i = 0; i < n; i++)
        printf("%d, ", d[jobNo[i]]);

    printf("\nProfit : ");
    for (i = 0; i < n; i++)
        printf("%d, ", p[i]);

    printf("\nMax Deadline: %d\n", d_max);

    schedule_jobs(d, p, n);

    return 0;
}

void schedule_jobs(int d[], int p[], int n) {
    int selected_jobs[n];
    int i, j, max_profit = 0;
    for (i = 0; i < n; i++) {
        selected_jobs[i] = 0;
    }

    int max_deadline = (d[0] < n ? d[0] : n);

    for (i = 0; i < n; i++) {
        for (j = max_deadline - 1; j >= 0; j--) {
            if (!selected_jobs[j]) {
                selected_jobs[j] = 1;
                max_profit += p[i];
                break;
            }
        }
    }

    printf("\nJob sequence: ");
    for (i = 0; i < n; i++) {
        if (selected_jobs[i]) {
            printf("%c, ", 'a' + i);
        }
    }
    printf("\nTotal profit: %d\n", max_profit);
}

int merge(int arr[], int p[], int d[], int jobNo[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, b[right + 1], c[right + 1], e[right + 1];
    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j]) { // Compare in descending order
            b[k] = arr[i];
            c[k] = p[i];
            e[k] = d[jobNo[i]];
            jobNo[k] = i;
            i++;
        } else {
            b[k] = arr[j];
            c[k] = p[j];
            e[k] = d[jobNo[j]];
            jobNo[k] = j;
            j++;
        }
        k++;
    }
    if (i > mid)
        while (j <= right) {
            b[k] = arr[j];
            c[k] = p[j];
            e[k] = d[jobNo[j]];
            jobNo[k] = j;
            j++;
            k++;
        }
    else
        while (i <= mid) {
            b[k] = arr[i];
            c[k] = p[i];
            e[k] = d[jobNo[i]];
            jobNo[k] = i;
            i++;
            k++;
        }
    for (k = left; k <= right; k++) {
        arr[k] = b[k];
        p[k] = c[k];
        d[jobNo[k]] = e[k];
    }
    return 0;
}

void mergesort(int arr[], int p[], int d[], int jobNo[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, p, d, jobNo, left, mid);
        mergesort(arr, p, d, jobNo, mid + 1, right);
        merge(arr, p, d, jobNo, left, mid, right);
    }
}