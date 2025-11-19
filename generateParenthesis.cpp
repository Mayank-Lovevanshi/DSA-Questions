class Solution {
public:
    void generate(vector<string> &ans,string &temp,int left,int right,int n)
    {
        if(left==n && right==n)
        {
            ans.push_back(temp);
            return;
        }
        if(left<right || left>n) return;
        temp+='(';
        generate(ans,temp,left+1,right,n);
        temp.pop_back();
        temp+=')';
        generate(ans,temp,left,right+1,n);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generate(ans,temp,0,0,n);
        return ans;
    }
};
