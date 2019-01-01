//
//  main.cpp
//  number_blackhole_pat_1019
//
//  Created by Michael Hui on 1/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::to_string;
using std::stoi;
# define KAPREKAR_CONSTANT "6174"

string descending_rearrange(string input){
    for(size_t i = 0; i < input.length() - 1; ++i){
        bool swapped = false;
        for(size_t j = 0; j < input.length() - 1 - i; ++j){
            if(input[j] < input[j + 1]){
                swap(input[j], input[j + 1]);
                swapped = true;
            }
        }
        if(swapped != true){
            break;
        }
    }
    return input;
}

string ascending_rearrange(string input){
    for(size_t i = 0; i < input.length() - 1; ++i){
        bool swapped = false;
        for(size_t j = 0; j < input.length() - 1 - i; ++j){
            if(input[j] > input[j + 1]){
                swap(input[j], input[j + 1]);
                swapped = true;
            }
        }
        if(swapped != true){
            break;
        }
    }
    return input;
}

void number_black_hole(string &input){
    if(input[0] == input[1] && input[1] == input[2] && input[2] == input[3]){
        cout << input << " - " << input << " = 0000" << endl;
        return;
    }
    string temp_1, temp_2;
    if(input == KAPREKAR_CONSTANT){
        temp_1 = descending_rearrange(input);
        temp_2 = ascending_rearrange(input);
        cout << temp_1 << " - " << temp_2 << " = " << input << endl;
        return;
    }
    while(input != KAPREKAR_CONSTANT){
        if(input.length() < 4){
            input.insert(0, 4 - input.length(), '0');
        }
        temp_1 = descending_rearrange(input);
        temp_2 = ascending_rearrange(input);
        input = to_string(stoi(temp_1) - stoi(temp_2));
        if(input.length() < 4){
            input.insert(0, 4 - input.length(), '0');
        }
        cout << temp_1 << " - " << temp_2 << " = " << input << endl;
    }
    return;
}

int main(){
    string n;
    cin >> n;
    number_black_hole(n);
    return 0;
}
