//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

map<int, bool> mp;

int _min(int a, int b) {
    return a < b ? a : b;
}

vector<int> Solution::solve(int A, int B, int C, int D) {
    mp.clear();
    vector<int> ret;
    vector<int> prime = {A, B, C};
    sort(prime.begin(), prime.end());
    A = prime[0]; B = prime[1]; C = prime[2];
    int _A = prime[0], _B = prime[1], _C = prime[2];
    int pa = 0, pb = 0, pc = 0;
    int cnt = 0;

    while(cnt < D) {
        int tmp = _min(A, _min(B, C));

        if(mp.find(tmp) == mp.end()) {
            ret.push_back(tmp);
            cnt += 1;
            mp[tmp] = true;
        }

        if(tmp == A) {
            A = _A * ret[pa];
            pa +=1;
        }

        else if(tmp == B) {
            B = _B * ret[pb];
            pb +=1;
        }

        else if(tmp == C) {
            C = _C * ret[pc];
            pc +=1;
        }
    }

    return ret;
}
