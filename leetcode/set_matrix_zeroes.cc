#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    bool row_zero = false;
    bool column_zero = false;
    for (int i = 0; i < n; i++) {
        if (matrix[0][i]==0) {
            row_zero = true;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][0]==0) {
            column_zero = true;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j]==0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) { 
            if (matrix[i][0]==0||matrix[0][j]==0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (row_zero) {
        for (int j = 1; j < n; j++) matrix[0][j] = 0;
    }
    if (column_zero) {
        for (int i = 1; i < m; i++) matrix[i][0] = 0;
    }
 
}

void dump(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        //vector<int> tmp = matrix[i];
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 0;
    vector<vector<int> > matrix;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> tmp;
        for (int j = 1; j <= n; j++) {
            tmp.push_back(j + (i-1) * n);
        }
        matrix.push_back(tmp);
    }

    matrix[1][2] = 0;
    matrix[3][4] = 0;
    dump(matrix);
    setZeroes(matrix);
    dump(matrix);

    return 0;
}

