//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int _max(int a, int b) {
    return a > b ? a : b;
}

int hist(vector<int> h, int sz) {
    int i = 0, j, k, ret = 0;
    stack<int> s;

    while(i < sz) {
        if(s.empty() || h[s.top()]<=h[i]) {
            s.push(i);
            i += 1;
        }
        else {
            int hi = h[s.top()]; s.pop();
            int wi = s.empty() ? i : i - s.top() - 1;
            ret = _max(ret, hi*wi);
        }
    }

    while(!s.empty()) {
        int hi = h[s.top()]; s.pop();
        int wi = s.empty() ? i : i - s.top() - 1;
        ret = _max(ret, hi*wi);
    }

    return ret;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int r = 0, c = 0, i, j, k, ret = 0;

    r = A.size();
    if(r != 0) {
        c = A[0].size();
    }

    vector<vector<int> > height(r+5, vector<int>(c+5, 0));

    for(i=0; i<r; i+=1) {
        for(j=0; j<c; j+=1) {
            if(A[i][j] == 0) {
                height[i][j] = 0;
            }
            else {
                height[i][j] = (i==0) ? 1 : height[i-1][j] + 1;
            }
        }
    }

    for(i=0; i<r; i+=1) {
        ret = _max(ret, hist(height[i], c));
    }

    return ret;
}
