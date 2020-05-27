//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

int _min(int a, int b) {
    return a < b ? a : b;
}

int _max(int a, int b) {
    return a > b ? a : b;
}

bool oneExist(const vector<int> &A) {
    int i, sz = A.size();
    for(i=0; i<sz; i+=1) if(A[i] == 1) return true;
    return false;
}

int Solution::maxProduct(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = A.size(), tmp, ret = 1, mx = 1, mn = 1;

    if(sz == 1) return A[0];

    for(i=0; i<sz; i+=1) {
        if(A[i] > 0) {
            mx *= A[i];
            mn = _min(mn*A[i], 1);
        }
        else if (A[i] == 0) {
            mx = 1;
            mn = 1;
        }
        else {
            tmp = mx;
            mx = _max(mn*A[i], 1);
            mn = tmp * A[i];
        }

        if(ret < mx) ret = mx;
    }

    if(ret == 1) {
        if(!oneExist(A)) ret = 0;
    }

    return ret;
}
