### Ways to Decode

Asked in: [Facebook](#) [Amazon](#)

A message containing letters from `A-Z` is being encoded to numbers using the following mapping:
```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```
Given an encoded message containing digits, determine the total number of ways to decode it.

Input Format:
```
The first and the only argument is a string A.
```

Output Format:
```
Return an integer, representing the number of ways to decode the string.
```

Constraints:
```
1 <= length(A) <= 1e5
```

Example :
```
Input 1:
    A = "8"

Output 1:
    1

Explanation 1:
    Given encoded message "8", it could be decoded as only "H" (8).

    The number of ways decoding "8" is 1.

Input 2:
    A = "12"

Output 2:
    2

Explanation 2:
    Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
    
    The number of ways decoding "12" is 2.
```