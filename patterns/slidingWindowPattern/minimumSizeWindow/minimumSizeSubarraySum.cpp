class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minLength = INT_MAX;
        int low = 0;
        for(int high=0;high<nums.size();high++)
        {
            sum+=nums[high];
            while(sum>=target)
            {
                int len = high - low + 1;
                minLength = min(minLength,len);
                sum-=nums[low];
                low++;
            }
        }
        if(minLength==INT_MAX) return 0;
        return minLength;
    }
};
