//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int Solution::seats(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = A.size();
    int ans = 0;
    deque<pair<int, int> > q;
    pair<int, int> lft, rgt;
    int ll, lr;

    i = 0;
    while(i < sz) {
        while(i<sz && A[i] == '.') i += 1;

        if(i == sz) break;

        j = i;
        while(j<sz && A[j] == 'x') j += 1;

        q.push_back(make_pair(i, j-1));
        i = j;
    }

    while(q.size() > 1) {
        lft = q.front();
        rgt = q.back();

        ll = lft.second - lft.first + 1;
        lr = rgt.second - rgt.first + 1;

        if(ll <= lr) {
            q.pop_front();
            ans += ((ll%10000003) * ((q.front().first - lft.second - 1)%10000003)) % 10000003;
            ans %= 10000003;
            q.front().first -= ll;
        }
        else {
            q.pop_back();
            ans += ((lr%10000003) * ((rgt.first - q.back().second - 1)%10000003)) % 10000003;
            ans %= 10000003;
            q.back().second += lr;
        }
    }

    return ans % 10000003;
}
