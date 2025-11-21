class Solution {
public:
    int countNumberOfSubarrays(vector<int> &nums,int k)
    {
        int count = 0;
        int i = 0;
        int n = nums.size();
        for(int j=0;j<n;j++)
        {
            if(nums[j]%2==1) k--;
            while(i<=j && k<0)
            {
                if(nums[i]%2==1) k++;
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countNumberOfSubarrays(nums,k) - countNumberOfSubarrays(nums,k-1);
    }
};
