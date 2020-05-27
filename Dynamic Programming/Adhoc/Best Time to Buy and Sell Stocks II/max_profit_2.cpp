//
// Created by Islam, Abdullah Al Raqibul on 5/21/20.
//

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    /*int i, j, sz = A.size();
    int tmp, tot = 0, profit = 0, bd = 0, sd = 1;

    while(sd < sz) {
        tmp = A[sd] - A[sd-1];
        if(tmp <= 0) {
            tot += profit;
            bd = sd;
            profit = 0;
        } else {
            tmp = A[sd] - A[bd];
            if(tmp > profit) profit = tmp;
        }
        sd += 1;
    }
    tot += profit;

    return tot;*/

    int sz = A.size();
    int maxProfit[sz];
    maxProfit[0]=0;
    for(int i=1; i<sz; i+=1) {
        if(A[i] > A[i-1]) {
            maxProfit[i] = A[i] - A[i-1] + maxProfit[i-1];
        }
        else{
            maxProfit[i]=maxProfit[i-1];
        }
    }

    return sz ? maxProfit[sz-1] : maxProfit[sz];
}
