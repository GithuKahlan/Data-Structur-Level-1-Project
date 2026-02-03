# Data Structures Project(s) (C++)

## Overview
This is a console-based Data Structures Project built in C++ as an academic and learning project.  
The project implements and demonstrates several core data structures including doubly linked lists, queues, stacks, dynamic arrays, a string manager with undo/redo functionality, and a real-world queue line management system.

## Features

### Doubly Linked List (`clsDblLinkedList`)
- Insert nodes at the beginning, end, or after a specific node
- Delete nodes (first, last, or specific)
- Reverse the list
- Find nodes by value
- Access or update nodes by index
- Check size and whether the list is empty
- Clear the entire list

### Queue (`clsMyQueue` and `clsMyQueueArr`)
- Enqueue and dequeue elements
- Access front and back items
- Print all items
- Check size and empty status
- Reverse queue
- Update elements
- Insert elements at specific positions, beginning, or end

### Stack (`clsMyStack` and `clsMyStackArr`)
- Push and pop elements
- Access top and bottom elements
- Inherits from queue for reusing common operations
- Implemented using both doubly linked list and dynamic array backends

### Dynamic Array (`clsDynamicArray`)
- Create resizable arrays
- Insert, update, delete, and access elements
- Reverse the array
- Find elements by value
- Clear the array
- Insert elements at beginning, end, before, or after a specific index

### MyString (`clsMyString`)
- Stores a string with undo/redo functionality
- Undo changes (like Ctrl+Z)
- Redo changes (like Ctrl+Y)
- Maintains a stack of previous and future string states
- Get and set string values with automatic history tracking

### Queue Line Management System (`clsQueueLine`)
- Simulates a real-world ticket-based queue system (e.g., banks or service centers)
- Issues tickets with customizable prefixes (A1, A2, B1, etc.)
- Tracks total, served, and waiting clients
- Calculates expected service time based on average service duration
- Identifies the next client to be served
- Serves clients in FIFO order
- Prints queue statistics and detailed ticket information
- Displays tickets in both left-to-right and right-to-left order

#### Usage Example of the Queu Line Management System
```cpp
#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main()
{
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionQueue("B0", 5);

    // Issue tickets
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    cout << "\nPay Bills Queue Info:\n";
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintTicketsLineLTR();
    PayBillsQueue.PrintTicketsLineRTL();

    // Serve clients
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();

    cout << "\nPay Bills Queue After Serving Clients:\n";
    PayBillsQueue.PrintInfo();

    return 0;
}
