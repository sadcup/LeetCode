## 3 Longest Substring Without Repeating Characters  
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

###Considerations
- Using unordered_map to find one element from the sink.  
- Do not forget the characters behind the recent judged repeating character

###Ideas  

s   		|a    | b   | c   | a   | b   | c   | b   | b
:--- 		| --- | --- | --- | --- | --- | --- | --- | ---
i			|0    | 1   | 2   | 3   | 4   | 5   | 6   | 7
counter   |1    | 2   | 3   | 3   | 3   | 3   | 2   | 1
ret    	|1    | 2   | 3   | 3   | 3   | 3   | 3   | 3

- Make a sink using unordered_map, while the key is character and the value is the recent index of the character  
- For each character in s (using `i` as the index) 
	- If it does not appear in sink or it appears before `i - counter`(which means it is not in the considered range), increase the `counter` and insert 	it to the sink
	- If it exists in the sink, update the counter to be `i - sink[s[i]]` and update the `ret` value
	- Do not forget to update `ret` at last