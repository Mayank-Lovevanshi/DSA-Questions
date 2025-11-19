class Solution {
public:
    int subarrayCount(vector<int> &nums,int goal)
    {
        int sum = 0;
        int n = nums.size();
        int i = 0;
        int count = 0;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            while(i<=j && sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrayCount(nums,goal)-subarrayCount(nums,goal-1);
    }
};
