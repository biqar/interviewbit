//
// Created by aislam6 on 12/15/19.
//

// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])

int _min(int a, int b) {
    return a < b ? a : b;
}

int _abs(int a) {
    return a < 0 ? -a : a;
}

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    long long int ret = 0;
    int sz = X.size();

    for(int i=0; i<sz-1; i+=1) {
        ret += _min(_abs(X[i]-X[i+1]), _abs(Y[i]-Y[i+1])) + _abs(_abs(X[i]-X[i+1]) - _abs(Y[i]-Y[i+1]));
    }

    return ret;
}
