class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int Smax = INT_MIN;
        int max = INT_MIN;
        int min = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max)
            {
                Smax = max;
                max = nums[i];
            }
            else if(nums[i]>Smax)
            {
                Smax = nums[i];
            }
            if(nums[i]<min)
            {
                min = nums[i];
            }
        }
        return max+Smax-min;
    }
};
