#Integer to Roman

Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

###Considerations
[Rules](https://en.wikipedia.org/wiki/Roman_numerals)  

With a fixed quantitative level, such as 10, 100, 1000. 3 letters are used to construct a number, which could be denoted as c1, c2, c3.

- n < 4, 1~n c1
- n = 4, c1, c2
- n > 4 and n < 9, c2, 1~(n-5)c1
- n = 9, c1, c3

###Ideas

- As the number is being within the range from 1 to 3999, 4 levels
- For each level from top to down, the 3 letters are `M??`, `CDM`, `XLC`, `IVX`
- Check each level and append it into the result