//
// Created by Islam, Abdullah Al Raqibul on 5/16/20.
//

int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, sz = A.size(), ones, twos, common_bits;
    ones = twos = 0;

    for(i=0; i<sz; i+=1) {
        twos = twos | (ones & A[i]);
        ones = ones ^ A[i];

        common_bits = ~(ones & twos);

        twos &= common_bits;
        ones &= common_bits;
    }
    return ones;
}
