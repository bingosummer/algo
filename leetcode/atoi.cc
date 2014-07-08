#include <iostream>
#include <climits>
using namespace std;

int myatoi(const char *str) {
    bool minus = false;
    int ret = 0;
 
    while (*str==' ') str++;

    switch (*str) {
        case '+':
            str++;
            break;
        case '-':
            minus = true;
            str++;
            break;
        default:
            break;
    }
 
    while(*str!='\0') {
        if ((*str>='0') && (*str<='9')) {
            ret = ret*10+(*str-'0');
            str++;
        } else {
            break;
        }
    }

    if (ret < 0) {
        if (minus) return INT_MIN;
        else return INT_MAX;
    }
 
    return (minus?-ret:ret);

}

int main() {
    char *str = "-2147483649";
    
    cout << myatoi(str) << endl;
    return 0;
}
