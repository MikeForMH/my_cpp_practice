//
//  main.cpp
//  bracket_matching_xuetangx_c9_3
//
//  Created by Michael Hui on 5/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

template<class T, int MAX = 1000>
class Stack
{
private:
    //T list[MAX + 1];
public:
    int top;
    Stack();
    bool push(const T &item);//将item压栈
    //T pop();//将栈顶元素弹出栈
    //const T & peek() const;//访问栈顶元素
    bool isEmpty() const;//判断是否栈空
};
//请完成栈模板类的实现，并解决括号匹配问题

template<class T, int MAX> Stack<T, MAX>::Stack(){
    top = -1;
}
template<class T, int MAX> bool Stack<T, MAX>::push(const T &item){
    if(item == '('){
        ++top;
        return true;
    }
    if(item == ')'){
        if(isEmpty()){
            return false;
        }
        --top;
    }
    return true;
}

template<class T, int MAX> bool Stack<T, MAX>::isEmpty() const{
    if(top <= -1){
        return true;
    }
    return false;
}

int main(){
    Stack<char> stack;
    string input;
    while(cin >> input) {
        for(size_t i = 0; i < input.length(); ++i){
            if(!stack.push(input[i])){
                stack.top = 1;
                break;
            }
        }
        if(stack.isEmpty()){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        stack.top = -1;
    }
    return 0;
}
