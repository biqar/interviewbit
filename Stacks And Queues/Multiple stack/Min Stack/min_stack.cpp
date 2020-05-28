//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

const long long int VAL = (long long int) 1 << 60;
vector<int> s;
long long int minVal = (long long int) 1 << 60;

MinStack::MinStack() {
    minVal = VAL;
    s.clear();
}

void MinStack::push(int x) {
    if(x < minVal) minVal = x;
    s.push_back(x);
}

void MinStack::pop() {
    if(s.empty()) return;

    if(s.back() == minVal) {
        minVal = VAL;
        int sz = s.size();
        for(int i=0; i<sz-1; i+=1) {
            if(s[i] < minVal) minVal = s[i];
        }
    }

    //if(minVal == (long long int) 1 << 60) minVal = -1;
    s.pop_back();
}

int MinStack::top() {
    if(!s.empty()) return s.back();
    return -1;
}

int MinStack::getMin() {
    if(minVal == VAL) return -1;
    return minVal;
}