//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
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
}*root;

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
            curr->count += 1;
        }
        curr = curr->next[id];
    }
    curr->endmark = 1;
}

string search(node *curr, string str, int sz) {
    if(curr->count != sz || curr->endmark == true) return str;

    int len = str.size();
    string ret;
    for(int i=0; i<26; i++) {
        if(curr->next[i] != NULL) {
            string tmp = search(curr->next[i], str+(char)('a'+i), sz);
            if(tmp.size() > len) {
                ret = tmp;
                len = tmp.size();
            }
        }
    }
    for(int i=26, j=0; i<52; i++,j++) {
        if(curr->next[i] != NULL) {
            string tmp = search(curr->next[i], str+(char)('A'+j), sz);
            if(tmp.size() > len) {
                ret = tmp;
                len = tmp.size();
            }
        }
    }
    return ret;
}

void del(node *cur) {
    for(int i=0; i<52; i++) {
        if(cur->next[i]) {
            del(cur->next[i]);
        }
    }
    delete(cur) ;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = A.size(), i, j, k = A[0].size();
    string ret = "";

    for(j=0; j<k; j+=1) {
        for(i=1; i<sz; i+=1) {
            if(A[i].size() >= j+1) {
                if(A[i][j] != A[0][j]) break;
            } else {
                break;
            }
        }
        if(i != sz) return ret;
        ret += A[0][j];
    }

    return ret;

    /*root = new node();
    int sz = A.size(), i, j, k;

    for(i=0; i<sz; i+=1) {
        insert(A[i], A[i].length());
    }
    string ret = search(root, "", sz);

    del(root);

    return ret;*/

    /*map<string, int> M;
    map<string, int> :: iterator it;

    int sz = A.size(), i, j, k;
    for(i=0; i<sz; i+=1) {
        k = A[i].length();
        for(j=0; j<k; j+=1) {
            M[A[i].substr(0, j+1)] += 1;
        }
    }

    int count = 0;
    string ret = "";
    for(it = M.begin(); it != M.end(); ++it) {
        if(it->second == sz && it->first.size() > count) {
            count = it->first.size();
            ret = it->first;
        }
    }

    return ret;*/
}
