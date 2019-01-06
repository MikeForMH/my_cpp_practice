//
//  main.cpp
//  add one to the number
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print_number(vector <int> *sum){
    int size = static_cast <int> (sum->size());
    for (int i = 0; i < size - 1; i++){
        cout << (*sum)[i] << " ";
    }
    cout << (*sum)[size - 1] << endl;
    return;
}

vector <int>* addition_by_vector(vector <int> &input_number_1, vector <int> &input_number_2){
    static vector <int> addition_result;
    static vector <int> *sum;
    vector <int> *long_number;
    vector <int> *short_number;
    if (input_number_1.size() >= input_number_2.size()){
        long_number = &input_number_1;
        short_number = &input_number_2;
    }
    else {
        short_number = &input_number_1;
        long_number = &input_number_2;
    }
    int carry = 0, result;
    int large_digits = static_cast <int> (long_number->size());
    int small_digits = static_cast <int> (short_number->size());
    int i = small_digits - 1, k = large_digits - 1;
    for (; i >= 0; --i, --k ){
        result = (*short_number)[i] + (*long_number)[k] + carry;
        carry = result / 10;
        addition_result.insert(addition_result.begin(), result % 10);
    }
    for (; k >= 0; --k){
        result = (*long_number)[k] + carry;
        carry = result / 10;
        addition_result.insert(addition_result.begin(), result % 10);
    }
    if (carry == 1){
        addition_result.insert(addition_result.begin(), 1);
    }
    sum = &addition_result;
    input_number_1.clear();
    input_number_2.clear();
    return sum;
}

int main(){
    int digits, input;
    cin >> digits;
    vector <int> input_number_1;
    for (int i = 0; i < digits; ++i){
        cin >> input;
        input_number_1.push_back(input);
    }
    vector <int> input_number_2;
    input_number_2.push_back(1);
    vector <int> *result;
    result = addition_by_vector(input_number_1, input_number_2);
    print_number(result);
    result->clear();
    return 0;
}
