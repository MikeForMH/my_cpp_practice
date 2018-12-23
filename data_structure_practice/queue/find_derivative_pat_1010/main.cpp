//
//  main.cpp
//  find_derivative_pat_1010
//
//  Created by Michael Hui on 23/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

template <typename T> class Queue{
private:
    T *_data;
    int _head, _tail, _count, _length;
    void expend(){
        int new_length = 2 * _length;
        T *new_data = new T[new_length];
        for(int i = 0; i < _count; ++i){
            new_data[(_head + i) % new_length] = _data[(_head + i) % new_length];
        }
        _tail = (_head + _count - 1) % new_length;
        _length = new_length;
        swap(_data, new_data);
        delete [] new_data;
        return;
    }
public:
    Queue(){
        _length = 2;
        _data = new T[_length];
        _head = 0;
        _tail = -1;
        _count = 0;
    }
    ~Queue(){
        delete [] _data;
    }
    void push(const T &input_data){
        if(_count >= _length){
            this->expend();
        }
        _tail = (_tail + 1) % _length;
        _data[_tail] = input_data;
        ++_count;
        return;
    }
    void pop(){
        if(_count <= 0){
            return;
        }
        _head = (_head + 1) % _length;
        --_count;
        return;
    }
    T front(){
        return _data[_head];
    }
    bool empty(){
        return _count <= 0;
    }
};

class Integral{
public:
    int _coefficient;
    int _index;
    int _coefficient_of_dydx;
    int _index_of_dydx;
    Integral(const int &input_coefficient, const int &input_index){
        _coefficient = input_coefficient;
        _index = input_index;
        _coefficient_of_dydx = _coefficient * _index;
        _index_of_dydx = _index - 1;
    }
    Integral(){
        _coefficient = 0;
        _index = 0;
        _coefficient_of_dydx = 0;
        _index_of_dydx = 0;
    };
    void output_dydx(){
        cout << _coefficient_of_dydx << " " << _index_of_dydx;
        return;
    }
};

void output_derivative(Queue <Integral> &input_queue){
    int i = 0, output_count = 0;
    while(!input_queue.empty()){
        if(input_queue.front()._index == 0 && input_queue.front()._coefficient == 0){
            if(i != 0){
                cout << " ";
            }
            cout << 0 << " " << 0;
            ++output_count;
        }
        else if(input_queue.front()._coefficient_of_dydx != 0){
            if(i != 0){
                cout << " ";
            }
            input_queue.front().output_dydx();
            output_count++;
        }
        input_queue.pop();
        ++i;
    }
    if(output_count <= 0){
        cout << 0 << " " << 0;
    }
    cout << endl;
}

int main(){
    Queue <Integral> queue;
    int var_1, var_2;
    while(cin >> var_1 >> var_2){
        queue.push(Integral(var_1, var_2));
    }
    output_derivative(queue);
    return 0;
}
