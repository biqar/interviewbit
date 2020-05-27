//
// Created by Islam, Abdullah Al Raqibul on 5/21/20.
//

int _min(int a, int b) {
    return a < b ? a : b;
}

int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l1 = A.size(), l2 = B.size();
    int i, j;
    int dp[l1+1][l2+1];

    memset(dp, 0, sizeof(dp));
    for(i=0; i<=l1; i+=1) {
        dp[i][0] = i;
    }
    for(i=0; i<=l2; i+=1) {
        dp[0][i] = i;
    }

    for(i=1; i<=l1; i+=1) {
        for(j=1; j<=l2; j+=1) {
            dp[i][j] = _min(dp[i-1][j], dp[i][j-1]) + 1;

            if(A[i-1] == B[j-1]) dp[i][j] = _min(dp[i-1][j-1], dp[i][j]);
            else dp[i][j] = _min(dp[i-1][j-1]+1, dp[i][j]);
        }
    }
    return dp[l1][l2];
}
