#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *ret = new int[m*n];
        for (int i = 0; i < m*n; i++) ret[i] = 0;

        for (int i = 0; i < m*n; i++) {
            cout << ret[i] << " ";
            if (((i+1)%n)==0) cout << endl;
        }
        cout << endl;

        for (int j = n-1; j >= 0; j--) ret[n*(m-1)+j] = 1;
        for (int i = m-1; i >= 0; i--) ret[n*i+n-1] = 1;
       
        for (int i = 0; i < m*n; i++) {
            cout << ret[i] << " ";
            if (((i+1)%n)==0) cout << endl;
        }
        cout << endl;

        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                ret[n*i+j] = ret[n*(i+1)+j] + ret[n*i+j+1];
            }
        }

        for (int i = 0; i < m*n; i++) {
            cout << ret[i] << " ";
            if (((i+1)%n)==0) cout << endl;
        }
        cout << endl;
        
        return ret[0]; 
    }

    int uniquePaths2(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if((m <= 0) || (n <= 0)) return 0;
        if((1 == m) || (1 == n)) return 1;
        int map[n + 1];
        memset(map, 0, sizeof(map));
        for(int i = 1; i <= n; i ++) map[i] = 1;
        for(int i = 2; i <= m; i ++) {
            for(int j = 2; j <= n; j ++) {
                map[j] += map[j - 1];
                cout << map[j] << " ";
            }
            cout << endl;
        }
        return map[n];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3,7) << endl;
    cout << s.uniquePaths2(3,7) << endl;
    cout << s.uniquePaths(7,3) << endl;
    cout << s.uniquePaths2(7,3) << endl;
    return 0;
}

