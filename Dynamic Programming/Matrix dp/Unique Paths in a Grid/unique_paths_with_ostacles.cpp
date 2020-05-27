//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int dp[105][105], r, c;

int solve(vector<vector<int> > &A, int cr, int cc) {
    if(cr >= r || cc >= c) return 0;
    if(A[cr][cc] == 1) return 0;
    if(cr == r-1 && cc == c-1) return 1;
    if(dp[cr][cc] != -1) return dp[cr][cc];

    return dp[cr][cc] = solve(A, cr+1, cc) + solve(A, cr, cc+1);
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    r = c = 0;
    r = A.size();
    if (r) c = A[0].size();

    if(!r && !c) return 0;

    memset(dp, -1, sizeof(dp));

    return solve(A, 0, 0);
}
