class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    typedef struct time
    {
        int startTime;
        int endTime;
    }timing;
    static bool comparator(timing &s1,timing&s2)
    {
        return s1.endTime<s2.endTime;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<timing> schedule(n);
        for(int i=0;i<n;i++)
        {
            schedule[i].startTime = start[i];
            schedule[i].endTime = end[i];
        }
        sort(schedule.begin(),schedule.end(),comparator);
        int lastMeetEndTime = -1;
        int meetings = 0;
        for(int i=0;i<n;i++)
        {
            if(lastMeetEndTime==-1 || lastMeetEndTime<schedule[i].startTime)
            {
                lastMeetEndTime = schedule[i].endTime;
                meetings++;
            }
        }
        return meetings;
    }
};
