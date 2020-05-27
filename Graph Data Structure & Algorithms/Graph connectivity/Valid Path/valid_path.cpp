//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

int dir_x[8] = {-1, 0, +1, -1, +1, -1, 0, +1};
int dir_y[8] = {-1, -1, -1, 0, 0, +1, +1, +1};

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int rec[A+1][B+1];
    memset(rec, 0, sizeof(rec));

    for(int i=0; i<=A; i+=1) {
        for(int j=0; j<=B; j+=1) {
            for(int c=0; c<C; c+=1) {
                if((((E[c]-i)*(E[c]-i)) + ((F[c]-j)*(F[c]-j))) <= D*D) {
                    rec[i][j] = -1;
                    break;
                }
            }
        }
    }

    if(rec[0][0]==-1 || rec[A][B]==-1) return "NO";

    queue<pair<int, int>> q;
    rec[0][0] = 1;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        int x = u.first;
        int y = u.second;

        for(int i=0; i<8; i+=1) {
            int xx = x + dir_x[i];
            int yy = y + dir_y[i];

            if(xx<0 || xx>A || yy<0 || yy>B || rec[xx][yy]!=0) continue;

            rec[xx][yy] = 1;
            q.push(make_pair(xx, yy));
        }
    }

    if(rec[A][B] == 1) return "YES";
    else return "NO";
}
