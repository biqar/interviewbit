//
// Created by aislam6 on 11/27/19.
//

bool is_prime(int a) {
    for(int i=2; i*i<=a; i+=1) {
        if(a % i == 0) return false;
    }

    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> ret;
    for(int i=2; i<=(A/2)+1; i+=1) {
        if(is_prime(i) && is_prime(A-i)) {
            ret.push_back(i);
            ret.push_back(A-i);
            break;
        }
    }
    return ret;
}
