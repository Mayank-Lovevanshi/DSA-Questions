// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        int minRotation = 0;
        while(R!=0 && D!=0)
        {
            int lastDigitSeq = R%10;
            int lastDigitDest = D%10;
            int result = abs(lastDigitSeq-lastDigitDest);
            if(result>5) result = 10 - result;
            minRotation+=result;
            R/=10;
            D/=10;
        }
        return minRotation;
    }
};
