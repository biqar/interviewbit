# Equal

Asked in: [Facebook](#)

## Problem Statement
Given an array A of integers, find the index of values that satisfy `A + B = C + D`, where `A`,`B`,`C` & `D` are integers values in the array

Note:
```
1) Return the indices "A1 B1 C1 D1", so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
```

Example:
```
Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
```

If no solution is possible, return an empty list.

## Solution Approach
**todo: will update the solution approach later**

1. If we store all the possible solutions and then sort that list before returning the "lexicographical smallest" one, then it will get MLE.
2. If we keep all possible `A` and `B` for a `sum`, and then check the all possible `C` and `D`, it will give TLE
3. Optimal runtime solution will be the one where we choose the smallest possible `A` and `B` and then look for all possible `C` and `D`, both in lexicographical order.

I hope this will help you cracking this problem, Happy Coding!
