//
// Created by Islam, Abdullah Al Raqibul on 5/22/20.
//

int Solution::chordCnt(int A) {
    long long int mod = 1000000007;
    if(A == 0) return 1;
    long long int table[A + 5];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    table[1] = 1;
    for(int i = 2; i <= A; i+=1) {
        for(int j = 0; j < i; j+=1) {
            table[i] += ((table[j]%mod) * (table[i - 1 - j]%mod))%mod;
            table[i] %= mod;
        }
    }
    return table[A];
}