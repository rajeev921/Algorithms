// Permuatation in String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) 
            return false;
        vector<int> lookup(128, 0);
        for (char c : s1) {
            lookup[c]++;
        }

        int start{}, end{}, counter = s1.length();
        while (end < s2.length()) {
            char c1 = s2.at(end);
            if (lookup[c1] > 0) {
                counter--;
            }
            lookup[c1]--;
            end++;
            while (counter == 0) {
                if (end - start == s1.length()) {
                    return true;
                }
                char c2 = s2.at(start);
                lookup[c2]++;
                if (lookup[c2] > 0) {
                    counter++;
                }
                start++;
            }
        }
        return false;
    }
};
