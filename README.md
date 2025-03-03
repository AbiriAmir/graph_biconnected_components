# Tarjan's Algorithm for Finding Biconnected Components

This repository contains a C++ implementation of Tarjan's Algorithm to identify biconnected components in an undirected graph. This project was developed as part of the Advanced Graph Theory course in 2016.

## Overview

A **biconnected component** in an undirected graph is a maximal subgraph such that the removal of any single vertex does not disconnect the subgraph. Identifying these components is crucial in understanding the resilience and connectivity of networks.

**Tarjan's Algorithm**, developed by Robert Tarjan, efficiently finds all biconnected components in a graph using Depth-First Search (DFS). The algorithm operates in O(V + E) time complexity, where V is the number of vertices and E is the number of edges. citeturn0search0

## Repository Structure

- `biconnected-stack.cpp`: Implements Tarjan's Algorithm using an explicit stack to manage the DFS traversal and track biconnected components.
- `biconnected.cpp`: An alternative implementation of the algorithm.
- `test.in`: Sample input file containing graph data for testing purposes.
- `testgen.cpp`: A utility to generate test cases for the algorithm.

## Getting Started

To compile and run the code:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/AbiriAmir/graph_biconnected_components.git
   ```
2. **Navigate to the repository directory**:
   ```bash
   cd graph_biconnected_components
   ```
3. **Compile the code**:
   ```bash
   g++ biconnected-stack.cpp -o biconnected
   ```
4. **Run the executable**:
   ```bash
   ./biconnected < test.in
   ```

Ensure you have a C++ compiler (like g++) installed on your system.

## Input Format

The input should be provided in the following format:

- The first line contains two integers, V (number of vertices) and E (number of edges).
- The next E lines each contain two integers, u and v, representing an edge between vertices u and v.

Example:
```
5 5
1 2
1 3
2 3
3 4
4 5
```

## Output

The program will output the biconnected components of the graph, each represented as a set of edges.

## References

- [Biconnected Components - GeeksforGeeks](https://www.geeksforgeeks.org/biconnected-components/)
- [Articulation points and bridges (Tarjan's Algorithm) - Codeforces](https://codeforces.com/blog/entry/71146)
- [Biconnected Components Tutorials & Notes | Algorithms - HackerEarth](https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/)

For more information on Tarjan's Algorithm and biconnected components, refer to the references above. 
