class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        int n = arr.size();
        int elementToPush;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()>=arr[i])
            {
                st.pop();
            }
            if(st.empty()) elementToPush = -1;
            else elementToPush = st.top();
            st.push(arr[i]);
            arr[i] = elementToPush;
        }
        return arr;
    }
};
