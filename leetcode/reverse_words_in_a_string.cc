#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    void swap(string &s) {
        for (int i = 0; i<s.length()/2; i++) {
             char tmp = s[i];
             s[i] = s[s.length()-1-i];
             s[s.length()-1-i] = tmp;
        }
    }
    void reverseWords(string &s) {
        swap(s);
        istringstream is(s);
        ostringstream os;
        string tmp;
        while (is>>tmp) {
            cout << tmp << endl;
            swap(tmp);
            os << tmp << " ";
        }
        s = os.str();
        s.erase(s.length()-1);
    }
};

int main()
{
    string s = " the  sky is   blue ";    
    cout << s << endl;
    Solution S;
    S.reverseWords(s);
    cout << s << "|||"<< endl;
    return 0;
}
