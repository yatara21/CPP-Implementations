#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node * next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
    Node(){
        this->data = 0;
        this->next = NULL;
    }
};




class LinkedList
{ 
private:
    Node * head;
    
public:
    LinkedList(){
        head = NULL;
    }
    bool isEmpty(){
        return head == NULL;
    }
    void insertAtHead(int value){
        Node * newNode = new Node();
        newNode->data = value;
        if (isEmpty()){
            newNode->next = NULL;
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void Display(){
        Node * temp = head;
        if (isEmpty()){
            cout << "List is empty";
            return;
        }
        else{
            while (temp != NULL){
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
    int getLength(){
        Node * temp = head;
        int count = 0;

        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool search(int value){
        Node * temp = head;
        
        while (temp != NULL){
            if (temp->data == value){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void insertBefore(int value, int newValue) {
    if (isEmpty()) {
        insertAtHead(newValue);
        return;
    }

    if (head->data == value) {
        insertAtHead(newValue);
        return;
    }

    Node* temp = head;

    // Traverse to find the node before the target value
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    // If the target value is found
    if (temp->next != nullptr && temp->next->data == value) {
        Node* newNode = new Node();
        newNode->data = newValue;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Item inserted successfully.\n";
    } else {
        cout << "Item not found.\n";
    }
}
    void insertAtTail(int value){
        if(isEmpty()){
            insertAtHead(value);
            return;
        }
        Node * newNode = new Node();
        newNode->data = value;
        Node * temp = head;
        while (temp->next != NULL){
            temp= temp->next;
        }
            newNode->next = NULL;
            temp->next = newNode;

            cout <<"Item Inserted successfully. \n";
    }
    void Delete(int value){
        if (isEmpty()){
            cout <<"List is Empty.\n";
            return;
        }
        if (head->data == value){
            Node * del_ptr = head;
            head = head->next;
            delete del_ptr;
            return;
        }
        Node * prev = head;
        Node * del_ptr = head->next;
        while (del_ptr != NULL && del_ptr->data != value){
            prev = del_ptr;
            del_ptr = del_ptr->next;
        }
        if (del_ptr != NULL){
            prev->next = del_ptr->next;
            delete del_ptr;
            cout<<"Item deleted successfully. \n";
        }
        else{
            cout<<"Item not found. \n";
        }
    }
    int getMiddle(Node * head){
        vector<int> list_values;
        while (head != nullptr) {
            list_values.push_back(head->data);
            head = head->next;
        }
        int mid_index = list_values.size() / 2;
        
        return list_values[mid_index];
    }
 
};



int main()
{
    LinkedList lst;
   if(lst.isEmpty())
   {
       cout<<"List is empty \n";
   }
   else
   {
       cout<<"the list contains:"<<lst.getLength()<<"\n";
   }
   int value;
   cout<<"Enter the value to be inserted \n";
   cin>>value;
   lst.insertAtHead(value);
   lst.Display();
   
   cout<<"Enter the value to be inserted \n";
   cin>>value;
   lst.insertAtHead(value);
   lst.Display();
   
   cout<<"Enter the value to be inserted \n";
   cin>>value;
   lst.insertAtHead(value);
   lst.Display();
   
   cout<<"Enter the value to be inserted \n";
   cin>>value;
   lst.insertAtHead(value);
   lst.Display();
   
   cout<<"Enter the value to be inserted \n";
   cin>>value;
   lst.insertAtHead(value);
   lst.Display();
   
   cout<<"the list contains:"<<lst.getLength()<<"\n";

   cout<<"Enter the value to be searched \n";
   cin>>value;
   if(lst.search(value))
   {
       cout<<"found \n";
   }
   else
   {
       cout<<"not found \n";
   }

    int newVal;
    cout<<"Enter the value to be deleted \n";
    cin>>newVal;
    lst.Delete(newVal);
    lst.Display();
    cout<<lst.getLength()<<"\n";
        

}
