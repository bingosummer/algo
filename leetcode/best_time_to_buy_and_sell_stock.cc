#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        int n = prices.size();

        for (int buy = 0; buy < n; buy++) {
            for (int sell = buy + 1; sell < n; sell++) {
                int profit = prices[sell] - prices[buy];
                if (profit > ret) ret = profit;
            }
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
