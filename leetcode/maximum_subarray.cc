#include <iostream>
using namespace std;

int maxsequence(int arr[], int len)
{
    int max = arr[0];
    for (int i=0; i<len; i++) {
        int sum = 0;
        for (int j=i; j<len; j++) {
            sum += arr[j];
            if (sum > max)
                max = sum;
        }
    }
    return max;
}

int max3(int i, int j, int k)
{
    if (i>=j && i>=k)
        return i;
    return max3(j, k, i);
}

int maxsequence2(int a[], int l, int u)
{
    if (l > u) return 0;
    if (l == u) return a[l];
    int m = (l + u) / 2;

    int lmax=a[m], lsum=0;
    for (int i=m; i>=l; i--) {
        lsum += a[i];
        if (lsum > lmax)
            lmax = lsum;
    }
    
    int rmax=a[m+1], rsum = 0; 
    for (int i=m+1; i<=u; i++) { 
        rsum += a[i];
        if (rsum > rmax) 
        rmax = rsum; 
    }
    return max3(lmax+rmax, maxsequence2(a, l, m), maxsequence2(a, m+1, u));
}

int maxsequence3(int a[], int len)
{
    int maxsum, maxhere;
    maxsum = maxhere = a[0];
    int start = 0;
    int end = 0;
    for (int i=1; i<len; i++) {
        if (maxhere <= 0)
            maxhere = a[i];
        else
            maxhere += a[i];
        if (maxhere > maxsum) {
            maxsum = maxhere;
            end = i;
        }
    }

    int tmp = maxsum;
    for (int i=end; i>=0; i--) {
        tmp -= a[i];
        if (tmp==0) { start = i; break;}
    }

    cout << "start: " << start << endl;
    cout << "end: " << end << endl;

    return maxsum;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int len = sizeof(arr)/sizeof(int);
    cout << maxsequence(arr, len) << endl;
    cout << maxsequence2(arr, 0, len-1) << endl;
    cout << maxsequence3(arr, len) << endl;
    return 0;
}

