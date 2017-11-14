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

class Stack
{
    friend ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
    public:
        Stack::Stack()
        Stack::size()
        Stack::empty()
        Stack::clear()
        Stack::top()
        Stack::push()    
        Stack::pop()    
        Stack<T>::Stack(const Stack<T>& other)
        Stack<T>& Stack<T>::operator=(const Stack<T>& other)
        Queue<T>::~Queue()
        void Stack<T>::copyList(const Stack<T>& other)
    private:
        
};

struct Node
{
/* Data members
 *
 * This template structure should have two data members: a member of the template parameter type to store an item to
 *  be inserted into the stack, and a pointer to a Node. This pointer, next, will point to the next node in the linked
 *  list (or be nullptr if this is the last node in the list).
 *
 * Since the Stack class will need access to these data members, make them public (which is the default for a struct).
 *
 * Methods
 *
 * Constructor
 *
 * The structure should have a constructor that can be used to initialize the data members of the stack node. */

};

template <class T>
Stack::Stack()
{
    stkTop = nullptr;
    stkSize = 0;
}

template <class T>
Stack::size()
{ 
    Return stkSize.
} 

template <class T>
Stack::empty()
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

template <class T>
Stack::clear()
{
    // Similar to queue.
}    

template <class T>
Stack::top()
{
    if (stack is empty)
    {
       throw exception
    }
        
   return stkTop->data;
}       

template <class T>
Stack::push()    
{
    // Insert new item at top of stack.
     
    Node<T>* newNode = new Node<T>(item, stkTop);
    stkTop = newNode;
    stkSize++;

}
     
template <class T>
Stack::pop()    
{
    Remove top item from stack.
     
    if (stack is empty)
    {
       throw exception
    }

    Node<T>* delNode = stkTop;
    stkTop = stkTop->next;       // or stkTop = delNode->next;
    delete delNode;
    stkSize--;

}

8. Copy Constructor
        
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
    stkTop = nullptr;
    copyList(other);
    stkSize = other.stkSize;
}

9. Copy Assignment Operator
 
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
 
10. Destructor

template <class T>
Queue<T>::~Queue()
{
    delete[] qArray;
}
 
11. copyList()
     
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
 
// need to update to contain Stack info 
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
    size_t current, i;

    for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
    {
        // Print queue element at subscript i
        lhs << rhs.qArray[current] << ' ';
        // Increment i, wrapping around to front of queue array if necessary     
        current = (current + 1) % rhs.qCapacity;
    }

    return lhs;
}
