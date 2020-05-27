//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int mod = 1000000007;
vector< vector< vector<int> > > dp;

int func(int len, int prev, int sum, int n, int s) {
    int ret = 0;
    if(len == n) {
        if(sum == s) return 1;
        return 0;
    }
    if(len > len) return 0;
    if(sum > s) return 0;
    if(dp[len][prev][sum] != -1) return dp[len][prev][sum];

    for(int i=0; i<10; i+=1) {
        if(len == 0 && i == 0) continue;
        if(sum+i > s) continue;
        ret += func(len+1, i, sum+i, n, s);
        ret %= mod;
    }
    return dp[len][prev][sum] = ret;
}

int Solution::solve(int A, int B) {
    dp.resize(A+1);
    for(int i=0; i<A+1; i+=1) {
        dp[i].resize(11);
        for(int j=0; j<11; j+=1) {
            dp[i][j].clear();
            dp[i][j].resize(B+1, -1);
        }
    }

    return func(0, 0, 0, A, B) % mod;
}
