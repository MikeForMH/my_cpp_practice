//
//  main.cpp
//  addition_by_string
//
//  Created by Michael Hui on 4/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
//# include <cmath>
//# include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;


string stringAddition (string s1, string s2){
    string OneToTen = "0123456789";
    string Result, temp1, temp2;
    int carry = 0, DigitSum = 0, SignOfs1 = 1, SignOfs2 = 1; // carry是进位
    
    if (s1 [0] == '-'){
        SignOfs1 = -1;
        s1.erase(0, 1);
    }
    else if (s2 [0] == '-'){
        SignOfs2 = -1;
        s2.erase(0, 1);
    }
    
    int s1_Length = static_cast <int> (s1.length()), s2_Length = static_cast <int> (s2.length());
    
    if (s1_Length > s2_Length){ // 在短的string前面补上0
        s2.insert (0, s1_Length - s2_Length, '0');
    }
    else if (s2_Length > s1_Length){
        s2.insert (0, s2_Length - s1_Length, '0');
    }
    
    for (int i = int (s1_Length - 1); i > -1; --i){
        temp1 = s1 [i];
        temp2 = s2 [i];
        DigitSum = stoi (temp1) + stoi (temp2) + carry;
        Result = OneToTen [(DigitSum + 10) % 10] + Result;
        carry = DigitSum / 10;
    }
    if (carry == 1){
        Result = OneToTen [1] + Result;
    }
    return Result;
}

int main (){
    string s1, s2, temp;
    cin >> s1 >> s2;
    temp = stringAddition (s1, s2);
    cout << temp << endl;
    return 0;
}
