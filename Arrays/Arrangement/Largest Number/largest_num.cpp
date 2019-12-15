//
// Created by aislam6 on 12/15/19.
//

bool comp(string a, string b) {
    return a+b > b+a;
}

string remove_padding_zeros(string a) {
    if (a.size() > 0) {
        if(a[0] == '0') {
            return "0";
        }
    }
    return a;
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string ret = "";
    int sz = A.size();
    vector<string> SA;

    for(int i=0; i<sz; i+=1) {
        SA.push_back(std::to_string(A[i]));
    }

    sort(SA.begin(), SA.end(), comp);
    for(int i=0; i<sz; i+=1) {
        ret += SA[i];
    }

    return remove_padding_zeros(ret);
}
