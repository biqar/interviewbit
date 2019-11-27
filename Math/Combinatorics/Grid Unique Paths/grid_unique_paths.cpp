//
// Created by aislam6 on 11/27/19.
//

int Solution::uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, ii, jj;
    int dp[A][B];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(i=0; i<A; i+=1) {
        for(j=0; j<B; j+=1) {
            ii = i - 1;
            jj = j - 1;
            if(ii >=0 && ii < A) dp[i][j] += dp[ii][j];
            if(jj >=0 && jj < B) dp[i][j] += dp[i][jj];
        }
    }

    return dp[A-1][B-1];
}
