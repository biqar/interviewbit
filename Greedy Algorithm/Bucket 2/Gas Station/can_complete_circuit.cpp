//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int sumRemaining = 0; // track current remaining
    int total = 0; // track total remaining
    int start = 0;

    for (int i = 0; i < gas.size(); i++) {
        int remaining = gas[i] - cost[i];

        //if sum remaining of (i-1) >= 0, continue
        if (sumRemaining >= 0) {
            sumRemaining += remaining;
            //otherwise, reset start index to be current
        } else {
            sumRemaining = remaining;
            start = i;
        }
        total += remaining;
    }
    return total >= 0 ? start : -1;
}
