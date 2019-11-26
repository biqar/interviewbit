### Distinct Numbers in Window

Asked in: [Amazon](#)

You are given an array of N integers, A<sub>1</sub>, A<sub>2</sub> ,…, A<sub>N</sub> and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence A<sub>i</sub>, A<sub>i+1</sub> ,…, A<sub>i+k-1</sub>.

Note:
```
 If K > N, return empty array.
 A[i] is a signed integer
```
For example,
```
A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
```