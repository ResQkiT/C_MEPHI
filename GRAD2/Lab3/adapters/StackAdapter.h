#pragma once
#include "AbstractAdapter.h"
#include "../Stack.hpp"
#include <string>

using namespace std;

template<class T>
class StackAdapter : public AbstractAdapter<T>{
private:
    Stack<T> container;

    string type = "stack";
public:
    StackAdapter() : container{Stack<T>()}{};
    ~StackAdapter() = default;
    
    void create_working_adt(T * list , size_t size) override
    {
        for (size_t i = 0; i < size; i++)
        {
            container.push(list[i]);
        }
    }
    void output() override{
        Stack<T> copy(container);
        cout << "Printing elements in "<< get_type() <<" order" << endl;
        while(!copy.empty()){
            cout << copy.top() << " ";
            copy.pop();
        }
        cout << endl;
    }
    void append(const T & value) override{
        container.push(value);
    }
    void prepend(const T & value) override{
        cout << "Warning! cant prepend element to start of stack, because od semantic rules"<<endl;
        cout << "Element wil be appended to endl" << endl;
        append(value);
    }
    std::string & get_type() override{
        return type;
    }
    StackAdapter<T> * clone(){
        StackAdapter<T> * clone = new StackAdapter<T>();
        clone->type = this->type;
        clone->container = this->container; 
        return clone;
    }
    
};