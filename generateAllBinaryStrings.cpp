class Solution {
  public:
    void bs(int count,string &s,vector<string> &ans,int n)
    {
        if(count>n) return;
        if(count==n)
        {
            ans.push_back(s);
            return;
        }
        s+="0";
        bs(count+1,s,ans,n);
        s.pop_back();
        s+="1";
        bs(count+1,s,ans,n);
        s.pop_back();
    }
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        string s;
        bs(0,s,ans,n);
        return ans;
    }
};
