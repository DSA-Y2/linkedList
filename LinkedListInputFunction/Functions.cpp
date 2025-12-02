#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << value << " inserted at the beginning.\n";
}

// Function to delete a node at the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << temp->data << " deleted from the beginning.\n";
    delete temp;
}

// Function to display the list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "List elements: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

// Function to search for an element by key
bool searchElement(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to delete a node by key
void deleteByKey(Node*& head, int key) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    // If head needs to be deleted
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << key << " deleted from the list.\n";
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << key << " not found in the list.\n";
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    cout << key << " deleted from the list.\n";
}

// Main function to test all operations
int main() {
    Node* head = nullptr; // Initialize empty list
    int choice, value;

    do {
        cout << "\nLinked List Operations Menu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Display List\n";
        cout << "4. Search Element\n";
        cout << "5. Delete by Key\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                deleteAtBeginning(head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Enter key to search: ";
                cin >> value;
                if (searchElement(head, value)) {
                    cout << value << " found in the list.\n";
                } else {
                    cout << value << " not found in the list.\n";
                }
                break;
            case 5:
                cout << "Enter key to delete: ";
                cin >> value;
                deleteByKey(head, value);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
