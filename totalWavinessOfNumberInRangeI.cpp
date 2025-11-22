class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int waviness = 0;
        for (int i = num1; i <= num2; i++) {
            vector<int> number1;
            int num = i;
            while (num != 0) {
                number1.push_back(num% 10);
                num /= 10;
            }
            if (number1.size() > 2) {
                for (int j = 1; j <= number1.size() - 2; j++) {
                    if ((number1[j] > number1[j- 1] &&number1[j] > number1[j + 1]) || 
                       (number1[j] < number1[j- 1] &&number1[j] < number1[j + 1])
                       ){
                        waviness++;
                    }
                }
            }
        }
    return waviness;

    }
        
};©leetcode
