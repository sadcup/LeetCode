##Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

###Considerations

`DP`problem  

1. Define subproblems
2. Write down the recurrence that relates subproblems
3. Recognise and solve the base cases

###Ideas

- Define subproblems: `s(j~i)` is a palindromic string if `i==j` or `s(j+1 ~ i-1) is a palindromic string and s[i]==s[j]`
- Write down the recurrence:  

```cpp
if (s[j]==s[i] && (i-j<2||dp[j+1][i-1])) {
	dp[j][i] = true;
	//other codes to calculate the length
}
```

- Recognize and solve the base cases: none

###Reference

[A much more better solution on LeetCode.](https://leetcode.com/discuss/32204/simple-c-solution-8ms-13-lines)

The code base on the idea.  

- enumerate each character of stirng s
- jump duplicate characters instead of increasing one by one
- expand the local string at both sides
- update the maximal length and update the start index

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        for (int i=0; i<s.size(); ) {
            if (s.size()-1 <= maxLength/2) {
                break;
            }

			  // skip the duplicate characters            
            int j = i;
            int k = i;
            while (k < s.size() - 1 && s[k+1] == s[k]) {
                k++;
            }
            
            i = k + 1;
            
            // expand the local string
            while (k < s.size()-1 && j > 0 && s[k+1] == s[j-1]) {
                ++k;
                --j;
            }
            
            // max length and start index update
            int newLength = k - j + 1;
            
            if (newLength > maxLength) {
                start = j;
                maxLength = newLength;
            }
        }
        return s.substr(start, maxLength);
    }
};

```

