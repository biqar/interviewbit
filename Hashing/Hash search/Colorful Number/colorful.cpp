//
// Created by Islam, Abdullah Al Raqibul on 5/27/20.
//

int Solution::colorful(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    char str[20];
    sprintf(str, "%d", A);
    int len = strlen(str), i, j, tmp;
    map<int, bool> m;

    for(i=0; i<len; i+=1) {
        tmp = 1;
        for(j=i; j<len; j+=1) {
            tmp *= (str[j] - '0');

            if(m.find(tmp) != m.end()) return 0;
            m[tmp] = true;
        }
    }
    return 1;
}
