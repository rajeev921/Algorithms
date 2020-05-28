/* I
I guess that's indeed a little gap that I just jumped intuitively. 
Well, sqrt gives you the root of the largest square in the range [1,n]. 
And 1 is the smallest root. So you have the roots from 1 to sqrt, that's sqrt many roots. 
Which correspond to the sqrt many squares.

bulb ends up on iff it is switched an odd number of times.
Call them bulb 1 to bulb n. Bulb i is switched in round d if and only if d divides i. 
So bulb i ends up on if and only if it has an odd number of divisors.
Divisors come in pairs, like i=12 has divisors 1 and 12, 2 and 6, and 3 and 4. 
Except when i is a square, like 36 has divisors 1 and 36, 2 and 18, 3 and 12, 4 and 9, and double divisor 6. 
So bulb i ends up on if and only if i is a square.
So just count the square numbers.
Let R = int(sqrt(n)). That's the root of the largest square in the range [1,n]. And 1 is the smallest root. So you have the roots from 1 to R, that's R roots. Which correspond to the R squares. So int(sqrt(n)) is the answer. (C++ does the conversion to int automatically, because of the specified return type)

*/

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

/*II 
Operations: O(flip odds), E(flip evens), A(flip all), T(flip 3k + 1), N(flip nothing)
Relations:
O + O = N, E + E = N, A + A = N, T + T = N
O + E = A, O + A = E, E + A = O
Exclusive statuses :
n > 2:
① N
② O
③ E
④ A
⑤ T
⑥ O + T
⑦ E + T
⑧ A + T

n = 2 (remove all T related statuses):
① N
② O
③ E
④ A

n = 1(remove all T, E, A related statuses):
① N
② O

Steps needed to all status( always can plus 2 * k)
① can only be achieved by 0, 2 steps
②，③，④ can be achieved by either 1 or 2 steps
⑤ can only be achieved by 1 steps
⑥，⑦，⑧ can only be achieved by 2 steps,

Thus:
0 steps -> ①
1 steps -> ②，③，④，⑤
2 steps -> ①，②，③，④，⑥，⑦，⑧
more than 2 steps -> ①, ②, ③, ④, ⑤, ⑥, ⑦, ⑧
*/
class Solution {
public:
    int flipLights(int n, int m) {
        n = min(n, 3);
        return min(1<<n, 1+m*n);
    }
};

/*  III
There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.

Return the number of moments in which all turned on bulbs are blue.
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int right{}, res{}, n = light.size();
        
        for (int i{}; i < n; ++i)
            res += (right = max(right, light[i])) == i + 1;
        
        return res;
    }
};

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(), ans{}, currMax{};
        long currSum{};
        
        for(int i = 0; i < n; i++) {
            currMax = max(currMax, light[i]);
            currSum += (long)light[i];
            if(currSum == ((long)currMax * (currMax + 1)) / 2) ans++;
        }
        
        return ans;
    }
};