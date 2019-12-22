class Solution {
public:
    //Return the smallest charachter frequency
    int getCount(string str)
    {
        short bit[52]{0};
        
        for(char& ch : str) {
            short idx;
            /*
            if(ch >= 'A' && 'Z')
            {
                idx = 26 + ch - 'A';
            }
            else*/
            if(ch >= 'a' && 'z')
            {
                idx = ch - 'a';
            }
            bit[idx] +=1;
        }
        int max = 0;
        for(short i =0; i<52;++i)
        {
            if(bit[i] != 0)
            {
                max = bit[i];
                break;
            }
        }
        return max;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        if(queries.size() < 1 || words.size()< 1)
        {
            return vector<int>{0};
        }
        vector<int> res;
        
        vector<int> quer;
        vector<int> word;
        
        for(int i=0; i < queries.size(); ++i)
        {
            quer.push_back(getCount(queries[i]));
        }    
        for(int j = 0; j < words.size(); ++j)
        {
            word.push_back(getCount(words[j]));
        }
        
        for(int i=0; i < quer.size(); ++i)
        {
            int count = 0;
            for(int j = 0; j < word.size(); ++j)
            {
                //std::cout <<quer[i] <<"  "<< word[j]<<endl;
                if(quer[i] < word[j])
                {
                    ++count;
                }
            }
            res.push_back(count);
        }
        
        return res;
    }
};


// Optimize version by map
class Solution {
private:
    map<int, int> myMap;
    // returns the frequency of the smallest character
    inline int getFrequencySmallestCharacter(string &s) {
        char cMin = 'z'+1;
        int count = 0;
        for (char c : s) {
            if (c < cMin) {
                count = 1;
                cMin = c;
            }
            else if (c == cMin)
                count++;
        }
        return count;
    }

    inline int getFrequenciesGreaterthan(string &s) {
        int count = 0;
        int qcount = getFrequencySmallestCharacter(s);

        // Add count for all > qCount
        for (auto iter = myMap.upper_bound(qcount); iter != myMap.end(); iter++)
            count += iter->second;

        return count;
    }
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> ret;
        int queriesLength = queries.size();
        int wordsLength = words.size();

        // Loop over words and create a map
        // Key = frequency of min char
        // Value = number of times it occurred over all strings in the vector
        for (int i = 0; i < wordsLength; i++) {
            myMap[getFrequencySmallestCharacter(words[i])]++;
        }

        // Get the frequency of min char for the query and find the sum of 
        // 'values' for 'keys' in the above created map.
        for (int i = 0; i < queriesLength; i++) {
            ret.push_back(getFrequenciesGreaterthan(queries[i]));
        }

        return ret;
    }
};
