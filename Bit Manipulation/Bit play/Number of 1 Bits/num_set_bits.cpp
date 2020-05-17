//
// Created by Islam, Abdullah Al Raqibul on 5/16/20.
//

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unsigned int mask = 1;
    int count = 0;

    for(int i=0; i<32; i+=1) {
        if(A & mask) count += 1;
        mask <<= 1;
    }

    return count;
}
