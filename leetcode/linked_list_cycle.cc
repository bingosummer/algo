//          5<-4 
//          |  ^
//          |  |
//    0->1->2->3
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        return true;
    }
};

int main()
{
    struct ListNode *head(0);
    for (int i = 5; i >= 1; i--) {
        struct ListNode *p(0);
    
    }
    Solution s;
    cout << s.hasCycle(head) << endl;;
    return 0;
}


