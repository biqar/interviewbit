//
// Created by aislam6 on 12/15/19.
//

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval a, Interval b) {
    if(a.start > b.start) return false;
    else if (a.start == b.start) {
        return a.end < b.end;
    }
    return true;
}

int _max(int a, int b) {
    return a > b ? a : b;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, j, sz = intervals.size() + 1;
    bool flg = false;
    vector<Interval> ret;

    if(newInterval.start > newInterval.end) {
        i = newInterval.start;
        newInterval.start = newInterval.end;
        newInterval.end = i;
    }

    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), comp);
    ret.push_back(intervals[0]);
    for(i=1,j=0; i<sz; i+=1) {
        if(intervals[i].start > ret[j].end) {
            ret.push_back(intervals[i]);
            j += 1;
        }
        else {
            ret[j].end = _max(intervals[i].end, ret[j].end);
        }
    }

    return ret;
}
