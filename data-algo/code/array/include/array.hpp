#pragma once
#include <stdexcept>

/**
 * @brief 动态数组模板类
 * 
 * 提供基本的数组操作，包括插入、删除、查找、扩容等。
 * 
 * @tparam T 元素类型
 */
template<typename T>
class Array {
private:
    T* data;         ///< 指向数组数据的指针
    int capacity;    ///< 数组容量
    int length;      ///< 当前元素个数

public:
    /**
     * @brief 构造函数，初始化指定容量的数组
     * @param capacity 数组容量
     */
    explicit Array(int capacity);

    /**
     * @brief 拷贝构造函数
     * @param other 被拷贝的数组
     */
    Array(const Array& other);

    /**
     * @brief 赋值操作符重载
     * @param other 被赋值的数组
     * @return 当前对象的引用
     */
    Array& operator=(const Array& other);

    /**
     * @brief 析构函数，释放内存
     */
    ~Array();

    /**
     * @brief 获取指定索引的元素
     * @param index 元素索引
     * @return 索引处的元素
     * @throws std::out_of_range 如果索引越界
     */
    T get(int index) const;

    /**
     * @brief 设置指定索引的元素值
     * @param index 元素索引
     * @param value 新值
     * @throws std::out_of_range 如果索引越界
     */
    void set(int index, const T& value);

    /**
     * @brief 在指定位置插入元素
     * @param index 插入位置
     * @param value 插入的元素
     * @throws std::out_of_range 如果索引越界
     * @throws std::overflow_error 如果数组已满
     */
    void insert(int index, const T& value);

    /**
     * @brief 删除指定位置的元素
     * @param index 删除位置
     * @throws std::out_of_range 如果索引越界
     */
    void remove(int index);

    /**
     * @brief 扩展数组容量
     * @param enlarge 扩容的大小
     */
    void extend(int enlarge);

    /**
     * @brief 查找元素，返回其索引
     * @param value 查找的元素
     * @return 元素索引，未找到返回-1
     */
    int search(const T& value) const;

    /**
     * @brief 获取当前元素个数
     * @return 元素个数
     */
    int size() const;

    /**
     * @brief 判断数组是否为空
     * @return 为空返回true，否则返回false
     */
    bool isEmpty() const;

    /**
     * @brief 判断数组是否已满
     * @return 已满返回true，否则返回false
     */
    bool isFull() const;
};

// ================== 实现部分 ==================

// 构造函数，分配指定容量的内存
template<typename T>
Array<T>::Array(int capacity)
    : data(new T[capacity]), capacity(capacity), length(0) {}

// 拷贝构造函数，深拷贝数据
template<typename T>
Array<T>::Array(const Array& other)
    : data(new T[other.capacity]), capacity(other.capacity), length(other.length) {
    for (int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

// 赋值操作符重载，深拷贝数据
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        length = other.length;
        data = new T[capacity];
        for (int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// 析构函数，释放内存
template<typename T>
Array<T>::~Array() {
    delete[] data;
}

// 获取指定索引的元素
template<typename T>
T Array<T>::get(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// 设置指定索引的元素
template<typename T>
void Array<T>::set(int index, const T& value) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

// 在指定位置插入元素
template<typename T>
void Array<T>::insert(int index, const T& value) {
    if (isFull()) {
        throw std::overflow_error("Array is full");
    }
    if (index < 0 || index > length) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = length; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++length;
}

// 删除指定位置的元素
template<typename T>
void Array<T>::remove(int index) {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < length - 1; ++i) {
        data[i] = data[i + 1];
    }
    --length;
}

// 扩展数组容量
template<typename T>
void Array<T>::extend(int enlarge) {
    if (enlarge <= 0) return;
    T* newData = new T[capacity + enlarge];
    for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity += enlarge;
}

// 查找元素，返回其索引
template<typename T>
int Array<T>::search(const T& value) const {
    for (int i = 0; i < length; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// 获取当前元素个数
template<typename T>
int Array<T>::size() const {
    return length;
}

// 判断数组是否为空
template<typename T>
bool Array<T>::isEmpty() const {
    return length == 0;
}

// 判断数组是否已满
template<typename T>
bool Array<T>::isFull() const {
    return length == capacity;
}
