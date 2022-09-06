/*
 *  LL_adapters.h
 *
 *  COSC 052 Fall 2019
 *  Project #4
 *
 *  Due on: NOV 14, 2019
 *  Author: jsk142
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */



#ifndef __COSC052_P4_LL_ADAPTERS_H__
#define __COSC052_P4_LL_ADAPTERS_H__



/****************************************************************************
 *                      class Stack declaration                             *
 ****************************************************************************/

template <typename T, typename S >
class Stack
{
private:
    S s;
    
public:
    bool empty() const;
    void pop();
    void push(T value);
    unsigned long size() const;
    T& top() const;
    
}; // END class Stack



/****************************************************************************
 *                      class Queue declaration                             *
 ****************************************************************************/

template <typename T, typename Q >
class Queue
{
private:
    Q q;
    
public:
    bool empty() const;
    void dequeue( T& value );
    void enqueue( T value );
    void clear();
    unsigned long size() const;
    
}; // END class Queue











/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                     class Stack implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

template <typename T, typename S >
bool Stack<T,S>::empty() const
{
    bool value = false;
    
    // update variable value to true or false as appropriate before returning
    value = s.empty();
    
    return value;
    
} // END empty method of Stack class



template <typename T, typename S >
void Stack<T,S>::pop()
{
    // Throw no_such_object exception if the list is empty
    if ( this->empty() )
    {
        throw no_such_object("ERROR: The list is empty!\n");
    }

    s.pop_front();
    
} // END pop method of Stack class



template <typename T, typename S >
void Stack<T,S>::push(T value)
{
    s.push_front(value);
    
} // END push method of Stack class



template <typename T, typename S >
unsigned long Stack<T,S>::size() const
{
    unsigned long value = 0;
    
    // update value to size of stack before returning
    value = s.size();
    
    return value;
    
} // END size method of Stack class



template <typename T, typename S >
T& Stack<T,S>::top() const
{
    // Throw no_such_object exception if the list is empty
    if ( this->empty() )
    {
        throw no_such_object("ERROR: The list is empty!\n");
    }

    return s.front();
    
} // END top method of Stack class



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                     class Queue implementation                         **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

template <typename T, typename Q >
bool Queue<T, Q>::empty() const
{
    bool value = false;
    
    // update variable value to true or false as appropriate before returning
    value = q.empty();
    
    return value;
    
} // END empty method of Queue class



template <typename T, typename Q >
void Queue<T, Q>::dequeue( T& value )
{
    // Throw no_such_object exception if the list is empty
    if ( this->empty() )
    {
        throw no_such_object("ERROR: The list is empty!\n");
    }

    value = q.front();
    q.pop_front();

} // END dequeue method of Queue class



template <typename T, typename Q >
void Queue<T, Q>::enqueue( T value )
{
    q.push_back(value);
    
} // END enqueue method of Queue class



template <typename T, typename Q >
void Queue<T, Q>::clear()
{
    q.clear();
    
} // END clear method of Queue class



template <typename T, typename Q >
unsigned long Queue<T, Q>::size() const
{
    unsigned long value = 0;
    
    // update value to size of queue before returning
    value = q.size();
    
    return value;
    
} // END size method of Queue class











#endif /*  __COSC052_P4_LL_ADAPTERS_H__  */