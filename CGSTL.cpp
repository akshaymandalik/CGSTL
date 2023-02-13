#include<iostream>
using namespace std;

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

#pragma pack(1)
template <class T>
struct NodeD{

    T iData;
    struct NodeD * next;
    struct NodeD * prev;
};

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

#pragma pack(1)
template <class T>
struct NodeS{

    T iData;
    struct NodeS * next;
};

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
class DoublyCL{
    public: 
        struct NodeD <T> * first;
        struct NodeD <T> * last;

        DoublyCL();
        void insertFirst(T iNo);
        void insertLast(T iNo);
        void insertAtPosition(T iNo,int iPos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPosition(int iPos);
        void display();
        int count();
        int findFirstOccurence(T iNo);
        int findLastOccurence(T iNo);
        bool searchElement(T iNo);
        int getFrequency(T iNo);
        T findMax();
        T findMin();
        T addElements();
        T findSecondMax();
        DoublyCL<int> findPerfect();
        DoublyCL<int> findPrime();
        DoublyCL<int> findEven();
        DoublyCL<int> findOdd();
        DoublyCL<int> addDigitOfElements();
};

//**********************************
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************

template <class T>
DoublyCL <T>:: DoublyCL(){
   
    first= NULL;
    last = NULL;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
void DoublyCL<T>:: insertFirst(T iNo){

    struct NodeD <T> *newn = new  NodeD<T>;
    newn->iData = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL){
        
        first = last = newn;
        first->next =first;
        first->prev =first;
    }
    else{
        newn->next = first;
        first->prev = newn;
        newn->prev = last;
        last->next = newn;
        first = newn;
    }

}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
void DoublyCL<T>::insertLast(T iNo){
    
    struct NodeD <T> * newn = new NodeD<T>;
    newn->next = NULL;
    newn->prev = NULL;
    newn->iData = iNo;

    if(first == NULL && last == NULL){

        first = last = newn;
        first->next = first;
        first->prev= newn;

    }
    else{

        last->next = newn;
        newn->prev = last;
        newn->next = first;
        first->prev = newn;
        last = newn;
    }
    
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

template <class T>
void DoublyCL<T>::insertAtPosition(T iNo,int iPos){

        int nodeCnt = count();
        int iCnt = 1;
        if(iPos < 1 || iPos > nodeCnt+1){
            cout<<"Invalid Position\n";
            return;
        }
        else if(iPos == 1){

            insertFirst(iNo);

        }else if(iPos == nodeCnt+1){

            insertLast(iNo);
        }
        else{
            struct NodeD<T> * newn = new NodeD<T>;
            struct NodeD<T> * temp = first;
            newn->iData = iNo;
            newn->next = NULL;
            newn->prev = NULL;

            while(iCnt < iPos -1){
                temp = temp->next;
                iCnt++;
            }
            newn->next = temp->next;
            newn->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
        }
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

template <class T>
void DoublyCL<T>::deleteFirst(){

        if(first == NULL && last == NULL){
           
            cout<<"Unable to delete..(Empty List)\n";
            return;
        }
        else if(first->next == first){
            delete first;
            first = NULL;
            last = NULL;
        }
        else{

            first = first->next;
            last->next = first;
            delete first->prev;
            first->prev = last;
        }

}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
void DoublyCL<T>::deleteLast(){

    if(first == NULL && last == NULL){
        
        cout<<"Unable to delete..(Empty List)\n";
        return;
    }
    else if(first->next == first){
        
        delete first;
        first = NULL;
        last = NULL;
    }
    else{
        
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
void DoublyCL<T>::deleteAtPosition(int iPos){

    int nodeCnt = count();
    int iCnt = 1;

    if(iPos < 1 && iPos > nodeCnt){
        cout<<"Invalid Position\n";
        return;
    }
    else{
        
        struct NodeD<T> * temp = first;

        while(iCnt != iPos-1){
            
            temp = temp->next;
            iCnt++;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
void DoublyCL<T>:: display(){
    
    struct NodeD<T> * temp = first;
    
    if(first == NULL && last == NULL){
        cout<<"Linked List is Empty\n";
        return;
    }
    else{
        do{
            cout<<"<-|"<<temp->iData<<"|->";
            temp = temp->next;

        }while(temp != first);
    }

    cout<<"NULL\n";
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
int DoublyCL<T>::count(){
    
    int iCnt = 0;
    struct NodeD<T> * temp = first;

    if(first == NULL && last == NULL){
        return 0;
    }
    else{

        do{
            iCnt++;
            temp = temp->next;

        }while(temp != first);

    }
    return iCnt;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
int DoublyCL<T>::findFirstOccurence(T iNo){

    struct NodeD<T> * temp = first;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        do
        {
            if(temp->iData == iNo){
                iPos = counter;
                break;
            }
            counter++;
            temp = temp->next;

        }while(temp != last->next);
    } 
    return iPos;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
int DoublyCL<T>::findLastOccurence(T iNo){

    struct NodeD<T> * temp = last;
    int counter = 0;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        do
        {
            if(temp->iData == iNo){
                iPos = counter;
                break;
            }
            counter++;
            temp = temp->prev;

        }while(temp != first->prev);
    } 

    if (iPos != -1)

        return (count()) - (iPos);
    else

        return iPos;    
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
bool DoublyCL<T>::searchElement(T iNo){

    struct NodeD<T> *temp = first;
    bool flag = false;
    if(temp == NULL){

        cout<<"Linked List is Empty.\n";
    }
    else{

        do
        {

            if(temp->iData == iNo){

                flag = true;
                break;
            }
            temp = temp->next;

        }while(temp != last->next);

    }
    return flag;
}


//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

template <class T>
int DoublyCL<T>::getFrequency(T iNo){

    struct NodeD<T> *temp = first;
    int iCnt = 0;
    if(temp == NULL){
        cout<<"Linked List is Empty";
        return -1;
    }
    else{

        do
        {

            if(temp->iData == iNo){
                iCnt++;
            }

            temp = temp->next;

        }while(temp != last->next);

    }
    return iCnt;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
T DoublyCL<T>::findMax(){

    T max = first->iData;
    struct NodeD<T> *temp = first->next;

    do
    {

        if(temp->iData > max){

            max = temp->iData;
        }

        temp = temp->next;

    }while(temp != last->next);

    return max;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

template <class T>
T DoublyCL<T>::addElements(){

    T sum = 0;
    struct NodeD<T>*temp = first;
    do
    {

        sum = sum+temp->iData;
        temp = temp->next;

    }while(temp != last->next);

    return sum;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
T DoublyCL<T>::findMin(){

    T min = first->iData;
    struct NodeD<T> *temp = first->next;

    do{

        if(temp->iData < min){

            min = temp->iData;
        }

        temp = temp->next;
    }while(temp != last->next);

    return min;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <>
DoublyCL<int> DoublyCL<int>::findPerfect(){

    struct NodeD<int> *temp = first;
    int iCnt,Sum = 0;

    DoublyCL<int> tempObj;

    do
    {
        Sum = 0;
        for(iCnt = 1.0;iCnt <= ((temp->iData)/ 2);iCnt++ ){

            if( (temp->iData) % iCnt == 0.0){

                Sum = Sum + iCnt;
            }

         }
         if((temp->iData) == Sum){
            
            tempObj.insertLast(temp->iData);
         }
         temp = temp->next;
    }while(temp != last->next);

    return tempObj;
    
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <>
DoublyCL<int> DoublyCL<int>::findPrime(){

    struct NodeD<int> *temp = first;
    int iCnt = 0;
    bool flag = true;

    DoublyCL<int> tempObj;

    do{

        flag = true;

        for(iCnt = 2;iCnt<((temp->iData)/2);iCnt++){

            if((temp->iData) % iCnt == 0){

                flag = false;
                break;
            }
        }

        if(flag == true){

            tempObj.insertLast(temp->iData);
        }

        temp = temp->next;  

    }while(temp != last->next);

    return tempObj;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <>
DoublyCL<int> DoublyCL<int>::findEven(){

    struct NodeD<int> * temp = first;
    bool flag = false;

    DoublyCL<int> tempObj;

    do{

        if((temp->iData) % 2 == 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
        
    }while(temp != last->next);

    if(flag == false){
        cout<<"No Even Elements\n";
    }

    return tempObj;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <>

DoublyCL<int> DoublyCL<int>::findOdd(){

    struct NodeD<int> * temp = first;
    bool flag = false;
    DoublyCL<int> tempObj;
    do{

        if((temp->iData) % 2 != 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;

    }while(temp != last->next);

    if(flag == false){
        cout<<"No Odd Elements\n";
    }

    return tempObj;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>

T DoublyCL<T>::findSecondMax(){

    struct NodeD <T> * temp = first;
    T iMax1 = 0.0,iMax2 = 0.0;

    if(temp == NULL){
     cout<<"There is no Element in Linked List\n";
    }
    else{
        do{

            if((temp->iData) >iMax1){

                iMax2 = iMax1;
                iMax1 = temp->iData;
            }
            else if((temp->iData) > iMax2){

                iMax2 = temp->iData;
            }
            temp = temp->next;
        }while(temp != last->next);
    }

    return iMax2;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <>
DoublyCL<int> DoublyCL<int>::addDigitOfElements(){

    struct NodeD<int> *temp = first;
    int Sum,tempElement;
    DoublyCL<int> tempObj;
    int iDigit;

    if(temp == NULL){
        cout<<"No Elements inserted.\n";
    }
    else{

        do
        {
            tempElement = temp->iData;
            Sum = 0;
            while(tempElement != 0){

                iDigit = tempElement % 10;
                Sum = Sum + iDigit;
                tempElement = tempElement / 10;
            }

            tempObj.insertLast(Sum);
            temp = temp->next;
        }while(temp != last->next);
    }
    return tempObj;
}

/******************************************************************************************
     
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Class : doublyLL
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This is the class of doubly linear linked list.
     
********************************************************************************************/


template <class T>
class DoublyLL{

    public:
        struct NodeD<T> * Head;

        DoublyLL();
        void insertFirst(T iNo);
        void insertLast(T iNo);
        void insertAtPosition(T iNo, int iPos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPosition(int iPos);
        void display();
        int count();
        int findFirstOccurence(T iNo);
        int findLastOccurence(T iNo);
        bool searchElement(T iNo);
        int getFrequency(T iNo);
        T findMax();
        T findMin();
        T addElements();
        T findSecondMax();
        DoublyLL<int> findPerfect();
        DoublyLL<int> findPrime();
        DoublyLL<int> findEven();
        DoublyLL<int> findOdd();
        DoublyLL<int> addDigitOfElements();
};

/*************************************************************************************
   
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Constructor : doublyLL
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This is the constructor of doubly Linear linked list.
     
************************************************************************************/

template <class T>
DoublyLL<T>::DoublyLL(){

    Head = NULL;
}

/**************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertFirst
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function inserts an element at first position of doubly 
                    Linear linked list.
                    
**************************************************************************************/

template <class T>
void DoublyLL<T>::insertFirst(T iNo){

    struct NodeD <T> * newn = new NodeD<T>;
    newn->iData = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL){
        Head = newn;
    }
    else{

        newn->next = Head;
        Head->prev= newn;
        Head = newn;
    }
}

/*****************************************************************************************
     
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertLast
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function inserts an element at last position of  doubly Linear 
                  linked list.

*******************************************************************************************/

template <class T>
void DoublyLL<T>::insertLast(T iNo){

    struct NodeD<T> * newn = new NodeD<T>;
    newn->iData = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL){
        Head = newn;
    }
    else{
        struct NodeD<T> * temp= Head;
        while(temp->next != NULL){
            temp= temp->next;
        }
        temp->next = newn;
        newn->prev = temp;

    }
}

/*********************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertAtPosition
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo,int iPos
     Description: This function inserts an element at specific position in doubly Linear 
                  linked list.

**********************************************************************************************/

template <class T>
void DoublyLL<T>::insertAtPosition(T iNo,int iPos){

    int nodeCnt = count();
    int iCnt = 1;

    if(iPos < 1 || iPos > nodeCnt+1){
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1){
        insertFirst(iNo);
    }
    else if(iPos == nodeCnt+1){
        insertLast(iNo);
    }
    else{

        struct NodeD <T>* temp = Head;
        struct NodeD <T>* newn = new NodeD<T>;
        newn->iData = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        while(iCnt<iPos-1){

            temp = temp->next;
            iCnt++;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
}

/******************************************************************************************
     
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteFirst
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function deletes first element of doubly Linear linked list.

*******************************************************************************************/

template <class T>
void DoublyLL<T>::deleteFirst(){

        
        if(Head == NULL){
            cout<<"Linked List is Empty\n";
            return;
        }
        else if(Head->next == NULL){

                delete Head;
                Head = NULL;
        }
        else{

            Head = Head->next;
            delete Head->prev;
            Head->prev = NULL;
        }

}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteLast
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function deletes last element of doubly Linear linked list.

****************************************************************************************/


template <class T>
void DoublyLL<T>::deleteLast(){

    if(Head == NULL){
        cout<<"Linked List is Empty\n";
        return;
    }
    else if(Head->next == NULL){
        delete Head;
        Head = NULL;

    }
    else{
        struct NodeD <T>* temp = Head;
        while(temp->next->next != NULL){

            temp = temp->next;

        }

        temp->next->prev = NULL;
        delete temp->next;
        temp->next = NULL;
    }
}

/*************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : deleteAtPosition
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : T iData
     Description: This function deletes the element from  given position from
                  Doubly Linear linked list.
                  
***************************************************************************************/

template <class T>
void DoublyLL<T>::deleteAtPosition(int iPos){

    int nodeCnt = count();
    int iCnt = 1;

    if(iPos<1 || iPos > nodeCnt){
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos ==1){
        deleteFirst();
    }
    else if(iPos == nodeCnt){
        deleteLast();
    }
    else{

        struct NodeD <T>* temp1 = Head;
        struct NodeD <T>* temp2 = NULL;
        while(iCnt<iPos-1){
            
            temp1 = temp1->next;
            iCnt++;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
        temp2 = NULL;
    }

}

/*****************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : display
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function displays the elements of doubly  Linear linked list.
     
******************************************************************************************/


template <class T>
void DoublyLL<T>::display(){

    struct NodeD<T>*temp = Head;
    cout<<"NULL";
    if(Head == NULL){
        cout<<"Empty Linked List\n";
        return;
    }
    else{
        while(temp != NULL){
            cout<<"<-|"<<temp->iData<<"|->";
            temp = temp->next;
        }
    }
    cout<<"NULL\n";
}

/***********************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : count
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function counts the number of elements from doubly Linear linked list.

*************************************************************************************************/


template <class T>
int DoublyLL<T>::count(){
    
    int iCnt = 0;

    struct NodeD<T>*temp = Head;
    if(Head == NULL){
        cout<<"Empty Linked List\n";
        return 0;
    }
    else{
        while(temp!= NULL){
            iCnt++;
            temp =temp->next;
        }
    }
    return iCnt;
}

/**************************************************************************************************
         
         Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
         Name of the Function : findFirstOccurance
         Name of the Author : Akshay Haribhau Mandalik
         Date : 13 April 2022
         Parameters : T iNo
         Description: This function returns the index of first occurence of the given 
                       element from doubly Linear linked list.
         
***************************************************************************************************/

template <class T>
int DoublyLL<T>::findFirstOccurence(T iNo){

    struct NodeD<T> * temp = Head;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        while(temp != NULL){
            if(temp->iData == iNo){
                iPos = counter;
                break;
            }
            counter++;
            temp = temp->next;
        }
    } 
    return iPos;
}

/***************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findLastOccurance
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the last occurance index of given element
                 from Doubly Linear linked list.
                 
***************************************************************************************/

template <class T>
int DoublyLL<T>::findLastOccurence(T iNo){

    struct NodeD<T> * temp = Head;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        while(temp != NULL){
            if(temp->iData == iNo){
                iPos = counter;
                
            }
            counter++;
            temp = temp->next;
        }
    } 
    return iPos;
}

/********************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : searchElement
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the boolean value depends upon number is present
                  or not in doubly Linear linked list.

********************************************************************************* **************/


template <class T>
bool DoublyLL<T>::searchElement(T iNo){

    struct NodeD<T> *temp = Head;
    bool flag = false;
    if(temp == NULL){

        cout<<"Linked List is Empty.\n";
    }
    else{

        while(temp != NULL){

            if(temp->iData == iNo){

                flag = true;
                break;
            }
            temp = temp->next;
        }
    }
    return flag;
}

/********************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : getFrequency
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the frequency of given element from doubly Linear linked list.

*********************************************************************************************************/

template <class T>
int DoublyLL<T>::getFrequency(T iNo){

    struct NodeD<T> *temp = Head;
    int iCnt = 0;
    if(Head == NULL){
        cout<<"Linked List is Empty";
        return -1;
    }
    else{
        while(temp!= NULL){

            if(temp->iData == iNo){
                iCnt++;
            }

            temp = temp->next;
        }
    }
    return iCnt;
}

/********************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findMax
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the largest element of doubly Linear linked list.
     
*********************************************************************************************/

template <class T>
T DoublyLL<T>::findMax(){

    T max = Head->iData;
    struct NodeD<T> *temp = Head->next;

    while(temp != NULL){

        if(temp->iData > max){

            max = temp->iData;
        }

        temp = temp->next;
    }

    return max;
}

/************************************************************************************************ 


     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : addElements
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the addition of elements from doubly Linear linked list.

*************************************************************************************************/


template <class T>
T DoublyLL<T>::addElements(){

    T sum = 0;
    struct NodeD<T>*temp = Head;
    while(temp!= NULL){

        sum = sum+temp->iData;
        temp = temp->next;  
    }

    return sum;
}

/********************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findMin
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the smallest element of doubly Linear linked list.
     
*********************************************************************************************/


template <class T>
T DoublyLL<T>::findMin(){

    T min = Head->iData;
    struct NodeD<T> *temp = Head->next;

    while(temp != NULL){

        if(temp->iData < min){

            min = temp->iData;
        }

        temp = temp->next;
    }

    return min;
}

/**************************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findPerfect (Only Applicable for int datatype)
     Name of the Author : Payal Shrikrushna Deshpande
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains perfect no from 
                  doubly Linear linked list.

**************************************************************************************************/

template <>
DoublyLL<int> DoublyLL<int>::findPerfect(){

    struct NodeD<int> *temp = Head;
    int iCnt,Sum = 0;

    DoublyLL<int> tempObj;

    while(temp != NULL){

        Sum = 0;
        for(iCnt = 1;iCnt <= ((temp->iData)/ 2);iCnt++ ){

            if( (temp->iData) % iCnt == 0){

                Sum = Sum + iCnt;
            }

         }
         if((temp->iData) == Sum){
            
            tempObj.insertLast(temp->iData);
         }
         temp = temp->next;
    }

    return tempObj;
    
}

/**********************************************************************************************

     Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findPrime (only applicable for int datatype)
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the linked list which contains prime no
                  from doubly Linear linked list.

***********************************************************************************************/

template <>
DoublyLL<int> DoublyLL<int>::findPrime(){

    struct NodeD<int> *temp = Head;
    int iCnt = 0;
    bool flag = true;

    DoublyLL<int> tempObj;

    while(temp != NULL){

        flag = true;

        for(iCnt = 2;iCnt<((temp->iData)/2);iCnt++){

            if((temp->iData) % iCnt == 0){

                flag = false;
                break;
            }
        }
        if(flag == true){

            tempObj.insertLast(temp->iData);
        }

        temp = temp->next;  
    }

    return tempObj;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

template <>
DoublyLL<int> DoublyLL<int>::findEven(){

    struct NodeD<int> * temp = Head;
    bool flag = false;

    DoublyLL<int> tempObj;

    while(temp != NULL){

        if((temp->iData) % 2 == 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
    }
    if(flag == false){
        cout<<"No Even Elements\n";
    }

    return tempObj;
}


//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//

template <>

DoublyLL<int> DoublyLL<int>::findOdd(){

    struct NodeD<int> * temp = Head;
    bool flag = false;
    DoublyLL<int> tempObj;
    while(temp != NULL){

        if((temp->iData) % 2 != 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
    }
    if(flag == false){
        cout<<"No Odd Elements\n";
    }

    return tempObj;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <class T>
T DoublyLL<T>::findSecondMax(){

    struct NodeD <T> * temp = Head;
    T iMax1 = 0.0,iMax2 = 0.0;

    if(temp == NULL){
     cout<<"There is no Element in Linked List\n";
    }
    else{
        while(temp != NULL){

            if((temp->iData) >iMax1){

                iMax2 = iMax1;
                iMax1 = temp->iData;
            }
            else if((temp->iData) > iMax2){

                iMax2 = temp->iData;
            }
            temp = temp->next;
        }
    }

    return iMax2;
}

//**********************************//
// Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
// Name of the Class : singlyLinear
// Name of the Author : Akshay Haribhau Mandalik.
// Date : 13 April 2022
// Parameters : None
// Description: This is the class for singly linear linked list
//**********************************//


template <>
DoublyLL<int> DoublyLL<int>::addDigitOfElements(){

    struct NodeD<int> *temp = Head;
    int Sum,tempElement;
    DoublyLL<int> tempObj;
    int iDigit;

    if(temp == NULL){
        cout<<"No Elements inserted.\n";
    }
    else{

        while(temp != NULL){

            tempElement = temp->iData;
            Sum = 0;
            while(tempElement != 0){

                iDigit = tempElement % 10;
                Sum = Sum + iDigit;
                tempElement = tempElement / 10;
            }

            tempObj.insertLast(Sum);
            temp = temp->next;
        }
    }
    return tempObj;
}

/****************************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the class : SinglyCL
      Name of the Author : Akshay Haribhau Mandalik
      Date : 13 April 2022
      Parameters : None
      Description: This class represents the singly circular linked list.

******************************************************************************************/

template <class T>
class SinglyCL{

    public:
        struct NodeS<T> * Head;
        struct NodeS<T> * Tail;

        SinglyCL();
        void insertFirst(T iNo);
        void insertLast(T iNo);
        void insertAtPosition(T iNo,int iPos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPosition(int iPos);
        void display();
        int count();
        int findFirstOccurence(T iNo);
        int findLastOccurence(T iNo);
        bool searchElement(T iNo);
        int getFrequency(T iNo);
        T findMax();
        T findMin();
        T addElements();
        T findSecondMax();
        SinglyCL<int> findPerfect();
        SinglyCL<int> findPrime();
        SinglyCL<int> findEven();
        SinglyCL<int> findOdd();
        SinglyCL<int> addDigitOfElements();

};

/**********************************************************************************

    Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
    Name of the Constructor : SinglyCL
    Name of the Author : Akshay Haribhau Mandalik
    Date : 13 April 2022
    Parameters : None
    Description: This is the constructor of singly circular linked list.

************************************************************************************/


template <class T>
SinglyCL<T>::SinglyCL(){
    Head = NULL;
    Tail = NULL;
}

/*************************************************************************************

    Name of the Project : Customized Generalized Standard Template Library(CGSTL)
    Name of the Function : display
    Name of the Author : Akshay Haribhau Mandalik
    Date : 13 April 2022
    Parameters : None
    Description: This function displays the elements of singly circular linked list.

****************************************************************************************/


template <class T>
void SinglyCL<T>::display(){

    struct NodeS <T> *temp = Head;
    if(Head == NULL && Tail == NULL){
        cout<<"Empty LinkedList\n";
        return;
    }
    else{
        do{
            cout<<"|"<<temp->iData<<"|->";
            temp= temp->next;

        }while(temp != Head);
    }
    cout<<"NULL\n";
}

/**********************************************************************************************
 
     Name of the Project :Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : count
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the number of elements of singly circular linked list.

***********************************************************************************************/


template <class T>

int SinglyCL<T>::count(){

    struct NodeS <T> *temp = Head;
    int iCnt = 0;
    do{
        iCnt++;
        temp = temp->next;

    }while(temp != Head);

    return iCnt;
}

/*******************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Library(CGSTL)
    Name of the Function : insertFirst
    Name of the Author : Akshay Haribhau Mandalik
    Date : 13 April 2022
    Parameters : T iNo
    Description: This function inserts the element at first position of singly circular linked list.

********************************************************************************************************/


template <class T>
void SinglyCL<T>::insertFirst(T iNo){

    struct NodeS<T> *newn = new NodeS<T>;
    newn->iData = iNo;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL){
        Head = Tail = newn;
        Tail->next = newn;
    }
    else{
        newn->next = Head;
        Head = newn;
        Tail->next = Head;
    }
}


/*****************************************************************************************************

    Name of the Project :Customized Generalized Standard Template Library(CGSTL)
    Name of the Function : insertLast
    Name of the Author : Akshay Haribhau Mandalik
    Date : 13 April 2022
    Parameters : T iNo
    Description: This function inserts the element at last position of singly circular linked list.

*******************************************************************************************************/

template <class T>
void SinglyCL<T>::insertLast(T iNo){

    struct NodeS<T> * newn= new NodeS<T>;
    struct NodeS<T> * temp = Head;
    newn->iData = iNo;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL){
        Head = Tail = newn;
        Tail->next = newn;
    }else{

       Tail->next = newn;
       Tail = newn;
       newn->next= Head;
    }
}

/********************************************************************************

Name of the Project :Customized Generalized Standard Template Library(CGSTL)
Name of the Function : insertAtPos
Name of the Author : Akshay Haribhau Mandalik
Date : 13 April 2022
Parameters : T iNo,int iPos
Description: This function inserts an element at specific position to singly 
             circular linked list.

**********************************************************************************/

template <class T>
void SinglyCL<T>::insertAtPosition(T iNo,int iPos){
    
    int nodeCnt = count();
    int iCnt = 1;
    struct NodeS <T> *temp = Head;

    if(iPos < 1 || iPos > nodeCnt+1){
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1){
        insertFirst(iNo);
    }
    else if(iPos == nodeCnt+1){
        insertLast(iNo);
    }
    else{

        struct NodeS<T> *newn = new NodeS<T>;
        newn->iData = iNo;
        newn->next = NULL;

        while(iCnt < iPos -1){
            temp = temp->next;
            iCnt++;
        }
        newn->next = temp->next;
        temp->next = newn;

    }

}


/***************************************************************************************

    Name of the Project :Customized Generalized Standard Template Library(CGSTL)
    Name of the Function : deleteFirst
    Name of the Author : Akshay Haribhau Mandalik
    Date : 13 April 2022
    Parameters : None
    Description: This function deletes first element from singly circular 
                 linked list.

****************************************************************************************/

template <class T>
void SinglyCL<T>::deleteFirst(){

        if(Head == NULL && Tail == NULL){
            cout<<"Empty Linked List\n";
            return;
        }
        else if(Head->next == Head){
             delete Head;
             Head = Tail = NULL;
        }
        else{

            struct NodeS<T> * temp = Head;
            Head = Head->next;
            delete temp;
            Tail->next = Head;
        }
}

/*****************************************************************************************

    Name of the Project :Customized Generalized Standard Template Library(CGSTL)
    Name of the Function : deleteLast
    Name of the Author : Akshay Haribhau Mandalik
    Date : 13 April 2022
    Parameters :None
    Description: This function deletes the last element from singly 
                 circular linked list.

********************************************************************************************/


template <class T>
void SinglyCL <T>::deleteLast(){

    if(Head == NULL && Tail == NULL){
        cout<<"Empty Linked List\n";
        return;
    }
    else if(Head->next == Head){
        delete Head;
        Head = Tail = NULL;
    }
    else{

        struct NodeS<T> * temp = Head;
        while(temp->next->next != Head){
            temp= temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;

    }
}


/***************************************************************************************
    
     Name of the Project :Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : deleteAtPosition
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : int iPos
     Description: This function deletes the element of specific position from 
                  singly circular linked list.

*******************************************************************************************/

template <class T>
void SinglyCL<T>::deleteAtPosition(int iPos){

    int nodeCnt = count();
    int iCnt = 1;

    if(Head == NULL && Tail == NULL){

        cout<<"List is Empyt\n";
        return;
    }
    else if(iPos < 1 || iPos > nodeCnt){
        cout<<"Invalid position\n";
        return;
    }
    else if(iPos == 1){
        deleteFirst();
    }
    else if(iPos == nodeCnt){
        deleteLast();
    }
    else{

        struct NodeS<T>* temp1 = Head;
        struct NodeS<T>* temp2 = NULL;

        while(iCnt < iPos-1){
            temp1 = temp1->next;
            iCnt++;
        }
        temp2 = temp1->next->next;
        temp1->next->next = NULL;
        delete temp1->next;
        temp1->next = temp2;
    }
    
}

/*************************************************************************************
 
     Name of the Project :Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : findFirstOccurance
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the first occurrence index of given 
                  element singly circular linked list.

***************************************************************************************/

template <class T>
int SinglyCL<T>::findFirstOccurence(T iNo){

    struct NodeS<T> * temp = Head;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        do
        {
            if(temp->iData == iNo){
                iPos = counter;
                break;
            }
            counter++;
            temp = temp->next;

        }while(temp != Tail->next);
    } 
    return iPos;
}

/************************************************************************************
 
     Name of the Project : Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : findLastOccurance
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the last occurrence index of given element 
                  singly circular linked list.

***************************************************************************************/


template <class T>
int SinglyCL<T>::findLastOccurence(T iNo){

    struct NodeS<T> * temp = Head;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        do
        {
            if(temp->iData == iNo){
                iPos = counter;
            }
            counter++;
            temp = temp->next;
        }while(temp != Tail->next);
    } 
    return iPos;
}

/************************************************************************************
 
     Name of the Project : Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : searchElement
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the true if given element found otherwose false. 

***************************************************************************************/

template <class T>
bool SinglyCL<T>::searchElement(T iNo){

    struct NodeS<T> *temp = Head;
    bool flag = false;
    if(temp == NULL){

        cout<<"Linked List is Empty.\n";
    }
    else{

        do
        {

            if(temp->iData == iNo){

                flag = true;
                break;
            }
            temp = temp->next;

        }while(temp != Tail->next);

    }
    return flag;
}


/************************************************************************************
 
     Name of the Project : Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : getFrequency
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : T iNo
     Description: This function returns the frequency of given number / character . 

***************************************************************************************/

template <class T>
int SinglyCL<T>::getFrequency(T iNo){

    struct NodeS<T> *temp = Head;
    int iCnt = 0;
    if(Head == NULL){
        cout<<"Linked List is Empty";
        return -1;
    }
    else{

        do
        {

            if(temp->iData == iNo){
                iCnt++;
            }

            temp = temp->next;

        }while(temp != Tail->next);

    }
    return iCnt;
}

/*********************************************************************************************
     
     Name of the Project :Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : findMax
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the largest element 
                  from singly circular linked list.
     
***********************************************************************************************/


template <class T>
T SinglyCL<T>::findMax(){

    T max = Head->iData;
    struct NodeS<T> *temp = Head->next;

    do
    {

        if(temp->iData > max){

            max = temp->iData;
        }

        temp = temp->next;

    }while(temp != Tail->next);

    return max;
}

/************************************************************************************
 
     Name of the Project : Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : addElements
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the addition of all elements in Singly 
                  Circular Linked List. 

***************************************************************************************/


template <class T>
T SinglyCL<T>::addElements(){

    T sum = 0;
    struct NodeS<T>*temp = Head;
    do
    {

        sum = sum+temp->iData;
        temp = temp->next;

    }while(temp != Tail->next);

    return sum;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Library(CGSTL)
     Name of the Function : findMin
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the smallest element from 
                  singly circular linked list.
     
*****************************************************************************************/

template <class T>
T SinglyCL<T>::findMin(){

    T min = Head->iData;
    struct NodeS<T> *temp = Head->next;

    do{

        if(temp->iData < min){

            min = temp->iData;
        }

        temp = temp->next;
    }while(temp != Tail->next);

    return min;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findPerfect (Applicable for only Int Datatype )
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the singly Circular Linked List of perfect numbers from 
                  given singly circular linked list.
     
*****************************************************************************************/

template <>
SinglyCL<int> SinglyCL<int>::findPerfect(){

    struct NodeS<int> *temp = Head;
    int iCnt,Sum = 0;

    SinglyCL<int> tempObj;

    do
    {
        Sum = 0;
        for(iCnt = 1;iCnt <= ((temp->iData)/ 2);iCnt++ ){

            if( (temp->iData) % iCnt == 0){

                Sum = Sum + iCnt;
            }

         }
         if((temp->iData) == Sum){
            
            tempObj.insertLast(temp->iData);
         }
         temp = temp->next;
    }while(temp != Tail->next);

    return tempObj;
    
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findPrime (Applicable for only Int Datatype )
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the Singly Circular Linked List of Prime Numbers
                  from given singly circular linked list.
     
*****************************************************************************************/

template <>
SinglyCL<int> SinglyCL<int>::findPrime(){

    struct NodeS<int> *temp = Head;
    int iCnt = 0;
    bool flag = true;

    SinglyCL<int> tempObj;

    do{

        flag = true;

        for(iCnt = 2;iCnt<((temp->iData)/2);iCnt++){

            if((temp->iData) % iCnt == 0){

                flag = false;
                break;
            }
        }

        if(flag == true){

            tempObj.insertLast(temp->iData);
        }

        temp = temp->next;  

    }while(temp != Tail->next);

    return tempObj;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findEven (Applicable for only Int Datatype)
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the Singly Circular Linked List of even elements
                  from given singly circular linked list.
     
*****************************************************************************************/

template <>
SinglyCL<int> SinglyCL<int>::findEven(){

    struct NodeS<int> * temp = Head;
    bool flag = false;

    SinglyCL<int> tempObj;

    do{

        if((temp->iData) % 2 == 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
        
    }while(temp != Tail->next);

    if(flag == false){
        cout<<"No Even Elements\n";
    }

    return tempObj;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findOdd (Applicable for only Int Datatype)
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the Singly Circular Linked List of Odd elements
                  from given singly circular linked list.
     
*****************************************************************************************/

template <>

SinglyCL<int> SinglyCL<int>::findOdd(){

    struct NodeS<int> * temp = Head;
    bool flag = false;
    SinglyCL<int> tempObj;
    do{

        if((temp->iData) % 2 != 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
    }while(temp != Tail->next);

    if(flag == false){
        cout<<"No Odd Elements\n";
    }

    return tempObj;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : findSecondMax
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns second maximum element from given singly circular linked list.
     
*****************************************************************************************/


template <class T>

T SinglyCL<T>::findSecondMax(){

    struct NodeS <T> * temp = Head;
    T iMax1 = 0,iMax2 = 0;

    if(temp == NULL){
     cout<<"There is no Element in Linked List\n";
    }
    else{
        do{

            if((temp->iData) >iMax1){

                iMax2 = iMax1;
                iMax1 = temp->iData;
            }
            else if((temp->iData) > iMax2){

                iMax2 = temp->iData;
            }
            temp = temp->next;
        }while(temp != Tail->next);
    }

    return iMax2;
}


/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : addDigitOfElements (Applicable for only Int Datatype)
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function returns the Singly Circular Linked List of addition of each 
                  element from given singly circular linked list.
     
*****************************************************************************************/

template <>
SinglyCL<int> SinglyCL<int>::addDigitOfElements(){

    struct NodeS<int> *temp = Head;
    int Sum,tempElement;
    SinglyCL<int> tempObj;
    int iDigit;

    if(temp == NULL){
        cout<<"No Elements inserted.\n";
    }
    else{

        do
        {
            tempElement = temp->iData;
            Sum = 0;
            while(tempElement != 0){

                iDigit = tempElement % 10;
                Sum = Sum + iDigit;
                tempElement = tempElement / 10;
            }

            tempObj.insertLast(Sum);
            temp = temp->next;
        }while(temp != Tail->next);
    }
    return tempObj;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Class : SinglyLL 
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This class represents the singly circular linked list

*****************************************************************************************/


template <class T>
class SinglyLL{

    public:
        struct NodeS <T> * Head;
        SinglyLL();
        void insertFirst(T iNo);
        void insertLast(T iNo);
        void insertAtPosition(T iNo,int iPos);
        void deleteFirst();
        void deleteLast();
        void deleteAtPosition(int iPos);
        void display();
        int count();
        void singlyReverse();
        int findFirstOccurence(T iNo);
        int findLastOccurence(T iNo);
        bool searchElement(T iNo);
        int getFrequency(T iNo);
        T findMax();
        T findMin();
        T addElements();
        T findSecondMax();
        SinglyLL<int> findPerfect();
        SinglyLL<int> findPrime();
        SinglyLL<int> findEven();
        SinglyLL<int> findOdd();
        SinglyLL<int> addDigitOfElements();

};


/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : SinglyLL 
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This is the constructor of the Class SinglyLL
     
*****************************************************************************************/

template <class T>
SinglyLL <T>::SinglyLL(){
    Head = NULL;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : display 
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function displays all the elements in the Singly Linear LinkedList
     
*****************************************************************************************/

template <class T>
void SinglyLL<T>:: display(){

    struct NodeS <T> * temp = Head;
    if(Head == NULL){
        cout<<"Link List is Empty\n";
        return;
    }else{
        while(temp != NULL){
            cout<<"|"<<temp->iData<<"|->";
            temp = temp->next;
        }
    }
    cout<<"NULL\n";
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : count 
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function return the no. of elements in the Singly Linear LinkedList
     
*****************************************************************************************/

template <class T>

int SinglyLL<T>::count(){

    struct NodeS<T> *temp = Head;
    int iCnt = 0;
    while(temp != NULL){
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertFirst 
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function inserts the element at first position of Singly Linear LinkedList
     
*****************************************************************************************/

template <class T>
void SinglyLL<T>::insertFirst(T iNo)
{

    struct NodeS<T> * newn = new NodeS<T>;

    newn->iData = iNo;

    newn->next = NULL;

    if(Head == NULL){
        Head = newn;
    }
    else{
        newn->next = Head;
        Head = newn;
    }
}

/**************************************************************************************
     
     Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
     Name of the Function : insertLast
     Name of the Author : Akshay Haribhau Mandalik
     Date : 13 April 2022
     Parameters : None
     Description: This function inserts the element at last position of Singly Linear LinkedList
     
*****************************************************************************************/

template <class T>
void SinglyLL<T>::insertLast(T iNo){

    struct NodeS<T> * newn = new NodeS<T>;
    struct NodeS<T> * temp = Head;

    newn->iData = iNo;

    newn->next = NULL;

    if(Head == NULL){
        Head = newn;
    }
    else{
        while(temp->next!= NULL){
            temp= temp->next;
        }
        temp->next = newn;
    }
}

/**********************************************************************************

      Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : insertAtPosition
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function inserts the element at given position.
      
**********************************************************************************/


template <class T>

void SinglyLL<T>::insertAtPosition(T iNo, int iPos)
{
    int NodeCnt = count();
    int iCnt = 1;

    if(iPos < 1 || iPos > NodeCnt+1){
        cout<<"Invalid Position\n";
        return;
    }
    if(iPos == 1){
        insertFirst(iNo);
    }
    else if(iPos == NodeCnt+1){
        insertLast(iNo);
    }
    else{

        struct NodeS <T> * temp = Head;
        struct NodeS <T> * newn = new NodeS<T>;
        newn->iData = iNo;
        newn->next = NULL;

        while(iCnt < iPos-1){
            iCnt++;
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }

}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : deleteFirst
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function deletes the first element from given Singly Linear Linked List.
      
**********************************************************************************/



template <class T>
void SinglyLL<T>::deleteFirst(){

    if(Head == NULL){
        cout<<"Empty List\n";
        return;
    }
    else if(Head->next==NULL){
        delete Head;
        Head = NULL;
    }
    else{
        struct NodeS <T> * temp = Head;
        Head = Head->next;
        delete temp;
    }
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : deleteLast
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function deletes the last element from given Singly Linear Linked List.
      
**********************************************************************************/


template <class T>
void SinglyLL<T>::deleteLast()
{
    if(Head == NULL){
        cout<<"Empty List\n";
        return;
    }
    else if(Head->next == NULL){
        delete Head;
        Head = NULL;
    }
    else{
        struct NodeS <T> * temp = Head;

        while(temp->next->next != NULL){

            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

/**********************************************************************************

      Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : deleteAtPosition
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : int iPos
      Description: This is the function deletes the element from given position 
                   from given Singly Linear Linked List.
      
**********************************************************************************/


template <class T>
void SinglyLL <T>:: deleteAtPosition(int iPos){

    int NodeCnt = count();
    int iCnt = 1;

    if(Head == NULL){
        cout<<"Linked List is Empty\n";
        return;
    }
    else if(iPos <1 || iPos > NodeCnt){
        cout<<"Invalid Position\n";
        return;
    }
    if(iPos == 1){
      
        deleteFirst();
    }
    else if(iPos == NodeCnt){
      
        deleteLast();
    }
    else{

        struct NodeS <T> * temp1 = Head;
        struct NodeS <T> * temp2 = NULL;

        while(iCnt < iPos-1){
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        temp1->next->next= NULL;
        delete temp1->next;
        temp1->next = temp2;

    }

}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : singlyReverse
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function reverses the given Singly Linear Linked List.
      
**********************************************************************************/


template <class T>
void SinglyLL<T>::singlyReverse(){

    struct NodeS<T> * Next = NULL;
    struct NodeS<T> * Previous = NULL;
    struct NodeS<T> * current = Head;

    while(current != NULL){

        Next = current->next;
        current->next = Previous;
        Previous = current;
        current = Next;
    }
    Head = Previous;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findFirstOccurence
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : T iNo
      Description: This is the function returns the first occurence of the 
                   given element in the Singly Linear Linked List
      
**********************************************************************************/


template <class T>
int SinglyLL<T>::findFirstOccurence(T iNo){

    struct NodeS<T> * temp = Head;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        while(temp != NULL){
            if(temp->iData == iNo){
                iPos = counter;
                break;
            }
            counter++;
            temp = temp->next;
        }
    } 
    return iPos;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findLastOccurence
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : T iNo
      Description: This is the function returns the last occurence of the 
                   given element in the Singly Linear Linked List

**********************************************************************************/


template <class T>
int SinglyLL<T>::findLastOccurence(T iNo){

    struct NodeS<T> * temp = Head;
    int counter = 1;
    int iPos = -1;
    if(temp == NULL){
        cout<<"Linked List is Empty..\n";
    }
    else{

        while(temp != NULL){
            if(temp->iData == iNo){
                iPos = counter;
            }
            counter++;
            temp = temp->next;
        }
    } 
    return iPos;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : searchElement
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : T iNo
      Description: This is the function returns true if  element found and false if element not found
                   
**********************************************************************************/


template <class T>
bool SinglyLL<T>::searchElement(T iNo){

    struct NodeS<T> *temp = Head;
    bool flag = false;
    if(temp == NULL){

        cout<<"Linked List is Empty.\n";
    }
    else{

        while(temp != NULL){

            if(temp->iData == iNo){

                flag = true;
                break;
            }
            temp = temp->next;
        }
    }
    return flag;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : getFrequency
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : T iNo
      Description: This is the function returns the frequency of the 
                   element from given Singly Linear Linked List.
                   
**********************************************************************************/


template <class T>
int SinglyLL<T>::getFrequency(T iNo){

    struct NodeS<T> *temp = Head;
    int iCnt = 0;
    if(Head == NULL){
        cout<<"Linked List is Empty";
        return -1;
    }
    else{
        while(temp!= NULL){

            if(temp->iData == iNo){
                iCnt++;
            }

            temp = temp->next;
        }
    }
    return iCnt;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findMax
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns the minimum element 
                    from given Singly Linear Linked List.
                   
**********************************************************************************/


template <class T>
T SinglyLL<T>::findMax(){

    T max = Head->iData;
    struct NodeS<T> *temp = Head->next;

    while(temp != NULL){

        if(temp->iData > max){

            max = temp->iData;
        }

        temp = temp->next;
    }

    return max;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : addElements
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns the addition of elements 
                   from given Singly Linear Linked List.
                   
**********************************************************************************/


template <class T>
T SinglyLL<T>::addElements(){

    T sum = 0;
    struct NodeS<T>*temp = Head;
    while(temp!= NULL){

        sum = sum+temp->iData;
        temp = temp->next;  
    }

    return sum;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findMin
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns the Minimum element from
                   given Singly Linear Linked List.
                   
**********************************************************************************/


template <class T>
T SinglyLL<T>::findMin(){

    T min = Head->iData;
    struct NodeS<T> *temp = Head->next;

    while(temp != NULL){

        if(temp->iData < min){

            min = temp->iData;
        }

        temp = temp->next;
    }

    return min;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findPerfect (Applicable for only Int Datatype)
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns 
                   Singly Linear Linked List of Perfect numbers from 
                   given Singly Linear Linked List

**********************************************************************************/


template <>
SinglyLL<int> SinglyLL<int>::findPerfect(){

    struct NodeS<int> *temp = Head;
    int iCnt,Sum = 0;

    SinglyLL<int> tempObj;

    while(temp != NULL){

        Sum = 0;
        for(iCnt = 1;iCnt <= ((temp->iData)/ 2);iCnt++ ){

            if( (temp->iData) % iCnt == 0){

                Sum = Sum + iCnt;
            }

         }
         if((temp->iData) == Sum){
            
            tempObj.insertLast(temp->iData);
         }
         temp = temp->next;
    }

    return tempObj;


}

/**********************************************************************************

      Name of the Project : Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findPrime (Applicable for only Int Datatype)
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns 
                   Singly Linear Linked List of Prime numbers from 
                   given Singly Linear Linked List

**********************************************************************************/


template <>
SinglyLL<int> SinglyLL<int>::findPrime(){

    struct NodeS<int> *temp = Head;
    int iCnt = 0;
    bool flag = true;

    SinglyLL<int> tempObj;

    while(temp != NULL){

        flag = true;

        for(iCnt = 2;iCnt<((temp->iData)/2);iCnt++){

            if((temp->iData) % iCnt == 0){

                flag = false;
                break;
            }
        }
        if(flag == true){

            tempObj.insertLast(temp->iData);
        }

        temp = temp->next;  
    }

    return tempObj;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findEven (Applicable for only Int Datatype)
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns 
                   Singly Linear Linked List of even numbers from 
                   given Singly Linear Linked List

**********************************************************************************/


template <>
SinglyLL<int> SinglyLL<int>::findEven(){

    struct NodeS<int> * temp = Head;
    bool flag = false;

    SinglyLL<int> tempObj;

    while(temp != NULL){

        if((temp->iData) % 2 == 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
    }
    if(flag == false){
        cout<<"No Even Elements\n";
    }

    return tempObj;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findOdd (Applicable for only Int Datatype)
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns 
                   Singly Linear Linked List of odd numbers from 
                   given Singly Linear Linked List

**********************************************************************************/


template <>

SinglyLL<int> SinglyLL<int>::findOdd(){

    struct NodeS<int> * temp = Head;
    bool flag = false;
    SinglyLL<int> tempObj;
    while(temp != NULL){

        if((temp->iData) % 2 != 0){

            flag = true;
            tempObj.insertLast(temp->iData);
        }
        temp = temp->next;
    }
    if(flag == false){
        cout<<"No Odd Elements\n";
    }

    return tempObj;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : findSecondMax 
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function returns the second Maximum element
                   from Singly Linear Linked List.

**********************************************************************************/


template <class T>
T SinglyLL<T>::findSecondMax(){

    struct NodeS <T> * temp = Head;
    T iMax1 = 0,iMax2 = 0;

    if(temp == NULL){
     cout<<"There is no Element in Linked List\n";
    }
    else{
        while(temp != NULL){

            if((temp->iData) >iMax1){

                iMax2 = iMax1;
                iMax1 = temp->iData;
            }
            else if((temp->iData) > iMax2){

                iMax2 = temp->iData;
            }
            temp = temp->next;
        }
    }

    return iMax2;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : addDigitOfElements (Applicable for only  int Datatype)
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the function of Singly Linear Linked List which 
                   returns the addition of each digit of each element.

**********************************************************************************/


template <>
SinglyLL<int> SinglyLL<int>::addDigitOfElements(){

    struct NodeS<int> *temp = Head;
    int Sum,tempElement;
    SinglyLL<int> tempObj;
    int iDigit;

    if(temp == NULL){
        cout<<"No Elements inserted.\n";
    }
    else{

        while(temp != NULL){

            tempElement = temp->iData;
            Sum = 0;
            while(tempElement != 0){

                iDigit = tempElement % 10;
                Sum = Sum + iDigit;
                tempElement = tempElement / 10;
            }

            tempObj.insertLast(Sum);
            temp = temp->next;
        }
    }
    return tempObj;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Class : Stack
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the Class of the Stack

**********************************************************************************/


template <class T>

class Stack{

    public: 
    struct NodeS<T> *first;
    int iCnt;

    Stack();
    bool isStackEmpty();
    void push(T iNo);  //insert
    T pop();    //delete
    void display();

};

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : Stack
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the constructor of the Stack Class.

**********************************************************************************/


template <class T>
Stack<T>::Stack(){

    first = NULL;
    iCnt = 0;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : isStackEmpty
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function returns true if stack is empty and 
                   returns false if stack is not empty.

**********************************************************************************/


template <class T>
bool Stack <T>:: isStackEmpty(){

    if(iCnt == 0){
        return true;
    }
    return false;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : push
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function pushes(insert) element in Stack.

**********************************************************************************/

template <class T>
void Stack <T>:: push(T iNo){ //insertFirst

    struct NodeS <T>* newn = new struct NodeS<T>;
    newn->iData = iNo;
    newn->next = NULL;
    if(first == NULL){
        first = newn;   
    }
    else{

        newn->next = first;
        first = newn;
    }
    iCnt++;
    cout<<"Elements Pushed....\n";

}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : pop
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function pops the top most element and returns it from Stack.

**********************************************************************************/


template <class T>
T Stack <T> :: pop(){  //deleteFirst

    T iValue = 0;
    bool bRet = isStackEmpty();
    if(bRet == true){
        cout<<"Unable to pop element as stack is empty..\n";
        return (T)-1;
    }
    else if(first->next == NULL){
        
        iValue = first->iData;
        delete first;
        first = NULL;
    }
    else{
       
        iValue = first->iData;
        struct NodeS <T> *temp = first;
        first = first->next;
        delete temp;

    }
        return iValue;

}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Function : display
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function displays elements of Stack.

**********************************************************************************/

template <class T>
void Stack <T>:: display(){

    if(first == NULL){
        cout<<"Stack is empty\n";
        return;
    }
    else{
        cout<<"Elements of stack are:\n";
        struct NodeS <T> * temp = first;
        while(temp != NULL){
            cout<<"|"<<temp->iData<<"|->";
            temp = temp->next;
        }
    }
    cout<<"NULL\n";
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the Class : Queue
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the class of Queue.

**********************************************************************************/

template <class T>
class Queue{

    public: 
    struct NodeS<T> *first;
    int iCnt;

    Queue();
    bool isQueueEmpty();
    void enQueue(T iNo);  //insert
    T deQueue();    //delete
    void display();

};

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : Queue 
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This is the default constructor of the class.

**********************************************************************************/


template <class T>
Queue<T>::Queue(){

    first = NULL;
    iCnt = 0;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : isQueueEmpty
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function returns true if Queue is Empty and returns false if Queue is Not Empty

**********************************************************************************/


template <class T>
bool Queue<T> :: isQueueEmpty(){

    if(iCnt == 0){
        return true;
    }
    return false;
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : enQueue
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : T iNo
      Description: This function inserts the element in Queue.

**********************************************************************************/

template <class T>
void Queue <T>:: enQueue(T iNo){ //insertLast

    struct NodeS <T>* newn = new struct NodeS<T>;
    newn->iData = iNo;
    newn->next = NULL;
    if(first == NULL){
        first = newn;
        
    }
    else{

        struct NodeS <T>* temp = first;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCnt++;
    cout<<"Element inserted...\n";

}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : deQueue
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function deletes the element and returns it from the Queue.

**********************************************************************************/

template <class T>
T Queue<T> :: deQueue(){  //deleteFirst

    int iValue = 0;
    bool bRet = isQueueEmpty();
    if(bRet == true){
        cout<<"Unable to delete element as Queue is empty..\n";
        return (T)-1;
    }
    // else if(first->next == NULL){
        
    //     iValue = first->iData;
    //     delete first;
    //     first = NULL;
    // }
    else{
       
        iValue = first->iData;
        struct NodeS <T>*temp = first;
        first=first->next;
        delete temp;

    }
        return iValue;

}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : display
      Name of the Author : Akshay Haribhau Mandalik 
      Date : 13 April 2022
      Parameters : None
      Description: This function displays the elements in the Queue.

**********************************************************************************/

template <class T>
void Queue <T>:: display(){

    if(first == NULL){
        cout<<"Queue is empty\n";
        return;
    }
    else{
        cout<<"Elements of Queue are:\n";
        struct NodeS <T>* temp = first;
        while(temp != NULL){
            cout<<"|"<<temp->iData<<"|->";
            temp = temp->next;
        }
    }
    cout<<"NULL\n";
}

/**********************************************************************************

      Name of the Project :Customized Generalized Standard Template Liabrary(CGSTL)
      Name of the function : Main (Driver Code)
      Name of the Author : Akshay Haribhau Mandalik     
      Date : 13 April 2022
      Parameters : None
      Description: This is the Driver Function for this project.

**********************************************************************************/


int main(){

    DoublyCL<int>sObj;
    DoublyCL<int>s1Obj;

    double iRet = 0;
    bool bRet = false;

    sObj.insertLast(61);
    sObj.insertLast(62);
    sObj.insertLast(6);
    sObj.insertLast(65);
    sObj.insertLast(65);
    sObj.insertLast(65);
    sObj.insertLast(8);
    sObj.insertLast(28);

     s1Obj = sObj.findOdd();
     s1Obj.display();

    // iRet = sObj.findSecondMax();
    // cout<<"last Occurence:"<<iRet;


    // bRet = sObj.searchElement(28);
    // if(bRet == true){
    //     cout<<"Element Searched.\n";
    // }
    // else{
    //     cout<<"Element Not Searched.\n";
    // }

    return 0;
}