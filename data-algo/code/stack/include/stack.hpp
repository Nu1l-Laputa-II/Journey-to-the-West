#pragma once
#include "../../linklist/include/linkList.hpp"

/**
 * @brief 栈模板类
 * 
 * 基于单链表实现的顺序栈，支持入栈、出栈、取栈顶、判空、获取大小、清空等操作。
 * 
 * @tparam T 栈元素类型
 */
template<typename T>
class Stack {
private:
    LinkList<T> list; ///< 底层链表实现

public:
    /**
     * @brief 构造函数，初始化空栈
     */
    Stack();

    /**
     * @brief 拷贝构造函数，深拷贝栈
     * @param other 被拷贝的栈
     */
    Stack(const Stack& other);

    /**
     * @brief 赋值操作符重载，深拷贝栈
     * @param other 被赋值的栈
     * @return 当前对象的引用
     */
    Stack& operator=(const Stack& other);

    /**
     * @brief 析构函数
     */
    ~Stack();

    /**
     * @brief 入栈
     * @param value 入栈元素
     * @throws std::bad_alloc 内存分配失败
     */
    void push(const T& value);

    /**
     * @brief 出栈
     * @throws std::out_of_range 栈为空
     */
    void pop();

    /**
     * @brief 获取栈顶元素（常量版本）
     * @return 栈顶元素的值
     * @throws std::out_of_range 栈为空
     */
    T top() const;

    /**
     * @brief 判断栈是否为空
     * @return 为空返回true，否则返回false
     */
    bool empty() const;

    /**
     * @brief 获取栈中元素个数
     * @return 元素个数
     */
    int size() const;

    /**
     * @brief 清空栈
     */
    void clear();
};

// ================== 实现部分 ==================

// 构造函数，初始化空栈
template<typename T>
Stack<T>::Stack() : list() {}

// 拷贝构造函数，深拷贝栈
template<typename T>
Stack<T>::Stack(const Stack& other) : list(other.list) {}

// 赋值操作符重载，深拷贝栈
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

// 析构函数
template<typename T>
Stack<T>::~Stack() {}

// 入栈
template<typename T>
void Stack<T>::push(const T& value) {
    list.insert(0, value); // 头插法，O(1)
}

// 出栈
template<typename T>
void Stack<T>::pop() {
    if (empty())
        throw std::out_of_range("Stack is empty");
    list.remove(0);
}

// 获取栈顶元素（常量版本）
template<typename T>
T Stack<T>::top() const {
    if (empty())
        throw std::out_of_range("Stack is empty");
    return list.get(0);
}

// 判断栈是否为空
template<typename T>
bool Stack<T>::empty() const {
    return list.empty();
}

// 获取栈中元素个数
template<typename T>
int Stack<T>::size() const {
    return list.size();
}

// 清空栈
template<typename T>
void Stack<T>::clear() {
    list.clear();
}