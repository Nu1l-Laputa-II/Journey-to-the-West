#include "../include/array.hpp"
#include <iostream>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

void printMenu() {
    std::cout << "\n====== 动态数组交互测试菜单 ======\n";
    std::cout << "命令列表：\n";
    std::cout << "  insert <下标> <值>   : 在下标插入值\n";
    std::cout << "  remove <下标>        : 删除指定下标的元素\n";
    std::cout << "  set <下标> <值>      : 设置指定下标的值\n";
    std::cout << "  get <下标>           : 获取指定下标的值\n";
    std::cout << "  search <值>          : 查找值，返回下标\n";
    std::cout << "  extend <扩容数>      : 扩展数组容量\n";
    std::cout << "  size                 : 当前元素个数\n";
    std::cout << "  isEmpty              : 判断数组是否为空\n";
    std::cout << "  isFull               : 判断数组是否已满\n";
    std::cout << "  print                : 打印数组内容\n";
    std::cout << "  help                 : 显示菜单\n";
    std::cout << "  exit / 0             : 退出程序\n";
    std::cout << "-----------------------------------\n";
    std::cout << "请输入命令: ";
}

template<typename T>
void printArray(const Array<T>& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr.get(i);
        if (i != arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
#ifdef _WIN32
    // 设置 Windows 控制台为 UTF-8，防止中文输出乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int cap;
    std::cout << "请输入数组初始容量: ";
    while (!(std::cin >> cap) || cap <= 0) {
        std::cout << "容量无效，请输入正整数: ";
        clearInput();
    }
    Array<int> arr(cap);

    std::string cmd;
    printMenu();
    while (true) {
        std::cout << "> ";
        std::cin >> cmd;
        if (cmd == "insert") {
            int idx, val;
            if (!(std::cin >> idx >> val)) {
                std::cout << "输入有误。用法: insert <下标> <值>\n";
                clearInput();
                continue;
            }
            try {
                arr.insert(idx, val);
                std::cout << "已在下标 " << idx << " 插入 " << val << "。\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "remove") {
            int idx;
            if (!(std::cin >> idx)) {
                std::cout << "输入有误。用法: remove <下标>\n";
                clearInput();
                continue;
            }
            try {
                arr.remove(idx);
                std::cout << "已删除下标 " << idx << " 的元素。\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "set") {
            int idx, val;
            if (!(std::cin >> idx >> val)) {
                std::cout << "输入有误。用法: set <下标> <值>\n";
                clearInput();
                continue;
            }
            try {
                arr.set(idx, val);
                std::cout << "已将下标 " << idx << " 设置为 " << val << "。\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "get") {
            int idx;
            if (!(std::cin >> idx)) {
                std::cout << "输入有误。用法: get <下标>\n";
                clearInput();
                continue;
            }
            try {
                int val = arr.get(idx);
                std::cout << "下标 " << idx << " 的值为: " << val << "\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "search") {
            int val;
            if (!(std::cin >> val)) {
                std::cout << "输入有误。用法: search <值>\n";
                clearInput();
                continue;
            }
            int idx = arr.search(val);
            if (idx == -1)
                std::cout << "未找到值 " << val << "。\n";
            else
                std::cout << "值 " << val << " 首次出现下标为 " << idx << "。\n";
        } else if (cmd == "extend") {
            int enlarge;
            if (!(std::cin >> enlarge)) {
                std::cout << "输入有误。用法: extend <扩容数>\n";
                clearInput();
                continue;
            }
            arr.extend(enlarge);
            std::cout << "已扩容 " << enlarge << "。\n";
        } else if (cmd == "size") {
            std::cout << "当前元素个数: " << arr.size() << "\n";
        } else if (cmd == "isEmpty") {
            std::cout << (arr.isEmpty() ? "数组为空。" : "数组非空。") << "\n";
        } else if (cmd == "isFull") {
            std::cout << (arr.isFull() ? "数组已满。" : "数组未满。") << "\n";
        } else if (cmd == "print") {
            std::cout << "数组内容: ";
            printArray(arr);
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
