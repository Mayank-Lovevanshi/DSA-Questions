class Solution {
  public:
    typedef struct JOB
    {
        int profit;
        int deadline;
    }jobs;
    static bool comparator(jobs & j1,jobs &j2)
    {
        return j1.profit>j2.profit;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int maxi = INT_MIN;
        int n = profit.size();
        vector<jobs> schedule(n);
        for(int i=0;i<n;i++)
        {
            schedule[i].deadline = deadline[i];
            schedule[i].profit = profit[i];
            maxi = max(maxi,deadline[i]);
        }
        sort(schedule.begin(),schedule.end(),comparator);
        vector<bool> lastDate(maxi+1,0);
        int maxProfit = 0;
        int jobsCompleted = 0;
        for(int i=0;i<n;i++)
        {
            int deadline = schedule[i].deadline;
            while(deadline>0 && lastDate[deadline])
            {
                deadline--;
            }
            if(deadline>0)
            {
                lastDate[deadline] = 1;
                jobsCompleted++;
                maxProfit+=schedule[i].profit;
            }
        }
        return {jobsCompleted,maxProfit};
    }
};
