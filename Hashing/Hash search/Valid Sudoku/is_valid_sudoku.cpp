//
// Created by Islam, Abdullah Al Raqibul on 5/29/20.
//

int Solution::isValidSudoku(const vector<string> &A) {
    int flg[10];

    // row check
    for(int i=0; i<9; i+=1) {
        memset(flg, 0, sizeof(flg));
        for(int j=0; j<9; j+=1) {
            if(A[i][j] != '.') {
                if(flg[A[i][j] - '0']) return 0;
                flg[A[i][j] - '0'] = 1;
            }
        }
    }

    // column check
    for(int j=0; j<9; j+=1) {
        memset(flg, 0, sizeof(flg));
        for(int i=0; i<9; i+=1) {
            if(A[i][j] != '.') {
                if(flg[A[i][j] - '0']) return 0;
                flg[A[i][j] - '0'] = 1;
            }
        }
    }

    // smaller board check
    for(int i=0; i<9; i+=3) {
        for(int j=0; j<9; j+=3) {
            memset(flg, 0, sizeof(flg));

            // 1st row
            if(A[i][j] != '.') {
                if(flg[A[i][j] - '0']) return 0;
                flg[A[i][j] - '0'] = 1;
            }
            if(A[i][j+1] != '.') {
                if(flg[A[i][j+1] - '0']) return 0;
                flg[A[i][j+1] - '0'] = 1;
            }
            if(A[i][j+2] != '.') {
                if(flg[A[i][j+2] - '0']) return 0;
                flg[A[i][j+2] - '0'] = 1;
            }

            // 2nd row
            if(A[i+1][j] != '.') {
                if(flg[A[i+1][j] - '0']) return 0;
                flg[A[i+1][j] - '0'] = 1;
            }
            if(A[i+1][j+1] != '.') {
                if(flg[A[i+1][j+1] - '0']) return 0;
                flg[A[i+1][j+1] - '0'] = 1;
            }
            if(A[i+1][j+2] != '.') {
                if(flg[A[i+1][j+2] - '0']) return 0;
                flg[A[i+1][j+2] - '0'] = 1;
            }

            // 3rd row
            if(A[i+2][j] != '.') {
                if(flg[A[i+2][j] - '0']) return 0;
                flg[A[i+2][j] - '0'] = 1;
            }
            if(A[i+2][j+1] != '.') {
                if(flg[A[i+2][j+1] - '0']) return 0;
                flg[A[i+2][j+1] - '0'] = 1;
            }
            if(A[i+2][j+2] != '.') {
                if(flg[A[i+2][j+2] - '0']) return 0;
                flg[A[i+2][j+2] - '0'] = 1;
            }
        }
    }

    return 1;
}
