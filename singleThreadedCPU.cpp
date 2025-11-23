typedef struct DS
{
    int duration;
    int enqueueTime;
    int index;
}dataStructure;

bool comparator(dataStructure& t1,dataStructure& t2)
{
    if (t1.enqueueTime==t2.enqueueTime)
    {
        return t1.duration<t2.duration;
    }
    return t1.enqueueTime<t2.enqueueTime;
}


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<dataStructure> ds(n);
        for(int i=0;i<n;i++)
        {
            ds[i].enqueueTime = tasks[i][0];
            ds[i].duration = tasks[i][1];
            ds[i].index = i;
        }
        sort(ds.begin(),ds.end(),comparator);
        vector<int> ans;
        int pos = 0;
        long long time = ds[0].enqueueTime;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        while(!minHeap.empty() || pos<n){
            while(pos<n && ds[pos].enqueueTime<=time)
            {
                minHeap.push({ds[pos].duration,ds[pos].index});
                pos++;
            }
            if(minHeap.empty())
            {
                time = ds[pos].enqueueTime;
            }
            else
            {
                time+=minHeap.top().first;
                ans.push_back(minHeap.top().second);
                minHeap.pop();
            } 
        }
        return ans;
    }
};
