#include "../include/linkList.hpp"
#include <iostream>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

void printMenu() {
    std::cout << "\n====== 单链表交互测试菜单 ======\n";
    std::cout << "命令列表：\n"; 
    std::cout << "  insert <下标> <值>   : 在下标插入值\n";
    std::cout << "  remove <下标>        : 删除指定下标的元素\n";
    std::cout << "  get <下标>           : 获取指定下标的值\n";
    std::cout << "  find <值>            : 查找值，返回下标\n";
    std::cout << "  clear                : 清空链表\n";
    std::cout << "  size                 : 当前元素个数\n";
    std::cout << "  empty                : 判断链表是否为空\n";
    std::cout << "  print                : 打印链表内容\n";
    std::cout << "  help                 : 显示菜单\n";
    std::cout << "  exit / 0             : 退出程序\n";
    std::cout << "-----------------------------------\n";
    std::cout << "请输入命令: ";
}

template<typename T>
void printList(const LinkList<T>& list) {
    std::cout << "链表内容: ";
    auto printElem = [](const T& x) { std::cout << x << " "; };
    list.traverse(printElem);
    std::cout << std::endl;
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
    LinkList<int> list;

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
                list.insert(idx, val);
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
                list.remove(idx);
                std::cout << "已删除下标 " << idx << " 的元素。\n";
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
                int val = list.get(idx);
                std::cout << "下标 " << idx << " 的值为: " << val << "\n";
            } catch (const std::exception& e) {
                std::cout << "错误: " << e.what() << "\n";
            }
        } else if (cmd == "find") {
            int val;
            if (!(std::cin >> val)) {
                std::cout << "输入有误。用法: find <值>\n";
                clearInput();
                continue;
            }
            int idx = list.find(val);
            if (idx == -1)
                std::cout << "未找到值 " << val << "。\n";
            else
                std::cout << "值 " << val << " 首次出现下标为 " << idx << "。\n";
        } else if (cmd == "clear") {
            list.clear();
            std::cout << "链表已清空。\n";
        } else if (cmd == "size") {
            std::cout << "当前元素个数: " << list.size() << "\n";
        } else if (cmd == "empty") {
            std::cout << (list.empty() ? "链表为空。" : "链表非空。") << "\n";
        } else if (cmd == "print") {
            printList(list);
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
