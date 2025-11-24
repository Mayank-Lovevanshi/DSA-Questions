class Solution {
public:
    void Combination(vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans,int pos,int target)
    {
        if(!target)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0 || pos>=nums.size()) return;
        temp.push_back(nums[pos]);
        Combination(nums,temp,ans,pos,target-nums[pos]);
        temp.pop_back();
        Combination(nums,temp,ans,pos+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        Combination(nums,temp,ans,0,target);
        return ans;
    }
};
