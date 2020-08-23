# Heap

Heap is a tree based data structure in which we can store our elements and perform tasks efficiently.

## Heap is of two types :-
1. Maximum Heap :- In this heap maximum element will be at the top of the heap.
2. Minimum Heap :- In this heap minimum element will be at the top of the heap.

### How to determine that the given question can be solved using heap ?
=> We will search two keywords:-
* k
* largest/smallest

### How to make choice between minimum and maximum heap?
* If we have smallest keyword in our problem then we will make a maximum heap(as we will pop all the elements greater than the required element).
* If we have largest/greatest keyword in our problem then we will make a minimum heap(as we will pop all the elements lesser than the required element).

#### Data structure we use for heap is Priority Queue.

## Note:-
#### => All the questions based on heap can be easily solved using sorting with nlogn time complexity where n is the number of elements in the array.
#### => But we can solve the same question using heap in nlogk time complexity if we have to find some kth element by sorting only required k elements and popping the unnecessory.

## Resources
1. [Video Playlist](https://www.youtube.com/watch?v=hW8PrQrvMNc&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9)
