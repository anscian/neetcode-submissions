class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        short cnt = 32;

        while (n)
            res = (res << 1) + (n & 1), n >>= 1, cnt--;

        return res << cnt;
    }
};
