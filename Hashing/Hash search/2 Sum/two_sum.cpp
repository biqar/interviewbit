//
// Created by Islam, Abdullah Al Raqibul on 5/29/20.
//

// update the index_1 and index_2 according to the folllowing rule:
//  - If multiple solutions exist, output the one where index2 is minimum.
void update_interval(int &cur_1, int &cur_2, int new_1, int new_2) {
    if(new_2 < cur_2) {
        cur_1 = new_1;
        cur_2 = new_2;
    }
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    map<int, vector<int>> m;
    int sz = A.size();
    int idx_1 = sz, idx_2 = sz;
    vector<int> ret;

    for(int i=0; i<sz; i+=1) {
        m[A[i]].push_back(i+1);
    }

    // note: the following loop will run to search for the first index
    for(int i=0; i<sz; i+=1) {
        if(m.find(B-A[i]) != m.end()) {
            // case: 4 = 2 + 2
            if(A[i] == B-A[i]) {
                if(m[A[i]].size() >= 2) {
                    update_interval(idx_1, idx_2, m[A[i]][0], m[A[i]][1]);
                }
            } else {
                // as noted earlier, loop on "i" runs to find the first index
                // and problem statement clarify "index1 < index2"
                if(m[B-A[i]][0] > i+1) {
                    update_interval(idx_1, idx_2, i+1, m[B-A[i]][0]);
                }
            }
        }
    }

    if(idx_1 != sz && idx_2 != sz) {
        ret.push_back(idx_1);
        ret.push_back(idx_2);
    }

    return ret;
}
