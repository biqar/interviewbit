//
// Created by aislam6 on 12/16/19.
//

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ret;
    ret.push_back(0);

    for(int i=0; i<A; i+=1) {
        int msk = (1 << i);
        int sz = ret.size();

        for(int j=sz-1; j>=0; j-=1) {
            ret.push_back((ret[j] | msk));
        }
    }
    return ret;
}
