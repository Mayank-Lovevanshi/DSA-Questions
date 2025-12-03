bool comparator(const vector<int> &a, const vector<int> &b) {
    if(a[0]==b[0])
    {
        return a[1] < b[1];
    }
    return a[0]<b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        
        int n = interval.size();
        sort(interval.begin(),interval.end(),comparator);
        int start = interval[0][0];
        int end = interval[0][1];
        int count = 0;
        for(int i=1;i<n;i++){
            if(interval[i][0]<end){
                if(interval[i][1]<end)
                {
                    start = interval[i][0];
                    end = interval[i][1];
                }
                count++;
            }
            else
            {
                start = interval[i][0];
                end = interval[i][1];
            }
        }
        return count;
    }
};
