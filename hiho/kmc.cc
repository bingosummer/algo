#include <iostream>
#include <string>

using namespace std;

#define MAX_LEN 10000

int next[MAX_LEN];

void get_next(string T)
{
  int i, j;
  i = 0;
  j = -1;
  next[0] = -1;
  int T_len = T.length();
  while (i < T_len) {
    if (j == -1 || T[i] == T[j]) {
      ++i;
      ++j;
      next[i] = j;
    }
    else
      j = next[j];
  }
}

int index_kmp(string S, string T, int pos)
{
  int i = pos;
  int j = 0;
  int S_len = S.length();
  int T_len = T.length();
  while (i < S_len && j < T_len) {
    if (j == -1 || S[i] == T[j]) {
      ++i;
      ++j;
    } else {
      j = next[j];
    }
  }
  if (j >= T_len)
    return i - T_len;
  else
    return -1;
}

int main()
{
  int N;
  cin >> N;
  while (N--) {
    string S, T;
    cin >> T >> S;
    get_next(T);
    int Ans = 0;
    int pos = 0;
    while ((pos = index_kmp(S, T, pos)) > -1) {
      ++pos;
      ++Ans;
    }
    cout << Ans << endl;
  }
  return 0;
}
