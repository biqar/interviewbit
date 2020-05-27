//
// Created by Islam, Abdullah Al Raqibul on 5/23/20.
//

const long long int inf = (((long long int)1<<(long long int)31) - 1);

int fib[50], fibLen;
// map<int, int> mp;
// queue<int> Q;

void genFib(long long int n) {
    fib[0] = 1;
    fib[1] = 1;

    int i;
    for(i=2; i<50; i+=1) {
        long long int cur = (long long int)fib[i-1] + (long long int)fib[i-2];
        if (cur > n) break;
        fib[i] = cur;
    }

    fibLen = i;
}

int greedy(int n) {
    int ret = 0;

    for(int i = fibLen-1; i>=0; i-=1) {
        if(fib[i] <= n) {
            while(n) {
                if(n - fib[i] < 0) break;
                n -= fib[i];
                ret += 1;
            }
        }
    }
    return ret;
}

// int bfs(long long int n) {
//     int i, j, k;
//     while(!Q.empty()) Q.pop();
//     mp.clear();

//     for(i=fibLen-1; i>=0; i-=1) {
//         if(fib[i] <= n) {
//             Q.push(fib[i]);
//             mp[fib[i]] = 1;
//         }
//         //else break;
//     }

//     while(!Q.empty()) {
//         long long int u = Q.front();
//         Q.pop();

//         if(u == n) return mp[u];

//         for(i=fibLen-1; i>=0; i-=1) {
//             long long int v = fib[i] + u;
//             if(v <= n && mp.find(v) == mp.end()) {
//                 if(v == n) return mp[u] + 1;
//                 Q.push(v);
//                 mp[v] = mp[u] + 1;
//             }
//         }
//     }
//     return -1;
// }

int Solution::fibsum(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    genFib(A);
    //return bfs(A);
    return greedy(A);
}
