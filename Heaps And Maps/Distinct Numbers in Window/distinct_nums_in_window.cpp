//
// Created by Islam, Abdullah Al Raqibul on 11/26/19.
//

vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int, int> cnt;
    vector<int> v;
    int i, j, k = B, sz = A.size(), cur = 0;

    if(k > sz) return v;

    for(i=0; i<sz; i+=1) {
        if(i < k) {
            if(cnt[A[i]] == 0) cur += 1;
            cnt[A[i]] += 1;
            if(i==k-1) {
                v.push_back(cur);
            }
        }
        else {
            if(cnt[A[i-k]] == 1) cur -= 1;
            cnt[A[i-k]] -= 1;
            if(cnt[A[i]] == 0) cur += 1;
            cnt[A[i]] += 1;

            v.push_back(cur);
        }
    }
    return v;
}
