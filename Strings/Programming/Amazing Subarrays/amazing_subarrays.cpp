//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

#define MOD 10003

bool is_vowel(const char ch) {
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
       || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;

    return false;
}

int Solution::solve(string A) {
    int sz = A.size();
    int ret = 0;

    for(int i=0; i<sz; i+=1) {
        if(is_vowel(A[i])) {
            ret += (sz - i);
            if(ret > MOD) ret %= MOD;
        }
    }

    return ret;
}
