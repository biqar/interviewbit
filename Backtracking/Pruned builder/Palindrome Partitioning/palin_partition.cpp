//
// Created by aislam6 on 12/16/19.
//

bool valid(string &str, int st, int ed){
    while(st < ed) {
        if(str[ed] != str[st]) {
            return false;
        }
        else {
            st += 1;
            ed -= 1;
        }
    }
    return true;
}


void find(string s, int st, vector<string> &r, vector<vector<string>> &res){
    if(st >= s.size()){
        res.push_back(r);
        return;
    }
    for(int i=st; i<s.size(); i+=1) {
        if(valid(s, st, i)) {
            r.push_back(s.substr(st, i-st+1));
            find(s, i+1, r, res);
            r.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<string>> res;
    vector<string> r;
    find(s, 0, r, res);
    return res;
}