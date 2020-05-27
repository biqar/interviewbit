//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size(), i, j = sz / 2;
    map<int, int> m;

    for(i=0; i<sz; i+=1) {
        m[A[i]] += 1;
        if(m[A[i]] > j) return A[i];
    }
}
