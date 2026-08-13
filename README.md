# Red-Black Tree in C

## 📌 Project Overview

A **Red-Black Tree** is a self-balancing Binary Search Tree that maintains balance using node colors and tree rotations.

This project implements a Red-Black Tree using **C programming and Data Structures**, supporting efficient insertion, deletion, and searching while maintaining the properties of a balanced tree.

## 🚀 Features

* Implements a self-balancing Red-Black Tree.
* Supports insertion of nodes.
* Supports deletion of nodes.
* Supports searching for elements.
* Performs left and right rotations to maintain balance.
* Uses color adjustments to preserve Red-Black Tree properties.
* Displays the tree structure for better visualization.

## 🔹 Operations

* Insert
* Delete
* Search
* Display

## 🌳 Red-Black Tree Properties

The implementation maintains the following properties:

* Every node is either **Red** or **Black**.
* The root node is always Black.
* Every NULL leaf is considered Black.
* A Red node cannot have a Red child.
* Every path from a node to its descendant NULL leaves contains the same number of Black nodes.

## ⚙️ Time Complexity

| Operation | Average / Worst Case |
| --------- | -------------------- |
| Search    | O(log n)             |
| Insertion | O(log n)             |
| Deletion  | O(log n)             |

## 🛠️ Technologies Used

* **Language:** C
* **Concepts:** Data Structures, Binary Search Tree, Red-Black Tree, Recursion, Pointers
* **Compiler:** GCC
* **Platform:** Linux

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the Project Directory

```bash
cd Red-Black-Tree
```

### 3. Compile the Program

```bash
gcc *.c -o red_black_tree
```

### 4. Run the Program

```bash
./red_black_tree
```

## 📂 Project Structure

```text
Red-Black-Tree/
│
├── main.c
├── red_black_tree.c
├── red_black_tree.h
└── README.md
```

## 📌 Sample Operations

```text
1. Insert
2. Delete
3. Search
4. Display
5. Exit

Enter your choice: 1
Enter the value: 50

Node 50 inserted successfully.
```

## 🎯 Learning Outcomes

* Understood the concept of self-balancing binary search trees.
* Implemented tree rotations and color adjustments.
* Strengthened knowledge of recursion, pointers, and dynamic memory allocation.
* Improved understanding of balanced tree algorithms and their time complexity.

## 👨‍💻 Author

**Akash Vasu**

ECE | Embedded Systems Enthusiast
