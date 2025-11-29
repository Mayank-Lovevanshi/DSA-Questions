class Solution {
  public:
    typedef struct JOB
    {
        int profit;
        int deadline;
    }job;
    static bool comparator(const job &j1,const job &j2)
    {
        return j1.profit>j2.profit;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = profit.size();
        vector<job> sq(n);
        for(int i=0;i<n;i++)
        {
            sq[i].deadline = deadline[i];
            sq[i].profit = profit[i];
        }
        sort(sq.begin(),sq.end(),comparator);
        int maxDeadline = -1;
        for(int i=0;i<n;i++)
        {
            maxDeadline = max(maxDeadline,deadline[i]);
        }
        vector<bool> schedular(maxDeadline+1);
        int maxProfit = 0;
        int totalJobsCompleted = 0;
        for(int i=0;i<n;i++)
        {
            if(!schedular[sq[i].deadline])
            {
                maxProfit+=sq[i].profit;
                totalJobsCompleted++;
                schedular[sq[i].deadline] = 1;
            }
            else
            {
                for(int j=sq[i].deadline-1;j>=1;j--)
                {
                    if(!schedular[j])
                    {
                        schedular[j] = 1;
                        maxProfit+=sq[i].profit;
                        totalJobsCompleted++;
                        break;
                    }
                }
            }
        }
        return {totalJobsCompleted,maxProfit};
    }
};
