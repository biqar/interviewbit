//
// Created by aislam6 on 12/16/19.
//

void permutation(vector<int> v, int pos, int sz, vector<vector<int> > &ret) {
    if(pos == sz) {
        ret.push_back(v);
        return;
    }

    for(int i=pos; i<=sz; i+=1) {
        int tmp = v[pos];
        v[pos] = v[i];
        v[i] = tmp;

        permutation(v, pos+1, sz, ret);

        tmp = v[pos];
        v[pos] = v[i];
        v[i] = tmp;
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ret;
    permutation(A, 0, A.size()-1, ret);
    return ret;
}
