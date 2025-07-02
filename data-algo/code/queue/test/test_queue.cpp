#include "../include/queue.hpp"
#include <iostream>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

void printMenu() {
    std::cout << "\n====== 队列交互测试菜单 ======\n";
    std::cout << "命令列表：\n";
    std::cout << "  push <值>      : 入队\n";
    std::cout << "  pop            : 出队\n";
    std::cout << "  peek           : 查看队首元素\n";
    std::cout << "  size           : 队列元素个数\n";
    std::cout << "  empty          : 判断队列是否为空\n";
    std::cout << "  clear          : 清空队列\n";
    std::cout << "  print          : 打印队列内容\n";
    std::cout << "  help           : 显示菜单\n";
    std::cout << "  exit / 0       : 退出程序\n";
    std::cout << "-----------------------------------\n";
    std::cout << "请输入命令: ";
}

template<typename T>
void printQueue(Queue<T>& q) {
    // 由于队列没有遍历接口，只能通过不断出队再入队实现打印
    Queue<T> tmp;
    std::cout << "[";
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        T val = q.peek();
        std::cout << val;
        if (i != n - 1) std::cout << ", ";
        tmp.push(val);
        q.pop();
    }
    // 恢复原队列
    for (int i = 0; i < n; ++i) {
        q.push(tmp.peek());
        tmp.pop();
    }
    std::cout << "]\n";
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    Queue<int> q;
    std::string cmd;
    printMenu();
    while (true) {
        std::cout << "> ";
        std::cin >> cmd;
        if (cmd == "push") {
            int val;
            if (!(std::cin >> val)) {
                std::cout << "输入有误。用法: push <值>\n";
                clearInput();
                continue;
            }
            q.push(val);
            std::cout << "已入队 " << val << "。\n";
        } else if (cmd == "pop") {
            try {
                q.pop();
                std::cout << "已出队队首元素。\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "peek") {
            try {
                int val = q.peek();
                std::cout << "队首元素为: " << val << "\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "size") {
            std::cout << "队列元素个数: " << q.size() << "\n";
        } else if (cmd == "empty") {
            std::cout << (q.empty() ? "队列为空。" : "队列非空。") << "\n";
        } else if (cmd == "clear") {
            q.clear();
            std::cout << "队列已清空。\n";
        } else if (cmd == "print") {
            std::cout << "队列内容: ";
            printQueue(q);
        } else if (cmd == "help") {
            printMenu();
        } else if (cmd == "exit" || cmd == "0") {
            std::cout << "程序结束，再见！\n";
            break;
        } else {
            std::cout << "未知命令。输入 help 查看菜单。\n";
        }
        clearInput();
    }
    return 0;
}
