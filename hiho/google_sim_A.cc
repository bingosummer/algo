#include <iostream>
#include <string>

using namespace std;

#define MAX_LEN 100

int erase_game(string s)
{
  int initial_len = s.length();
  int old_len = 0;
  int new_len = 0;
  do {
    old_len = s.length();
    int begin[MAX_LEN] = {0};
    int end[MAX_LEN] = {0};
    int index = -1;
    int is_same = 0;
    for (int i = 0; i < old_len; i++) {
      if (!is_same && s[i+1] == s[i]) { is_same = 1; begin[++index] = i;}
      if (is_same && s[i+1] != s[i]) {
        is_same = 0; end[index] = i;
      }
    }
    //char t[MAX_LEN + 1] = {'\0'};
    for (int i = index; i >= 0; i--) {
      //cout << begin[i] << " " << end[i] << endl;
      s.erase(s.begin() + begin[i], s.begin() + end[i] + 1);
    }
    //    cout << s << endl;
    new_len = s.length();
  } while (old_len != new_len); 
  //cout << s << endl;
  return initial_len - s.length();
}

int main()
{
  char *a[3] = {"A", "B", "C"};
  int N;
  cin >> N;
  while (N--) {
    string S, T;
    cin >> S;
    int len = S.length();
    int max = 0;
    for (int i = 0; i <= len; ++i) {
      for (int j = 0; j < 3; ++j) {        
        T = S;
        T.insert(i, a[j]);
        if (max < erase_game(T))
          max = erase_game(T);
      }
    }
    cout << max << endl;
  }
  return 0;
}
