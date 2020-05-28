//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = A.size(), len = 1;
    bool first = true;

    for(i=0,j=0; i<sz-1; ) {
        if(A[i] == A[i+1]) {
            i += 1;
        } else {
            A[++j] = A[i+1];
            i += 1;
            len += 1;
        }
    }

    while(A.size() != j+1) A.pop_back();

    return len;
}
