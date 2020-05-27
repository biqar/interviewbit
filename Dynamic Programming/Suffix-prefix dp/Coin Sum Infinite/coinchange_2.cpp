//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

const int mod = 1000007;
vector<int> dp;

int Solution::coinchange2(vector<int> &A, int B) {
    int sz = A.size();
    dp.clear();
    dp.resize(B + 1, 0);

    dp[0] = 1;
    for(int i=0; i<sz; i+=1) {
        for(int j=A[i]; j<=B; j+=1) {
            dp[j] += dp[j-A[i]];
            dp[j] %= mod;
        }
    }

    return dp[B];
}
