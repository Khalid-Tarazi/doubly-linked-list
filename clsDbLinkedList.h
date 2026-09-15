#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDbLinkedList { //class

protected:

    int _Size = 0;

public:

	class Node { //sub class

    public:  /// it should be public here

		T value; // whatever datatype in class, it will be here
		Node* next;
		Node* prev;
	};

	Node* head = NULL;

	void InsertAtBeginning(T value) {

        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;
	}

    void PrintList() {

        Node* current = head; // i don't move the head, I create current node

        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
        delete current;
    }

    Node* Find(T value) {
        
        Node* current = head;

        while (current != NULL) {
            if (current->value == value) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void InsertAfter(Node* current, T value) {

        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;
    }

    bool InsertAfter(int index, T value) {

        Node* itemNode = GetNode(index);

        if (itemNode != NULL) {// it means I found the node
            InsertAfter(itemNode, value); // InsertAfter method we created before
            return true;
        }
        else {
            return false;
        }
    }

    void InsertAtEnd(T value) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;
    }

    void DeleteNode(Node*& NodeToDelete) {

        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode() {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode() {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    int Size() {
        return _Size;
    }

    bool IsEmpty() {
        return (_Size == 0? true : false);
    }

    void Clear() {

        while (_Size > 0) {
            DeleteFirstNode();
        }
    }

    void Reverse() {

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* GetNode (int index) {

        int counter = 0;

        if (index > _Size - 1 || index < 0) {
            return NULL;
        }

        Node* current = head;

        while (current != NULL && (current->next != NULL)) {
            if (counter == index) {
                break;
            }

            if (counter == index) {
                break;
            }

            current = current->next;
            counter++;
        }

        return current;
    }

    T GetItem(int index) {

        Node* itemNode = GetNode(index);

        if (itemNode == NULL)
            return NULL;
        else
            return itemNode->value;
    }

    bool UpdateItem(int index, T newValue) {

        Node* itemNode = GetNode(index);

        if (itemNode != NULL) {// it means I found the node
            itemNode->value = newValue;
            return true;
        }
        else {
            return false;
        }
    }
};