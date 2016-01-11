# 13 Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question

###Considerations
[Rules](https://en.wikipedia.org/wiki/Roman_numerals)

- Iterate from right to left
	- Set a max indicator to be the last maximal signle value
	- For the current number, if it is above or equal to the last max value, add it into the result, or vise visa

###Ideas

- Build a map to store the value of the characters
- Initialize the max value to be zero
- Loop from right to left
	- Update the max value if the current value is smaller than max
	- Add/Substrate the value to the result 