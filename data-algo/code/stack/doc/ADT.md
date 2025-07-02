# 栈抽象数据类型（Stack ADT）

## 定义

栈（Stack）是一种后进先出（LIFO, Last-In-First-Out）的线性数据结构。  
在 C++ 中，栈常用模板类实现，支持元素的入栈、出栈、取栈顶等操作，常用于表达式求值、递归、括号匹配等场景。

## 基本操作

- **初始化**
  - `Stack()`：构造函数，初始化空栈
  - 时间复杂度：O(1)

- **拷贝与赋值**
  - `Stack(const Stack& other)`：拷贝构造函数，深拷贝栈
  - `Stack& operator=(const Stack& other)`：赋值操作符，深拷贝栈
  - 时间复杂度：O(n)

- **析构**
  - `~Stack()`：析构函数，释放所有资源
  - 时间复杂度：O(n)

- **入栈**
  - `push(const T& value)`：将元素压入栈顶
  - 时间复杂度：O(1)

- **出栈**
  - `pop()`：移除栈顶元素，若栈空抛出异常
  - 时间复杂度：O(1)

- **取栈顶元素**
  - `top()`：返回栈顶元素，若栈空抛出异常
  - 时间复杂度：O(1)

- **判空**
  - `empty() const`：判断栈是否为空
  - 时间复杂度：O(1)

- **获取元素个数**
  - `size() const`：返回栈中元素个数
  - 时间复杂度：O(1)

- **清空栈**
  - `clear()`：移除所有元素
  - 时间复杂度：O(n)

## 异常与边界

- 出栈或取栈顶时若栈为空，抛出 `std::out_of_range` 异常

## 接口定义（伪代码）

```typescript
interface StackADT<T> {
    constructor();
    copyConstructor(other: StackADT<T>);
    assign(other: StackADT<T>): StackADT<T>;
    destructor();
    push(value: T): void;           // O(1)
    pop(): void;                    // O(1), 空栈抛异常
    top(): T;                       // O(1), 空栈抛异常
    empty(): boolean;               // O(1)
    size(): number;                 // O(1)
    clear(): void;                  // O(n)
}
```

## 空间复杂度

- O(n)，n为栈元素个数

## 优点

- 入栈、出栈、取栈顶操作均为O(1)
- 动态分配，无需预设容量
- 支持任意类型元素（模板实现）
- 支持深拷贝与赋值，栈对象可安全复制

## 局限性

- 只能访问栈顶元素，无法随机访问
- 仅适合后进先出场景

## 适用场景

- 表达式求值、括号匹配、递归模拟、深度优先搜索等

## 交互式测试（中文版）

本模块附带交互式测试程序，所有命令行交互均为中文，便于中文用户体验和学习。详见 [../test/test_stack.cpp](../test/test_stack.cpp)。

示例命令：

- `push 10` 入栈10
- `pop` 出栈
- `top` 查看栈顶元素
- `size` 当前元素个数
- `empty` 是否为空
- `clear` 清空栈
- `print` 打印栈内容
- `help` 显示菜单
- `exit` 或 `0` 退出程序

所有异常和错误提示也为中文，便于理解和调试。
