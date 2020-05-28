//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

int _abs(int a) {
    return a < 0 ? -a : a;
}

int Solution::threeSumClosest(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, k, sz = A.size(), sum, diff, res, ret;
    long long int min_diff = (long long int) 1 << 40;
    sort(A.begin(), A.end());

    for(i=0; i<sz; i+=1) {
        j = i + 1;
        k = sz - 1;

        while(j < k) {
            sum = A[i] + A[j] + A[k];
            diff = _abs(sum-B);

            if(diff == 0) return sum;
            if(diff < min_diff) {
                min_diff = diff;
                ret = sum;
            }

            if(sum <= B) {
                j += 1;
            } else {
                k -= 1;
            }
        }
    }

    return ret;
}
