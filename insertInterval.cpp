class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        int n = intervals.size();
        int pos = -1;
        for(int i=0;i<n;i++)
        {
            if(end<intervals[i][0])
            {
                ans.push_back({start,end});
                pos = i;
                break;
            }
            else if(start>intervals[i][1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
            }
        }
        if(pos==-1)
        {
            ans.push_back({start,end});
            return ans;
        }
        for(int i=pos;i<n;i++)
        {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
