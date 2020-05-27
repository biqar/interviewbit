//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

long long int _abs(long long int a) {
    return a < 0 ? -a : a;
}

string num_to_string(long long int a) {
    ostringstream convert;
    convert << a;
    return convert.str();
}

string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(numerator == 0 || denominator == 0) return "0";

    bool minus = false;
    map<long long int, int> mod;
    vector<long long int> res;
    int i, j, k;
    int pos = -1;
    string ret = "";
    long long int a, b, m;

    if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)) minus = true;
    a = _abs(numerator);
    b = _abs(denominator);

    i = 0;
    while(true) {
        res.push_back(a / b);
        m = a % b;

        if(!m) break;
        if(mod.find(m) != mod.end()) {
            pos = mod[m];
            break;
        }
        mod[m] = i;
        i += 1;
        a = m * 10;
    }

    k = res.size();
    if(k == 1) {
        ret = num_to_string(res[0]);
    } else {
        ret = num_to_string(res[0]) + ".";

        for(i=1; i<k; i+=1) {
            if(pos+1 == i) ret += "(";
            ret += num_to_string(res[i]);
        }
        if(pos != -1) ret += ")";
    }

    return minus == true ? "-" + ret : ret;
}
