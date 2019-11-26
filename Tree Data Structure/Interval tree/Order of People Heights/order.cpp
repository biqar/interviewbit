//
// Created by Islam, Abdullah Al Raqibul on 11/26/19.
//

struct person {
    int h, i;

    person(int _h, int _i) {
        h = _h;
        i = _i;
    }
};

struct Tree {
    int tot, pos;
} T[1000000];

bool comp(person a, person b) {
    return a.h < b.h;
}

void init(int Node, int lft, int rgt) {
    if(lft == rgt) {
        T[Node].tot = 1;
        T[Node].pos = lft;
        return;
    }
    int mid = (lft + rgt) / 2;
    init(2*Node, lft, mid);
    init(2*Node+1, mid+1, rgt);

    T[Node].tot = T[2*Node].tot + T[2*Node+1].tot;
}

int query(int Node, int lft, int rgt, int cnt, int pos) {
    Tree L, R;

    //cout << "Node = " << Node << ", Left = " << lft << ", Right = " << rgt << ", Cnt = " << cnt << ", Pos = " << pos << endl;
    //cout << "Left Total = " << T[2*Node].tot << ", Right Total = " << T[2*Node+1].tot << endl;

    if(lft == rgt) {
        return cnt+T[Node].tot == pos ? T[Node].pos : -1;
    }

    int mid = (lft + rgt) / 2;
    if(cnt+T[2*Node].tot >= pos) {
        return query(2*Node, lft, mid, cnt, pos);
    }
    else {
        return query(2*Node+1, mid+1, rgt, cnt+T[2*Node].tot, pos);
    }
}

void update(int Node, int lft, int rgt, int pos) {
    if(lft == rgt && T[Node].pos == pos) {
        T[Node].tot = 0;
        return;
    }

    int mid = (lft + rgt) / 2;
    if(pos <= mid) update(2*Node, lft, mid, pos);
    else update(2*Node+1, mid+1, rgt, pos);
    T[Node].tot = T[2*Node].tot + T[2*Node+1].tot;
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, cnt, sz = heights.size();
    vector<person> v;
    vector<int> ret(sz, -1);

    for(i=0; i<sz; i+=1) {
        v.push_back(person(heights[i], infronts[i]));
    }

    sort(v.begin(), v.end(), comp);

    init(1, 0, sz-1);

    for(i=0; i<sz; i+=1) {
        cnt = 0;
        /*for(j=0; j<sz; j+=1) {
            if(ret[j] == -1) cnt += 1;
            if(cnt == v[i].i + 1) break;
        }*/
        //cout << "Value = " << v[i].h << endl;
        j = query(1, 0, sz-1, 0, v[i].i+1);
        //cout << "J = " << j << endl;
        ret[j] = v[i].h;
        update(1, 0, sz-1, j);
    }

    return ret;
}