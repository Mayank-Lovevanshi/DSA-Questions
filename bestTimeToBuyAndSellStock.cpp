class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(min>prices[i]){
                min = prices[i];
            }
            else
            {
                profit = max(profit,prices[i]-min);
            }
        }
        return profit;
    }
};
