#include <iostream>
#include <cstdlib>

/*
    known issues

    1. Invalid indices return -1 instead of seg fault, which may or may not be considered a good thing
    2. Node class has public constructor, which enables anyone to create obj of Node class
    3. No use of inheritance
    4. Complexity of some function can be optimised using secondary pointer
    5. LinkedList class has no overloaded constructor
    6. Both classes have no iterators

    Next i'll try to :

    1. Use inheritance or shift 'Node' class inside 'LinkesList'
    2. OverLoad constructor of LinkedList class to initilise at time of object creation
    3. optimising functions by introducing another pointer in Node class
*/

class Node // parent class for containing data members
{
    private:
    int data;
    Node *next;

    public:
    // no constructor with empty parameter

    Node(const int value) : data(value), next(nullptr) {}
    // using initlizer list to assign values while creating constructor

    const int getData() const // function to return data
    {
        return data;
    }

    Node *getNext() const // function to return next node
    {
        return next;
    }

    void setData(const int value) // function to set/update data
    {
        data = value;
    }

    void setNext(Node *obj) // function to set/update next
    {
        next = obj;
    }

    void print() const // function to print the data member
    {
        std::cout << data << std::endl;
    }
};

class LinkedList
{
    private :
    size_t length;
    Node* head, *tail, *temp;

    public : 

    // default contructor
    LinkedList() : head(nullptr), tail(nullptr), temp(nullptr), length(0) {}
    
    const int getLength() const   // function to return length, complexity O(n) 
    {
        return this->length;
    }

    void push_back(const int value) // function to add an element at end
    {   // complexity O(1) or constant time
        temp = new Node(value);
        
        if (head == nullptr) 
            head = tail = temp;
        else 
        {
            tail->setNext(temp);
            tail = temp;
        }
        ++length;
    }

    void pop_back() // function to remove last element
    {   // complexity O(n) or linear time
        // as it is a single linked list, have to traverse all the way to last

        if (head == nullptr)
            return;
        else
        {
            for (temp = head; temp->getNext() != tail; temp = temp->getNext());

            free(tail);
            tail = temp;
        }

        --length;
    }

    void new_head(const int value)  // function to add a new head to list
    {   // complexity O(1) or constant time

        temp = new Node(value);

        if (head == nullptr)
            head = tail = temp;
        else
        {
            temp->setNext(head);
            head = temp;
        }

        ++length;
    }

    void remove_head()  // function to remove current head and make 2nd node as head
    { // complexity O(1)

        if (head == nullptr)
            return;
        
        temp = head;
        head = head->getNext();
        free(temp);

        --length;
    }

    const int getData(const int idx)   // function to get data from node
    {   // complexity O(n)
        // runs on 0 bases index

        if (idx < 0 || idx >= length)    // invalid location
            return -1;
        else if (idx == 0)  // head
            return head->getData();
        else if (idx == length - 1) // tail
            return tail->getData();
        else    // for other indices
        {
            temp = head;
            for (int i = idx; i > 0; --i)
                temp = temp->getNext();

            return temp->getData();
        }
    }

    const int operator[](const int idx) // operator overloading to ease up getData function
    {   // same as getData function

        if (idx < 0 || idx >= length)    // invalid location
            return -1;
        else if (idx == 0)  // head
            return head->getData();
        else if (idx == length - 1) // tail
            return tail->getData();
        else    // for other indices
        {
            temp = head;
            for (int i = idx; i > 0; --i)
                temp = temp->getNext();

            return temp->getData();
        }
    }

    LinkedList& operator+(LinkedList& obj) // concatinate passed LinkedList to first
    {
        this->tail->setNext(obj.head);
        this->length += obj.length;

        return *this;
    }

    bool operator==(LinkedList& obj)
    {
        if (this->length != obj.length)    // if lengths aren't equal, so are they
            return false;
        
        for (int i = 0; i < this->length; ++i)  // if length is equal, check each data member
            if ((*this)[i] != obj[i])    // if data member is diff
                return false;   
        
        return true;
    }

};

int main()
{

    LinkedList obj;

    obj.push_back(10);
    obj.push_back(20);
    
    LinkedList obj2;

    obj2.push_back(10);
    obj2.push_back(30);

    std::cout << (obj == obj2) << std::endl;
    
    return 0;
}
