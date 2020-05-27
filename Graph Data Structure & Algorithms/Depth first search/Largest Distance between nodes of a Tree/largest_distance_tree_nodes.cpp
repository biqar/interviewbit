//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

const int MAX = 40000 + 5;
int d[MAX];
vector<int> gr[MAX];

pair<int, int> bfs(int n, int root) {
    int i, j, k, u, v, sz, ret = 0;
    for(i=0; i<n; i+=1) d[i] = MAX * 100;
    d[root] = 0;
    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        u = q.front();
        q.pop();

        sz = gr[u].size();
        for(i=0; i<sz; i+=1) {
            v = gr[u][i];

            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    for(i=0; i<n; i+=1) {
        if(d[i] != MAX * 100 && d[i] > ret) {
            root = i;
            ret = d[i];
        }
    }

    return make_pair(ret, root);
}

int Solution::solve(vector<int> &A) {
    int i, u, v;
    pair <int, int> ret;
    int n = A.size(), root;

    for(i=0; i<n; i+=1) gr[i].clear();

    for(i=0; i<n; i+=1) {
        u = i;
        v = A[i];

        if(v == -1) {
            root = u;
            continue;
        }
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    ret = bfs(n, root);
    return bfs(n, ret.second).first;
}
