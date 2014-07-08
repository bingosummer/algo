#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> get_new_num(map<vector<int>, bool> seen) {
    vector<int> ret;
    for (map<vector<int>, bool>::iterator it = seen.begin(); it != seen.end(); it++) {
        if (it->second == false)
            return it->first;
    }
    return ret;
}

vector<vector<int> > permute(vector<int> &num) {
    int n = num.size();

    vector<vector<int> > ret;
    ret.push_back(num);

    map<vector<int>, bool> seen;
    seen[num] = false;

    vector<int> new_num = get_new_num(seen); 
    while (new_num.size()>0) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = new_num[i];
                new_num[i] = new_num[j];
                new_num[j] = tmp;
                map<vector<int>, bool>::iterator it = seen.find(new_num);
    cout << it->second << endl;
                if (it == seen.end()) {
                    ret.push_back(new_num);
                    seen[new_num] = false;
                }
            }
        }
        seen[new_num] = true;
        new_num = get_new_num(seen); 
    }
    return ret;
}

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    vector<vector<int> > vv = permute(num);

    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[0].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }

    return 0;
}
