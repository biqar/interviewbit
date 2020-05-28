//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

string get_space_padding(int n) {
    string ret = "";
    for(int i=0; i<n; i+=1) {
        ret += " ";
    }
    return ret;
}

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> len;
    vector<string> ret;
    int i, j, k, l, sn, tmp, pos, diff, sz = A.size();
    bool first, extra;
    string tmp_str;

    for(i=0; i<sz; i+=1) {
        len.push_back(A[i].size());
    }

    for(i=0,j=0; i<sz; i=k) {
        k = i;
        tmp = 0;
        first = true;
        while(k<sz) {
            if(first && (tmp + len[k] <= B)) {
                tmp += len[k];
                first = false;
            }
            else if(!first && (tmp + len[k] + 1 <= B)) {
                tmp += (len[k] + 1);
            }
            else {
                break;
            }
            k += 1;
        }

        first = true;
        diff  = B - tmp;
        pos = k - i - 1;
        tmp_str = "";
        for(l=i; l<k; l+=1) {
            if(first) {
                tmp_str += A[l];
                first = false;
            } else {
                if(k == sz) {
                    tmp_str += get_space_padding(1);
                    tmp_str += A[l];
                }
                else {
                    sn = 1;
                    if(diff > 0 && pos > 0) {
                        extra = false;
                        sn += (diff/pos);
                        if(diff%pos) {
                            sn += 1;
                            extra = true;
                        }
                        diff -= (diff/pos);
                        if(extra) diff -= 1;
                        pos -= 1;
                    }
                    tmp_str += get_space_padding(sn);
                    tmp_str += A[l];
                }
            }
        }
        if(tmp_str.length() == B) ret.push_back(tmp_str);
        else ret.push_back(tmp_str + get_space_padding(B - tmp_str.length()));
    }

    return ret;
}
