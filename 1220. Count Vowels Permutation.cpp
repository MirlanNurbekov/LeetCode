#include <vector>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        const int MODULO = 1000000007;
        
        vector<vector<long long>> dp(n, vector<long long>(5, 0));
        
        // Initialization
        for (int i = 0; i < 5; ++i) {
            dp[0][i] = 1;
        }
        
        // Transition
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % MODULO;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MODULO;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MODULO;
            dp[i][3] = dp[i-1][2];
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MODULO;
        }
        
        long long result = 0;
        for (int i = 0; i < 5; ++i) {
            result = (result + dp[n-1][i]) % MODULO;
        }
        
        return result;
    }
};
