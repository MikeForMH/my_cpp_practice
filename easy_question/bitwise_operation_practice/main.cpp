//
//  main.cpp
//  bitwise operation practice
//
//  Created by Michael Hui on 8/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

int main(){
    string input_1, input_2, temp_1, temp_2;
    cin >> input_1 >> input_2;
    int length = input_1.length();
    for (int i = 0; i < length; ++i){
        temp_1 = input_1[i];
        temp_2 = input_2[i];
        if (stoi(temp_1) && stoi(temp_2)){
            cout << 1;
        }
        else if (input_1[i] == input_2[i]){
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
