##2 Add Two Numbers
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: `(2 -> 4 -> 3) + (5 -> 6 -> 4)`  
Output: `7 -> 0 -> 8`

###Consideration
1. `l1` or `l2` is maybe NULL
2. `l1` and `l2` can be with different length
3. The result list's length is equal to `max(length(l1), length(l2))` or `max(length(l1), length(l2)) + 1`
4. The "next one" is the one who is not NULL

###Ideas  
- Return `l1` if `l2` is NULL and vice visa
- Set the `ret` to be `l1` and update the `val` and `add`
- Make a `node` to trversal the whole new list  
- Loop until `l1` and `l2` both equals to NULL
	- Update the current node's (tmp) `val` and `add`
	- Increase `l1` and `l2` if needed
- If `add` is not zero, insert another new node at the back

