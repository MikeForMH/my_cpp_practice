//
//  main.cpp
//  move_array_rightward_pat_1008
//
//  Created by Michael Hui on 22/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T> class Full_Queue{
private:
    T *_data;
    int _head, _tail, _length, _count;
public:
    Full_Queue(const int &length_input){
        _data = new T[length_input];
        _length = length_input;
        _head = 0;
        _tail = -1;
        _count = 0;
    }
    ~Full_Queue(){
        delete [] _data;
    }
    bool push(T input_data){
        if(_count >= _length){
            return false;
        }
        _tail = (_tail + 1) % _length;
        _data[_tail] = input_data;
        ++_count;
        return true;
    }
    void output(){
        for(int i = 0, j = _head; i < _count; ++i){
            if(i != 0){
                cout << " ";
            }
            cout << _data[j];
            j = (j + 1) % _length;
        }
        cout << endl;
        return;
    }
    void move_rightward_for_ver_2(const int &input_units){
        _tail = _tail - input_units % _length;
        _head = _head - input_units % _length + _length;
        return;
    }
};

int main(){
    int n, input_number, moving_units;
    cin >> n >> moving_units;
    Full_Queue <int> queue(n);
    for(int i = 0; i < n; ++i){
        cin >> input_number;
        queue.push(input_number);
    }
    queue.move_rightward_for_ver_2(moving_units);
    queue.output();
    return 0;
}
