//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

vector<int> parent;
vector< pair< int, pair<int, int> > > gr;
int n;

bool comp(pair< int, pair<int, int> > a, pair< int, pair<int, int> > b) {
    if(a.first != b.first) return a.first < b.first;
    if(a.second.first != b.second.first) return a.second.first < b.second.first;
    return a.second.second != b.second.second;
}

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);

    if(pu != pv) {
        parent[pu] = pv;
    }
}

int mst() {
    int sz = gr.size(), i, u, v, w, pu, pv, ret = 0;

    for(i=0; i<sz; i+=1) {
        w = gr[i].first;
        u = gr[i].second.first;
        v = gr[i].second.second;

        pu = find(u);
        pv = find(v);

        if(pu != pv) {
            ret += w;
            merge(u, v);
        }
    }

    return ret;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    n = A;
    parent.resize(A+2);
    parent.clear();
    for(int i=0; i<A+2; i+=1) {
        parent[i] = i;
    }
    int sz = B.size(), u, v, w;
    gr.resize(sz + 5);
    gr.clear();
    for(int i=0; i<sz; i+=1) {
        if(B[i].size() > 0) w = B[i][2];
        if(B[i].size() > 1) u = B[i][0];
        if(B[i].size() > 2) v = B[i][1];
        gr.push_back(make_pair( w, make_pair( u, v )));
    }

    sort(gr.begin(), gr.end(), comp);

    return mst();
}
