class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int i = 0;
        int n = nums.length;
        int findClosest = Integer.MAX_VALUE;
        int mini = Integer.MAX_VALUE;
        while(i<n)
        {
            int j = i + 1;
            int k = n - 1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target) return sum;
                else if(sum<target)
                {
                    int closest = Math.abs(sum-target);
                    if(closest<findClosest)
                    {
                        mini = sum;
                        findClosest = closest;
                    }
                    j++;
                }
                else
                {
                    int closest = Math.abs(sum-target);
                    if(closest<findClosest)
                    {
                        mini = sum;
                        findClosest = closest;
                    }
                    k--;
                }
            }
            i++;
            while(i<n && nums[i-1]==nums[i]) i++;
        }
        return mini;
    }
}
