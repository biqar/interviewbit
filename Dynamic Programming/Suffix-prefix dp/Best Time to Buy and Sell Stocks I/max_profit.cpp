//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = A.size();
    int tmp, profit = 0, bd = 0, sd = 1;

    while(sd < sz) {
        tmp = A[sd] - A[bd];
        if(tmp <= 0) bd = sd;
        if(tmp > profit) profit = tmp;
        sd += 1;
    }
    return profit;
}
