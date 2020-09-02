# Dynamic Programming

## Definition  
Dynamic Programming is mainly an optimization over plain recursion by which we can reduce the time complexity by trading with time and space complexities.
The basic idea of dynamic programming is to store the results of previous calculation and reuse it in future instead of recalculating them.

## Properties of Dynamic Programming
There are two main properties of any problem which identifies a problem that it can be solved using the dynamic programming approach:

#### 1. Overlapping Subproblem Property.
Dynamic Programming is mainly used when solutions of the same subproblems are needed again and again. In dynamic programming, computed solutions to subproblems 
are stored in a table so that these don’t have to be recomputed.

#### 2. Optimal Substructure Property.
A given problem has Optimal Substructure Property if the optimal solution of the given problem can be obtained by using optimal solutions of its subproblems.

## Methods for solving Dynamic Programming Problems:

#### 1. Memoization (Top Down):
The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.

#### 2. Tabulation (Bottom Up): 
The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally, we are building the solutions of subproblems bottom-up.

## How to identify that the given problem can be solved using Dynamic Programming?
* After analysing the problem , you will think of solving it using recursion as you will have feeling that the question can be solved in self similar manner.
* We will optimise the recursion solution by DP only if our recursion will have more than one branches (if it have overlapping property).
* If we have any optimum keyword in our problem like maximum , minimum etc.

## How to proceed in a DP problem?
* Don't jump into Bottom up solution of DP directly , first try to solve the problem by recursion then memoize the recursion using DP matrix in which we store pre-processed 
outputs for some particular input values , then convert the recursion into its iterative version by using loops and DP table.

## How to choose the variables for making DP matrix?
* We take those variables which are changing if we are analysing our problem to convert it into smaller input problem like in string problems we take size of strings as the index variables of DP matrix.

## Resources
* [DP Playlist](https://youtu.be/nqowUJzG-iM)
