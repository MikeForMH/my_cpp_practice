//
//  main.cpp
//  rapid_product
//
//  Created by Michael Hui on 16/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <vector>
# include <string>
# include <cmath>
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
    vector <int> *addition_result = new vector <int>;
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
        addition_result->insert(addition_result->begin(), result % 10);
    }
    for (; k >= 0; --k){
        result = (*long_number)[k] + carry;
        carry = result / 10;
        addition_result->insert(addition_result->begin(), result % 10);
    }
    if (carry == 1){
        addition_result->insert(addition_result->begin(), 1);
    }
    return addition_result;
}

vector <int> * multiply(vector <int> &v1, vector <int> &v2){
    vector <int> *result = new vector <int>;
    vector <int> *long_number;
    vector <int> *short_number;
    if (v1.size() >= v2.size()){
        long_number = &v1;
        short_number = &v2;
    }
    else {
        long_number = &v2;
        short_number = &v1;
    }
    //int large_size = static_cast <int> (long_number->size());
    int small_size = static_cast <int> (short_number->size());
    int array_size = 0;
    for (int i = 0; ;){
        if (pow(2, i) > )
    }
    //for (int temp_size = small_size, i = 0; temp_size > 0; ++i){  // since i got a wrong idea here,
    //    ++array_size;                                             // thus i am unable to finish this
    //    temp_size -= static_cast <int> (pow(2, i));
    //}
    vector <int> * rapid_array_list = new vector <int> [array_size];
    if (array_size != 0){
        rapid_array_list[0] = *new vector <int> (*long_number);
    }
    vector <int> temp_vector_of_2;
    vector <int> * temp_vector_pointer;
    temp_vector_of_2.push_back(2);
    for (int i = 1; i < array_size; ++i){
        rapid_array_list[i] = *addition_by_vector(rapid_array_list[i - 1], temp_vector_of_2);
    }
    for (int temp_size = small_size, i = array_size - 1; temp_size > 0; --i){
        while (temp_size - static_cast<int>(pow(2, i)) > 0){
            temp_size -= static_cast<int>(pow(2, i));
            temp_vector_pointer = addition_by_vector(*result, rapid_array_list[i]);
            (*result).swap(*temp_vector_pointer);
        }
    }
    return result;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector <int> v1;
    vector <int> v2;
    string temp;
    int s1_length = static_cast<int>(s1.length());
    int s2_length = static_cast<int>(s2.length());
    for (int i = 0; i < s1_length; ++i){
        temp = s1[i];
        v1.push_back(stoi(temp));
    }
    for (int i = 0; i < s2_length; ++i){
        temp = s2[i];
        v2.push_back(stoi(temp));
    }
    vector <int> *result = multiply(v1, v2);
    print_number(result);
    return 0;
}
