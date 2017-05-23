#define prog 1

#if(prog == 1)

#include <iostream>

using namespace std;

/*
 
 Question 1:
 
 Implement a stack template to include a constructor that takes a C++11 initializer list as a parameter:
 
 */

template<class T>

class MyStack

{
    
public:
    
    MyStack();
    
    //TO DO (1): Add a constructor with a C++11 initializer_list parameter
    
    
    void push(T p_newItem);
    
    void pop();
    
    T top(); // reference topmost item
    
private:
    
    int capacity = 5;
    
    T *m_arr = new T[capacity];
    
    int m_size = 0;
    
    //Helper Function:
    
    // To prevent pushing beyond capacity
    
    void doubleCapacity();
    
};

template<class T>

MyStack<T>::MyStack() {
    
    for (int i = 0; i < capacity; i++) {
        
        m_arr[i] = i;
        
    }
    
};

template<class T>

void MyStack<T>::push(T p_newItem) {
    
    if (m_size >= capacity)
        
        doubleCapacity();
    
    this->m_arr[m_size++] = p_newItem;
    
};

template<class T>

void MyStack<T>::pop() {
    
    this->m_arr[m_size--] = NULL;
    
};

template<class T>

void MyStack<T>::doubleCapacity() {
    
    this->capacity *= 2;
    
};

template<class T>

T MyStack<T>::top() {
    
    return m_arr[m_size-1];
    
};

#include <iostream>

//TO DO (2): Add other necessary headers

#include <memory>

using namespace std;

int main(){
    
    cout << "Integer stack...\n";
    
    MyStack<int> stk1;
    
    for (int i = 0; i < 10; i++) {
        stk1.push(i + 1);
    }
    
    
    for (int i = 0; i < 10; i++)
        
    {
        
        cout << stk1.top() << " ";
        
        stk1.pop();
        
        
        
    }
    
     cout << "\nFloating-point stack...\n";
     
     MyStack<double> stk2;
     
     for (int i = 0; i < 10; i++)
     
     stk2.push(1.5 * static_cast<double>(i + 1));
     
     for (int i = 0; i < 10; i++) {
     
     cout << stk2.top() << ' ';
     
     stk2.pop();
     
     }
    
    cout << endl;
    
    
     cout << "\nCharacter stack constructed with C++11 initializer list...\n";
     
     MyStack<char> stk3{ 'C', 'O', 'M', 'P', ' ', '3', '6', '5' };
     
     for (int i = 0; i < 8; i++)
     
     {
     
     cout << stk3.top() << ' ';
     
     stk3.pop();
     
     }
     
     cout << endl;
     
     /**/
    
    return 0;
    
}

#elif(prog == 2)

#include <iostream>

#include <memory>

using namespace std;

/*
 
 Implement a singly-linked list using smart pointers
 
 */

struct Node {
    
    Node() {
        
        data = 0;
        
        link = nullptr;
        
    }
    
    int data;
    
    Node *link;
    
};

int main() {
    
    cout << "Singly linked list with smart pointers...\n";
    
    shared_ptr<Node> ptr = nullptr;
    
    // use make_shared to allocate dynamic memory instead of ‘new’
    
    auto p = make_shared<int>(1);
    
    Node *headPtr = nullptr; // pointer
    
    Node *tailPtr = nullptr; // pointer
    
    auto tmpNodePtr = make_shared<Node>();
    
    // assign pointers
    
    headPtr = new Node; // new
    
    tailPtr = headPtr;
    
    for (int i = 99; i >= 77; i = i - 11)
        
    {
        
        if (i == 99) //Our first node
            
        {
            
            headPtr->data = i;
            
            headPtr->link = nullptr;
            
            tailPtr = headPtr;
            
        }
        
        else //Other new nodes to be linked
            
        {
            
            tailPtr = tailPtr->link;
            
            tailPtr->data = i;
            
            tailPtr->link = nullptr;
            
        }
        
    }
    
    // put a dummy head pointer in front
    
    Node * dummyHead = new Node; // another new pointer
    
    dummyHead->data = NULL;
    
    dummyHead->link = headPtr;
    
    //Add a new node, value = 100 at the front
    
    tmpNodePtr->data = 100;
    
    tmpNodePtr->link = dummyHead->link;
    
    dummyHead->link = tmpNodePtr;
    
    //Add a new node, value = 1 at the end
    
    temp->data = 1;
    
    temp->link = nullptr;
    
    tailPtr->link = temp; // because tailPtr was already at the end from the construction for loop
    
    //Add a new node, value 80, between 77 and 88
    
    temp = new Node; // pointer assign to new
    
    temp->data = 80;
    
    temp->link = nullptr;
    
    // send moving pointer to location in linked list
    
    // where to perform the insert
    
    cout << "Moving right along...\n";
    
    Node * movPtr = dummyHead->link; // start at dummy head's link
    
    while (movPtr->link->data >= 80) {
        
        cout << movPtr->data << ' ';
        
        movPtr = movPtr->link;
        
    }
    
    // link temp (new node 80) to same as movPtr link (pointing at 77)
    
    temp->link = movPtr->link;
    
    // link moving pointer link to temp
    
    movPtr->link = temp;
    
    // all is linked, yes?
    
    cout << endl;
    
    cout << "Moving pointer data: " << movPtr->data << ' ';
    
    cout << endl;
    
    //Display the list
    
    cout << "Its the final countdown...\n";
    
    temp = dummyHead;
    
    while (temp != nullptr)
        
    {
        
        cout << temp->data << ' ';
        
        temp = temp->link;
        
    }
    
    cout << endl;
    
    return 0;
    
}

#endif
