//
//  main.cpp
//  elementary_arithmetic_operations
//
//  Created by Michael Hui on 27/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

#include<iostream>
#include<string>
#include<cassert>
using std::cin;
using std::cout;
using std::endl;
using std::string;
template<typename Type> class Stack {
private:
    Type *elements;
    int _max_size, _top_index;
public:
    Stack(const int &input_size) {
        _max_size = input_size;
        elements = new Type [_max_size];
        _top_index = -1;
    }
    ~Stack() {
        delete [] elements;
    }
    bool push(const Type &input_element) {
        if (_top_index >= _max_size - 1){
            cout << "Queue is full." << endl;
            return false;
        }
        ++_top_index;
        elements[_top_index] = input_element;
        cout << elements[_top_index] << " is pushed." << endl;
        return true;
    }
    bool pop() {
        if (_top_index < 0){
            cout << "Queue is empty." << endl;
            return false;
        }
        --_top_index;
        cout << elements[_top_index + 1] << " is deleted." << endl;
        return true;
    }
    Type top() {
        if (_top_index <= -1){
            cout << "No element in queue." << endl;
            assert(_top_index >= 0);
        }
        cout << elements[_top_index] << " is returned" << endl;
        return elements[_top_index];
    }
    bool empty() {
        if (_top_index < 0){
            cout << "Queue is not empty." << endl;
        }
        else {
            cout << "Queue is empty." << endl;
        }
        return _top_index < 0;
    }
};
bool precede(const char &prior_sign, const char &current_sign) {
    if (prior_sign == '+' || prior_sign == '-'){
        if (current_sign == '*' || current_sign == '/'){
            cout << current_sign << " precedes " << prior_sign << "." << endl;
            return true;
        }
        cout << current_sign << " does not precede " << prior_sign << "." << endl;
        return false;
    }
    cout << current_sign << " does not precede " << prior_sign << "." << endl;
    return false;
}
float operate(const char &sign, const float &prior_number, const float &current_number) {
    switch(sign){
        case '+':
            cout << prior_number << " + " << current_number << " = " << prior_number + current_number << endl;
            return prior_number + current_number;
            break;
        case '-':
            cout << prior_number << " - " << current_number << " = " << prior_number - current_number << endl;
            return prior_number - current_number;
            break;
        case '*':
            cout << prior_number << " * " << current_number << " = " << prior_number * current_number << endl;
            return prior_number * current_number;
            break;
        case '/':
            cout << prior_number << " / " << current_number << " = " << prior_number / current_number << endl;
            return prior_number / current_number;
            break;
    }
    cout << "Invalid operation." << endl;
    return 0;
}
void calc(Stack <float> &numbers, Stack <char> &operators) {
    float current_number = numbers.top();
    numbers.pop();
    float prior_number = numbers.top();
    numbers.pop();
    numbers.push(operate(operators.top(), prior_number, current_number));
    operators.pop();
    return;
}
int main() {
    int m;
    cin >> m;
    Stack <float> numbers(m);
    Stack <char> operators(m);
    string buffer;
    cin >> buffer;
    int i = 0;
    while (i < m){
        if (isdigit(buffer[i])){
            numbers.push(buffer[i] - '0');
            ++i;
        }
        else {
            if (operators.empty() || precede(operators.top(), buffer[i])){
                operators.push(buffer[i]);
                ++i;
            }
            else {
                calc(numbers, operators);
            }
        }
    }
    while (!operators.empty()){
        calc(numbers, operators);
    }
    cout << numbers.top() << endl;
    return 0;
}
