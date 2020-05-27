//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = A.size(), tmp, ret = -1, l, r;
    map<char, bool> m;

    for(l=r=0; r<sz; ) {
        if(m[A[r]] == true) {
            ret = _max(ret, r-l);

            while(A[r] != A[l]) {
                m[A[l]] = false;
                l += 1;
            }
            l += 1;
            r += 1;
        }
        else {
            m[A[r]] = true;
            r += 1;
        }
    }
    ret = _max(ret, sz - l);
    return ret;
}
