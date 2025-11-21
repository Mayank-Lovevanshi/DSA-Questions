class Solution {
public:
    int trap(vector<int>& height) {
        int prevMax = INT_MIN;
        int nextMax = INT_MIN;
        int n = height.size();
        vector<int> prevMaximum(n);
        vector<int> nextMaximum(n);
        for(int i=0;i<n;i++)
        {
            if(height[i]>=prevMax)
            {
                prevMax = height[i];
                prevMaximum[i] = -1;
            }
            else prevMaximum[i]= prevMax;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>=nextMax)
            {
                nextMax = height[i];
                nextMaximum[i] = -1;
            }
            else nextMaximum[i] = nextMax;
        }
        int maxTrappedWater = 0;
        for(int i=0;i<n;i++)
        {
            if(prevMaximum[i]==-1 || nextMaximum[i]==-1) continue;
            maxTrappedWater+= min(prevMaximum[i],nextMaximum[i])-height[i];
        }
        return maxTrappedWater;
    }
};
