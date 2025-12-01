#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node(T value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// DLL = Doubly Linked List
template <typename T>
class DLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    DLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor frees all nodes
    ~DLL()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        cout << "Memory Freed \n";
    }

    // ---------------- INSERTION OPERATIONS ---------------- //

    // Insert at the beginning (O(1))
    void insertAtBeginning(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        // If list is empty, new node becomes both head and tail
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            // Rewire pointers to insert before head
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Insert at the end (O(1))
    void insertAtEnd(T value)
    {
        Node<T> *newNode = new Node<T>(value);

        if (tail == nullptr)
        { // list empty
            head = tail = newNode;
        }
        else
        {
            // Attach after tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Insert at specific index (O(n))
    void insertAtIndex(int index, T value)
    {
        if (index < 0 || index > size)
        {
            cout << "Index is out of range \n";
            return;
        }

        if (index == 0)
        {
            insertAtBeginning(value);
            return;
        }

        if (index == size)
        {
            insertAtEnd(value);
            return;
        }

        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;

        // Move to the node BEFORE the insertion point
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        // Rewire pointers
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;

        size++;
    }

    // ---------------- TRAVERSAL OPERATIONS ---------------- //

    // Forward traversal (O(n))
    void displayForward() const
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Backward traversal (O(n))
    void displayBackward() const
    {
        Node<T> *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    // ---------------- DELETION OPERATIONS ---------------- //

    // Delete from beginning (O(1))
    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty \n";
            return;
        }

        Node<T> *temp = head;

        // If there's only one node
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
    }

    // Delete from end (O(1))
    void deleteEnd()
    {
        if (tail == nullptr)
        {
            cout << "List is empty \n";
            return;
        }

        Node<T> *temp = tail;

        if (head == tail)
        { // one node
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        size--;
    }

    // Delete at index (O(n))
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index \n";
            return;
        }

        if (index == 0)
        {
            deleteFront();
            return;
        }

        if (index == size - 1)
        {
            deleteEnd();
            return;
        }

        Node<T> *temp = head;

        // Move to node at "index"
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        // Bridge the gap
        Node<T> *left = temp->prev;
        Node<T> *right = temp->next;

        left->next = right;
        right->prev = left;

        delete temp;
        size--;
    }

    // ---------------- EXTRA: Optional Features ---------------- //

    // Reverse the DLL by swapping next and prev pointers (O(n))
    void reverse()
    {
        if (head == nullptr)
        {
            cout << "Empty \n";
            return;
        }

        Node<T> *temp = head;

        // Swap next and prev for each node
        while (temp != nullptr)
        {
            Node<T> *swap = temp->next;
            temp->next = temp->prev;
            temp->prev = swap;
            temp = swap;
        }

        // Swap head & tail pointers
        temp = head;
        head = tail;
        tail = temp;
    }

    // Splits list for merge sort
    Node<T> *split(Node<T> *head)
    {
        Node<T> *slow = head;
        Node<T> *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node<T> *second = slow->next;
        slow->next = nullptr;
        if (second)
            second->prev = nullptr;

        return second;
    }

    // Merge two sorted lists
    Node<T> *merge(Node<T> *first, Node<T> *second)
    {
        if (!first)
            return second;
        if (!second)
            return first;

        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            first->next->prev = first;
            first->prev = nullptr;
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            second->next->prev = second;
            second->prev = nullptr;
            return second;
        }
    }

    // Recursive merge sort
    Node<T> *mergeSort(Node<T> *node)
    {
        if (!node || !node->next)
            return node;

        Node<T> *second = split(node);

        node = mergeSort(node);
        second = mergeSort(second);

        return merge(node, second);
    }

    // Public sort
    void sort()
    {
        if (!head || !head->next)
            return;

        head = mergeSort(head);

        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        tail = temp;
    }
};

int main()
{
    DLL<int> nums;

    cout << "Displaying when empty: \n \n";
    cout << "Forward: ";
    nums.displayForward();
    cout << "Backward: ";
    nums.displayBackward();

    cout << "Insertion: \n \n";
    nums.insertAtBeginning(10);
    nums.insertAtEnd(30);
    nums.insertAtIndex(1, 20);
    nums.displayForward();
    nums.displayBackward();

    cout << "Deletion: \n \n";
    nums.deleteAtIndex(1);
    nums.displayForward();
    nums.deleteFront();
    nums.displayForward();
    nums.deleteEnd();
    nums.displayForward();

    cout << "Reversal: \n \n";
    nums.insertAtBeginning(10);
    nums.insertAtEnd(30);
    nums.insertAtIndex(1, 20);

    nums.reverse();
    nums.displayForward();
    nums.displayBackward();

    cout << "Sorting: \n \n";
    nums.insertAtBeginning(40);
    nums.insertAtEnd(50);
    nums.insertAtIndex(1, 60);
    nums.sort();
    nums.displayForward();
}