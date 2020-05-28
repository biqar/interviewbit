//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

vector<int> Solution::maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, k, sz = A.size();
    vector<int> ret;
    int st, nd, count, gap;

    count = gap = 0;
    st = nd = 0;
    for(i=j=0; i<sz; i+=1) {
        if(A[i] == 0) {
            count += 1;
        }

        if(count > B) {
            if(i-j > gap) {
                gap = i - j;
                st = j;
                nd = i - 1;
            }
            while(count > B) {
                if(A[j] == 0) count -= 1;
                j += 1;
            }
        }
    }

    if(i-j > gap) {
        gap = i - j;
        st = j;
        nd = i - 1;
    }

    for(i=st; i<=nd; i+=1) ret.push_back(i);
    return ret;
}
