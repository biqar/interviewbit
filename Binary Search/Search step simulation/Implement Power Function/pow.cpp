//
// Created by aislam6 on 12/16/19.
//

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(x < 0) {
        while(x < 0) x += d;
    }

    if(n == 0) {
        return x > 0;
    }
    if(n == 1) return x % d;

    long long int ret = pow(x, n/2, d);
    if(n % 2 == 0) {
        return ((ret % d) * (ret % d)) % d;
    } else {
        ret = ((ret % d) * (ret % d)) % d;
        return (ret * (x %d)) % d;
    }
}
