/* Zoilo Mercedes
 * Happy Number
 * https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/815
 */

#include<iostream> // cout, endl
#include<string>   // string
#include<vector>   // vector
#include<set>      // set

using namespace std;

class Solution {
  public:
    bool isHappy(int n) {
        string number = to_string(n);
        set<int> repeats = {};
        int sum;
        while(true){
            sum = 0;
            for(auto i : number)
                sum+= (i - '0') * (i - '0');

            if(sum == 1) return true;
            if(repeats.count(sum)) return false;
            else {
                repeats.emplace(sum);
                number = to_string(sum);
            }
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    vector<int> testCases = {1,2,19};

    for(int i =0;i<testCases.size(); i++){
        bool ret = Solution().isHappy(testCases[i]);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}