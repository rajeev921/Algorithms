class Solution {
public:
    /*
    struct myclass {
        bool operator() (auto interval_a, auto interval_b) { 
            return (interval_a[0]<interval_b[0]);
        }
    } myobject;
    */
public:    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals.size()==1) {
            return intervals;
        }
        auto cmp = [](auto const& interval_a, auto const& interval_b) { 
            return (interval_a[0]<interval_b[0]);
        };
        //sort(intervals.begin(), intervals.end(), myobject);
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        auto t = intervals[0];
        
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] >= t[0] && intervals[i][1] <= t[1]) {
                continue;
            }
            else if(t[1] >= intervals[i][0]) {
                t[1] = intervals[i][1];
            }
            else {
                res.push_back(t);
                t = intervals[i];
            }
        } 
        res.push_back(t);
        
        return res;
    }
};