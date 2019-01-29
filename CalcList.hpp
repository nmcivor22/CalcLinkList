#ifndef CALC_LIST_H
#define CALC_LIST_H
/***********************************************
 * Implementing a singly linked list Calculator
 * Add each new node at the start of the list
 * ********************************************/

#include "CalcListInterface.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>



class CalcList : public CalcListInterface{
    public:
            CalcList() : Tot(0){}; //construct the calculator and initilize to 0
            ~CalcList(){ //remove linked lists 
                    while(head != NULL){
                            node *p = head;
                            head = p -> next;
                            delete p; 
                    }
                    delete head; 
            }
            double total() const; //returns the running total. 
            void newOperation(const FUNCTIONS func, const double operand); //Add New node to front of list
            void removeLastOperation();
            std::string toString(unsigned short precision) const; //string is part of std lib??? or string lib??
    private:
        double Tot;
        struct node
        {
                double total; //keeps updated total
                double operand; //user chosen value 
                int numOps; //number of ops used, also #of nodes
                FUNCTIONS opUsed; //type of operator chosen
                node *next;
        };
        node *head = NULL; //head will initially pt to NULL
};


#endif
