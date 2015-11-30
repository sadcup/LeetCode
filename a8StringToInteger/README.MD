##String to Integer (atoi)  
Implement atoi to convert a string to an integer.

**Hint:** Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

**Notes:** It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

###Considerations
- skip spaces
- sign process
- break when encountering illegal character
- check if over `INT_MAX` or `INT_MIN`

###Ideas
- Skip the first zero or several spaces
- Judge if a sign exists, `+` or `-`
- Loop from the begining to the end
	- break if s[i] is not between '0' and '9'  
	- check if `ret > INT_MAX/10` or `ret == INT_MAX/10 and str[i]-'0' > 7`
	- `ret = ret * 10 + s[i]-'0'`