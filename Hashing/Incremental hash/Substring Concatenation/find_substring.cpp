//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sz = B.size(), len = A.size(), l, i, j, k;
    vector<int > ret;
    map<string, int > cntM;

    if(sz == 0) return ret;
    l = B[0].size();

    for(i=0; i<sz; i+=1) {
        cntM[B[i]] += 1;
    }

    for(i=0; i<len-((sz*l)-1); i+=1) {
        map<string, int > m;
        j = 0;
        while(j < sz) {
            string subStr = A.substr(i+(j*l), l);
            if(cntM.find(subStr) == cntM.end()) break;
            m[subStr] += 1;
            if(m[subStr] > cntM[subStr]) break;
            j += 1;
        }
        if(j == sz) ret.push_back(i);
    }
    return ret;
}
