class Solution {
public:
    int minimumFlips(int n) {
        string binaryForm;
        while(n>0){
            if(n%2==0)
            {
                binaryForm+='0';
            }
            else binaryForm+='1';
            n/=2;
        }
        //reverse(binaryForm.begin(),binaryForm.end());
        int i = 0;
        int j = binaryForm.size() - 1;
        int minRequired = 0;
        while(i<j)
        {
            if(binaryForm[i]!=binaryForm[j]) minRequired+=2;
            i++;
            j--;
        }
        return minRequired;
    }
};©leetcode
