#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int lengthOfLastWord(const char *s) {
    istringstream is(s);
    string word;
    while (is >> word) {}
    return word.length();
}

int main()
{
    const char *s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}
