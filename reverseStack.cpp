class Solution {
public:
void push(stack<int> &st,int temp)
{
if(st.empty())
{
st.push(temp);
return;
}
int val = st.top();
st.top();
push(st,temp);
st.push(val);
}
void reverseStack(stack<int> &st)
{
if(st.empty()) return;
int temp = st.top();
st.pop();
reverseStack(st);
push(st,emp);   
}
};
