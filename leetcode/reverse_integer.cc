#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
    bool minus = false;
    if (x<0) {
        minus = true; 
        x = -x;
    }

    int r = 0;
    while (x!=0) {
        int num = x % 10;
        r = r * 10 + num;
        x = (x - num) / 10;
    }

    if (r<0) {
        return minus?INT_MIN:INT_MAX;
    }
    return minus?-r:r;
}

int main()
{
    int x = 0;
    while (cin >> x)
        cout <<  reverse(x) << endl;
    return 0;
}

