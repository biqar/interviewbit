//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

vector<string> res;
vector< vector<string> > dpStr;

void dfs(int pos, vector<string> tmp, int sz) {
    if(pos == sz) {
        int tmpSz = tmp.size();
        if(tmpSz != 0) {
            string line = tmp[0];
            for(int i=1; i<tmpSz; i+=1) {
                line += (" " + tmp[i]);
            }
            res.push_back(line);
        }
    }
    if(pos > sz) return;

    for(int i=0; i<dpStr[pos].size(); i+=1) {
        tmp.push_back(dpStr[pos][i]);
        dfs(pos+dpStr[pos][i].size(), tmp, sz);
        tmp.pop_back();
    }
}

vector<string> getUniqueVector(vector<string> v) {
    set<string> s(v.begin(), v.end());
    vector<string> ret(s.begin(), s.end());
    return ret;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    vector<string> tmp;
    res.clear();
    dpStr.resize(A.size()+5);

    B = getUniqueVector(B);

    int asz = A.size();
    int bsz = B.size();

    for(int i=0; i<asz; i+=1) {
        dpStr[i].clear();
        for(int j=0; j<bsz; j+=1) {
            int sz = B[j].size();
            if(i+sz <= asz && B[j].compare(A.substr(i, sz)) == 0) {
                dpStr[i].push_back(B[j]);
            }
        }
    }

    dfs(0, tmp, asz);
    sort(res.begin(), res.end());
    return res;
}
