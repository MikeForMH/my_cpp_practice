//
//  main.cpp
//  palindrome_test_2
//
//  Created by Michael Hui on 30/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename Type> class Queue{
private:
    Type *_data;
    int _head, _tail, _length, _count;
public:
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
            cout << "Queue is empty." << endl;
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
        return _count == 0;
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
    Type *elements;
    int _max_size, _top_index, _count;
public:
    Stack(const int &input_size){
        _max_size = input_size;
        elements = new Type [_max_size];
        _top_index = -1;
        _count = 0;
    }
    ~Stack(){
        delete [] elements;
    }
    bool push(const Type &input_element){
        if (_top_index >= _max_size - 1){
            return false;
        }
        ++_top_index;
        elements[_top_index] = input_element;
        ++_count;
        return true;
    }
    bool pop(){
        if (_top_index < 0){
            return false;
        }
        --_top_index;
        --_count;
        return true;
    }
    Type top(){
        return elements[_top_index];
    }
    bool empty(){
        return _top_index < 0;
    }
};

bool is_palindromic(const string &input_string){
    int length = static_cast <int> (input_string.length());
    Queue <char> temp_queue(length);
    Stack <char> temp_stack(length);
    for (int i = 0; i < length; ++i){
        temp_queue.push(input_string[i]);
        temp_stack.push(input_string[i]);
    }
    for (int i = length / 2; i > 0; --i){
        if (temp_stack.top() != temp_queue.front()){
            return false;
        }
        temp_stack.pop();
        temp_queue.pop();
    }
    return true;
}

int main(){
    string input_string;
    cin >> input_string;
    input_string.pop_back();
    if (is_palindromic(input_string)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
