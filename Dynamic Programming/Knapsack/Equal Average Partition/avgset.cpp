//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int sz;
vector<vector<vector<int> > > dp;
vector<int> v, res;

int isPossible(int pos, int len, int sum) {
    if(len == 0) {
        if(sum == 0) return 1;
        return 0;
    }
    if(pos >= sz) {
        return 0;
    }
    //if(pos > sz) return false;
    if(dp[pos][sum][len] != -1) return dp[pos][sum][len];

    if(sum >= v[pos]) {
        res.push_back(v[pos]);
        if(isPossible(pos+1, len-1, sum-v[pos])) return dp[pos][sum][len] = 1;
        res.pop_back();
    }
    if(isPossible(pos+1, len, sum)) return dp[pos][sum][len] = 1;
    return dp[pos][sum][len] = 0;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    int i, j, k, tot_sum = 0;
    int p1, p2;
    vector<int> res2;

    sort(A.begin(), A.end());
    sz = A.size();
    v.clear();
    v = A;
    dp.clear();
    res.clear();

    for(i=0; i<sz; i+=1) tot_sum += A[i];
    dp.resize(sz, vector<vector<int> > (tot_sum + 1, vector<int> (sz, -1)));

    for(i=1; i<sz; i+=1) {
        if((tot_sum * i) % sz != 0) continue;
        //res.clear();
        int sum1 = (tot_sum * i) / sz;

        if(isPossible(0, i, sum1) == 1) {
            p1 = p2 = 0;
            int res_sz = res.size();

            while(p1 < sz || p2 < res_sz) {
                if(p2 < res_sz && res[p2] == v[p1]) {
                    p1 += 1;
                    p2 += 1;
                }
                else {
                    res2.push_back(v[p1]);
                    p1 += 1;
                }
            }
            vector<vector<int> > ret;
            ret.push_back(res);
            ret.push_back(res2);
            return ret;
        }
    }

    vector<vector<int> > ret;
    return ret;
}
