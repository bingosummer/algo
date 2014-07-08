#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy = 0;
        int sell = 0;
        int ret = 0;

        while (sell + 1 < prices.size()) {

            for (;prices[buy]>=prices[buy+1];buy++) {}
            for (;prices[sell]<=prices[sell+1];sell++) {}

            cout << buy << " " << sell << endl;
            ret += (prices[sell] - prices[buy]);

            buy = sell + 1;
            sell = sell + 1;
        }
        return ret;
    }
};
int main()
{
    vector<int> prices;
    prices.push_back(1); 
    prices.push_back(2); 
    prices.push_back(2); 
    prices.push_back(3); 
    prices.push_back(2); 
    prices.push_back(4); 
    prices.push_back(1); 
    prices.push_back(3); 
    prices.push_back(5); 
    prices.push_back(6); 
    prices.push_back(2); 

    Solution s;
    cout << "MaxProfit: " << s.maxProfit(prices) << endl;   

    return 0;
}
