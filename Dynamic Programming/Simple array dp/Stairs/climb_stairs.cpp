//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int dp[1000005];

int func(int pos, int dest) {
    if(pos > dest) return 0;
    if(pos == dest) return 1;
    if(dp[pos] != -1) return dp[pos];

    int ret = 0;
    if(pos+1 <= dest) ret += func(pos+1, dest);
    if(pos+2 <= dest) ret += func(pos+2, dest);
    return dp[pos] = ret;
}

int Solution::climbStairs(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    memset(dp, -1, sizeof(dp));
    return func(0, A);
}
