//
//  main.cpp
//  sequent_list_practice_3
//
//  Created by Michael Hui on 20/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Linked_List{
public:
    Linked_List(const int &size){
        this->size = size;
        coefficient_list = new int [size];
        //index_list = new int [3];
        length = 0;
    }
    ~Linked_List(){
        delete [] coefficient_list;
        //delete [] index_list;
    }
    void insert(const int &coefficient, const int &index){
        if (coefficient == 0){
            return;
        }
        index_list[length] = index;
        coefficient_list[length] = coefficient;
        ++length;
        print_data();
        return;
    }
    void insert(const int &variable){
        this->variable = variable;
        return;
    }
    int find_sum(){
        int result = 0;
        for (int i = 0; i < length; ++i){
            result += coefficient_list[i] * find_power(index_list[i]);
        }
        return result;
    }
    void print_data(){
        for (int i = 0; i < length; ++i){
            cout << coefficient_list[i] << " ";
        }
        cout << endl;
        for (int i = 0; i > length; ++i){
            cout << index_list[i] << " ";
        }
        cout << endl;
        return;
    }
private:
    int *coefficient_list;
    int *index_list;
    int size;
    int length;
    int variable;
    int find_power(const int &index){
        if (index == 1){
            return 1;
        }
        int result = 1;
        for (int i = 0; i < index; ++i){
            result *= variable;
        }
        return result;
    }
};

int main(){
    int number_of_terms = 0, variable = 0, coefficient = 0, index = 0;
    cin >> number_of_terms;
    Linked_List linkedlist(number_of_terms);
    cin >> coefficient >> index;
    for (int i = 1; i <= number_of_terms; ++i){
        linkedlist.insert(coefficient, index);
        cin >> coefficient >> index;
    }
    
    cin >> variable;
    cout << linkedlist.find_sum() << endl;
    return 0;
}
