//*********************************************************************
//// FILE:        Stack.h
//// AUTHOR:      Samuel Piecz
//// LOGON ID:    Z1732715
//// DUE DATE:    11/16/17
////
//// PURPOSE:     Declaration for the Stack class. ADTs 4 life. 
////********************************************************************
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

// Forward declaration of the Queue template class
template <class T>
class Node;

template <class T>
struct Node
{
    public:
        // Method Prototypes
        Node(const T& = T(),Node<T>* = nullptr);

        // Data Members
        T data;
        Node<T>* next;
};

/***************************************************************
 Node Constructor 

 Use: Instantiates Node object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
template <class T>
Node<T>::Node(const T& newData,Node<T>* newNext)
{
    // T() makes it dynamic so the template knows
    // what to populate the empty 
    data = newData;
    next = newNext;
}

// Forward declaration of the Queue template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T>
class Stack
{
    // Friend function
    friend ostream& operator<< <>(ostream& lhs, const Stack<T>& rhs);

    public:
        Stack();
        size_t size() const;
        bool empty() const;
        void clear();
        const T& top() const;
        void push(const T&);
        void pop();
        Stack(const Stack<T>& other);
        Stack<T>& operator=(const Stack<T>& other);
        void copyList(const Stack<T>& other);
        ~Stack();
    private:
        Node<T>* stkTop;
        size_t stkSize;
};

/***************************************************************
 Stack Constructor 

 Use: Instantiates Stack object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
template <class T>
Stack<T>::Stack()
{
    stkTop = nullptr;
    stkSize = 0;
}

/***************************************************************
 Size Method 

 Use: Returns stack size data attribute. 

 Parameters: No parameters. 

 Returns: stkSize
***************************************************************/
template <class T>
size_t Stack<T>::size() const
{ 
    return stkSize;
} 

/***************************************************************
 Empty Method 

 Use: Checks to see if Stack object is empty. 

 Parameters: No parameters. 

 Returns: True or False
****************************************************************/
template <class T>
bool Stack<T>::empty() const
{ 
    if (stkSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}     

/***************************************************************
 Clear Method

 Use: Clears the Stack. 

 Parameters: No parameters. 

 Returns: No return.
****************************************************************/
template <class T>
void Stack<T>::clear()
{
    while ( stkSize > 0)
    {
        pop();
    }
}    

/***************************************************************
 Top method 

 Use: Returns the top item in the stack. 

 Parameters: No parameters. 

 Returns: stkTop
****************************************************************/
template <class T>
const T& Stack<T>::top() const
{
    if (stkSize == 0)
    {
       throw underflow_error("Stack is empty yo."); 
    }
   return stkTop->data;
}       

/***************************************************************
 Push method 

 Use: Pushes a new item onto the stack.  

 Parameters: No parameters. 

 Returns: No return.
****************************************************************/
template <class T>
void Stack<T>::push(const T& item)    
{
    // Insert new item at top of stack.
     
    Node<T>* newNode = new Node<T>(item, stkTop);
    stkTop = newNode;
    stkSize++;

}
     
/***************************************************************
 Pop method 

 Use: Removes item from the top of the stack. 

 Parameters: No parameters. 

 Returns: No return.
****************************************************************/
template <class T>
void Stack<T>::pop()    
{
     
    if (stkSize == 0)
    {
       throw underflow_error("The stack is empty."); 
    }

    Node<T>* delNode = stkTop;
    stkTop = stkTop->next;       // or stkTop = delNode->next;
    delete delNode;
    stkSize--;

}

/***************************************************************
 Copy Constructor 

 Use: Copies one stack into another. 

 Parameters: Constant reference to a stack object called other. 

 Returns: No return.
***************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    stkTop = nullptr;
    copyList(other);
    stkSize = other.stkSize;
}

/***************************************************************
 Stack Assignment Operator 

 Use: Sets one Stack equal to another. 

 Parameters: No parameters. 

 Returns: No return.
****************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        clear();
        copyList(other);
        stkSize = other.stkSize;
    }

    return *this;
}
 
/***************************************************************
 Stack Destructor 

 Use: Deletes a stack object. 

 Parameters: No parameters. 

 Returns: No return.
****************************************************************/
template <class T>
Stack<T>::~Stack()
{
    clear();
}
 
/***************************************************************
 Copylist method 

 Use: Makes a copy of a linked list.  

 Parameters: A constant reference to a stack template object.  

 Returns: No return.
***************************************************************/
template <class T>
void Stack<T>::copyList(const Stack<T>& other)
{
    Node<T>* ptr, * newNode, * last = nullptr;
    for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
    {
        newNode = new Node<T>(ptr->data);

        if (last == nullptr)
        {
            stkTop = newNode;
        }
        else
        {
            last->next = newNode;
        }

        last = newNode;
    }
}
 
/***************************************************************
 Output operator 

 Use: Makes it possible to display a stack object using standard
 output. 

 Parameters: Reference to an ostream object lhs and reference to
 a constant stack object rhs. 

 Returns: lhs
***************************************************************/
template <class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
    Node<T>* bin;

    for (bin = rhs.stkTop; bin != nullptr; bin = bin->next)
    {
        lhs << bin->data << ' ';
    }

    return lhs;

}

#endif
