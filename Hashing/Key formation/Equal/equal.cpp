//
// Created by Islam, Abdullah Al Raqibul on 5/30/20.
//

bool comp(const vector<int>& p1, const vector<int>& p2) {
    if(p1[0] == p2[0]) {
        if(p1[1] == p2[1]) {
            if(p1[2] == p2[2]) {
                return p1[3] < p2[3];
            } else {
                return p1[2] < p2[2];
            }
        } else {
            return p1[1] < p2[1];
        }
    } else {
        return p1[0] < p2[0];
    }
}

vector<int> Solution::equal(vector<int> &A) {
    map<int, vector<pair<int, int> > > m;
    int sz = A.size();
    vector<int> ret;

    for(int i=0; i<sz; i+=1) {
        for(int j=i+1; j<sz; j+=1) {
            int sum = A[i] + A[j];
            if(m.find(sum) == m.end()) {
                m[sum].push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<sz; i+=1) {
        for(int j=i+1; j<sz; j+=1) {
            int sum = A[i] + A[j];
            if(m.find(sum) != m.end()) {
                for(int k=0; k<m[sum].size(); k+=1) {
                    if(m[sum][k].first < i
                       && m[sum][k].second != i
                       && m[sum][k].second != j) {
                        vector<int> tmp;
                        tmp.push_back(m[sum][k].first);
                        tmp.push_back(m[sum][k].second);
                        tmp.push_back(i);
                        tmp.push_back(j);

                        if(ret.size() && comp(tmp, ret)) {
                            ret.clear();
                            ret = tmp;
                        }
                        if(!ret.size()) ret = tmp;
                    }
                }
            }
        }
    }

    return ret;
}

// TLE Solution
/*vector<int> Solution::equal(vector<int> &A) {
    map<int, vector<pair<int, int> > > m;
    int sz = A.size();
    vector<int> ret;

    for(int i=0; i<sz; i+=1) {
        for(int j=i+1; j<sz; j+=1) {
            int sum = A[i] + A[j];
            if(m.find(sum) != m.end()) {
                for(int k=0; k<m[sum].size(); k+=1) {
                    if(m[sum][k].first < i
                    && m[sum][k].second != i
                    && m[sum][k].second != j) {
                        // we already found a solution,
                        // let's check whether the current solution is
                        // lexicographically smaller or not

                        vector<int> tmp;
                        tmp.push_back(m[sum][k].first);
                        tmp.push_back(m[sum][k].second);
                        tmp.push_back(i);
                        tmp.push_back(j);

                        if(ret.size() && comp(tmp, ret)) {
                            ret.clear();
                            ret = tmp;
                        }
                        if(!ret.size()) ret = tmp;
                    }
                }
            }

            m[sum].push_back(make_pair(i, j));
        }
    }

    return ret;
}*/
