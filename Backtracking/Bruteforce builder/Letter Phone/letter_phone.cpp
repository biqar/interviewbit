//
// Created by aislam6 on 12/16/19.
//

vector<string> ret;

bool is_break_point(char ch) {
    if(ch == 'c' || ch == 'f' || ch == 'i' || ch == 'l'
       || ch == 'o' || ch == 's' || ch == 'v' || ch == 'z') {
        return true;
    }
    return false;
}

void retrive_digit_string(string str, string res, map<char, vector<char>> m, int pos, int sz) {
    if(pos == sz) {
        ret.push_back(res);
        return;
    }

    vector<char> v = m[str[pos]];
    int len = v.size();
    for(int i=0; i<len; i+=1) {
        retrive_digit_string(str, res+v[i], m, pos+1, sz);
    }
}

vector<string> Solution::letterCombinations(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<char> v;
    map<char, vector<char>> m;
    int button = 2;

    v.push_back('0');
    m['0'] = v;
    v.clear();

    v.push_back('1');
    m[(char)(1 + '0')] = v;
    v.clear();

    for(char i='a'; i<='z'; i+=1) {
        v.push_back(i);
        if(is_break_point(i)) {
            m[(char)(button + '0')] = v;
            v.clear();
            button += 1;
        }
    }

    ret.clear();
    retrive_digit_string(A, "", m, 0, A.size());
    return ret;
}