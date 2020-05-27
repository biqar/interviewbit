//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

int Solution::candy(vector<int> &ratings) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, sz = ratings.size(), ret = 0;
    vector<int> l(sz, 1), r(sz, 1);

    for(i=1; i<sz; i+=1) {
        if(ratings[i] > ratings[i-1]) l[i] = l[i-1] + 1;
    }

    for(i=sz-2; i>=0; i-=1) {
        if(ratings[i] > ratings[i+1]) r[i] = r[i+1] + 1;
    }

    for(i=0; i<sz; i+=1) ret += _max(l[i], r[i]);

    return ret;
}
