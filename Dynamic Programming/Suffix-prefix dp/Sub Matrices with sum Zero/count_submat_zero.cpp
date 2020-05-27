//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

vector< vector<int> > sum;

int countSubmat(int sa, int sb) {
    int i, j, _i, _j, ret = 0;
    int t1, t2, t3;

    for(i=0; i<sa; i+=1) {
        for(j=0; j<sb; j+=1) {
            for(_i=i; _i<sa; _i+=1) {
                for(_j=j; _j<sb; _j+=1) {
                    t1 = t2 = t3 = 0;
                    if(i-1 >= 0) t1 = sum[i-1][_j];
                    if(j-1 >= 0) t2 = sum[_i][j-1];
                    if(i-1>=0 && j-1>=0) t3 = sum[i-1][j-1];
                    if(t1+t2-t3 == sum[_i][_j]) ret += 1;
                }
            }
        }
    }
    return ret;
}

int Solution::solve(vector<vector<int> > &A) {
    sum = A;
    int t1, t2, t3, i, j, sb, sa = A.size();
    if(sa!=0) sb = A[0].size();

    if(sa == 0 && sb == 0) return 0;

    for(i=0; i<sa; i+=1) {
        for(j=0; j<sb; j+=1) {
            t1 = t2 = t3 = 0;
            if(i-1 >= 0 && j-1>=0) t1 = sum[i-1][j-1];
            if(i-1 >= 0) t2 = sum[i-1][j];
            if(j-1 >= 0) t3 = sum[i][j-1];
            sum[i][j] = (t2+t3-t1) + A[i][j];
        }
    }

    return countSubmat(sa, sb);
}
