//
//  main.cpp
//  integer_addition_vector_ver
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//


# include <iostream>
# include <vector>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void print_number(vector <int> *sum){
    int size = static_cast <int> (sum->size());
    for (int i = 0; i < size; i++){
        cout << (*sum)[i];
    }
    cout << endl;
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
    string s1, s2;
    cin >> s1 >> s2;
    vector <int> v1;
    vector <int> v2;
    string temp;
    for (int i = 0; i < s1.length(); ++i){
        temp = s1[i];
        v1.push_back(stoi(temp));
    }
    for (int i = 0; i < s2.length(); ++i){
        temp = s2[i];
        v2.push_back(stoi(temp));
    }
    print_number(addition_by_vector(v1, v2));
    return 0;
}
