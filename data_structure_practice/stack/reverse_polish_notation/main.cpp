//
//  main.cpp
//  reverse_polish_notation
//
//  Created by Michael Hui on 30/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <cassert>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename Type> class Queue{
public:
    Type *_data;
    int _head, _tail, _length, _count;
private:
    Queue(const int &input_length){
        _length = input_length;
        _data = new Type [_length];
        _head = 0;
        _tail = -1;
        _count = 0;
    }
    ~Queue(){
        delete [] _data;
    }
    bool push(const Type &input_data){
        if (_count >= _length){
            return false;
        }
        _tail = (_tail + 1) % _length;
        _data[_tail] = input_data;
        ++_count;
        return true;
    }
    bool pop(){
        if (_count <= 0){
            return false;
        }
        _head = (_head + 1) % _length;
        --_count;
        return true;
    }
    Type front(){
        return _data[_head];
    }
    bool empty(){
        return _count <= 0;
    }
    void output_test(){
        for (int i = 0; i < _count; ++i){
            if (i != 0){
                cout << " ";
            }
            cout << _data[(i + _head) % _length];
        }
        cout << endl;
        return;
    }
};

template <typename Type> class Stack{
private:
    Type *_data;
    int _max_size, _top_index, _count;
public:
    Stack(const int &input_size){
        _max_size = input_size;
        _data = new Type [_max_size];
        _top_index = -1;
        _count = 0;
    }
    ~Stack(){
        delete [] _data;
    }
    bool push(const Type &input_data){
        if (_top_index >= _max_size - 1){
            return false;
        }
        ++_top_index;
        _data[_top_index] = input_data;
        ++_count;
        return true;
    }
    bool pop(){
        if (_top_index <= -1){
            return false;
        }
        --_top_index;
        --_count;
        return true;
    }
    Type top(){
        return _data[_top_index];
    }
    void testing_output(){
        for (int i = 0; i < _count; ++i){
            if (i != 0){
                cout << " ";
            }
            cout << _data[_top_index - i];
        }
        cout << endl;
        return;
    }
    bool empty(){
        return _count <= 0;
    }
};

int evaluate_reverse_polish_notation(string *input_string){
    int length = static_cast <int> (input_string->length());
    Stack <int> numbers(length);
    int i = 0, temp_1, temp_2;
    while(i < length){
        if (isdigit((*input_string)[i])){
            numbers.push((*input_string)[i] - '0');
            ++i;
        }
        else {
            temp_1 = numbers.top();
            numbers.pop();
            temp_2 = numbers.top();
            numbers.pop();
            switch((*input_string)[i]){
                case '+':
                    numbers.push(temp_2 + temp_1);
                    break;
                case '-':
                    numbers.push(temp_2 - temp_1);
                    break;
                case '*':
                    numbers.push(temp_2 * temp_1);
                    break;
                case '/':
                    numbers.push(temp_2 / temp_1);
                    break;
            }
            ++i;
        }
    }
    return numbers.top();
}

string* reverse_polish_notation(const string &input_string){
    string *output_string = new string;
    int length = static_cast <int> (input_string.length());
    Stack <char> temp(length);
    for (int i = 0; i < length; ++i){
        if (isdigit(input_string[i])){
            cout << input_string[i];
            output_string->push_back(input_string[i]);
            continue;
        }
        if (temp.empty()){
            temp.push(input_string[i]);
            continue;
        }
        if (input_string[i] == '*' || input_string[i] == '/'){
            if (temp.top() == '+' || temp.top() == '-'){
                temp.push(input_string[i]);
                continue;
            }
            cout << temp.top();
            output_string->push_back(temp.top());
            temp.pop();
            temp.push(input_string[i]);
            continue;
        }
        while (!temp.empty()){
            cout << temp.top();
            output_string->push_back(temp.top());
            temp.pop();
        }
        temp.push(input_string[i]);
    }
    while(!temp.empty()){
        cout << temp.top();
        output_string->push_back(temp.top());
        temp.pop();
    }
    cout << endl;
    return output_string;
}

int main(){
    string input_string;
    string *output_string;
    cin >> input_string;
    output_string = reverse_polish_notation(input_string);
    cout << evaluate_reverse_polish_notation(output_string) << endl;
    return 0;
}

