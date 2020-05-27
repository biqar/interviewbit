### Largest Distance between nodes of a Tree

Asked in: [Facebook](#) [Google](#)

#### Find largest distance
Given an arbitrary unweighted rooted tree which consists of `N` (`2 <= N <= 40000`) nodes. The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree). The nodes will be numbered `0` through `N - 1`.

The tree is given as an array `P`, there is an edge between nodes `P[i]` and `i` (`0 <= i < N`). Exactly one of the `i`’s will have `P[i]` equal to `-1`, it will be root node.

Example: If given `P` is `[-1, 0, 0, 0, 3]`, then node `0` is the root and the whole tree looks like this:
```
          0
       /  |  \
      1   2   3
               \
                4
```

One of the longest path is `1 -> 0 -> 3 -> 4` and its length is `3`, thus the answer is `3`. Note that there are other paths with maximal distance.
