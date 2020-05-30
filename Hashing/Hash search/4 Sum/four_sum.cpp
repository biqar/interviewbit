//
// Created by Islam, Abdullah Al Raqibul on 5/29/20.
//

#include <iterator>

// This makes sure that the solution set is lexicographically sorted.
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

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    // store the pisition of the first 2 numbers
    map<int, vector<pair<int, int> > > m;
    map<string, bool> dup_check;
    int sz = A.size();
    vector<vector<int> > ret;

    for(int i=0; i<sz; i+=1) {
        for(int j=i+1; j<sz; j+=1) {
            int sum1 = A[i] + A[j];
            m[sum1].push_back(make_pair(i, j));
        }
    }

    for(int i=0; i<sz; i+=1) {
        for(int j=i+1; j<sz; j+=1) {
            int sum2 = B - (A[i] + A[j]);
            if(m.find(sum2) != m.end()) {
                int m_sz = m[sum2].size();

                for(int k=0; k<m_sz; k+=1) {
                    if(m[sum2][k].first < i && m[sum2][k].second < i
                       && m[sum2][k].first < j && m[sum2][k].second < j) {
                        vector<int> tmp;
                        tmp.push_back(A[i]);
                        tmp.push_back(A[j]);
                        tmp.push_back(A[m[sum2][k].first]);
                        tmp.push_back(A[m[sum2][k].second]);

                        sort(tmp.begin(), tmp.end());

                        stringstream ss;
                        copy(tmp.begin(), tmp.end(), ostream_iterator<int>(ss, " "));

                        if(dup_check.find(ss.str()) == dup_check.end()) {
                            dup_check[ss.str()] = true;
                            ret.push_back(tmp);
                        }
                    }
                }
            }
        }
    }

    sort(ret.begin(), ret.end(), comp);

    return ret;
}
