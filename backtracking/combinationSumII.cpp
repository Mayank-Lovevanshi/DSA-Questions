class Solution {
public:
    void combinationSum(vector<int> &candidates,vector<int> &temp,vector<vector<int>> &ans,int pos,bool flag,int target,int prev)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0 || pos>=candidates.size())
        {
            return;
        }
        if(!flag && prev==candidates[pos]) combinationSum(candidates,temp,ans,pos+1,false,target,candidates[pos]);
        else
        {
            temp.push_back(candidates[pos]);
        combinationSum(candidates,temp,ans,pos+1,true,target-candidates[pos],candidates[pos]);
        temp.pop_back();
        combinationSum(candidates,temp,ans,pos+1,false,target,candidates[pos]);
        }
        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(candidates,temp,ans,0,true,target,-1);
        return ans;
    }
};
