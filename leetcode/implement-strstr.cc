#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
  int *next;
  int next_len;

  void get_next(char *T)
  {
    next = new int[next_len];
    int i, j;
    i = 0;
    j = -1;
    next[0] = -1;
    while (i < next_len) {
      if (j == -1 || T[i] == T[j]) {
	++i;
	++j;
	next[i] = j;
      }
      else
	j = next[j];
    }
  }

  void dump_next()
  {
    for (int i = 0; i < next_len; i++) cout << next[i];
    cout << endl;
  }

  char *strStr(char *haystack, char *needle) {
    int S_len = strlen(haystack);
    int T_len = strlen(needle);
    next_len = T_len; 
    if (S_len == 0 || T_len == 0)
      return NULL;
    get_next(needle);
    dump_next();
    int i = 0;
    int j = 0;
    while (i < S_len && j < T_len) {
      if (j == -1 || haystack[i] == needle[j]) {
	++i;
	++j;
      } else {
	j = next[j];
      }
    }
    delete [] next;

    if (j >= T_len) {
      return haystack + i - T_len;
    }
    else
      return NULL;
        
  }
};


int main()
{
  char *S = "aaa";
  char *T = "aaa";
  Solution s = Solution();
  cout << s.strStr(S, T) << endl;
  return 0;
}
