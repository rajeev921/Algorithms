/*
mersenne_twister_engine is a random number engine based on Mersenne Twister algorithm. It produces high quality unsigned integer random numbers of type UIntType on the interval [0, 2w
-1]. 

*/

/* 		 https://diego.assencio.com/?index=6890b8c50169ef45b74db135063c227c
If we cannot use std::random_device repeatedly, then what should we do to generate multiple random numbers? The answer is simple: use std::random_device to generate a single random number which is then used as a seed for a pseudorandom number generator (PRNG) and then use the PRNG itself to generate as many pseudorandom numbers as we wish. For those who do not know what a PRNG is, think of it as an algorithm that takes an initial seed (a random number) and applies it on an internal mechanism to produce numbers which while not truly random, are still "sufficiently close to random".

The procedure we just described is exactly what we did on our original piece of code: we used std::random_device to generate a seed for a very commonly used PRNG called Mersenne Twister which is implemented by the std::mt19937 class (MT19937 stands for "Mersenne Twister" based on the Mersenne prime 219937−1
). This PRNG produces sequences of 32-bit integers with a very long period of 219937−1, i.e., the sequence will repeat itself only after 219937−1 numbers have been generated — an imaginably large number! This line initializes the PRNG with a seed produced by device, which is an object of type std::random_device:


*/

class Solution {
public:
    Solution(vector<int>& w) {
        rng = mt19937(dev());
        dist = std::discrete_distribution<int>(w.begin(), w.end());
    }
    
    int pickIndex() {
        return dist(rng);
    }
private:
    mt19937 rng;
    std::discrete_distribution<int> dist;
    std::random_device dev;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

//better Solution
class Solution {
public:
    Solution(vector<int>& w) {
        for(int i{1}; i < w.size(); ++i){
            w[i] += w[i-1];
        }
        
        w_ = std::move(w);
    }
    
    int pickIndex() {
        return upper_bound(begin(w_), end(w_), rand() % w_.back()) - begin(w_);
    }
private:
    std::vector<int> w_;
};


//Optimize Solution
