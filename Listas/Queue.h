//
// Created by miky_ on 30/10/2023.
//

#ifndef DLLIST_QUEUE_H
#define DLLIST_QUEUE_H
#include "DLList.h"

template<typename XD>
class Queue : private DLList<XD>{
public:
    Queue(){
    }

    ~Queue(){
        clear();
        delete DLList<XD>::head;
        delete DLList<XD>::tail;
    }

    void enqueue(XD &data){
        DLList<XD>::push_back(data);
    }

    void enqueue(XD &&data){
        DLList<XD>::push_back(data);
    }

    void dequeue(){
        DLList<XD>::pop_front();
    }

    void print(){
        DLList<XD>::print();
    }

    void clear(){
        DLList<XD>::clear();
    }

    XD front(){
        return DLList<XD>::head->next->data;
    }
};

#endif //DLLIST_QUEUE_H
