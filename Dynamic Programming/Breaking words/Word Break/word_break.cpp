//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

vector<int> dp;

int _max(int a, int b) {
    return a > b ? a : b;
}

int func(string s, int ssz, vector<string> &v, int vsz, int pos) {
    if(pos == ssz) return 1;
    if(pos > ssz) return 0;
    if(dp[pos] != -1) return dp[pos];

    int i, ret = 0;

    for(i=0; i<vsz; i+=1) {
        int sz = v[i].size();
        if(v[i].compare(s.substr(pos, sz)) == 0) {
            ret = _max(ret, func(s, ssz, v, vsz, pos+sz));
            if(ret == 1) {
                return dp[pos] = ret;
            }
        }
    }

    return dp[pos] = ret;
}

int Solution::wordBreak(string A, vector<string> &B) {
    dp.clear();
    dp.resize(A.size()+5, -1);
    return func(A, A.size(), B, B.size(), 0);
}
