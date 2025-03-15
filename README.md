Rat in a Maze Problem

Problem Statement: 
The "Rat in a Maze" problem is a classic backtracking problem where a rat starts at the top-left corner of an N x N grid and needs to reach the bottom-right corner. The rat can only move in four directions: up, down, left, and right. The maze contains open paths (represented by 1) and blocked paths (represented by 0). The goal is to find all possible paths the rat can take to reach the destination.

Approach: 
The problem can be solved using backtracking, which involves exploring all possible paths while ensuring that the rat does not revisit the same cell in a path. We explore each direction recursively and backtrack when a path is not feasible.

Two Approaches: 

1. Using a visited matrix:
Maintain an additional N x N boolean matrix to keep track of visited cells.
Recursively try moving in all four directions (D, U, R, L).
Backtrack by marking the cell as unvisited after exploring all possibilities.
2. Optimized Approach (without extra space for visited matrix):
Modify the original matrix by marking visited cells with -1.
Restore the matrix back to its original state after backtracking.
Reduces the space complexity from O(N^2) to O(1).

Complexity Analysis: 
Time Complexity: O(4^(N^2)), since there are at most 4 choices at each cell.
Space Complexity:
O(N^2) for the approach using a visited matrix.
O(1) for the optimized approach (modifying the matrix directly).

Example: 
Input Maze:
1  0  0  0
1  1  0  1
1  1  0  0
0  1  1  1
Possible Paths (Output):
DDRDRR
DRDDRR
(Where D = Down, U = Up, R = Right, L = Left)

Applications: 
Robotics and AI for pathfinding.
Game development for maze-solving algorithms.
Optimization problems in grid-based puzzles.
