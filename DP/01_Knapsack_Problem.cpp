/* (https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)

Question:- We are given a knapsack and we have an array of items with price of each item and we have a max capacity of knapsack . We have to find the maximum profit after 
including the items in the knapsack.

Approach:-
1. As in question , we have to calculate the maximum profit(Optimum) , So we can apply dp here.
2. Initialisation:- Either in case of empty array of items or if capacity of knapsack is zero , there will be no profit or zero profit so we will initialise first row and 
first column by 0.
3. Then we will only make choice from the items whose weight is less than or equal to the weight of knapsack and everytime we will reduce our knapsack capacity after 
including the item .

*/
