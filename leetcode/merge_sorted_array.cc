#include <iostream>
using namespace std;

#define PRINT(x) cout << #x  << ": "<< x << endl;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n==0) {
            return;
        }

        if (m==0) {
            for(int i = 0; i < n; i++) A[i] = B[i];
            return;
        }

        int i = m - 1;
        int j = n - 1;
        while(i>=0 && j>=0) {
            if (A[i]<=B[j]) {
                A[i+j+1] = B[j];
                j--;
            }
            if (B[j]<=A[i]) {
                A[i+j+1] = A[i];
                i--;
            }
        }        

        while(j>=0) {
            A[j]=B[j];
            j--;
        }
    }
};

void dump(int A[], int m) {
    for (int i=0; i<m; i++)
        PRINT(A[i]);
}

int main() {
    int A[100] = {2, 4 ,6, 7, 10};
    int B[6] = {1, 5 , 8, 9, 11, 13};

    Solution s;
    s.merge(A, 5, B, 6);
    
    dump(A, 11);

    return 0;
}
