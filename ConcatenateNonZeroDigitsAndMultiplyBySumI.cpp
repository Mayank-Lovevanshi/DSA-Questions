class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> preComputation;
        int x;
        while(n!=0){
            x = n % 10;
            if(x!=0) preComputation.push_back(x);
            n = n / 10;
        }
        reverse(preComputation.begin(),preComputation.end());
        int sum = 0;
        long long  num = 0;
        int size = preComputation.size();
        for(int i=0;i<size;i++){
            sum+=preComputation[i];
            num*=10;
            num+=preComputation[i];
        }
        return num*sum;
    }
};
