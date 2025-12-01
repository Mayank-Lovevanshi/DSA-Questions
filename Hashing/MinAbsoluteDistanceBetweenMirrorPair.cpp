class Solution {
public:
    int reverseDigit(int num)
    {
        int reverseNum = 0;
        while(num){
            int rem = num%10;
            reverseNum*=10;
            reverseNum+=rem;
            num/=10;
        }
        return reverseNum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        int minAbsolute = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(hashMap.find(nums[i])!=hashMap.end())
            {
                minAbsolute = min(minAbsolute,i-hashMap[nums[i]]);
            }
            hashMap[reverseDigit(nums[i])] = i;
        }
        if(minAbsolute==INT_MAX) return -1;
        return minAbsolute;
    }
};
