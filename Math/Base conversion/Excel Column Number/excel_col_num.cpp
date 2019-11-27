//
// Created by aislam6 on 11/27/19.
//

int Solution::titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, ans = 0, power, sz = A.size();
    for(power=1,i=sz-1; i>=0; i-=1, power*=26) {
        ans += ((int)(A[i] - 'A' + 1) * power);
    }
    return ans;
}
