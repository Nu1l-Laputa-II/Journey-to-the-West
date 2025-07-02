# Stack 栈模块

本模块实现了一个通用的栈模板类 `Stack<T>`，基于单链表（LinkList）实现，支持入栈、出栈、取栈顶、判空、获取大小、清空等常用操作，接口风格参考工业界标准，适用于 C++ 项目。

## 特性

- 支持任意类型元素（模板实现）
- 基于 LinkList，无需预设容量
- 提供常用栈操作接口
- 支持深拷贝与赋值，栈对象可安全复制
- 边界检查与异常安全
- 代码风格规范，接口注释详细
- 附带交互式测试程序

## 主要接口

- `Stack()`：构造函数，初始化空栈
- `Stack(const Stack& other)`：拷贝构造函数，深拷贝栈
- `Stack& operator=(const Stack& other)`：赋值操作符，深拷贝栈
- `~Stack()`：析构函数
- `void push(const T& value)`：入栈
- `void pop()`：出栈
- `T& top()`：获取栈顶元素
- `const T& top() const`：获取栈顶元素（常量）
- `bool empty() const`：判断栈是否为空
- `int size() const`：获取栈中元素个数
- `void clear()`：清空栈

详细接口说明见 [../include/stack.hpp](../include/stack.hpp)。

## 用法示例

```cpp
#include "stack.hpp"
#include <iostream>

int main() {
    Stack<int> stk;
    stk.push(10);
    stk.push(20);
    std::cout << "栈顶元素: " << stk.top() << std::endl;
    stk.pop();
    std::cout << "栈顶元素: " << stk.top() << std::endl;
    std::cout << "栈大小: " << stk.size() << std::endl;
    std::cout << (stk.empty() ? "栈为空" : "栈非空") << std::endl;
    stk.clear();
    std::cout << "清空后栈大小: " << stk.size() << std::endl;
    return 0;
}
```

## 交互式测试

本模块提供了交互式测试程序，支持命令行操作栈，便于学习和调试。**测试程序所有交互均为中文，适合中文用户体验。**

编译并运行：

```bash
g++ -std=c++11 test/test_stack.cpp -o test_stack
./test_stack
```

示例交互（中文版）：

```
====== 栈交互测试菜单 ======
命令列表：
  push <值>      : 入栈
  pop            : 出栈
  top            : 查看栈顶元素
  size           : 当前元素个数
  empty          : 判断栈是否为空
  clear          : 清空栈
  print          : 打印栈内容
  help           : 显示菜单
  exit / 0       : 退出程序
-----------------------------------
请输入命令: > push 42
已入栈 42。
> print
栈内容: 42 
> push 99
已入栈 99。
> top
栈顶元素为: 99
> pop
已出栈。
> exit
程序结束，再见！
```

## 常见问题

- **Q: 出栈/取栈顶越界怎么办？**  
  A: 会抛出异常并提示错误信息。

- **Q: 支持哪些类型？**  
  A: 支持任意可赋值类型（模板实现）。

- **Q: 支持栈对象的拷贝和赋值吗？**  
  A: 支持，已实现深拷贝构造和赋值操作，栈对象可安全复制。

## 模板使用说明

本模块为模板实现，建议直接包含 `stack.hpp` 头文件，无需单独编译 cpp 文件。例如：

```bash
g++ -std=c++11 your_code.cpp -o your_program
```

## 相关文档

- [../include/stack.hpp](../include/stack.hpp)：接口定义与注释
