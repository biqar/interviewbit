//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

int Solution::adjacent(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = A[0].size();
    int dp[sz][2];
    int t1, t2;

    memset(dp, 0, sizeof(dp));

    for(i=0; i<sz; i+=1) {
        t1 = t2 = 0;
        if(i-1 >= 0) t1 = _max(dp[i-1][0], dp[i-1][1]);
        if(i-2 >= 0) t2 = _max(dp[i-2][0], dp[i-2][1]);

        dp[i][0] = _max(A[0][i]+t2, t1);
        dp[i][1] = _max(A[1][i]+t2, t1);
    }
    return _max(dp[sz-1][0], dp[sz-1][1]);
}
