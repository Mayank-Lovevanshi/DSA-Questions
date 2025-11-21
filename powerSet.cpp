class Solution {
public:
    void powerSet(vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans,int pos)
    {
        if(pos==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        powerSet(nums,temp,ans,pos+1);
        temp.push_back(nums[pos]);
        powerSet(nums,temp,ans,pos+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        powerSet(nums,temp,ans,0);
        return ans;
    }
};
