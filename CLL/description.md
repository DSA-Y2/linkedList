A **Circular Linked List (CLL)** is a linked list where the **last node points back to the first node**, forming a closed loop.
There is **no null terminator**, meaning traversal continues cyclically unless explicitly stopped.

### Key Characteristics

* Every node has **data** and a **next pointer**.
* The **tail node points to the head**, completing the circle.
* Traversal is done using `do...while` to ensure the head is always visited.
* Useful for **round-robin scheduling**, **buffers**, **token passing**, etc.

---

# **Operations Implemented**

## **Insertion**

### **1. Insert at Beginning**

Logic:

* Create a new node.
* If list is empty → head = tail = newNode and point tail->next = head.
* Otherwise → newNode becomes new head and tail->next is updated to head.

### **2. Insert at End**

Logic:

* If list is empty → same as above.
* Otherwise attach newNode after tail, move tail to newNode, and reconnect tail->next = head.

---

## **Deletion**

### **1. Delete from Beginning**

Logic:

* If list is empty → nothing to do.
* If only one node → delete it and reset both head & tail.
* Otherwise → move head to head->next and update tail->next to new head.

### **2. Delete from End**

Logic:

* If list is empty → nothing to do.
* If only one node → delete it and reset both head & tail.
* Otherwise → traverse to the node before tail, reconnect its next to head, delete old tail, and update tail pointer.

---

## **Traversal (Display)**

Logic:

* Since the list loops infinitely, use a **do–while loop**:

  * print current node
  * move to next
  * stop only when back at head

---