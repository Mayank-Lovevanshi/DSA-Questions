
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        vector<int> ans;
        for(int i=0;i<indices.size();i++)
        {
            int index = indices[i];
            int count = 0;
            int element = arr[index];
            for(int j=index+1;j<arr.size();j++)
            {
                if(arr[j]>element)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
