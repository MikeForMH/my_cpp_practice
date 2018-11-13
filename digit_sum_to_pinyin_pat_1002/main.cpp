//
//  main.cpp
//  digit_sum_to_pinyin_pat_1002
//
//  Created by Michael Hui on 13/11/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::string;

string digit_sum_to_pinyin(const string &input_number){
    string pinyin_list[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string result;
    string temp;
    int sum = 0;
    int length = static_cast <int> (input_number.length());
    for (int i = 0; i < length; ++i){
        temp = input_number[i];
        sum += stoi(temp);
    }
    for (;sum > 0;){
        result = pinyin_list[sum % 10] + " " + result;
        sum /= 10;
    }
    result.pop_back();
    return result;
}

int main(){
    string input_number;
    cin >> input_number;
    cout << digit_sum_to_pinyin(input_number) << endl;
    return 0;
}
