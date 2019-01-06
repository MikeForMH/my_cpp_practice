//
//  main.cpp
//  word_count_xuetangx_c10_1
//
//  Created by Michael Hui on 7/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <map>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main(){
    map<string, int> word_count;
    string input;
    do{
        cin >> input;
        if(input == "QUIT"){
            break;
        }
        cout << word_count[input]++ << endl;
    }
    while(true);
    return 0;
}
