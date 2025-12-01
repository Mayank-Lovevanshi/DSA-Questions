class Solution {
public:
    int maxDistinct(string s) {
        vector<int> appers(26,0);
        for(int i=0;i<s.size();i++){
            appers[s[i]-'a']++;
        }
        int count = 0;
        for(int i=0;i<26;i++){
            if(appers[i]!=0) count++;
        }
        return count;
    }
};
