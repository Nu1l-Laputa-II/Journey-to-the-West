#pragma once
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data_;
    int size_;
    int capacity_;

    void reallocate(int new_cap);

public:
    // 类型定义
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    using size_type = int;

    // 构造与析构
    Vector();
    Vector(int n, const T& val = T());
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    // 赋值
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    // 容量
    int size() const noexcept;
    int capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(int n);
    void resize(int n, const T& value = T());

    // 元素访问
    T& operator[](int index);
    const T& operator[](int index) const;
    T& at(int index);
    const T& at(int index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data() noexcept;
    const T* data() const noexcept;

    // 修改操作
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    iterator insert(int index, const T& value);
    iterator insert(int index, T&& value);
    iterator erase(int index);
    void clear() noexcept;
    void swap(Vector& other) noexcept;

    // 查找与遍历
    int find(const T& value) const;
    void traverse(void (*visit)(const T&)) const;

    // 迭代器
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
};