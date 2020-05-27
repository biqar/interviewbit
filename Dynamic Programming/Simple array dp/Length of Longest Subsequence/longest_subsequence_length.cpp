//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

vector<int> lis, lds;

int _max(int a, int b) {
    return a > b ? a : b;
}

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int i, j, k;
    int sz = A.size();
    int ret = 0;

    lis.clear(); lds.clear();
    lis.resize(sz+1, 1); lds.resize(sz+1, 1);

    for(i=1; i<sz; i+=1) {
        for(j=0; j<i; j+=1) {
            if(A[i] > A[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for(i=sz-2; i>=0; i-=1) {
        for(j=sz-1; j>i; j-=1) {
            if(A[i] > A[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    for(i=0; i<sz; i+=1) ret = _max(ret, lis[i]+lds[i]-1);

    return ret;
}
