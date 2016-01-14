#3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

**Note**:  
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
    

###Considerations

- Pay attention to the duplicate cases


###Ideas

- Sort the vector first
- Loop from begin(0) to end(n-3) with index of i
	- Assume a new target to be -nums[i]
	- Set a left and right index to be initialised as i+1 and n-1
		- Increase left if `nums[left] + nums[right] < target`
		- Decrease right if `nums[left] + nums[right] > target`
		- Push back `{nums[i], nums[left], nums[right]}` to the result if `nums[left]+nums[right]==target`
			- Increase left to the non-duplicate index
			- Decrease right to the non-duplicate index
	- Increase i to the non-duplicate index