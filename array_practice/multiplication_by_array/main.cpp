//
//  main.cpp
//  slow_multiplication_by_using_addition
//
//  Created by Michael Hui on 17/11/2018.
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
using std::to_string;

string * multiply(string s1, string s2){
    string temp;
    int s1_length = static_cast<int>(s1.length());
    int s2_length = static_cast<int>(s2.length());
    int *input_number_1 = new int [s1_length];
    int *input_number_2 = new int [s2_length];
    for (int i = 0; i < s1_length; ++i){
        temp = s1[i];
        input_number_1[i] = stoi(temp);
    }
    for (int i = 0; i < s2_length; ++i){
        temp = s2[i];
        input_number_2[i] = stoi(temp);
    }
    int long_size, short_size;
    int *long_number, *short_number;
    if (s1_length >= s2_length){
        long_size = s1_length;
        long_number = input_number_1;
        short_size = s2_length;
        short_number = input_number_2;
    }
    else {
        long_size = s2_length;
        long_number = input_number_2;
        short_size = s1_length;
        short_number = input_number_1;
    }
    int **buffer_array = new int *[short_size];
    for (int i = 0; i < short_size; ++i){
        buffer_array[i] = new int [long_size];
    }
    for (int i = short_size - 1, m = 0; i >= 0; --i, ++m){
        for (int j = long_size - 1, n = 0; j >= 0; --j, ++n){
            buffer_array[m][n] = short_number[i] * long_number[j];
            //cout << buffer_array[m][n] << " "; //testing
        }
        //cout << endl; // testing
    }
    int carry = 0, sum = 0, temp_1, temp_2;
    int *result = new int [long_size + short_size];
    for (int i = 0; i < long_size + short_size; ++i){
        result[i] = 0;
    }
    for (int i = 0; i < short_size; ++i){
        for (int j = 0; j < long_size; ++j){
            temp_1 = result[i + j];
            temp_2 = buffer_array[i][j];
            sum = temp_1 + temp_2 + carry;
            carry = sum / 10;
            result[i + j] = sum % 10;
            //cout << result[i + j] << " ";
        }
        if (carry != 0){
            result[i + long_size] = carry;
        }
        carry = 0;
        /*
        //cout << result[short_size - i] << endl;
        for (int k = 0; k < long_size + short_size; ++k){ // testing
            cout << result[k] << " ";                     //
        }                                                 //
        cout << endl;                                     //
        */
    }
    string *output_string = new string;
    for (int i = 0; i < short_size; ++i){
        delete [] buffer_array[i];
    }
    delete [] buffer_array;
    delete [] input_number_1;
    delete [] input_number_2;
    int count = 0;
    for (int i = long_size + short_size - 1; i >= 0; --i){
        if (result[i] != 0){
            for (int k = i; k >= 0; --k){
                temp = to_string(result[k]);
                (*output_string) = (*output_string) + temp;
                ++count;
                //cout << temp << " ";
            }
            //cout << endl;
            break;
        }
    }
    if (count == 0){
        (*output_string) = "0";
    }
    //for (int k = 0; k < long_size + short_size; ++k){ // testing
    //    cout << result[k] << " ";                     //
    //}                                                 //
    //cout << endl;                                     //
    delete [] result;
    //cout << (*output_string)[0] << endl;
    return output_string;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string *result = multiply(s1, s2);
    cout << *result << endl;
    return 0;
}
