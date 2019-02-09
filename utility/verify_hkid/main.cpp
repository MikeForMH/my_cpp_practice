//
//  main.cpp
//  verify_hkid
//
//  Created by Michael Hui on 8/2/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//
//  sample: D2887542 YES
//          H265123A YES
//          H265723A NO

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::isalpha;

void verify_hkid(string &input){
    int sum = (input[0] - 64) * 8;
    for(int i = 1, weight = 7; i < 8; ++i, --weight){
        if(isalpha(input[i])){
            sum += 10;
        }
        else{
            sum += (input[i] - '0') * weight;
        }
    }
    if(sum % 11 == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
    return;
}

int main(){
    string input;
    cin >> input;
    verify_hkid(input);
    return 0;
}
