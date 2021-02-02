class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()==0 && t.length()==0){
            return true;
        }
        else if(s.length()==0 || t.length()==0){
            return false;
        }
        else if(s.length() != t.length()){
            return false;
        }
        
        unordered_map<char, int> lookup;
        
        for(auto ch : s){
            if(lookup.find(ch) != lookup.end()) {
                lookup.at(ch)++;
            }
            else {
                lookup[ch] = 1;
            }
        }
        
        for(auto ch : t){
            if(lookup.find(ch) == lookup.end() || lookup.at(ch) <=0) {
                return false;
            }
            else {
                lookup.at(ch)--;
            }
        }
        
        for(auto itr = lookup.begin(); itr != lookup.end(); ++itr) {
            cout << itr->first << " "<< itr->second << endl;
        }
        
        return true;
    }
};

// another faster approach
class Solution {
public:
    bool isAnagram(string s, string t) {
	size_t len = s.size();

	if (len != t.size())
		return false;

	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

	char s1 = 0;
	char s2 = 0;
	char f1 = 1;
	char f2 = 1;

	for (size_t i = 0; i < len; ++i) {
		s1 += s[i] - 'a';
		s2 += t[i] - 'a';
		f1 *= primes[s[i] - 'a'];
		f2 *= primes[t[i] - 'a'];
	}
    return f1 == f2 && s1 == s2;
    }
};