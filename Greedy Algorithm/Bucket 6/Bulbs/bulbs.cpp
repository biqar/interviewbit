//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int Solution::bulbs(vector<int> &A) {
    int i, cnt = 0, sz = A.size();

    for(i=0; i<sz; i+=1) {
        if(A[i] == 1) {
            if(cnt%2 == 1) {
                cnt += 1;
            }
        }
        else {
            if(cnt%2 == 0) {
                cnt += 1;
            }
        }
    }
    return cnt;
}
