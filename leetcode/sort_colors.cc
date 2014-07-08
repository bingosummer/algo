#include <iostream>

using namespace std;

void swap(int A[], int a, int b) {
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void sortColors(int A[], int n) {
    int i = -1;
    for (int j = 0; j < n; j++) {
        if (A[j] < 1) {
            i++;
            swap(A, i , j);
        }
    }
    for (int j = i+1; j < n; j++) {
        if (A[j] < 2) {
            i++;
            swap(A, i , j);
        }
    }
}

int main()
{
    int A[] = {0, 1, 2, 2, 1, 2, 0};
    int n = sizeof(A)/sizeof(int);
    sortColors(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << endl;
    return 0;
}
