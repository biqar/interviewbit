//
// Created by Islam, Abdullah Al Raqibul on 5/30/20.
//

// Solution using two pointer

/*int Solution::diffPossible(const vector<int> &A, int B) {
    vector<int> vec = A;
    sort(vec.begin(), vec.end());
    int sz = A.size();

    if(sz < 2) return 0;

    int i = 0, j = 1;
    while(i<sz && j<sz && i<j) {
        if(vec[j]-vec[i] == B) return 1;
        if(vec[j]-vec[i] < B) j += 1;
        if(vec[j]-vec[i] > B) i += 1;
    }

    return 0;
}*/

// Solution using STL lower_bound feature
int Solution::diffPossible(const vector<int> &vec, int B) {
    vector<int> A = vec;
    std::sort(A.begin(), A.end());
    int sz = A.size();

    for(int i=i; i<sz; i+=1) {
        int lookup = B + A[i];
        std::vector<int>::iterator low = lower_bound(A.begin(), A.end(), lookup);
        if(low != A.end() && A[low - A.begin()] == lookup) {
            if(B) return 1;
            else {
                if((low - A.begin() + 1 < sz)
                   && (A[low - A.begin()] == A[low - A.begin() + 1])) return 1;
            }
        }
    }

    return 0;
}

// MLE
/*int Solution::diffPossible(const vector<int> &A, int B) {
    map<int, vector<int> > m;
    int sz = A.size();

    for(int i=0; i<sz; i+=1) {
        if(m.find(A[i]) == m.end() || m[A[i]].size() == 1) m[A[i]].push_back(i);
    }

    for(int i=0; i<sz; i+=1) {
        int sum = B + A[i];
        if(m.find(sum) != m.end()) {
            if(B) {
                return 1;
            } else {
                if(m[sum].size() > 1) return 1;
            }
        }
    }

    return 0;
}
*/