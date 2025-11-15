class Solution {
  public:
    int findMin(int n) {
        // code here
        int coins[] = {10,5,2,1};
        int i = 0;
        int count = 0;
        while(n>0 && i<=3)
        {
            if(n-coins[i]>=0)
            {
                n = n - coins[i];
                count++;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};
