# NEXTGREATER

Asked in:

## Problem Statement
Given an array, find the next greater element G[i] for every element A[i] in the array. The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 
More formally,
```
G[i] for an element A[i] = an element A[j] such that 
    j is minimum possible AND 
    j > i AND
    A[j] > A[i]
```
Elements for which no greater element exist, consider next greater element as -1.

Example 1:
```
Input : A : [4, 5, 2, 10]
Output : [5, 10, 10, -1]
```
Example 2:
```
Input : A : [3, 2, 1]
Output : [-1, -1, -1]
```
## Solution Approach
**todo: will update the solution approach later**

Solution Idea [1]:
- For every element, search for the next greater element
- Issue: Complexity O(N^2)
    
Solution Idea [2]:
- Use a stack to maintain ...

I hope this will help you cracking this problem, Happy Coding!