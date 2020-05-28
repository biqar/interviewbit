//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> ret;
    int i, sz = A.size();

    for(i=0; i<sz; i+=1) {
        while(!s.empty() && s.top() >= A[i]) s.pop();
        if(s.empty()) ret.push_back(-1);
        else ret.push_back(s.top());
        s.push(A[i]);
    }
    return ret;
}