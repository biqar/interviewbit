//
// Created by Islam, Abdullah Al Raqibul on 11/26/19.
//

struct Trie {
    bool endmark;
    Trie *next[30];
    Trie() {
        endmark=false;
        for(int i=0; i<30; i++) next[i]=NULL;
    }
} *T;

struct review {
    int pos, val;
};

bool comp(const review &a, const review &b) {
    if (a.val != b.val) return a.val > b.val;
    return a.pos < b.pos;
}

string serializeString(string str) {
    int i, sz = str.size();

    for(i=0; i<sz; i+=1) {
        if(str[i] == '_') str[i] = ' ';
    }
    return str;
}

void initTrie() {
    T = new Trie();
}

void insert(string str, int len) {
    Trie *curr = T;
    for(int i=0; i<len; i+=1) {
        int id = -1;

        if(str[i]>='a' && str[i]<='z') id = str[i] - 'a';
        if(str[i]>='A' && str[i]<='Z') id = str[i] - 'A';

        if(id == -1) continue;

        if(curr->next[id] == NULL) {
            curr->next[id] = new Trie();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}

int search(string str, int len) {
    Trie *curr = T;
    for(int i=0; i<len; i+=1) {
        int id = -1;

        if(str[i]>='a' && str[i]<='z') id = str[i] - 'a';
        if(str[i]>='A' && str[i]<='Z') id = str[i] - 'A';

        if(id == -1) continue;

        if(curr->next[id] == NULL) {
            return 0;
        }
        curr = curr->next[id];
    }
    return curr->endmark == true ? 1 : 0;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    initTrie();
    vector<review> rv;
    string str;
    stringstream ss(serializeString(A));
    while(ss >> str) {
        insert(str, str.size());
    }

    int sz = B.size();
    for(int i=0; i<sz; i+=1) {
        review tmp;
        tmp.pos = i;
        tmp.val = 0;

        stringstream ss(serializeString(B[i]));
        while(ss >> str) {
            tmp.val += search(str, str.size());
        }
        rv.push_back(tmp);
    }

    sort(rv.begin(), rv.end(), comp);

    vector<int> ret;
    for(int i=0; i<sz; i+=1) ret.push_back(rv[i].pos);

    return ret;
}
