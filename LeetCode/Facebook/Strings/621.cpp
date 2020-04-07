/*
1. First count the number of occurrences of each element.
2. Let the max frequency seen be M for element E
3. We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
4. Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
5. Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
6. Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
7. If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> lookup;
        int count{};
        
        for(auto ch : tasks){
            lookup[ch]++;
            count = max(count, lookup[ch]);
        }
        
        int res = (n+1)*(count-1);
        
        for(auto e : lookup) 
            if(e.second == count) 
                res++;

        return max((int)tasks.size(), res);
        // Above line is for n= 0 , ["A","A","A","B","B","B"]  - 0
    }
};

// Another Solution
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {0};
        for (char task : tasks) {
            counter[task - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (counter[i]) {
                pq.push(counter[i]);
            }
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> remaining;
            int all = n + 1;
            while (all && !pq.empty()) {
                int counts = pq.top();
                pq.pop();
                if (--counts) {
                    remaining.push_back(counts);
                }
                time++;
                all--;
            }
            for (int counts : remaining) {
                pq.push(counts);
            }
            if (pq.empty()) {
                break;
            }
            time += all;
        }
        return time;
    }
};
