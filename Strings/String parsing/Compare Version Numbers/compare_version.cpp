//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

string remove_leading_zeros(string str) {
    int i, sz = str.size();
    for(i=0; i<sz; i+=1) {
        if (str[i] != '0') break;
    }

    if(i == sz) return "0";
    return str.substr(i);
}

int check_greater(string a, string b) {
    int l1 = a.size(), l2 = b.size();
    if(l1 > l2) return 1;
    if(l1 < l2) return -1;

    if(a > b) return 1;
    if(a < b) return -1;
    return 0;
}

int _min(int a, int b) {
    return a < b ? a : b;
}

int Solution::compareVersion(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int l1 = A.size(), l2 = B.size();
    int i, j, k;
    vector<string> a, b;
    string tmp;

    for(i=0; i<l1; i+=1) {
        if(A[i] == '.') A[i] = ' ';
    }
    for(i=0; i<l2; i+=1) {
        if(B[i] == '.') B[i] = ' ';
    }
    stringstream sa(A);
    stringstream sb(B);

    while(sa >> tmp) {
        a.push_back(tmp);
    }

    while(sb >> tmp) {
        b.push_back(tmp);
    }

    l1 = a.size(), l2 = b.size();
    for(i=0; i<_min(l1, l2); i+=1) {
        string sa = remove_leading_zeros(a[i]);
        string sb = remove_leading_zeros(b[i]);
        if(check_greater(sa, sb) == 1) return 1;
        if(check_greater(sa, sb) == -1) return -1;
    }

    if(l1 > l2) {
        for(i=l2; i<l1; i+=1) {
            string sa = remove_leading_zeros(a[i]);
            if(sa != "0") return 1;
        }
        return 0;
    }

    if(l1 < l2) {
        for(i=l1; i<l2; i+=1) {
            string sb = remove_leading_zeros(b[i]);
            if(sb != "0") return -1;
        }
        return 0;
    }

    return 0;
}
