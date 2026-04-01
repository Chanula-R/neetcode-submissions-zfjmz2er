#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int l = 0;
        int r = 1;
        while (l<prices.size() && r<prices.size())
        {
            int profit = prices[r] - prices[l];
            if (profit >= 0)
            {
                if (profit > max_profit)
                {
                    max_profit = profit;
                }    
            }
            else
            {
                l = r;
            }
            r++;
        }
        return max_profit;

        
    }
};
