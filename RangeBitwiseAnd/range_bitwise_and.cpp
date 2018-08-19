/* Zoilo Mercedes
 * Ranged Bitwise And
 * https://leetcode.com/problems/bitwise-and-of-numbers-range/
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int MSB(int n){
        int msb = -1;
        while(n){
            n = n >> 1;
            msb++;
        }
        return msb;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        if(n-m == 0)
            return m;
        
        int result = 0;
        int msb_p1,msb_p2,msb_val;

        while(m && n){
            msb_p1 = MSB(m);
            msb_p2 = MSB(n);

            if(msb_p1 != msb_p2)
                break;

            msb_val = (1 << msb_p1);

            result += msb_val;
            m -= msb_val;
            n -= msb_val;
        }

        return result;
    }
};

int main() {

    int result;
    vector<int> testCases = {17,19,43,46};

    for(int i = 0; i < testCases.size(); i+=2){
        result = Solution().rangeBitwiseAnd(testCases[i], testCases[i+1]);
        cout << to_string(result) << endl;
    }

    return 0;
}