://*********************************************************************
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

struct Node
{
    public:
        // Method Prototypes
        Node();

        // Data Members
        T topItem;
        Node *next;
};

/***************************************************************
 Node Constructor 

 Use: Instantiates Node object and sets it's data attributes. 

 Parameters: No parameters. 

 Returns: No return.
***************************************************************/
template <class T>
Node::Node()
{
    topItem = nullptr;
    next = nullptr;
}


class Stack
{
    // friend ostream& operator<<(ostream& lhs, const Stack<T>& rhs)

    public:
        Stack();
        /*
        size_t size();
        bool empty();
        void clear();
        top();
        void push();
        void pop();
        Stack(const Stack<T>& other);
        operator=(const Stack<T>& other);
        Stack();
        void copyList(const Stack<T>& other);
        ~Stack();
        */
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
Stack::Stack()
{
    stkTop = nullptr;
    stkSize = 0;
}

/***************************************************************
 Size Method 

 Use: Returns stack size data attribute. 

 Parameters: No parameters. 

 Returns: stkSize
***************************************************************
template <class T>
size_t Stack::size()
{ 
    return stkSize;
} 

/***************************************************************
 Empty Method 

 Use: Checks to see if Stack object is empty. 

 Parameters: No parameters. 

 Returns: True or False
***************************************************************
template <class T>
bool Stack::empty()
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
***************************************************************
template <class T>
void Stack::clear()
{
    if ( stkSize != 0)
    {
        pop();
    }
}    

/***************************************************************
 Top method 

 Use: Returns the top item in the stack. 

 Parameters: No parameters. 

 Returns: stkTop
***************************************************************
template <class T>
Stack::top()
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
***************************************************************
template <class T>
void Stack::push()    
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
***************************************************************
template <class T>
void Stack::pop()    
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
***************************************************************
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
***************************************************************
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
***************************************************************
template <class T>
Stack<T>::~Stack()
{
    delete[] stkArray;
}
 
/***************************************************************
 Copylist method 

 Use: Makes a copy of a linked list.  

 Parameters: A constant reference to a stack template object.  

 Returns: No return.
***************************************************************
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
***************************************************************
ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
{
    size_t current, i;

    for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
    {
        // Print stack element at subscript i
        lhs << rhs.qArray[current] << ' ';
        // Increment i, wrapping around to front of stack array if necessary     
        current = (current + 1) % rhs.qCapacity;
    }

    return lhs;
}
*/
#endif
