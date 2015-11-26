#Reverse Integer

Reverse digits of an integer.

Example1: `x = 123`, return `321`  
Example2: `x = -123`, return `-321`  

###Considerations
- minus maybe
- zeros tailing maybe
- the reversed integer may be larger than `INT_MAX` or less than `INT_MIN`

###Idea1
- Using a `long` variable to calculate  

###Idea2
- Using a `int` variable to calculate and judge if the result beyonds `INT_MAX `or `INT_MIN`