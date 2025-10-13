#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class CLL{
private:
    Node *head;

public:
    CLL(){
        head = nullptr;
    }

    void insert(){
        int value, pos;
        cout << "Enter value to insert: ";
        cin >> value;
        cout << "Enter the position: ";
        cin >> pos;
        Node *newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            cout << "Node inserted at position 1." << endl;
            return;
        }

        if(pos == 1){
            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
            cout << "Node inserted at position 1." << endl;
            return;
        }

        Node *temp = head;
        int i = 1;
        while(i < pos - 1 && temp->next != head){
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted at position " << pos << "." << endl;
    }

    void deleteNode(){
        if(head == nullptr){
            cout << "List is empty!" << endl;
            return;
        }

        int k;
        cout << "Enter position from end to delete (k): ";
        cin >> k;

        int len = 1;
        Node *temp = head;
        while(temp->next != head){
            len++;
            temp = temp->next;
        }

        if(k > len || k <= 0){
            cout << "Invalid position!" << endl;
            return;
        }

        int pos = len - k + 1;
        if(pos == 1){
            Node *last = head;
            while(last->next != head)
                last = last->next;

            Node *del = head;
            if(head->next == head)
                head = nullptr;
            else{
                head = head->next;
                last->next = head;
            }
            delete del;
            cout << "Deleted node from position " << k << " (from end)." << endl;
            return;
        }

        temp = head;
        for(int i = 1; i < pos - 1; i++)
            temp = temp->next;

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Deleted node from position " << k << " (from end)." << endl;
    }

    void display(){
        if(head == nullptr){
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        cout << "Circular Linked List: ";
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }

    void search(){
        if(head == nullptr){
            cout << "List is empty!" << endl;
            return;
        }

        int value;
        cout << "Enter element to search: ";
        cin >> value;
        Node *temp = head;
        int pos = 1;
        bool found = false;
        while(temp != nullptr){
            if(temp->data == value){
                cout << "Element " << value << " found at position " << pos << "." << endl;
                found = true;
                break;
            }
            temp = temp->next;
            pos++;
            if (temp == head)
                break;
        }
        if(!found)
            cout << "Element " << value << " not found in the list." << endl;
    }

    ~CLL(){
        if(head == nullptr)
            return;
        Node *current = head;
        Node *nextNode;
        do{
            nextNode = current->next;
            delete current;
            current = nextNode;
        }while(current != head);
    }
};

int main(){
    CLL cll;
    int choice;
    while (true){
        cout << "\n\n--- Circular Linked List ---" << endl;
        cout << "1. Insert at any position" << endl;
        cout << "2. Delete from a position (kth from end)" << endl;
        cout << "3. Display the list" << endl;
        cout << "4. Search an element" << endl;
        cout << "5. Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "Enter your choice(1-5): ";
        cin >> choice;

        switch (choice){
        case 1:
            cll.insert();
            break;
        case 2:
            cll.deleteNode();
            break;
        case 3:
            cll.display();
            break;
        case 4:
            cll.search();
            break;
        case 5:
            cout << "Exiting program ..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}