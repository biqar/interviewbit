# Largest Continuous Sequence Zero Sum

Asked in: [Microsoft](#)

## Problem Statement
Find the largest continuous sequence in a array which sums to zero.

Example:
```
Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}
```

**NOTE:** If there are multiple correct answers, return the sequence which occurs first in the array.

## Solution Approach
**todo: will update the solution approach later**

First of all, the naive solution will not work as the overall complexity will be very high i.e. O(n^2). 
The optimised one is even not very hard to device. The idea comes from `finding range sum from an immutable array` problem,
where we need to find the sum from different `range(i, j)`, where `i < j`. The idea of that problem is we can calculate
the prefix sum upto index `i`, where `0 <= i < n`. 

The idea is if the prefix sum upto index `j` occurred to any index `i` and if `i < j`, then the sum of the elements of
the sub-array from index `i` to `j` will be `0`. I used STL Map of `<sum, index>` pair to keep the already discovered 
`sum` at `index`.

Although the idea of this problem is simple, you may consider several tricky corner cases. For example,
1. We are keeping the sum upto index `i`, so we need to consider sum `0` before the index 0 (i.e. index -1).
2. It could be possible there is no such continuous sequence in the array which sums to zero.

I hope this will help you cracking this problem, Happy Coding!