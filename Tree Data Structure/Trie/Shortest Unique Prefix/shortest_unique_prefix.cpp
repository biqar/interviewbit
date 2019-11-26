//
// Created by Islam, Abdullah Al Raqibul on 11/26/19.
//

struct node {
    bool endmark;
    int count;
    node *next[52+1];
    node() {
        endmark=false;
        count = 1;
        for(int i=0; i<52; i++) next[i]=NULL;
    }
} *root;

void insert(string str, int len) {
    node *curr = root;
    for(int i=0; i<len; i++) {
        int id;
        if(str[i] >= 'a' && str[i] <= 'z') {
            id = str[i]-'a';
        } else {
            id = 26 + (str[i] - 'A');
        }

        if(curr->next[id]==NULL) {
            curr->next[id] = new node();
        } else {
            curr->next[id]->count += 1;
        }
        curr = curr->next[id];
    }
    curr->endmark = 1;
}

void del(node *cur) {
    for(int i=0; i<52; i++) {
        if(cur->next[i]) {
            del(cur->next[i]);
        }
    }
    delete(cur) ;
}

string search(node *curr, string str, int pos, string ret) {
    if(curr->count == 1 || curr->endmark == true || pos == str.size()) return ret;

    int id;
    if(str[pos] >= 'a' && str[pos] <= 'z') {
        id = str[pos]-'a';
    } else {
        id = 26 + (str[pos] - 'A');
    }

    if(curr->next[id] != NULL) {
        return search(curr->next[id], str, pos+1, ret+str[pos]);
    }
}

vector<string> Solution::prefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size(), i, j, k;
    vector<string> ret;
    root = new node();

    for(i=0; i<sz; i+=1) {
        insert(A[i], A[i].length());
    }

    for(i=0; i<sz; i+=1) {
        int id;
        if(A[i][0] >= 'a' && A[i][0] <= 'z') {
            id = A[i][0]-'a';
        } else {
            id = 26 + (A[i][0] - 'A');
        }

        string tmp = "";
        tmp = search(root->next[id], A[i], 1, tmp + A[i].at(0));
        ret.push_back(tmp);
    }
    del(root);

    return ret;
}
