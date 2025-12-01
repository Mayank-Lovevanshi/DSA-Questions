class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<nums.size();i++)
        {
            minHeap.push(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            while(!minHeap.empty() && minHeap.top()<=nums[i]) minHeap.pop();
            if(minHeap.size()>=k) ans++;
        }
        return ans;
    }
};
