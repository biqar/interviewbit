# Next Pointer Binary Tree

Asked in: [Microsoft](#) [Amazon](#)

## Problem Statement
Given a binary tree
```
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

Note:
1. You may only use constant extra space.
2. You may assume that it is a perfect binary tree (i.e., all leaves are at the same level, and every parent has two children).

Example :

Given the following perfect binary tree,
```
         1
       /  \
      2    5
     / \  / \
    3  4  6  7
```
After calling your function, the tree should look like:
```
         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL
```

Note that using recursion has memory overhead and does not qualify for constant space.

## Solution Approach
**todo: will update the solution approach later**

Solution Idea [1]:
- traverse the tree in level order and set the next pointer properly
- advantage: it will work whether the binary tree is a perfect binary tree or not
- issue: need extra space to maintain queue
    
Solution Idea [2]:
- traverse the tree in in-order and set the next pointer properly.
- this solution will work because we will set the next pointer of parent before going for the left and right children.
- so the next pointer logic will be like this,
    - `current->left->next = current->right`
    - `current->right->next = current->next->left`
- advantage: it will not take any extra space
- issue: it will not work if the binary tree is not perfect

I hope this will help you cracking this problem, Happy Coding!