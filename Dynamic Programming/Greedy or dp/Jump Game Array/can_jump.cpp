//
// Created by Islam, Abdullah Al Raqibul on 6/2/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

vector<int> dp;

int solve(vector<int> &v, int pos, int sz) {
    int ret = 0;
    if(pos == sz-1) return 1;
    if(pos >= sz) return 0;
    if(dp[pos] != -1) return dp[pos];

    for(int i=1; i<=v[pos]; i+=1) {
        if(i+pos >= sz) {
            break;
        }

        if(i+pos == sz-1) {
            ret = 1;
            break;
        }

        if(solve(v, pos+i, sz)) {
            ret = 1;
            break;
        }
    }

    return dp[pos] = ret;
}

int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size();

    if(sz == 0) return 0;
    if(sz == 1) return 1;

    dp.resize(sz + 5);
    for(int i=0; i<sz; i+=1) {
        dp[i] = -1;
        //dp.push_back(-1);
    }
    dp[sz-1] = 1;
    return solve(A, 0, sz);
}
