#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    int steps[n];
    steps[1] = 1;
    steps[2] = 2;
    for (int i = 3; i < n; i++) {
        steps[i] = steps[i-1] + steps[i-2];
    }
    for (int i = 3; i < n; i++) {
        cout << i << ": " << steps[i] << endl;
    }
    return 0;
}
