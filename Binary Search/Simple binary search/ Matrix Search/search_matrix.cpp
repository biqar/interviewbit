//
// Created by aislam6 on 12/16/19.
//

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size(), col = A[0].size();
    int lo = 0, hi = row * col, mid;
    int mid_r, mid_c;

    while(lo < hi) {
        mid = lo + (hi - lo) / 2;
        mid_r = mid / col;
        mid_c = mid % col;

        if(A[mid_r][mid_c] < B) {
            lo = mid + 1;
        } else if (A[mid_r][mid_c] > B) {
            hi = mid;
        } else {
            return 1;
        }
    }

    return 0;
}
