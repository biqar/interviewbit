//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    int i, sz = A.size();

    int p1 = A[0] * A[1] * A[sz-1];
    int p2 = A[sz-3] * A[sz-2] * A[sz-1];
    return (p1 > p2) ? p1 : p2;
}
