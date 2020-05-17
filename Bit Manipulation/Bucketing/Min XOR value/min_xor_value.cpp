//
// Created by Islam, Abdullah Al Raqibul on 5/16/20.
//

int _min(int a, int b) {
    return a < b ? a : b;
}

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());

    int i, sz = A.size(), ret = 1000000000 + 5;
    for(i=0; i<sz-1; i+=1) {
        ret = _min(ret, A[i]^A[i+1]);
    }

    return ret;
}
