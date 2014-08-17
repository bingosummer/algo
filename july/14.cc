#include <iostream>

using namespace std;

void find2Number(int a[], int n, int dest)
{
  int *f = a, *e = a + n - 1;
  int sum = *f + *e;
  while (sum != dest && f < e) {
    if (sum < dest) ++f;
    else --e;
    sum = *f + *e;
  }
  if (sum == dest) cout << *f << " " << *e << endl;
}

int main()
{
  int a[6] = {1, 2, 4, 7, 11, 15};
  int dest = 15;
  int n = 6;
  find2Number(a, n, dest);
  return 0;
}
