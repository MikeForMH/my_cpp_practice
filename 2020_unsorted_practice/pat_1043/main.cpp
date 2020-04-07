//
//  main.cpp
//  pat_1043
//
//  Created by Michael Hui on 7/4/2020.
//  Copyright © 2020 Michael Hui. All rights reserved.
//

#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;

void handle_input(map<char, int>& data, const char& input){
    auto iter = data.find(input);
    if(iter != data.end()){
        ++iter->second;
    }else{
        data.insert({input, 1});
    }
    return;
}
void handle_output(map<char, int>& data, const char& output){
    if(data.count(output)){
        if(data[output] != 0){
            cout << output;
            --data[output];
            return;
        }else{
            data.erase(output);
            return;
        }
    }
    return;
}

int main(){
    char temp = '\0';
    map<char, int> data;
    while(true){
        temp = cin.get();
        if(temp == '\n'){
            break;
        }
        switch (temp) {
            case 'P':
                handle_input(data, temp);
                break;
            case 'A':
                handle_input(data, temp);
                break;
            case 'T':
                handle_input(data, temp);
                break;
            case 'e':
                handle_input(data, temp);
                break;
            case 's':
                handle_input(data, temp);
                break;
            case 't':
                handle_input(data, temp);
                break;
            default:
                break;
        }
    }
    char arr[6] = {'P', 'A', 'T', 'e', 's', 't'};
    while(!data.empty()){
        for(const char& i: arr){
            handle_output(data, i);
        }
    }
    cout << endl;
    return 0;
}
