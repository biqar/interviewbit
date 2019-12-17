//
// Created by aislam6 on 12/16/19.
//

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int lo = 0, hi = A.size(), mid;

    while(lo < hi) {
        mid = lo + (hi - lo) / 2;

        if(A[mid] < B) {
            lo = mid + 1;
        } else if (A[mid] > B) {
            hi = mid;
        } else {
            return mid;
        }
    }

    return lo;
}
