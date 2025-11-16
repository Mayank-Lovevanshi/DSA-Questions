class Solution {
  public:
    void Sort(stack<int> &st,int value)
    {
        if(st.empty() || st.top()<=value){
            st.push(value);
            return;
        }
        int temp = st.top();
        st.pop();
        Sort(st,value);
        st.push(temp);
    }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int value = st.top();
        st.pop();
        sortStack(st);
        Sort(st,value);
    }
};

