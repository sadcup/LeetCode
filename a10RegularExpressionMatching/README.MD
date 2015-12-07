##Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.  
'*' Matches zero or more of the preceding element.  

The matching should cover the entire input string (not partial).  

The function prototype should be:  
`bool isMatch(const char *s, const char *p)`

```
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```

###Considerations
- Pay attention to the `*`, it matches 0 or n of the preceding element, that is why te last example gives a true result(0 c 2 a 1 b)
- If an `*` occurs, we should consider 2 cases: matching or skip

###Ideas
- Check if the next element is `*`
	- Check if the current element matches
	- Preceed the match to s+1 and p+1
- If the current singular element matches
	- Preceed the match to s and p+2
- Neither of the two above, `*` makes the function of 0
	- Preceed the match to s and p+2 