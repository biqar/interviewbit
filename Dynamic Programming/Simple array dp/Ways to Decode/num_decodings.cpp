//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

vector< vector<int> > dp;
string str;

int solve(int pos, int ll, int len) {
    if(pos > len) return 0;
    if(pos == len) return 1;
    if(dp[pos][ll] != -1) return dp[pos][ll];

    int ret = 0, num = 0;
    num += (str[pos] - '0');
    if(num == 0) ret = 0;
    else {
        ret += solve(pos+1, num, len);
        if(pos+1 < len) {
            num *= 10; num += (str[pos+1] - '0');
            if(num >=1 && num<=26) ret += solve(pos+2, num, len);
        }
    }
    return dp[pos][ll] = ret;
}

int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size() + 2;
    dp.clear();
    dp.resize(sz);
    for(int i=0; i<sz; i+=1) {
        dp[i].resize(30, -1);
    }
    str = A;

    return solve(0, 0, A.size());
}
