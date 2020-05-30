//
// Created by Islam, Abdullah Al Raqibul on 5/29/20.
//

vector<int> Solution::lszero(vector<int> &A) {
    // map contains prefix-sum/position pair
    map<int, int> m;
    int sz = A.size();
    int sum = 0, len = 0;
    int st = -1, nd = -1;

    m[0] = -1;
    for(int i=0; i<sz; i+=1) {
        sum += A[i];

        if(m.find(sum) == m.end()) {
            m[sum] = i;
        } else {
            if(len < (i - m[sum] + 1)) {
                st = m[sum] + 1;
                nd = i;
                len = (i - m[sum] + 1);
            }
        }
    }

    vector<int> ret;

    if(len > 0) {
        for(int i=st; i<=nd; i+=1) {
            ret.push_back(A[i]);
        }
    }

    return ret;
}
