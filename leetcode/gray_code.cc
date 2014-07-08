TODO:
#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    int i = 0;
    int gray = 0;
    for (int j = 0; j < n; j++) {
        cout << gray << endl;
        gray ^= (1 << i);
        i = (i + 1) % j;
    }
    return 0;
}
