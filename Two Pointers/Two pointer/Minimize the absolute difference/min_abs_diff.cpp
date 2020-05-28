//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

int _max(int a, int b, int c) {
    return c > _max(a, b) ? c : _max(a, b);
}

int _min(int a, int b) {
    return a < b ? a : b;
}

int _min(int a, int b, int c) {
    return c < _min(a, b) ? c : _min(a, b);
}

int _abs(int a) {
    return a < 0 ? -a : a;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int sa = A.size();
    int sb = B.size();
    int sc = C.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int a, b, c, ret = (1 << 30);
    a = b = c = 0;

    while(a<sa && b<sb && c<sc) {
        int min = _min(A[a], B[b], C[c]);
        int max = _max(A[a], B[b], C[c]);

        if(_abs(max - min) < ret) ret = _abs(max-min);
        if(ret == 0) break;

        if(min == A[a]) {
            a += 1;
        } else if(min == B[b]) {
            b += 1;
        } else {
            c += 1;
        }
    }
    return ret;
}
