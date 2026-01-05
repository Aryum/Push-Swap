# Push swap
A program that takes multiple numbers and organizes them in ascending order. But only using two stacks and only having a few moves available. Meant to make us learn about sorting algorithms and adapt them to our needs.

The program was not about computing power efficiency but to organize the numbers in the fewest moves possible.

# Requirements
For this exercise we only had two stacks available we will call them A and B. At the end of the program we are supposed to have all the numbers organized in stack A. 

For it we have a limited amount of moves that we can use, printing in the terminal the executed move:

- Rotate A **_(RA)_**
- Rotate B **_(RB)_**
- Rotate Both **_(RR)_**
- Reverse Rotate A **_(RRA)_**
- Reverse Rotate B **_(RRB)_**
- Reverse Rotate Both **_(RRB)_**
- Swap A **_(sa)_**
- Swap B **_(sb)_**
- Swap Both **_(ss)_**
- Push A **_(pa)_**
- PusH B **_(pb)_**

The exercise was graded depending on the amount of moves needed to sort them.

# My solution
I decided to take a divide and conquer approach dividing the numbers in chunks pushing them to the stack B starting with the lower numbers and then pushing them back in a sorted way. 

Even if this approach was already very effective we can do it better by doing some optimisations:
- Pushing the chunks two by two, pushing the lower chunk to the end of stack B
- When pushing the numbers back checking if is faster to push the one after it first and then do a swap
- Checking what rotation it would be faster to push a number to the other stack
- Checking if we can do the same move in both stacks
