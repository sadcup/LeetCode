##4 Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

###Considerations

- Just find the kth element of the two arrays or find the median of kth and k+1th.

###Ideas
- If m + n % 2 != 0, return the (m+n)/2+1 th element of the two arrays
- otherwise return the mean value of (m+n)/2 th and (m+n)/2+1 th element of the two arrays

