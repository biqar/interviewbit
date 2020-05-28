//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i, sz = A.size();
    int a, b;
    stack<int> s;

    for(i=0; i<sz; i+=1) {
        if(A[i] == "+") {
            a = b = 0;
            if(!s.empty()) {
                a = s.top();
                s.pop();
            }

            if(!s.empty()) {
                b = s.top();
                s.pop();
            }

            s.push(a+b);
        }
        else if (A[i] == "-") {
            a = b = 0;
            if(!s.empty()) {
                a = s.top();
                s.pop();
            }

            if(!s.empty()) {
                b = s.top();
                s.pop();
            }

            s.push(b-a);
        }
        else if (A[i] == "*") {
            a = b = 0;
            if(!s.empty()) {
                a = s.top();
                s.pop();
            }

            if(!s.empty()) {
                b = s.top();
                s.pop();
            }

            s.push(a*b);
        }
        else if (A[i] == "/") {
            a = b = 0;
            if(!s.empty()) {
                a = s.top();
                s.pop();
            }

            if(!s.empty()) {
                b = s.top();
                s.pop();
            }

            s.push(b/a);
        }
        else {
            s.push(stoi(A[i]));
        }
    }

    if(!s.empty()) return s.top();
    return 0;
}
