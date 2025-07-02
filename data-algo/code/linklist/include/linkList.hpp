#pragma once
#include <stdexcept>

/**
 * @brief 单链表节点模板结构体
 * 
 * 表示单链表的一个节点，包含数据域和指向下一个节点的指针。
 * 
 * @tparam T 节点存储的数据类型
 */
template<typename T>
struct LinkNode {
    T data;                ///< 节点存储的数据
    LinkNode<T>* next;     ///< 指向下一个节点的指针

    /**
     * @brief 构造函数
     * @param x 节点数据，默认为T类型的默认值
     */
    LinkNode(const T& x = T()) : data(x), next(nullptr) {}
};

/**
 * @brief 单链表模板类
 * 
 * 提供单链表的基本操作，包括插入、删除、查找、清空等。
 * 
 * @tparam T 链表存储的数据类型
 */
template<typename T>
class LinkList {
private:
    LinkNode<T>* head;     ///< 头结点指针（带头结点）
    int length;            ///< 链表长度（元素个数）
    
    /**
     * @brief 获取指定位置的节点指针
     * @param index 节点索引（-1返回头结点，0返回第一个元素）
     * @return 指向对应节点的指针，越界返回nullptr
     */
    LinkNode<T>* access(int index) const;

public:
    /**
     * @brief 构造函数，初始化空链表
     */
    LinkList();

    /**
     * @brief 拷贝构造函数，深拷贝链表
     * @param other 被拷贝的链表
     */
    LinkList(const LinkList& other);

    /**
     * @brief 赋值操作符重载，深拷贝链表
     * @param other 被赋值的链表
     * @return 当前对象的引用
     */
    LinkList& operator=(const LinkList& other);

    /**
     * @brief 析构函数，释放所有节点
     */
    ~LinkList();

    /**
     * @brief 清空链表内容
     * 
     * 删除所有元素节点，链表变为空表但对象仍可复用。
     */
    void clear();

    /**
     * @brief 判断链表是否为空
     * @return 为空返回true，否则返回false
     */
    bool empty() const;

    /**
     * @brief 获取链表长度
     * @return 链表中元素个数
     */
    int size() const;

    /**
     * @brief 获取指定位置的元素
     * @param index 元素索引（0为第一个元素）
     * @return 指定位置的元素值
     * @throws std::out_of_range 如果索引越界
     */
    T get(int index) const;

    /**
     * @brief 查找元素首次出现的位置
     * @param data 要查找的元素值
     * @return 元素索引，未找到返回-1
     */
    int find(const T& data) const;

    /**
     * @brief 在指定位置插入元素
     * @param index 插入位置（0为头部，size()为尾部）
     * @param data 插入的元素值
     * @throws std::out_of_range 如果索引越界
     */
    void insert(int index, const T& data);

    /**
     * @brief 删除指定位置的元素
     * @param index 删除位置（0为第一个元素）
     * @throws std::out_of_range 如果索引越界
     */
    void remove(int index);

    /**
     * @brief 遍历链表，对每个元素调用visit函数
     * @param visit 回调函数，参数为const T&，无返回值
     */
    void traverse(void (*visit)(const T&)) const;
};

// ================== 实现部分 ==================

// 构造函数，初始化带头结点的空链表
template<typename T>
LinkList<T>::LinkList()
    : head(new LinkNode<T>()), length(0) {}

// 清空链表，释放所有元素节点但保留头结点
template<typename T>
void LinkList<T>::clear() {
    LinkNode<T>* p = head->next;
    while (p != nullptr) {
        LinkNode<T>* next = p->next;
        delete p;
        p = next;
    }
    head->next = nullptr;
    length = 0;
}

// 析构函数，释放所有节点（包括头结点）
template<typename T>
LinkList<T>::~LinkList() {
    clear();
    delete head;
}

// 判断链表是否为空
template<typename T>
bool LinkList<T>::empty() const {
    return length == 0;
}

// 获取链表长度
template<typename T>
int LinkList<T>::size() const {
    return length;
}

// 获取指定位置的节点指针，index=-1返回头结点，0返回第一个元素
template<typename T>
LinkNode<T>* LinkList<T>::access(int index) const {
    if (index < -1 || index >= length)
        return nullptr;
    LinkNode<T>* p = head;
    for(int i = 0; i <= index; ++i)
        p = p->next;
    return p;
}

// 获取指定位置的元素值
template<typename T>
T LinkList<T>::get(int index) const {
    LinkNode<T>* p = access(index);
    if (p == nullptr)
        throw std::out_of_range("Index out of range");
    return p->data;
}

// 查找元素首次出现的位置，未找到返回-1
template<typename T>
int LinkList<T>::find(const T& data) const {
    int index = 0;
    LinkNode<T>* p = head->next;
    while (p != nullptr && p->data != data) {
        p = p->next;
        ++index;
    }
    if (p == nullptr)
        return -1;
    return index;
}

// 在指定位置插入元素
template<typename T>
void LinkList<T>::insert(int index, const T& data) {
    LinkNode<T>* prev_p = access(index - 1);
    if (prev_p == nullptr)
        throw std::out_of_range("Index out of range");
    LinkNode<T>* p = new LinkNode<T>(data);
    p->next = prev_p->next;
    prev_p->next = p;
    ++length;
}

// 删除指定位置的元素
template<typename T>
void LinkList<T>::remove(int index) {
    LinkNode<T>* prev_p = access(index - 1);
    if (prev_p->next == nullptr)
        throw std::out_of_range("Index out of range");
    LinkNode<T>* p = prev_p->next;
    prev_p->next = p->next;
    delete p;
    --length;
}

// 遍历链表，对每个元素调用visit函数
template<typename T>
void LinkList<T>::traverse(void (*visit)(const T&)) const {
    LinkNode<T>* p = head->next;
    while (p != nullptr) {
        visit(p->data);
        p = p->next;
    }
}

// 拷贝构造函数，深拷贝链表
template<typename T>
LinkList<T>::LinkList(const LinkList& other)
    : head(new LinkNode<T>()), length(0) {
    LinkNode<T>* src = other.head->next;
    LinkNode<T>* dst = head;
    while (src) {
        dst->next = new LinkNode<T>(src->data);
        dst = dst->next;
        src = src->next;
        ++length;
    }
}

// 赋值操作符重载，深拷贝链表
template<typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList& other) {
    if (this != &other) {
        clear();
        LinkNode<T>* src = other.head->next;
        LinkNode<T>* dst = head;
        while (src) {
            dst->next = new LinkNode<T>(src->data);
            dst = dst->next;
            src = src->next;
            ++length;
        }
    }
    return *this;
}
