#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// 定義 Stack 的節點結構
struct Node {
    char data;  // 存儲字符 (運算子或括號)
    Node* next; // 指向下一個節點
};

// 使用 linked list 實作 Stack
class Stack {
private:
    Node* top; // 指向堆疊頂端
public:
    Stack() { top = nullptr; } // 初始化堆疊

    // Push 操作：將元素放入堆疊
    void push(char ch) {
        Node* newNode = new Node; // 創建新節點
        newNode->data = ch;       // 存入數據
        newNode->next = top;      // 讓新節點指向目前的頂端
        top = newNode;            // 更新頂端指標
    }

    // Pop 操作：移除並回傳頂端元素
    char pop() {
        if (isEmpty()) return '\0'; // 若堆疊為空，回傳空字符
        char ch = top->data;         // 取得頂端元素
        Node* temp = top;            // 暫存頂端節點
        top = top->next;             // 移動頂端指標
        delete temp;                 // 釋放記憶體
        return ch;                   // 回傳彈出的元素
    }

    // Peek 操作：取得頂端元素但不移除
    char peek() {
        return (top ? top->data : '\0');
    }

    // 判斷堆疊是否為空
    bool isEmpty() {
        return top == nullptr;
    }
};

// 判斷運算子(加減乘除) 的優先順序
int precedence(char op) {
	if (op == '+' || op == '-') {
        return 1;//給+和-優先順序1 
    }
    if (op == '*' || op == '/') {
        return 2;//給*和/優先順序2 
    }
    else {
        return 0;//其他的給優先順序0 
    }   
} 

// 將中序表達式 (infix) 轉換為後序表達式 (postfix)
void InfixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    int j = 0;//用來紀錄放到輸出的哪個位置 
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];//放到ch 

        if (isalnum(ch)) {
            postfix[j] = ch;//字母和數字直接輸出 
            j++;
        }
        else if (ch == '(') {
            stack.push(ch);//(放進stack 
        }
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix[j] = stack.pop();//把直到左括號或直到stack變空的運算符號都pop 
                j++;
            }

            stack.pop();//(拿掉 
        }
        else {
            while (!stack.isEmpty() && stack.peek() != '(' && precedence(stack.peek()) >= precedence(ch)) {
                postfix[j] = stack.pop();//當優先順序高的運算符號遇到優先順序低的時候 高的要被輸出 
                j++;
            }

            stack.push(ch);//低的放進stack
        }
    }

    while (!stack.isEmpty()) {
        postfix[j] = stack.pop();//把剩下的都輸出 
        j++;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter an Infix expression: ";
    cin >> infix; // 輸入中序表達式

    InfixToPostfix(infix, postfix); // 轉換為後序表達式
    cout << "Postfix expression: " << postfix << endl; // 輸出後序表達式

    return 0;
}
