/*
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, bit = 1;
        for(int i=0;i<32;i++){
            res = res<<1;
            if(n&bit) res+=1;
            bit = bit<<1;
        }
        return res;
    }
};

int main(void){
    Solution solution;
    uint32_t n;

    n = 43261596;
    cout << solution.reverseBits(n) << endl;

    n = 4294967293;
    cout << solution.reverseBits(n) << endl;

    return 0;
}