//
//  main.cpp
//  magic_machine
//
//  Created by Michael Hui on 29/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename Type> class Queue{
private:
    Type *_data;
    int _head, _tail, _length, _count;
public:
    Queue(const int &input_length){
        _data = new Type [input_length];
        _length = input_length;
        _head = 0;
        _tail = -1;
        _count = 0;
    }
    ~Queue(){
        delete [] _data;
    }
    bool push(const Type &input_data){
        if (_count >= _length){
            cout << "Queue is full." << endl;
            return false;
        }
        _tail = (_tail + 1) % _length;
        _data[_tail] = input_data;
        ++_count;
        //cout << _data[_tail] << " is successfully pushed." << endl;
        return true;
    }
    void output(){
        for (int i = 0; i < _count; ++i){
            if (i != 0){
                cout << " ";
            }
            cout << _data[(i + _head) % _length];
        }
        cout << endl;
    }
    void pop(){
        if (_count == 0){
            cout << "Queue is empty." << endl;
        }
        _head = (_head + 1) % _length;
        --_count;
        //cout << _data[(_head - 1) % _length] << " is deleted." << endl;
        return;
    }
    Type front(){
        return _data[_head];
    }
    bool output_front_and_pop(){
        if (empty()){
            return false;
        }
        cout << front();
        pop();
        return true;
    }
    bool empty(){
        return _count == 0;
    }
    int get_length(){
        return _count;
    }
};

template <typename Type> class Stack{
private:
    Type *_elements;
    int _max_size, _top_index, _length;
public:
    Stack(const int &input_size){
        _max_size = input_size;
        _elements = new Type [_max_size];
        _top_index = -1;
        _length = 0;
    }
    ~Stack(){
        delete [] _elements;
    }
    bool push(const Type &input_element){
        if (_top_index >= _max_size - 1){
            cout << "Queue is full." << endl;
            return false;
        }
        ++_top_index;
        _elements[_top_index] = input_element;
        ++_length;
        //cout << elements[_top_index] << " is pushed." << endl;
        return true;
    }
    bool pop(){
        if (_top_index < 0){
            //cout << "Queue is empty." << endl;
            return false;
        }
        --_top_index;
        --_length;
        //cout << elements[_top_index + 1] << " is deleted." << endl;
        return true;
    }
    Type top(){
        if (_top_index < 0){
            //cout << "No element in queue." << endl;
            return false;
        }
        return _elements[_top_index];
    }
    bool empty(){
        return _top_index < 0;
    }
    Type return_top_and_pop(){
        if (_top_index < 0){
            cout << "error occur in return_top_and_pop" << endl;
        }
        Type temp = top();
        pop();
        return temp;
    }
    void output_all(){
        while (_top_index >= 0){
            cout << top() << endl;
            pop();
        }
        return;
    }
    int get_length(){
        return _length;
    }
};

template <typename Type> void stack_to_stack(Stack <Type> &current_stack, Stack <Type> &target_stack){
    for (int i = current_stack.get_length();i > 0; --i){
        target_stack.push(current_stack.return_top_and_pop());
    }
    return;
}

template <typename Type> bool is_magic_product(Stack <Type> &input_stack){
    Type last_value = input_stack.get_length() + 1, temp;
    for(int i = input_stack.get_length(); i > 0; --i){
        temp = input_stack.return_top_and_pop();
        if (temp >= last_value){
            return false;
        }
        last_value = temp;
    }
    return true;
}

template <typename Type> bool is_magic_sequent(Queue <Type> &input_queue, Queue <Type> &output_queue){
    int length = input_queue.get_length();
    Stack <Type> temp_stack(length);
    for (int i = 0; i < length; ++i){
        if (input_queue.front() == output_queue.front()){
            input_queue.pop();
            output_queue.pop();
        }
        else if (output_queue.front() == temp_stack.top()){
            output_queue.pop();
            temp_stack.pop();
            --i;
        }
        else {
            temp_stack.push(input_queue.front());
            input_queue.pop();
        }
    }
    while (!output_queue.empty()){
        if (temp_stack.top() != output_queue.front()){
            return false;
        }
        temp_stack.pop();
        output_queue.pop();
    }
    return true;
}

int main(){
    int n, current_value;
    cin >> n;
    Queue <int> input_queue(n);
    Queue <int> output_queue(n);
    for (int i = 0; i < n; ++i){
        cin >> current_value;
        output_queue.push(current_value);
    }
    for (int i = 1; i <= n; ++i){
        input_queue.push(i);
    }
    //input_queue.output();
    //output_queue.output();
    if (is_magic_sequent(input_queue, output_queue)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
