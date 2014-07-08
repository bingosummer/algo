#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ret;
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i]+numbers[j]==target) {
                ret.push_back(i+1);
                ret.push_back(j+1);
                break;
            }
        }
    }

    return ret;
}

int main()
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);

    vector<int> ret = twoSum(numbers, 9);

    for (int i = 0; i < ret.size(); i++) cout << ret[i] << endl;

    return 0;
}
