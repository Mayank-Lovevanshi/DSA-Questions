class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        int leftSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            rightSum+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(i-1>=0){
                leftSum+=nums[i-1];
            }
            rightSum-=nums[i];
            if(leftSum==rightSum){
                return i;
            }
        }
        return -1;
    }
};
