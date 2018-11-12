//
//  main.cpp
//  Palindrome string
//
//  Created by Michael Hui on 4/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void palindromeString (const string &Input){
    for (int i = 0; i < Input.length()/2; ++i){
        if (Input [i] != Input [Input.length() - i - 1]){
            cout << "No." << endl;
            return;
        }
    }
    cout << "Yes." << endl;
    return;
}

int main (){
    string Input;
    cin >> Input;
    palindromeString(Input);
    return 0;
}
