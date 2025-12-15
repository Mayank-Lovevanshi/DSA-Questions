class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        while(i<n)
        {
            int j = i + 1;
            int k = n - 1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0)
                {
                    List<Integer> temp= new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    ans.add(temp);
                    j++;
                    k--;
                    while(j<k && nums[j-1]==nums[j])
                    {
                        j++;
                    }
                    while(j<k && nums[k+1]==nums[k])
                    {
                        k--;
                    }
                }
                else if(sum<0) j++;
                else k--;
            }
            i++;
            while(i<n && nums[i-1]==nums[i])
            {
                i++;
            }
        }
        return ans;
    }
}
