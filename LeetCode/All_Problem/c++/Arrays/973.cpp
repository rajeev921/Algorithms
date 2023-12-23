class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        auto cmp = [](auto const p1, auto const p2){
            return (p1[0]*p1[0] + p1[1]*p1[1]) < ((p2[0]*p2[0] + p2[1]*p2[1]));
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for(auto vec: points){
            pq.push(vec);
            if(pq.size() > K)
                pq.pop();
        }
        
        vector<vector<int>> res;
        
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};


// TC - O)n
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, int> m;
      for (int i = 0; i < points.size(); ++i)
        m.insert({ points
        	[i][0] * points[i][0] + points[i][1] * points[i][1], i });
      
      vector<vector<int>> res;

      for (auto it = m.begin(); K > 0; ++it, --K)
          res.push_back(points[it->second]);
      
      return res;
    }
};