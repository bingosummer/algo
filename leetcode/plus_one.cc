#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    vector<int> ret;
    int n = digits.size();
    digits[n-1] = digits[n-1] + 1;
    for (int i = n - 1; i > 0; i--) {
        if (digits[i] == 10) {
            digits[i-1] += 1;
            digits[i] = 0;
        }
    }
    if (digits[0] == 10) {
        ret.push_back(1);
        ret.push_back(0);
    } else {
        ret.push_back(digits[0]);
    }
    for (int i = 1; i < n; i++) ret.push_back(digits[i]);
    return ret;
}

int main()
{
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    vector<int> new_digits = plusOne(digits);
    for (int i = 0; i < new_digits.size(); i++) cout << new_digits[i] << endl;
    return 0;
}
