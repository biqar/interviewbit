//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

int _abs(int a) {
    return a < 0 ? -a : a;
}

int Solution::mice(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, sz = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int res = 0;

    for(i=0; i<sz; i+=1) {
        res = _max(res, _abs(A[i]-B[i]));
    }
    return res;
}
