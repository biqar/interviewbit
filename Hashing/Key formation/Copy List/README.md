# Copy List

Asked in: [Amazon](#) [Microsoft](#)

## Problem Statement
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or `NULL`.

Return a deep copy of the list.

Example

Given list
```
   1 -> 2 -> 3
```
with random pointers going from
```
  1 -> 3
  2 -> 1
  3 -> 1
```
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

## Solution Approach
**todo: will update the solution approach later**

Solution Idea [1]:
- Using Map <Original_LL_Node, Copy_LL_Node>
- Easy to implement, but need extra space for Map

Solution Idea [2]:
- Put copy nodes in between the input chain, copy the `random` pointers, and finally decoupling the copy LL.
- Hard to implement, but use no extra space.

I hope this will help you cracking this problem, Happy Coding!