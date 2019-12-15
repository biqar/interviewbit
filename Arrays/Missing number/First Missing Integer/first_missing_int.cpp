//
// Created by aislam6 on 12/15/19.
//

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    int i, tmp = 1, sz = A.size();
    for(i=0; i<sz; i+=1) {
        if(A[i] > 0) {
            if(A[i] != tmp) return tmp;
            else tmp += 1;
        }
    }
    return tmp;

    /*int i, tmp, sz = A.size();
    for(i=0; i<sz; i+=1) {
        while (A[i] != i+1) {
            if(A[i] <= 0 || A[i] > sz) break;
            if(A[i] == A[A[i]-1]) break;

            tmp = A[A[i]-1];
            A[A[i]-1]=A[i];
            A[i]=tmp;
        }
    }

    for(i=0; i<sz; i+=1) {
        if(A[i] != i+1) {
            return i+1;
        }
    }

    return i+1;*/
}
