# Dynamic Programming

## Defination:- 
Dynamic Programming is mainly an optimization over plain recursion by which we can reduce the time complexity by trading with time and space complexities.

### Recursion + Memoization = Dynamic Programming

### We just convert that memoized version of recursion into iteration by using a DP matrix to store the answers for particular inputs so that we don't have to process them again.

## How to indentify that the given problem can be solved using Dynamic Programming?
* After analysing the problem , you will think of solving it using recursion as you will have feeling that the question can be solved in self similar manner.
* We will optimise the recursion solution by DP only if our recursion will have more than one branches (if we have choices either to include or not).
* If we have any optimum keyword in our problem like maximum , minimum etc.

## How to proceed in a DP problem?
* Don't jump into Bottom up solution of DP directly , first try to solve the problem by recursion then memoize the recursion using DP matrix in which we store pre-processed 
outputs for some particular input values , then convert the recursion into its iterative version by using loops and DP table.
