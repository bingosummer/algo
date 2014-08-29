#include <iostream>
#include <string>

using namespace std;

int helper(string query, string text)
{
  int max = 0;

  int text_len = text.length();
  int query_len = query.length();
  if (text_len == 0 || query_len == 0) return 0;

  for (int i = 0; i < text_len; ++i) {
    int j = max + 1;
    while (i + j <= text_len) {
      string tmp = text.substr(i, j);
      size_t found = query.find(tmp);
      if (found != string::npos) {
        max = j;
      }
      j++;
    }
  }
  return max;
}

int main()
{
  string query = "acbac";
  string text = "acbaccbabb";

  cout << helper(query, text) << endl;

  return 0;
}
