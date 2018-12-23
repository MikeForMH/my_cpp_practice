//
//  main.cpp
//  reverse_sentance_pat_1009
//
//  Created by Michael Hui on 23/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T> class Stack{
private:
    T *elements;
    int _max_size, _top_index, _count;
public:
    Stack(){
        _max_size = 80;
        elements = new string[_max_size];
        _top_index = -1;
        _count = 0;
    }
    ~Stack(){
        delete [] elements;
    }
    bool push(const T &input_data){
        if(_top_index >= _max_size - 1){
            return false;
        }
        ++_top_index;
        elements[_top_index] = input_data;
        ++_count;
        return true;
    }
    bool pop(){
        if(_top_index <= -1){
            return false;
        }
        --_top_index;
        --_count;
        return true;
    }
    T top(){
        return elements[_top_index];
    }
    void output_stack(){
        int i = 0;
        while(_count != 0){
            if(i != 0){
                cout << " ";
            }
            cout << this->top();
            this->pop();
            ++i;
        }
        cout << endl;
        return;
    }
};

int main(){
    string input_string;
    Stack <string> stack;
    while(cin >> input_string){
        stack.push(input_string);
    }
    stack.output_stack();
    return 0;
}
