#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class Stack {
    Node* top;
    
public:
    Stack() {
        top = NULL;
    }

    // O(1) time complexity
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    // O(1) time complexity
    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return;
        } else {
            Node* tmp = top;
            top = top->next;
            cout << tmp->data << " popped successfully.\n";
            delete tmp;
        }
    }

    // O(1) time complexity
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return -1; // or throw an exception
        }
        return top->data;
    }

    // O(1) time complexity
    bool isEmpty() {
        return top == NULL;
    }

    // O(n) time complexity, can be optimized to O(1) by maintaining a size variable
    int getSize() {
        int counter = 0;
        Node* tmp = top;
        if (isEmpty()) {
            return counter;
        } else {
            while (tmp != NULL) {
                tmp = tmp->next;
                counter++;
            }
        }
        return counter;
    }

    // O(n) time complexity
    void Display() {
        if (isEmpty()) {
            cout << "Stack is Empty.\n";
            return; 
        } else {
            Node* tmp = top;
            cout << "Stack has the following items:\n";
            while (tmp != NULL) {
                cout << tmp->data << "\n";
                tmp = tmp->next;
            }
        }
    }

    // O(n) time complexity
    bool isFound(int value) {
        if (isEmpty()) {
            return false;
        } else {
            Node* tmp = top;
            while (tmp != NULL) {
                if (tmp->data == value) {
                    return true;
                } else {
                    tmp = tmp->next;
                } 
            }
            return false;
        }
    }
};

int main() {
    Stack s;
    s.Display();
    int value;
    
    // Pushing values to the stack
    for (int i = 0; i < 3; i++) {
        cout << "Enter the value to be inserted.\n";
        cin >> value;
        s.push(value);
    }
    
    s.Display();

    // Popping the top value and showing the new top value
    s.pop();
    cout << "Top element is: " << s.peek() << "\n";

    // Checking if the stack is empty
    cout << "Is stack empty: " << (s.isEmpty() ? "Yes" : "No") << "\n";

    // Showing the size of the stack
    cout << "Stack size is: " << s.getSize() << "\n";

    // Push another value and display the stack
    s.push(5);  
    s.Display();

    // Edge cases
    s.pop(); // Pops the top element
    s.pop(); // Pops the second element
    s.pop(); // Pops the last element, making the stack empty
    s.pop(); // Attempt to pop from an empty stack
    
    s.peek(); // Attempt to peek in an empty stack

    s.Display(); // Display an empty stack
}
