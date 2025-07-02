# Queue 队列模块

本模块实现了一个通用的队列模板类 `Queue<T>`，基于链表实现，支持基本队列操作，接口风格规范，适用于 C++ 项目。

## 特性

- 支持任意类型元素（模板实现）
- 基于链表，入队/出队效率高
- 提供常用队列操作接口
- 边界检查与异常安全
- 代码风格规范，接口注释详细
- 附带交互式测试程序

## 主要接口

- `Queue()`：构造函数，初始化队列
- `~Queue()`：析构函数
- `int size() const`：获取队列元素个数
- `bool empty() const`：判断队列是否为空
- `T peek() const`：获取队首元素
- `void push(const T& value)`：入队
- `void pop()`：出队
- `void clear()`：清空队列

详细接口说明见 [../include/queue.hpp](../include/queue.hpp)。

## 用法示例

```cpp
#include "queue.hpp"
#include <iostream>

int main() {
    Queue<int> q;
    q.push(10);
    q.push(20);
    std::cout << "队首: " << q.peek() << std::endl;
    q.pop();
    std::cout << "队首: " << q.peek() << std::endl;
    std::cout << "队列大小: " << q.size() << std::endl;
    return 0;
}
```

## 交互式测试

本模块提供了交互式测试程序，支持命令行操作队列，便于学习和调试。**测试程序所有交互均为中文，适合中文用户体验。**

编译并运行：

```bash
g++ -std=c++11 test/test_queue.cpp -o test_queue
./test_queue
```

示例交互（中文版）：

```
====== 队列交互测试菜单 ======
命令列表：
  push <值>      : 入队
  pop            : 出队
  peek           : 查看队首元素
  size           : 队列元素个数
  empty          : 判断队列是否为空
  clear          : 清空队列
  print          : 打印队列内容
  help           : 显示菜单
  exit / 0       : 退出程序
请输入命令: > push 42
已入队 42。
> print
队列内容: [42]
> push 99
已入队 99。
> peek
队首元素为: 42
> pop
已出队队首元素。
> print
队列内容: [99]
> exit
程序结束，再见！
```

## 常见问题

- **Q: 队列为空时出队或取队首怎么办？**  
  A: 会抛出异常并提示错误信息。

- **Q: 支持哪些类型？**  
  A: 支持任意可赋值类型（模板实现）。

## 模板使用说明

本模块为模板实现，建议直接包含 `queue.hpp` 头文件，无需单独编译 cpp 文件。例如：

```bash
g++ -std=c++11 your_code.cpp -o your_program
```

## 相关文档

- [doc/ADT.md](doc/ADT.md)：队列抽象数据类型说明
- [../include/queue.hpp](../include/queue.hpp)：接口定义与注释
