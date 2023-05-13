// https://leetcode.com/problems/count-ways-to-build-good-strings/

// https://leetcode.com/problems/count-ways-to-build-good-strings/discuss/3520434/C%2B%2B-DP-Tabulation-Explained!

#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1);
    dp[0] = 1; // 1 string of length 0
    int res = 0;
    for(int i = 1; i <= high; ++i) {
        if(i >= zero)
            dp[i] = (dp[i] + dp[i - zero]) % mod;
        
        if(i >= one)
            dp[i] = (dp[i] + dp[i - one]) % mod;
        
        if(i >= low) // it's in range
            res = (res + dp[i]) % mod;
    }
    
    return res;
}

int main() {
    int low, high, zero, one;
    cin >> low >> high >> zero >> one;


    cout << countGoodStrings(low, high, zero, one) << "\n";

    return 0;
}
