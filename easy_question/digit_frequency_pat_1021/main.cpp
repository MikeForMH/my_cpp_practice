//
//  main.cpp
//  digit_frequency_pat_1021
//
//  Created by Michael Hui on 4/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

void number_frequency(string &input){
    int list[10] = {};
    for(size_t i = 0; i < input.length(); ++i){
        ++list[input[i] - '0'];
    }
    for(int i = 0; i < 10; ++i){
        if(list[i] != 0){
            cout << i << ':' << list[i] << endl;
        }
    }
    return;
}

int main(){
    string input;
    cin >> input;
    number_frequency(input);
    return 0;
}
