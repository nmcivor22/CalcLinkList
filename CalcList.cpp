#include "CalcList.hpp" 

double CalcList::total() const{
     if (head == NULL)
        return Tot;
     else
        return head -> total;
}
/********************************************************************
 * newOperation is called with operator and operand to be performed
 * is then added to the head of the linked list with calculated 
 * elements
 * ******************************************************************/
void CalcList::newOperation(const FUNCTIONS func, const double operand){
    double prevTot , newTot;
    int prevNodeNum;

    if(head == NULL){
        prevTot = 0;
        prevNodeNum = 0;
    }
    else {
        prevTot = head -> total;
        prevNodeNum = head -> numOps;
    }
    if (func == MULTIPLICATION){
        newTot = prevTot * operand;
    }
    if (func == DIVISION){
        try { //trying code
            if(operand == 0)
            throw std::logic_error("Cannot Divide by zero");
        }
        catch(const char* msg) { //if gets thrown, gets caught here 
            std::cout << msg << std::endl;
            return;
        }
        newTot = prevTot / operand;
    }
    if (func == SUBTRACTION){
        newTot = prevTot - operand;
    }
    if (func == ADDITION){
        newTot = prevTot + operand; 
    }
    node *newnode = new node; //create new node
    newnode -> operand = operand;
    newnode -> opUsed = func;
    newnode -> total = newTot; //store new total
    newnode -> numOps = prevNodeNum+1; //store what num of op it is

    newnode -> next = head; //point next of new node to point to what head WAS pointing to 
    head = newnode; //redirect the new node to now be the new head
}
/********************************************************************
 * RemoveLastOperation will simply remove the last node that was
 * created off of the front of the linked list 
 * ******************************************************************/
void CalcList::removeLastOperation(){
    try {
        if (head == NULL)
        throw std::logic_error("Cannot Divide by zero");
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
        return;
    }
        node *old = head; //point temp to old head
        head = old -> next; //head pts to what the old head "next" was pting to
        delete old; //deletes the front LL node
}
/********************************************************************
 * toString will output the elements contained in each node
 * ******************************************************************/
std::string CalcList::toString(unsigned short precision)const{
    node *p,*q; //create temp ptr to scan through list
    double tempTot;
    p = head;
   std::string s1, tempStr;
    while (p != NULL){
        q = p -> next;
        std::ostringstream oss1; 
            if (q == NULL){ 
                tempTot = 0.0;
            }
            else{
                tempTot = q-> total;
            }
            if (p -> opUsed == MULTIPLICATION) //print op sign
               tempStr = "*";
            if (p -> opUsed == SUBTRACTION)
                tempStr = "-";
            if (p -> opUsed == DIVISION)
                tempStr = "/";
            if (p -> opUsed == ADDITION)
                tempStr = "+";
        oss1 << p -> numOps << ": " << std::fixed << std::setprecision(precision) << tempTot << tempStr << p->operand << "=" << p->total;
       s1 = s1 + oss1.str() + "\n"; 
       p = p->next; 
    }
    return s1; 
}
