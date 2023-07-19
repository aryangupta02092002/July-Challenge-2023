class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2)
    {
        if(v1[1]==v2[1])
            return v1[0]<v2[0];
        return v1[1]<v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0][1];
        int count=0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < end){
                count++;
            }
            else{
                end = max(intervals[i][1], end);
            }
        }
        return count;
    }
};
