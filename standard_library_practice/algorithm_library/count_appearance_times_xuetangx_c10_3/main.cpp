//
//  main.cpp
//  count_appearance_times_xuetangx_c10_3
//
//  Created by Michael Hui on 7/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::count;
using std::vector;

int main(){
    string str_1, str_2;
    vector <string> sub_string;
    cin >> str_1 >> str_2;
    for(string::iterator i = str_1.begin(); i != str_1.end() - str_2.length(); ++i){
        sub_string.push_back(string(i, i + str_2.length()));
    }
    cout << count(sub_string.begin(), sub_string.end(), str_2) << endl;
    return 0;
}
