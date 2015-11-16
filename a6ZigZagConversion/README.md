##6 ZigZag Conversion
The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
	
And then read line by line: `"PAHNAPLSIIGYIR"`  
Write the code that will take a string and make this conversion given a number of rows:

	string convert(string text, int nRows);
	
`convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.

###Consideration
- The number of lines which are not *full* equals to nRows-2
- The number of each cell is 2*nRows-2  
- For the first and last row, only one character should be appended
- For other rows, 2 characters should be appended
- Loop every row and process each cell
	- logic for first and last row is `j=i, j+=numEle`
	- logic for other rows ar `j1=i, j2=numEle-i`, `j1+=numEle, j2+=numEle`

###Ideas

- Loop every row with the index of `i`
	- if row is the first or the last row, append one character into the result with the index start from `i` and an increasing step of `numEle`
	- if other rows, append two(may be one) characters into the result with the index1 start from `i` and an increasing step of `numEle`, index2 start from `numEle-i` and the same step


