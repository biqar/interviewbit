//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

string pal_string(string s, int st, int nd, int sz) {
    int i;

    while(st>=0 && nd<sz && s[st]==s[nd]) {
        st -= 1;
        nd += 1;
    }

    return s.substr(st+1, nd-st-1);
}

string Solution::longestPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, k, sz = A.size();
    string ret = "";

    for(i=0; i<sz; i+=1) {
        string tmp = pal_string(A, i, i, sz);
        if(tmp.size() > ret.size()) ret = tmp;

        tmp = pal_string(A, i, i+1, sz);
        if(tmp.size() > ret.size()) ret = tmp;
    }
    return ret;
}
