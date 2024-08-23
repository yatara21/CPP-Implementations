#include <iostream>
#include <cassert>
using namespace std;


class Node{
public:
    int data;
    Node * next;
    
public: 
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
private:
    Node * front;
    Node * rear;

public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    bool isEmpty(){
        return front == NULL && rear == NULL;
    }
    void enqueue(int value){
        Node * newNode = new Node(value);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue(){
        if (isEmpty()){
            cout<<"Queue is Empty.\n";
            return;
        }
        else if(front == rear){
            cout<<front->data<<" dequeued successfully.\n";
            delete front;
            front = rear = NULL;
        }
        else{
            Node * tmp = front;
            front = front->next;
            cout<<tmp->data<<" dequeued successfully.\n";
            delete tmp;
        }
    }
    int peek(){
        if (isEmpty()){
            cout<<"Queue is Empty.\n";
            return -1;
        }
        return front->data;
    }
    void Display(){
        if (isEmpty()){
            cout<<"Queue is Empty.\n";
            return;
        }
        else{
            Node * tmp = front;
            int count = 0;
            cout<<"Queue has the following items:\n";
            while (tmp != NULL){
                cout<<tmp->data<<"\t";
                tmp = tmp->next;
                count++;
            }
            cout<<"\nTotal number of elements: "<<count<< "\n";
        }
        
    }
    bool search(int value){
        if (isEmpty()){
            cout<<"Queue is Empty.\n";
            return false;
        }
        else {
            Node * tmp = front;
            while (tmp != nullptr){
                if (tmp->data == value){
                    cout<<value<<" is found.\n";
                    return true;
                }
                tmp = tmp->next;
            }
            cout << value << " is not found.\n";
            return false;
        }
    }
    void clear(){
        if (isEmpty()){
            cout<< "Queue is Empty.\n";
            return;
        }
        
        while (!isEmpty()){
            dequeue();
        }
    cout << "Queue cleared successfully.\n";
    }


};

int main() {
    Queue q;

    // Test 1: Test isEmpty() on an empty queue
    assert(q.isEmpty() == true);
    cout << "Test 1 Passed: Queue is initially empty.\n";

    // Test 2: Enqueue elements and test isEmpty() again
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    assert(q.isEmpty() == false);
    cout << "Test 2 Passed: Queue is not empty after enqueueing elements.\n";

    // Test 3: Test peek() on non-empty queue
    assert(q.peek() == 10);
    cout << "Test 3 Passed: Peek returns the correct front element.\n";


    // Test 5: Search for existing and non-existing elements
    assert(q.search(20) == true);
    assert(q.search(40) == false);
    cout << "Test 5 Passed: Search function works correctly.\n";

    // Test 6: Dequeue elements and check the front
    q.dequeue();  // Should remove 10
    assert(q.peek() == 20);
    cout << "Test 6 Passed: Dequeue removes the front element correctly.\n";

    // Edge Case 1: Dequeue until empty and try one more dequeue
    q.dequeue();  // Removes 20
    q.dequeue();  // Removes 30
    assert(q.isEmpty() == true);
    q.dequeue();  // Attempting to dequeue from an empty queue should be handled
    cout << "Edge Case 1 Passed: Dequeue works correctly and handles empty queue.\n";

    // Edge Case 2: Peek on empty queue
    assert(q.peek() == -1);  // Assuming peek() returns -1 on empty queue
    cout << "Edge Case 2 Passed: Peek handles empty queue correctly.\n";

    // Edge Case 3: Search on empty queue
    assert(q.search(50) == false);
    cout << "Edge Case 3 Passed: Search handles empty queue correctly.\n";

    // Test 7: Enqueue and Clear the queue
    q.enqueue(40);
    q.enqueue(50);
    q.clear();  // Should clear the queue
    assert(q.isEmpty() == true);
    cout << "Test 7 Passed: Clear function works correctly.\n";

    // Edge Case 4: Clear on an already empty queue
    q.clear();  // Should not crash or behave unexpectedly
    assert(q.isEmpty() == true);
    cout << "Edge Case 4 Passed: Clear function handles empty queue correctly.\n";

    // Test 8: Enqueue a single element and then dequeue
    q.enqueue(60);
    assert(q.peek() == 60);  // Single element should be at the front
    q.dequeue();  // Should remove the single element
    assert(q.isEmpty() == true);
    cout << "Test 8 Passed: Enqueue and Dequeue with single element work correctly.\n";

    // Edge Case 5: Peek, Dequeue, and Search on queue with one element
    q.enqueue(70);
    assert(q.peek() == 70);  // Check peek with one element
    q.dequeue();  // Dequeue the only element
    assert(q.isEmpty() == true);
    assert(q.search(70) == false);  // Search for dequeued element
    cout << "Edge Case 5 Passed: Operations on a single-element queue are handled correctly.\n";

    cout << "All tests, including edge cases, passed successfully.\n";
    return 0;
}