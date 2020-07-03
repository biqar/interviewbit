# Word Ladder II

Asked in: [Google](#) | [Microsoft](#) | [Ebay](#)

## Problem Statement
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, such that:

1. Only one letter can be changed at a time
2. Each intermediate word must exist in the dictionary

If there are multiple such sequence of shortest length, return all of them. Refer to the example for more details.

Note:
1. All words have the same length.
2. All words contain only lowercase alphabetic characters.

Input Format
```
The first argument is string start.
The second argument is string end.
The third argument is an array of strings dict
```
Output Format
```
Return all transformation sequences such that first word of each sequence is start and last word is end, all intermediate words belongs to dictionary(dict) and consecutive words had atmost 1 difference.  
```

Example :
```
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
```
Return
```
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
```

## Solution Approach
**todo: will update the solution approach later**
Leetcode: https://leetcode.com/problems/word-ladder-ii/
Note: this solution get TLE on the similar problem at leetcode.

I hope this will help you cracking this problem, Happy Coding!