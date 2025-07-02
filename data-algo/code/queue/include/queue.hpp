#pragma once
#include "../../linklist/include/linkList.hpp"

template<typename T>
class Queue {
private:
    LinkList<T> list;

public:
    Queue();
    ~Queue();
    
    int size() const;
    bool empty() const;
    T peek() const;
    void push(const T& value);
    void pop();
    void clear();
};

template<typename T>
Queue<T>::Queue() : list() {}

template<typename T>
Queue<T>::~Queue() {}

template<typename T>
int Queue<T>::size() const {
    return list.size();
}

template<typename T>
bool Queue<T>::empty() const {
    return list.empty();
}

template<typename T>
T Queue<T>::peek() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return list.get(list.size() - 1);   // 时间复杂度为O(n)，list增加尾指针或者改成循环链表则降为O(1)
}

template<typename T>
void Queue<T>::push(const T& value) {
    list.insert(0, value);
}

template<typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    list.remove(list.size() - 1);
}

template<typename T>
void Queue<T>::clear() {
    list.clear();
}
