#ifndef STACK_H
#define STACK_H

// Created by David A Gaitros on 10/15/19.
// ********************************************************************
// * Name: Stack Class                                                                                               *
// * Description: A template Stack class designed to be used with *
// * any simple C++ type to include floating point, double                   *
// * floating point, character, and Boolean.                                                    *
// * The stack pointer, as is the convention, points to the last            *
// * or highest element in the array. So if you allocate 100                  *
// * elements of type "T" then the first empty element will be 99. *
// * Author: Dr. David A. Gaitros                                                                         *
// * Date: January 19, 2019 *
// ********************************************************************
#include <iostream>
using namespace std;

const int DEFAULTSIZE=100;
template <class T>
class Stack 
{

public:
   Stack();                                             // Default Constructor, stack is size 100.
   Stack(const int size);                               // Constructor, creates stack of size "size"
   //Stack(const Stack & Obj);                          // Copy constructor
   bool Full();                                         // Return true if the stack is full
   bool Empty();                                        // Return true if the stack is empty
   int Size();                                          // Return the size of the stack
   int Number();                                        // Return the number of elements stored
   T Top();                                             // Returns the top element, does not pop it
   bool Push (const T item);                            // Put an item on the stack
   bool Pop();                                          // Pop an item off and display to std out
   friend ostream &operator <<(ostream & os, Stack<T> &s) 
   { 
        if(!s.Empty())
        {
            T t = s.Top();
            s._number -=1; 
            return os << t; 
        }

        return os << "Stack Empty";    
   }

private:
   T * _stack;                                          // The "stack"
   int _size;                                           // The number of elements the stack can hold
   int _top;                                            // Points to the first empty node
   int _number;                                         // The number of elements in the stack.
};

template<class T>
Stack<T>::Stack()
{
    _size = DEFAULTSIZE;    //set size to default
    _number = 0;            //set initial number of elements
    _stack = new T;         //initialize stack pointer
}

template<class T>
Stack<T>::Stack(const int size)
{
    _size = size;           //set size to input value
    _number  = 0;           //set initial number of elements
    _stack = new T;         //initialize stack pointer
}

template<class T>
int Stack<T>::Size(){
    return _size;           //return capacity of stack
}

template<class T>
bool Stack<T>::Full()
{
    if(_size ==_number)
    {
        return true;
    }

    return false;
}

template<class T>
int Stack<T>::Number()
{
   return _number;          //return current number of elements in stack
}

template<class T>
bool Stack<T>::Empty()
{
    if(_number<=0)
    {
        return true;
    }

    return false;
}

template<class T>
bool Stack<T>::Push(const T item)
{
    //check if stack is full
    if(!Full())
    {
        //add item to current stack position and increment
        _stack[_number++] = item;
        return true;
    }

    //return error
    cout << "Stack Full" << std::endl;
    return false;
}

template<class T>
T Stack<T>::Top()
{
    //check for empty stack
    if(!Empty())
    {
        //return top element of stack
        return _stack[_number - 1];
    }

    //return error
    cout << "Stack Empty" << std::endl;
    return NULL;
}

template<class T>
bool Stack<T>::Pop()
{
    //check for empty stack
    if(!Empty())
    {
        //out top item
        cout << Top() << std::endl;

        //remove from stack
        --_number;
        return true;
    }

    //print error
    cout << "Stack Empty" << std::endl;
    return false;
}
#endif