class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int n = prices.size();
        int candiesPicked = 0;
        int minCost = 0;
        int maxCost = 0;
        int freeCandies = 0;
        for(int i=0;i<n;i++)
        {
            if(freeCandies>=n-candiesPicked) break;
            minCost+=prices[i];
            candiesPicked++;
            freeCandies+=k;
        }
        candiesPicked = 0;
        freeCandies = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(freeCandies>=n-candiesPicked) break;
            maxCost+=prices[i];
            candiesPicked++;
            freeCandies+=k;
        }
        return {minCost,maxCost};
    }
};
