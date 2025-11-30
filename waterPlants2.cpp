class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refill = 0;
        int currentWaterA = capacityA;
        int currentWaterB = capacityB;
        int i = 0;
        int j = plants.size() - 1;
        while(i<j)
        {
            if(currentWaterA<plants[i])
            {
                refill++;
                currentWaterA = capacityA;
            }
            currentWaterA-=plants[i];
            if(currentWaterB<plants[j])
            {
                refill++;
                currentWaterB = capacityB;
            }
            currentWaterB-=plants[j];
            i++;
            j--;
        }
        if(i==j)
        {
            if(max(currentWaterA,currentWaterB)<plants[i])
            {
                refill++;
            }
        }
        return refill;
    }
};
