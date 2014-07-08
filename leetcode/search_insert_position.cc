#include <iostream>
using namespace std;

class Solution {
public:
    int binarySearch(int A[], int start, int end, int target) {
        
        if (start==end-1) {
            if (A[start] == target) return start;
            else return end;
        }

        while (start < end) {
            int middle = (end-start)/2+start;
            int key = A[middle];
            
            if (key == target)
                return middle;
            else if (key < target)
                return binarySearch(A, middle, end, target);
            else
                return binarySearch(A, start, middle, target);
        }

        return -1;
    }
    
    int searchInsert(int A[], int n, int target) {
        if (A[n-1]<target) return n;
        if (A[0]>target) return 0;
        return binarySearch(A, 0, n-1, target);
    }
};

int main()
{
    int A[] = {1,2,3,5,6,8};
    Solution s;
    for (int i=0; i<10; i++)
        cout << i << ": " << s.searchInsert(A, 6, i) << endl;
}
