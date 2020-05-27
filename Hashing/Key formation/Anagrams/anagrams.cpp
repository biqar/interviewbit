//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ret;
    vector<int > v;
    int sz = A.size(), i, j;
    vector<int > flg(sz);
    vector<string> cA;

    for(i=0; i<sz; i+=1) {
        flg[i] = 0;
        cA.push_back(A[i]);
        sort(cA[i].begin(), cA[i].end());
    }

    for(i=0; i<sz; i+=1) {
        if(flg[i] == 0) {
            v.clear();
            v.push_back(i+1);
            flg[i] = 1;
            for(j=i+1; j<sz; j+=1) {
                if(cA[i] == cA[j]) {
                    flg[j] = 1;
                    v.push_back(j+1);
                }
            }
            ret.push_back(v);
        }
    }
    return ret;
}
