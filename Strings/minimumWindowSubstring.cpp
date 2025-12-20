class Solution {
    public :
    bool func(vector<int> &hashMap)
    {
        for(int i=0;i<256;i++)
        {
            if(hashMap[i]>0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> hashMap(256);
        for(char ele : t)
        {
            hashMap[ele]++;
        }
        int low = 0;
        int mini = INT_MAX;
        int lowIdx = -1;
        int highIdx = -1;
        for(int high=0;high<s.size();high++)
        {
            hashMap[s[high]]--;
            while(func(hashMap))
            {
                if(high-low+1<mini)
                {
                    mini = high - low + 1;
                    lowIdx = low;
                    highIdx = high;
                }
                hashMap[s[low]]++;
                low++;
            }
        }
        if(lowIdx==-1 || highIdx==-1) return "";
        return s.substr(lowIdx,mini);
    }
};
