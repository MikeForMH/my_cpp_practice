//
//  main.cpp
//  sequent_list_practice_2
//
//  Created by Michael Hui on 19/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T> class Sequent_List{
private:
    int size;
    int length;
    T *data;
public:
    Sequent_List(int size){
        this->size = size;
        data = new T [size];
        length = 0;
    }
    ~Sequent_List(){
        delete [] data;
    }
    void insert(int value){
        data[length] = value;
        ++length;
        return;
    }
    void move_leftward(int units){
        T *temp_data = new T [size];
        for (int i = 0; i < length; ++i){
            temp_data[(length - units + i) % length] = data[i];
        }
        delete [] data;
        data = temp_data;
        return;
    }
    void print_list(){
        for (int i = 0; i < length; ++i){
            if (i != 0){
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
        return;
    }
};

int main(){
    int data_quantity, moving_units, input_data;
    cin >> data_quantity >> moving_units;
    Sequent_List <int> sequent_list(data_quantity);
    for (int i = 0; i < data_quantity; ++i){
        cin >> input_data;
        sequent_list.insert(input_data);
    }
    sequent_list.move_leftward(moving_units);
    sequent_list.print_list();
    return 0;
}
