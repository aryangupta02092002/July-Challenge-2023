class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour < dist.size() - 1) 
            return -1;
        int left = 0;
        int right = 10000000;
        int m;
        int ans = -1;
        
        while (left <= right) {
            m = (left + right) / 2;            
            if (check(dist, hour, m)) {
                ans = m;
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        return ans;
    }

    bool check(vector<int>& dist, double hour, int speed) {
        double time = 0;
        int i = 0;
        while (time <= hour && i < dist.size() - 1) {
            time += ceil(static_cast<double>(dist[i]) / speed);
            i++;
        }
        time += static_cast<double>(dist[dist.size() - 1]) / speed;
        return (time <= hour);
    }
};
