# Breadth First Search (BFS)

Breadth First Search (BFS) is an uninformed search algorithm that explores nodes level by level starting from the initial node.  
It first visits all nodes at the current depth before moving to nodes at the next depth level.

BFS uses a queue (FIFO – First In First Out) to keep track of nodes that need to be explored.

## How BFS Works

1. Start from the initial node.
2. Mark the node as visited.
3. Add the node to the queue.
4. Remove a node from the queue.
5. Visit all unvisited neighboring nodes.
6. Add those neighbors to the queue.
7. Repeat until all nodes are explored or the goal state is found.

BFS is complete and optimal for problems where all actions have the same cost, but it may use more memory because it stores many nodes in the queue.


# Depth First Search (DFS)

Depth First Search (DFS) is an uninformed search algorithm that explores nodes by going as deep as possible along one path before backtracking.

DFS typically uses a stack (LIFO – Last In First Out) or recursion to manage the nodes.

## How DFS Works

1. Start from the initial node.
2. Mark the node as visited.
3. Visit one unvisited neighboring node.
4. Continue exploring deeper nodes along the same path.
5. If no unvisited neighbors remain, backtrack to the previous node.
6. Continue this process until all nodes are explored or the goal state is found.

DFS usually uses less memory than BFS, but it is not guaranteed to find the shortest path.
# Uniform Cost Search (UCS)

Uniform Cost Search (UCS) is an uninformed search algorithm used to find the lowest cost path from a starting node to a goal node in a graph or state space.

Unlike BFS, which expands nodes based on their depth, UCS expands the node with the smallest path cost first. This ensures that the algorithm always explores the most promising path in terms of cost.

## How UCS Works

1. Start from the initial node.
2. Add the node to a priority queue with cost 0.
3. Remove the node with the lowest path cost from the queue.
4. Check if it is the goal node.
5. If not, expand the node and add its neighboring nodes to the queue with their updated path costs.
6. Repeat the process until the goal node is reached.

Because UCS always selects the node with the lowest cumulative cost, it guarantees finding the optimal solution when all costs are non-negative.

# Water Jug Problem

The Water Jug Problem is a classic problem used in artificial intelligence to demonstrate search algorithms such as BFS and DFS.

In this problem, there are two jugs with fixed capacities and an unlimited supply of water. The goal is to measure a specific amount of water using only the operations allowed on the jugs.

## Allowed Operations

The following actions can be performed:

1. Fill a jug completely.
2. Empty a jug.
3. Pour water from one jug to the other until one jug becomes empty or the other becomes full.

## Example

A common example uses:
- Jug 1 capacity: 4 liters
- Jug 2 capacity: 3 liters
- Goal: obtain exactly 2 liters of water

The problem is solved by exploring different states of the jugs, where each state represents the amount of water currently in both jugs.

Example state representation:
(0,0),
(4,0),
(1,3),
(1,0)

Search algorithms like BFS and DFS are used to explore these states until the goal state is reached.
# Comparison of BFS, DFS and UCS

Breadth First Search (BFS), Depth First Search (DFS), and Uniform Cost Search (UCS) are uninformed search algorithms used to explore a state space. Although they are all used to traverse graphs or solve search problems, they differ in how they explore nodes and how they choose the next node to expand.

## Exploration Strategy

BFS explores nodes level by level. It visits all nodes at the current depth before moving to the next depth level.

DFS explores nodes by going as deep as possible along one path before backtracking to explore other paths.

UCS explores nodes based on the lowest path cost from the start node. It always expands the node that has the smallest cumulative cost.

## Data Structure Used

BFS uses a queue (FIFO – First In First Out) to store nodes that need to be explored.

DFS uses a stack (LIFO – Last In First Out) or recursion to explore nodes.

UCS uses a priority queue where nodes are ordered according to their total path cost.

## Memory Usage

BFS usually requires more memory because it stores all nodes at the current level before moving deeper into the search tree.

DFS typically uses less memory because it only stores nodes along the current path being explored.

UCS can require significant memory because it stores multiple paths in the priority queue to ensure the lowest cost path is always selected.

## Speed / Execution Time

DFS is generally faster in many problems because it quickly explores deeper paths without storing large numbers of nodes.

In the implementation provided in `Water_Jug_Problem.c`, the program measures and displays the execution time for BFS and DFS. From the output we observe that BFS takes significantly more time compared to DFS for this problem, showing that DFS runs faster in this implementation.

UCS may be slower than both BFS and DFS because it must constantly check and update path costs while selecting the node with the smallest cost.

## Optimality

BFS guarantees the shortest path to the goal when all actions have equal cost.

DFS does not guarantee the shortest solution because it may follow a longer path before finding the goal.

UCS guarantees the optimal solution because it always expands the node with the lowest cumulative cost.

## Summary

BFS is useful when the shortest path in terms of number of steps is required, but it may consume more memory.

DFS is more memory efficient and often faster in practice, but it does not always produce the optimal solution.

UCS is useful when actions have different costs and the lowest cost path must be found, although it may require more computation and memory.
