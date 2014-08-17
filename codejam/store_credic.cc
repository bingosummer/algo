#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

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
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int C;
    cin >> C;
    int I;
    cin >> I;
    vector<int> numbers;
    while (I--) {
      int P;
      cin >> P;
      numbers.push_back(P);
    }
    vector<int> output = twoSum(numbers, C);
    cout << "Case #" << i << ": " << output[0] << " " << output[1] << endl;
  }
  return 0;
}
