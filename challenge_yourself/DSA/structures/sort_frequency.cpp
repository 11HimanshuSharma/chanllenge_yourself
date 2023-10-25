// You are using GCC
#include <stdio.h>

const int MAX_N = 100;

void merge(int arr[], int temp[], int left, int mid, int right) {
    //Type your code here
}

void mergeSort(int arr[], int temp[], int left, int right) {
    //Type your code here
}

void countAndSortFrequency(int arr[], int n) {
    int freqArr[MAX_N][2] = {0};
    int values[MAX_N];

    int index = 0;
    for (int i = 0; i < n; i++) {
        int isAlreadyCounted = 0;
        for (int j = 0; j < index; j++) {
            if (values[j] == arr[i]) {
                freqArr[j][1]++;
                isAlreadyCounted = 1;
                break;
            }
        }
        if (!isAlreadyCounted) {
            values[index] = arr[i];
            freqArr[index][0] = arr[i];
            freqArr[index][1] = 1;
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (freqArr[i][1] < freqArr[j][1] || (freqArr[i][1] == freqArr[j][1] && freqArr[i][0] > freqArr[j][0])) {
                int temp = freqArr[i][0];
                freqArr[i][0] = freqArr[j][0];
                freqArr[j][0] = temp;

                temp = freqArr[i][1];
                freqArr[i][1] = freqArr[j][1];
                freqArr[j][1] = temp;
            }
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < freqArr[i][1]; j++) {
            printf("%d ", freqArr[i][0]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_N];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    countAndSortFrequency(arr, n);

    return 0;
}