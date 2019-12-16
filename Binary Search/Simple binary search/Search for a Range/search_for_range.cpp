//
// Created by aislam6 on 12/16/19.
//

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int st = -1, nd = -1;
    int l = 0, h = A.size()-1, mid;
    vector<int> ret;

    while(h-l > 1) {
        //cout << l << " " << h << endl;
        mid = l + ((h-l)/2);

        if(A[mid] > B) {
            h = mid;
        } else if (A[mid] < B) {
            l = mid;
        } else {
            h = mid;
        }
    }
    //cout << A[l] << endl;
    if(A[l] == B) st = l;
    else if (A[l+1] == B) st = l + 1;

    l = 0, h = A.size()-1;
    while(h-l > 1) {
        mid = l + ((h-l)/2);

        if(A[mid] > B) {
            h = mid;
        } else if (A[mid] < B) {
            l = mid;
        } else {
            l = mid;
        }
    }
    if(A[h] == B) nd = h;
    else if (A[h-1] == B) nd = h - 1;

    ret.push_back(st);
    ret.push_back(nd);

    return ret;
}
