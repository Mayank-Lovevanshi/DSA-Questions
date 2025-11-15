class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int minTime = INT_MIN;
        for(int i=0;i<mices.size();i++)
        {
            minTime = max(minTime,abs(holes[i]-mices[i]));
        }
        return minTime;
    }
};
