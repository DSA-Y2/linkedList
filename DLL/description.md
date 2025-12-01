## **Doubly Linked List (DLL)**

A **Doubly Linked List** is a linear data structure where each node stores:

* a data value
* a pointer to the **next** node
* a pointer to the **previous** node

This allows:

* traversal in **both directions**
* insertion and deletion in **constant time** at the ends
* simpler removal of any node because you already have a `prev` pointer

The trade-off is slightly higher memory use and more pointer management.

---

## **Operations Implemented**

### **Insertion**

* **Insert at Beginning**
* **Insert at End**
* **Insert at Index**

### **Deletion**

* **Delete from Beginning**
* **Delete from End**
* **Delete at Index**

### **Traversal**

* **Forward traversal**
* **Backward traversal**

---

## **Logic Behind Each Operation**

### **Insertion**

#### **1. At Beginning**

* Create a new node.
* If the list is empty: head = tail = new node.
* Otherwise:

  * newNode → next = head
  * head → prev = newNode
  * update head
* **O(1)**

#### **2. At End**

* If empty → same as above.
* Otherwise:

  * tail → next = newNode
  * newNode → prev = tail
  * update tail
* **O(1)**

#### **3. At Index**

* Bounds check.
* If index = 0 → insert at beginning.
* If index = size → insert at end.
* Otherwise:

  * Traverse to `index - 1`
  * Rewire next and prev pointers around newNode
* **O(n)**

---

### **Deletion**

#### **1. From Beginning**

* If empty → nothing to delete.
* If one node → reset head and tail.
* Otherwise:

  * Move head forward
  * Set new head’s `prev = nullptr`
* **O(1)**

#### **2. From End**

* If empty or single node → handled above.
* Otherwise:

  * Move tail backward
  * Set new tail’s `next = nullptr`
* **O(1)**

#### **3. At Index**

* Bounds check.
* If index = 0 → deleteFront().
* If index = size - 1 → deleteEnd().
* Otherwise:

  * Traverse to target node
  * Bridge left and right nodes
  * Delete target
* **O(n)**

---

### **Traversal**

* **Forward**: start at head, follow `next`
* **Backward**: start at tail, follow `prev`

Both run in **O(n)**.
--- 