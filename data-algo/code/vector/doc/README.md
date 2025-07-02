# Vector 动态数组模块

本模块实现了一个通用的动态数组模板类 `Vector<T>`，接口风格参考 C++ STL `std::vector`，支持动态扩容、随机访问、插入、删除、遍历、拷贝、赋值等常用操作，适用于 C++ 项目。

## 特性

- 支持任意类型元素（模板实现）
- 动态扩容与收缩，自动管理内存
- 随机访问效率高（O(1)）
- 提供常用动态数组操作接口
- 支持深拷贝与赋值，容器对象可安全复制
- 边界检查与异常安全
- 代码风格规范，接口注释详细
- 附带交互式测试程序

## 主要接口

- 构造与析构
  - `Vector()`：构造函数，初始化空数组
  - `Vector(size_t n, const T& val = T())`：构造函数，初始化 n 个元素
  - `Vector(const Vector& other)`：拷贝构造函数
  - `Vector(Vector&& other)`：移动构造函数
  - `Vector& operator=(const Vector& other)`：拷贝赋值
  - `Vector& operator=(Vector&& other)`：移动赋值
  - `~Vector()`：析构函数

- 容量相关
  - `size_t size() const`：元素个数
  - `size_t capacity() const`：当前容量
  - `bool empty() const`：是否为空
  - `void reserve(size_t n)`：预留容量
  - `void resize(size_t n, const T& val = T())`：调整大小

- 元素访问
  - `T& operator[](size_t index)`：下标访问（无越界检查）
  - `const T& operator[](size_t index) const`
  - `T& at(size_t index)`：带越界检查访问
  - `const T& at(size_t index) const`
  - `T& front()`：首元素
  - `T& back()`：尾元素
  - `const T& front() const`
  - `const T& back() const`
  - `T* data()`：底层数据指针

- 修改操作
  - `void push_back(const T& value)`：尾部插入
  - `void push_back(T&& value)`：尾部插入（移动）
  - `void pop_back()`：删除尾部
  - `void insert(size_t index, const T& value)`：指定位置插入
  - `void erase(size_t index)`：删除指定位置
  - `void clear()`：清空
  - `void swap(Vector& other)`：与另一数组交换内容

- 查找与遍历
  - `int find(const T& value) const`：查找首次出现位置
  - `void traverse(void (*visit)(const T&)) const`：遍历

- 迭代器支持（简易版）
  - `T* begin()`
  - `T* end()`
  - `const T* begin() const`
  - `const T* end() const`

详细接口说明见 [../include/vector.hpp](../include/vector.hpp)。

## 用法示例

```cpp
#include "vector.hpp"
#include <iostream>

void printInt(const int& x) { std::cout << x << " "; }

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.insert(1, 15);
    std::cout << "首元素: " << v.front() << std::endl;
    std::cout << "尾元素: " << v.back() << std::endl;
    v.resize(5, 0);
    for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";
    std::cout << std::endl;
    v.pop_back();
    v.swap(Vector<int>(3, 99));
    std::cout << "交换后: ";
    v.traverse(printInt);
    std::cout << std::endl;
    return 0;
}
```

## 交互式测试

本模块提供了交互式测试程序，支持命令行操作动态数组，便于学习和调试。**测试程序所有交互均为中文，适合中文用户体验。**

编译并运行：

```bash
g++ -std=c++11 test/test_vector.cpp -o test_vector
./test_vector
```

示例交互（中文版）：

```
====== 动态数组交互测试菜单 ======
命令列表：
  push <值>             : 尾部插入值
  pop                   : 删除尾部元素
  insert <下标> <值>    : 在下标插入值
  erase <下标>          : 删除指定下标的元素
  get <下标>            : 获取指定下标的值
  find <值>             : 查找值，返回下标
  size                  : 当前元素个数
  capacity              : 当前容量
  empty                 : 判断数组是否为空
  print                 : 打印数组内容
  help                  : 显示菜单
  exit / 0              : 退出程序
-----------------------------------
请输入命令: > push 42
已在尾部插入 42。
> print
数组内容: 42 
> insert 1 99
已在下标 1 插入 99。
> get 1
下标 1 的值为: 99
> exit
程序结束，再见！
```

## 常见问题

- **Q: 插入/删除/访问越界怎么办？**  
  A: 会抛出异常并提示错误信息。

- **Q: 支持哪些类型？**  
  A: 支持任意可赋值类型（模板实现）。

- **Q: 支持容器对象的拷贝和赋值吗？**  
  A: 支持，已实现深拷贝构造和赋值操作，容器对象可安全复制。

## 模板使用说明

本模块为模板实现，建议直接包含 `vector.hpp` 头文件，无需单独编译 cpp 文件。例如：

```bash
g++ -std=c++11 your_code.cpp -o your_program
```

## 相关文档

- [doc/ADT.md](doc/ADT.md)：动态数组抽象数据类型说明
- [../include/vector.hpp](../include/vector.hpp)：接口定义与注释
