#include "../include/stack.hpp"
#include <iostream>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

void printMenu() {
    std::cout << "\n====== 栈交互测试菜单 ======\n";
    std::cout << "命令列表：\n";
    std::cout << "  push <值>      : 入栈\n";
    std::cout << "  pop            : 出栈\n";
    std::cout << "  top            : 查看栈顶元素\n";
    std::cout << "  size           : 当前元素个数\n";
    std::cout << "  empty          : 判断栈是否为空\n";
    std::cout << "  clear          : 清空栈\n";
    std::cout << "  print          : 打印栈内容\n";
    std::cout << "  help           : 显示菜单\n";
    std::cout << "  exit / 0       : 退出程序\n";
    std::cout << "-----------------------------------\n";
    std::cout << "请输入命令: ";
}

template<typename T>
void printStack(Stack<T>& stk) {
    // 为了打印，临时弹出元素存到辅助栈，再还原
    Stack<T> tmp;
    std::cout << "栈内容: ";
    while (!stk.empty()) {
        T val = stk.top(); // 只用常量版本top()
        std::cout << val << " ";
        tmp.push(val);
        stk.pop();
    }
    // 还原原栈
    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }
    std::cout << std::endl;
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
    Stack<int> stk;

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
            try {
                stk.push(val);
                std::cout << "已入栈 " << val << "。\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "pop") {
            try {
                stk.pop();
                std::cout << "已出栈。\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "top") {
            try {
                std::cout << "栈顶元素为: " << stk.top() << "\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "size") {
            std::cout << "当前元素个数: " << stk.size() << "\n";
        } else if (cmd == "empty") {
            std::cout << (stk.empty() ? "栈为空。" : "栈非空。") << "\n";
        } else if (cmd == "clear") {
            stk.clear();
            std::cout << "栈已清空。\n";
        } else if (cmd == "print") {
            printStack(stk);
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
