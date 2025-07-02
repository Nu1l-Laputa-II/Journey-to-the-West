# 动态数组抽象数据类型（Vector ADT）

## 定义

动态数组（Dynamic Array，类似 C++ STL `vector`）是一种线性数据结构，支持随机访问、动态扩容和收缩。  
每个元素在内存中连续存储，支持高效的下标访问和尾部插入/删除。

## 基本操作

- **初始化**
  - `Vector()`：构造函数，初始化空数组
  - `Vector(n, val)`：构造函数，初始化 n 个元素
  - 时间复杂度：O(n)

- **拷贝与赋值**
  - `Vector(const Vector& other)`：拷贝构造函数
  - `Vector(Vector&& other)`：移动构造函数
  - `Vector& operator=(const Vector& other)`：拷贝赋值
  - `Vector& operator=(Vector&& other)`：移动赋值
  - 时间复杂度：O(n)

- **析构**
  - `~Vector()`：析构函数
  - 时间复杂度：O(n)

- **容量管理**
  - `size()`：返回元素个数
  - `capacity()`：返回当前容量
  - `reserve(n)`：预留容量
  - `resize(n, val)`：调整大小
  - `empty()`：是否为空
  - 时间复杂度：O(1) 或 O(n)

- **元素访问**
  - `operator[](index)`：下标访问（无越界检查）
  - `at(index)`：带越界检查访问
  - `front()`：首元素
  - `back()`：尾元素
  - `data()`：底层数据指针
  - 时间复杂度：O(1)

- **修改操作**
  - `push_back(val)`：尾部插入
  - `pop_back()`：删除尾部
  - `insert(index, val)`：指定位置插入
  - `erase(index)`：删除指定位置
  - `clear()`：清空
  - `swap(other)`：与另一数组交换内容
  - 时间复杂度：O(1)~O(n)

- **查找与遍历**
  - `find(val)`：查找首次出现位置
  - `traverse(visit)`：遍历
  - 时间复杂度：O(n)

- **迭代器**
  - `begin()` / `end()`：返回首/尾迭代器
  - 时间复杂度：O(1)

## 异常与边界

- 所有越界操作均抛出 `std::out_of_range` 异常

## 接口定义（伪代码）

```typescript
interface VectorADT<T> {
    constructor();
    constructor(n: number, val: T);
    copyConstructor(other: VectorADT<T>);
    moveConstructor(other: VectorADT<T>);
    assign(other: VectorADT<T>): VectorADT<T>;
    moveAssign(other: VectorADT<T>): VectorADT<T>;
    destructor();
    clear(): void;
    empty(): boolean;
    size(): number;
    capacity(): number;
    reserve(n: number): void;
    resize(n: number, val?: T): void;
    get(index: number): T;                // O(1), 越界抛异常
    set(index: number, value: T): void;   // O(1), 越界抛异常
    at(index: number): T;                 // O(1), 越界抛异常
    operator[](index: number): T;         // O(1), 不检查越界
    front(): T;                           // O(1)
    back(): T;                            // O(1)
    data(): pointer;
    find(value: T): number;               // O(n), 未找到返回-1
    push_back(value: T): void;            // 均摊O(1)
    pop_back(): void;                     // O(1)
    insert(index: number, value: T): void;// O(n), 越界抛异常
    erase(index: number): void;           // O(n), 越界抛异常
    swap(other: VectorADT<T>): void;      // O(1)
    traverse(visit: (value: T) => void): void; // O(n)
    begin(): iterator;
    end(): iterator;
}
```

## 空间复杂度

- O(n)，n为数组元素个数，实际分配空间可能大于 n 以支持扩容

## 优点

- 随机访问效率高（O(1)）
- 动态扩容，支持元素数量变化
- 支持任意类型元素（模板实现）
- 支持深拷贝与赋值，容器对象可安全复制

## 局限性

- 插入、删除非尾部元素需移动大量元素（O(n)）
- 扩容时可能导致内存重新分配和元素拷贝

## 适用场景

- 需要高效随机访问的线性表
- 元素数量变化频繁但以尾部操作为主的场景

## 交互式测试（中文版）

本模块附带交互式测试程序，所有命令行交互均为中文，便于中文用户体验和学习。详见 [../test/test_vector.cpp](../test/test_vector.cpp)。

示例命令：

- `push 10` 尾部插入10
- `pop` 删除尾部元素
- `insert 1 20` 在下标1插入20
- `erase 2` 删除下标2的元素
- `get 0` 获取下标0的值
- `find 99` 查找99首次出现的下标
- `size` 当前元素个数
- `capacity` 当前容量
- `empty` 是否为空
- `print` 打印数组内容
- `help` 显示菜单
- `exit` 或 `0` 退出程序

所有异常和错误提示也为中文，便于理解和调试。
