//
// Created by aislam6 on 12/16/19.
//

void printres(vector<int> A, int n, vector<vector<string> > &res) {
    vector<string> r;
    for(int i=0; i<n; i++) {
        string str(n,'.');
        str[A[i]] = 'Q';
        r.push_back(str);
    }
    res.push_back(r);
}


bool isValid(vector<int> A, int r) {
    for(int i=0; i<r; i++) {
        if((A[i] == A[r]) || (abs(A[i]-A[r]) == (r-i)) ) {
            return false;
        }
    }
    return true;
}

void nqueens(vector<int> A, int cur, int n, vector<vector<string> > &res) {
    if (cur==n){
        printres(A, n, res);
        return;
    }
    for(int i=0; i<n; i++) {
        A[cur] = i;
        if(isValid(A, cur)) {
            nqueens(A, cur+1, n, res);
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string> > res;
    vector<int> v(A,-1);
    nqueens(v, 0, A, res);
    return res;
}
