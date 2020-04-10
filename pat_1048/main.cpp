//
//  main.cpp
//  pat_1048
//
//  Created by Michael Hui on 10/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const char data[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main() {
    string key = "";
    string text = "";
    string result = "";
    bool is_odd = true;
    cin >> key >> text;
    if(key.length() > text.length()){
        text.insert(0, key.length() - text.length(), '0');
    }
    for(auto text_it = text.rbegin(), key_it = key.rbegin(); text_it != text.rend(); ++text_it){
        if(key_it == key.rend()){
            result.insert(result.begin(), *text_it);
        }else{
            if(is_odd){
                result.insert(result.begin(), data[((*text_it - '0') + (*key_it - '0')) % 13]);
            }else{
                int temp = *text_it - *key_it;
                if(temp < 0){
                    temp += 10;
                }
                result.insert(result.begin(), static_cast<char>('0' + temp));
            }
            is_odd = !is_odd;
            ++key_it;
        }
    }
    cout << result << endl;
    return 0;
}
