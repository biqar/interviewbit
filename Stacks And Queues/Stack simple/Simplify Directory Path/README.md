### Evaluate Expression

Asked in: [Microsoft](#)

Given a string `A` representing an absolute path for a file (Unix-style). Return the string `A` after simplifying the absolute path.

**Note:**
1. Absolute path always begin with ’/’ ( root directory ).
2. Path will not have whitespace characters.

Input Format
```
The only argument given is string A.
```

Output Format
```
Return a string denoting the simplified absolue path for a file (Unix-style).
```

For Example
```
Example 1:
Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:
Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:
Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:
Input: "/a/./b/../../c/"
Output: "/c"

Example 5:
Input: "/a/../../b/../c//.//"
Output: "/c"

Example 6:
Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
```

LeetCode Problem Link: https://leetcode.com/problems/simplify-path/