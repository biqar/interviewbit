//
// Created by aislam6 on 12/16/19.
//

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l = 0, h = A;
    long long int mid;

    while(l < h) {
        mid = (h + l) / 2;

        if(mid * mid < A) {
            l = mid + 1;
        } else if (mid * mid > A) {
            h = mid;
        } else {
            return mid;
        }
    }
    if((long long int) l*l <= A) return l;
    return l - 1;
}
