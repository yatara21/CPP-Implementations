#include <iostream>
using namespace std;

class Array
{
private:
    int size = 0;
    int length = 0;
    int * ptr;
public:
    Array(int arrSize){
        size = arrSize;
        ptr = new int[size];
    }
    int getSize(){
        return size;
    }
    int getLength(){
        return length;
    }
    void Fill(){
        int num_of_items;
        cout <<"How many items you want to fill? \n";
        cin >> num_of_items;
        if (num_of_items > size){
            cout <<"you cannot exceed the array size \n";
            return; 
        }
        else {
            for (int i = 0; i < num_of_items; i++)
            {
                cout <<"Enter item no:" << i+1 << endl;
                cin >> ptr[i];
                length++;
            }
            
        }
    }
    void Display(){
        cout <<"Display Array content \n";
        for (int i = 0; i < length; i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl;
        
    }
        /**
         * Appends an item to the end of the array if there is space available.
         *
         * 
         */
    void Append(){
        int item = 0;
        cout <<"Enter the item you want to append: \n";
        cin >> item;
        if (length == size){
            cout <<"Array is full \n";
            return;
        }
        ptr[length] = item;
        length++;
        cout <<"Item appended successfully \n";
    }

    int Search(int value){
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (ptr[i] == value)
            {
                index = i;
                break;
            }
        }
    return index;
    }

    int insert(){
        cout <<"Enter the index and value you want to insert: \n";
        int index;
        int value;
        cin >> index;
        cin >> value;
        if (index < 0 || index > length || length == size)
        {
            cout <<"Invalid index \n";
            return -1;
        }
        for(int i = length; i > index; i--){
            ptr[i] = ptr[i-1];

        }
        ptr[index] = value;
        length++;
        cout <<"Item inserted successfully \n";
        return 1;
    }

    int Delete(int index){
        if (index < 0 || index >= length || length == 0){
            return -1;
        }
        for (int i = index; i < length-1; i++)
        {
           ptr[i] = ptr[i+1]; 
        }
        length--;
        return 1;
    }    

    int Enlarge(int newSize){
        if (newSize <= size){
            return -1;
        }
        else {
            size = newSize;
            int * temp = ptr;
            ptr = new int[size];
            for (int i = 0; i < length; i++){
                ptr[i] = temp[i];
            }
            delete [] temp;
            return 1;
        }
    }

};


int main()
{
    Array myArray(10);
    myArray.Fill();
    myArray.Display();
    //cout<< myArray.Search(80);
    // cout <<"Enter the index you want to delete: \n";
    // int index;
    // cin >> index;
    // int result = myArray.Delete(index);
    // if (result == -1){
    //     cout <<"Invalid index \n";
    // }
    // else{
    //     cout <<"Item deleted successfully \n";
    // }
    cout <<"Array length is:"<< myArray.getLength()<<"\n";
    cout <<"Array size is:"<< myArray.getSize()<<"\n";
    int newSize;
    cout <<"enter new size \n";
    cin >> newSize;
    int result = myArray.Enlarge(newSize); 
    if (result == -1){
        cout <<"Invalid new size \n";
    }
    else{
        cout <<"Array enlarged successfully \n";
    }
    myArray.Display();
    cout <<"Array length is :"<< myArray.getLength()<<"\n";
    cout <<"Array size is :"<< myArray.getSize()<<"\n";
    myArray.Delete(1);
    myArray.Display();
    cout<< myArray.getLength() <<"\n";
    cout<< myArray.getSize() <<"\n";
}
