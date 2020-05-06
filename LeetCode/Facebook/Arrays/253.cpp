// O(2nlog2n)+O(2nlog2n)=O(4nlogn+4nlog2)=O(nlogn)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       map<int, int> lookup; // key: time; val: +1 if start, -1 if end

    for(int i=0; i< intervals.size(); i++) {
        lookup[intervals[i][0]] ++;
        //cout << intervals[i][0] << "  " << lookup[intervals[i][0]] <<endl;
        lookup[intervals[i][1]] --;
        //cout << intervals[i][1] << "  " << lookup[intervals[i][1]] <<endl;
    }
    
    int cnt{}, maxCnt{};
    //for(auto it = mp.begin(); it != mp.end(); it++) {
      for(auto it : lookup) {
        //cout << it.first << "  " << it.second << endl;
        cnt += it.second;
        //cout << cnt << endl;
        maxCnt = max( cnt, maxCnt);
    }
    
    return maxCnt; 
    }
};
// // TC - O(nlogn)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        
        auto cmp = [](auto& first, auto& second){
            return first[0] < second[0];
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};


