//
//  main.cpp
//  convert_number_format_pat_1006
//
//  Created by Michael Hui on 21/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void convert_format(int &input_number){
    if(input_number == 0){
        return;
    }
    for(int i = input_number/100; i > 0; --i){
        cout << "B";
    }
    input_number %= 100;
    for(int i = input_number/10; i > 0; --i){
        cout << "S";
    }
    input_number %= 10;
    for(int i = 1; i <= input_number; ++i){
        cout << i;
    }
    cout << endl;
    return;
}

int main(){
    int input_number;
    cin >> input_number;
    convert_format(input_number);
    return 0;
}
