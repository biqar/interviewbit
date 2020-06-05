//
// Created by Islam, Abdullah Al Raqibul on 6/4/20.
//

vector<int> Solution::nextGreater(vector<int> &A) {
    stack<pair<int, int>> s;
    int sz = A.size();
    vector<int> ret(sz);

    s.push(make_pair(0, A[0]));
    for(int i=1; i<sz; i+=1) {
        while(!s.empty() && A[i] > s.top().second) {
            ret[s.top().first] = A[i];
            s.pop();
        }
        s.push(make_pair(i, A[i]));
    }

    while(!s.empty()) {
        ret[s.top().first] = -1;
        s.pop();
    }

    return ret;
}
