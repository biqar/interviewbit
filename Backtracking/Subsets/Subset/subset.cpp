//
// Created by aislam6 on 12/16/19.
//

vector<vector<int>> ret;

void dfs(int pos, int sz, vector<int> v, vector<int> A) {
    if(pos == sz+1) {
        return;
    }
    ret.push_back(v);

    for(int i=pos; i<sz; i+=1) {
        v.push_back(A[i]);
        dfs(i+1, sz, v, A);
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size();
    vector<int> v;

    sort(A.begin(), A.end());
    ret.clear();
    dfs(0, sz, v, A);

    return ret;
}
