//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

//todo: solution got TLE, need to optimize it

string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, sz = A.size();
    string str, ret;
    stack<string> s;
    int cnt;

    for(i=0; i<sz-1; ) {
        if(A[i] == '/' && A[i+1] == '/') {
            A.erase(i, 1);
        } else {
            i += 1;
        }
    }

    if(A[A.size() - 1] != '/') A = A + "/";

    str = "";
    cnt = 0;
    sz = A.size();
    for(i=0; i<sz; i+=1) {
        if(A[i] == '/') {
            cnt += 1;
        }

        if(cnt == 1) {
            str += A[i];
        }
        else if (cnt == 2) {
            if(str == "/.." && !s.empty()) {
                s.pop();
            }
            if(str != "/." && str != "/..") {
                s.push(str);
            }
            str = "/";
            cnt = 1;
        }
    }

    if(s.empty()) return "/";
    ret = "";
    while(!s.empty()) {
        ret = s.top() + ret;
        s.pop();
    }

    return ret;
}
