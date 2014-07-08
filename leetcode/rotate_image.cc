#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }            
}

void dump(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        vector<int> tmp = matrix[i];
        for (int j = 0; j < n; j++) {
            cout << tmp[j] << " ";
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

    dump(matrix);
    rotate(matrix);
    dump(matrix);

    return 0;
}

