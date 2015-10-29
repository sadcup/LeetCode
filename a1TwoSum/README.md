##1 Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

**Input**: `numbers={2, 7, 11, 15}`, `target=9`  
**Output**: `index1=1`, `index2=2`

###Idea
1. The initial idea: Binary search  

	- Sort the array first
	- Fix one value which travels the sorted array from left to right
	- Binary search the `target-val` in the "left" array
	- Find the original indices

2. An advanced idea  
	- Sort the array first
	- Set two indices locates at the head and tail of the array seperately
	- Increase the head if the sum of the two indexed value is small then the target, and decrease the tail if the sum is larger than the target, or return the indices if the sum is equal to the target  

3. Use unordered map  
	- Build an map
	- Fill a `val` into the map and search `target-val` at the same time

###Note
The idea 2 is the fastest one while it beats 89.81% of cpp submissions.
The idea 3 is most neatest.
 
