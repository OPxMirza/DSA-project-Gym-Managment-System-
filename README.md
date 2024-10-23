# Gym Management System

This project is a **Gym Management System** developed using **Data Structures and Algorithms (DSA)** principles. It efficiently manages gym operations such as member registration, tracking workouts, and payments. The project focuses on optimizing data storage and retrieval operations, ensuring minimal latency and maximum efficiency.

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Project Structure](#project-structure)
- [Data Structures Used](#data-structures-used)
- [Algorithms Implemented](#algorithms-implemented)
- [Installation](#installation)
- [Usage](#usage)
- [Contact](#contact)

## About the Project

The **Gym Management System** provides a way to organize and streamline gym-related tasks. By implementing the right data structures, it offers better efficiency in handling tasks like adding new members, maintaining workout records, and managing fees. This project is designed to be simple yet effective, with a focus on clarity in code and ease of use.

## Features

- **Member Registration**: Add, edit, and remove members.
- **Workout Management**: Track and manage members' workout routines.
- **Payment Tracking**: Maintain records of membership fees and dues.
- **Search Functionality**: Quickly find member records by name, ID, or other criteria.
- **Report Generation**: Generate monthly reports on member attendance and payments.

This project is built on the following concepts:  
- **Linked List**  
- **Basic Operations on Linked Lists** such as insertion, deletion, searching, updating, counting, and displaying records.

The **Gym Management System** is a simple console application based on linked lists that helps in coding structured operations easily understandable to beginners. The system includes functionalities such as:

- **Insert Record**  
- **Search Record**  
- **Update Record**  
- **Delete Record**  
- **Count Records**  
- **Show Records**  
- **Fee Function**  
- **Diet Plan Function**

### Functionalities

1. **Check Record**  
   Checks if a record already exists before insertion, using the concept of searching for a node with the given data in the linked list.

2. **Insert Record**  
   Creates a new node in the empty or non-empty linked list, and inserts the member record. Each member ID acts as a unique key.

3. **Search Record**  
   Searches for a specific member in the linked list using their unique member ID.

4. **Update Record**  
   Allows users to modify the details of an existing member.

5. **Count Records**  
   Counts the total number of records in the linked list.

6. **Delete Record**  
   Removes a specific record from the linked list using the member ID as the key.

7. **Show Records**  
   Displays all member records stored in the linked list.

8. **Fee Function**  
   Displays the fee information of the member.

9. **Diet Plan**  
   Provides a customized diet plan for the member based on their age.

## Project Specification

The project follows these specifications:  
- **Unique ID**: Each member is assigned a unique ID, which is used as a key to distinguish between different records.  
- **Sorted Order**: Records are inserted in sorted order based on the member ID.  
- **Use of OOP and DSA Concepts**: The project employs classes and objects, namespaces, header files, pointers, linked lists, and singly linked lists.

### File Handling

The project utilizes file handling techniques to:  
- Write member records into a file when inserted.  
- Read data from the file for displaying or searching.  
- Delete all records from the file when needed.

### Login and Signup Page

The system includes a login page for user authentication. It requires the user to enter a correct username and password to access the main menu. In case of incorrect credentials, an error message is displayed, prompting the user to re-enter the details.

### Class Structure

The project includes the following classes:

1. **Node Class**  
   Contains private variables such as:
   - **int id**  
   - **string name**  
   - **string address**  
   - **int contact**  
   - **int dateofjoin**  
   - **float weight**  
   - **string exercise**  

   Public methods include:  
   - Getters and setters for all variables.  
   - Functions for basic linked list operations such as insertion, search, update, deletion, display, and count.

2. **Gym Class**  
   Manages the entire gym management system with the help of linked list operations.

## Project Structure

```
📦 gym-management-system
├── 📁 src
│   ├── 📄 gymm.cpp               # Main file
└── 📄 README.md                  # Project Readme file
```

## Data Structures Used

- **Linked Lists**: To manage members and workouts efficiently.
- **Binary Search Trees (BST)**: For searching and storing records like payments.
- **Hash Maps**: To store and retrieve member information based on IDs quickly.
- **Queues**: For scheduling workout sessions.

## Algorithms Implemented

- **Searching Algorithms**: Binary search and hash-based search for efficient lookup.
- **Sorting Algorithms**: Quick sort for sorting member records by different criteria (like name, ID, etc.).
- **Queue Management**: For handling member requests or workout sessions in a FIFO order.
- **Tree Traversal Algorithms**: In-order, pre-order, and post-order traversals to manage hierarchical data efficiently.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/gym-management-system.git
   cd gym-management-system
   ```

2. **Compile the code** (for C++):
   ```bash
   g++ -o gym-system src/*.cpp
   ```

3. **Run the executable**:
   ```bash
   ./gym-system
   ```

## Usage

After running the program, you'll be prompted with a menu. The following options will be available:

1. **Register Member**: Add a new member to the system.
2. **Record Workout**: Add workout details for a member.
3. **Track Payments**: View and update membership payments.
4. **Search Members**: Look up a member by name or ID.
5. **Generate Reports**: Generate and export reports on attendance and payments.


## Contact

For any questions or feedback, please reach out:

- **GitHub**: [OPxMirza](https://github.com/OPxMirza)
- **Email**: abdullahakmal002@gmail.com
