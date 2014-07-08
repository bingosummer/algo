#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ret;
    for (int i = 1; i <= numRows; i++) {
        vector<int> line;
        vector<int> pre_line;
        if (!ret.empty())
            pre_line = ret[ret.size()-1];
        for (int j = 0; j < i; j++) {
            if (j==0 || j==i-1)
                line.push_back(1);
            else {
                line.push_back(pre_line[j]+pre_line[j-1]);
            }
        }
        ret.push_back(line);
    }
    return ret;
}

void dump(vector<vector<int> > vv) {
    for (int i = 0; i < vv.size(); i++) {
        vector<int> v = vv[i];
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int> > ret = generate(0);
    dump(ret);
    return 0;
}
