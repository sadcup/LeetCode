#11. Container With Most Water  
> Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.  
Note: You may not slant the container.

###Considerations
- It is too complicated if the algorithm peforms O(n2)
- We can assume that once the maximal area occurs, the left line is lower than the right line
- increase left if the left line is lower than the right
- decrease right if the left line is higher than the left

###Ideas
- Set indices both for left and right
- loop while left < right
	- calculate the current area and set it to be ret if needed
	- update the maximal value from the begining to the left index
	- update the maximal value from the right to the end
	- increase if left maximal value is less than the right one and vise visa