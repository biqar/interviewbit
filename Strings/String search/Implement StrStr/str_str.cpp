//
// Created by Islam, Abdullah Al Raqibul on 5/28/20.
//

//todo: getting a Compilation Error now, but solved and scored it previously

int Solution::strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int lh = haystack.size(), ln = needle.size();
    int i, j, k;

    if(lh == 0 || ln == 0) return -1;

    for(i=0; i<=lh-ln; i+=1) {
        for(j=0; j<ln; j+=1) {
            if(haystack[i+j] != needle[j]) break;
        }
        if(j == ln) return i;
    }

    return -1;
}
