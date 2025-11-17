class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        vector<int> ngr(nums2.size());
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty()) ngr[i] = -1;
            else ngr[i] = st.top();
            st.push(nums2[i]);
        }
        map<int,int> hashMap;
        for(int i=0;i<n;i++)
        {
            hashMap[nums2[i]] = ngr[i];
        }
        vector<int> finalAns(m);
        for(int i=0;i<m;i++)
        {
            finalAns[i] = hashMap[nums1[i]];
        }
        return finalAns;
    }
};
