//
// Created by aislam6 on 12/15/19.
//

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int st = -1, nd = -1, tmp_st = -1;
    vector<int> ret;
    int i, flg = 0, sz = A.size();
    long long int max_sum = 0, cur_sum = 0;

    for(i=0; i<sz; i+=1) {
        if(A[i] < 0) {
            if(flg) {
                if(cur_sum > max_sum) {
                    max_sum = cur_sum;
                    st = tmp_st;
                    nd = i;
                } else if(cur_sum == max_sum) {
                    if(nd-st < i-tmp_st) {
                        st = tmp_st;
                        nd = i;
                    }
                }
                cur_sum = 0;
                tmp_st = -1;
                flg = 0;
            }
        }
        else {
            flg = 1;
            if(tmp_st < 0) tmp_st = i;
            cur_sum += A[i];
        }
    }

    if(flg) {
        if(cur_sum > max_sum) {
            max_sum = cur_sum;
            st = tmp_st;
            nd = i;
        } else if(cur_sum == max_sum) {
            if(nd-st < i-tmp_st) {
                st = tmp_st;
                nd = i;
            }
        }
    }

    if(st >= 0) {
        for(i=st; i<nd; i+=1) {
            ret.push_back(A[i]);
        }
    }

    return ret;
}
