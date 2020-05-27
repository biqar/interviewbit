//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

#define MAX 100000

int in_degree[MAX];
vector<int> g[MAX];
queue<int> q;

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    memset(in_degree, 0, sizeof(in_degree));
    for(int i=1; i<=A; i+=1) g[i].clear();

    int sz = B.size();
    for(int i=0; i<sz; i+=1) {
        g[B[i]].push_back(C[i]);
        in_degree[C[i]] += 1;
    }

    for(int i=1; i<=A; i+=1) {
        if(!in_degree[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front(); q.pop();

        sz = g[u].size();
        for(int i=0; i<sz; i+=1) {
            in_degree[g[u][i]] -= 1;
            if(in_degree[g[u][i]] == 0) q.push(g[u][i]);
        }
    }

    for(int i=1; i<=A; i+=1) {
        if(in_degree[i]) return 0;
    }

    return 1;
}
