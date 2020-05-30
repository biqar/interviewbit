# 2 Sum

Asked in: [Facebook](#) [Amazon](#) [Google](#)

## Problem Statement
Given an array of integers, find two numbers such that they add up to a specific target number.

The function `twoSum` should return indices of the two numbers such that they add up to the target, where `index1 < index2`. Please note that your returned answers (both `index1` and `index2`) are not zero-based. 
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If `multiple solutions` exist, output the one where `index2` is minimum. If there are multiple solutions with the minimum `index2`, choose the one with minimum `index1` out of them.

```
Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
```

## Solution Approach
**todo: will update the solution approach later**

Tricky cases,
1. Corner case: 2 + 2 = 4, we need to confirm we have two 2s in the input array.
2. Tie breaking case: If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

I hope this will help you cracking this problem, Happy Coding!