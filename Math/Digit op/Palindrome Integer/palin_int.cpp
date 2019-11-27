//
// Created by aislam6 on 11/27/19.
//

int Solution::isPalindrome(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int rev = 0, a = A > 0 ? A : -A;
    while(A) {
        rev = (rev * 10) + (A % 10);
        A /= 10;
    }

    if(rev == a) return 1;
    return 0;
}
