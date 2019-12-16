//
// Created by aislam6 on 12/16/19.
//

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l = 0, h = A.size(), mid;

    while(l < h) {
        mid = l + ((h-l)/2);

        if(A[mid] == B) return mid;

        if(A[l] < A[mid]) {
            if(A[l] <= B && B < A[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if(A[mid] < B && B <= A[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }

    return A[l] == B ? l : -1;
}
