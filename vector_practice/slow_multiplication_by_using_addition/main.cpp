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

int * multiply(int *n1, int *n2){
    int long_size, short_size;
    if (sizeof(n1) >= sizeof(n2)){
        long_size = sizeof(n1)/sizeof(int);
        short_size = sizeof(n2)/sizeof(int);
    }
    else {
        long_size = sizeof(n2)/sizeof(int);
        short_size = sizeof(n1)/sizeof(int);
    }
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
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
    int *result = multiply(input_number_1, input_number_2);
    return 0;
}
