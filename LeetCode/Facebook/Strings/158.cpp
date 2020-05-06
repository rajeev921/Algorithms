// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i{};
        while(i < n && (bufferPtr_ < bufferCntr_ || (bufferPtr_= 0) < (bufferCntr_ = read4(buf_)) ) )
            buf[i++] = buf_[bufferPtr_++];

        return i;    
    }
private:
    int bufferCntr_{}, bufferPtr_{};
    char buf_[4];
};