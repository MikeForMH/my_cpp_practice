//
//  main.cpp
//  recent_calls
//
//  Created by Michael Hui on 26/11/2018.
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
};

template <typename Type> void output_phone_record(Queue <Type> &missed_calls, Queue <Type> &incoming_calls,
                                                  Queue <Type> &outgoing_calls){
    for (int i = 0; i < 10; ++i){
        if (!missed_calls.output_front_and_pop()){
            cout << "0";
        }
        cout << " ";
        if (!incoming_calls.output_front_and_pop()){
            cout << "0";
        }
        cout << " ";
        if (!outgoing_calls.output_front_and_pop()){
            cout << "0";
        }
        cout << endl;
    }
    return;
}

template <typename Type> void testing_output(Queue <Type> &testing_queue){
    cout << "second testing: " << testing_queue.front() << endl;
    return;
}
template <typename Type> void testing_output_2(Queue <Type> &testing_queue){
    if (!testing_queue.output_front_and_pop()){
        cout << "output not success.";
    }
    cout << endl;
    //testing_queue.output_front_and_pop();
    cout << endl;
    return;
}

int main(){
    Queue <string> missed_calls(10), incoming_calls(10), outgoing_calls(10);
    //Queue <int> testing(10);
    //testing.push(123);
    //cout << "first testing: " << testing.front() << endl;
    //testing_output_2(testing);
    int flag = 0;
    string input_number;
    for (int i = 0; i < 10; ++i){
        cin >> flag >> input_number;
        switch(flag){
            case 0:
                missed_calls.push(input_number);
                break;
            case 1:
                incoming_calls.push(input_number);
                break;
            case 2:
                outgoing_calls.push(input_number);
                break;
        }
    }
    output_phone_record(missed_calls, incoming_calls, outgoing_calls);
    return 0;
}
