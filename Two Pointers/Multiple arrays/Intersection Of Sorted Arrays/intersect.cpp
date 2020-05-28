//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sa = A.size(), sb = B.size();
    vector<int> ret;

    for(i=0,j=0; i<sa && j<sb; ) {
        if(A[i] > B[j]) {
            j += 1;
        } else if(A[i] < B[j]) {
            i += 1;
        } else {
            ret.push_back(A[i]);
            i += 1;
            j += 1;
        }
    }

    return ret;
}
