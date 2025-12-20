class Solution {
public:
    int findMax(vector<int>&freq)
    {
        int maxi = 0;
        for(int i=0;i<26;i++)
        {
            maxi = max(maxi,freq[i]);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int low = 0;
        int n = s.size();
        vector<int> freq(26);
        int maxLength = 0;
        for(int high=0;high<n;high++)
        {
            freq[s[high]-'A']++;
            int len = high - low + 1;
            int maxi = findMax(freq);
            while(len-maxi>k)
            {
                freq[s[low]-'A']--;
                low++;
                maxi = findMax(freq);
                len = high - low + 1;
            }
            maxLength = max(maxLength,len);
        }
        return maxLength;
    }
};
