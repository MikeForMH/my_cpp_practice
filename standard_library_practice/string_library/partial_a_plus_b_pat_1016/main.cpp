//
//  main.cpp
//  partial_a_plus_b_pat_1016
//
//  Created by Michael Hui on 30/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

int count(string &a, char &d_a){
    int result = 0;
    for(size_t i = 0; i < a.length(); ++i){
        if(a[i] == d_a){
            ++result;
        }
    }
    return result;
}

void partial_a_plus_b(string &a, char &d_a, string &b, char &d_b){
    string p_a, p_b;
    for(int i = count(a, d_a); i > 0; --i){
        p_a = p_a + d_a;
    }
    for(int i = count(b, d_b); i > 0; --i){
        p_b = p_b + d_b;
    }
    if(p_a.empty()){
        p_a = "0";
    }
    if(p_b.empty()){
        p_b = "0";
    }
    cout << stoi(p_a) + stoi(p_b) << endl;
}

int main(){
    string a, b;
    char d_a, d_b;
    cin >> a >> d_a >> b >> d_b;
    partial_a_plus_b(a, d_a, b, d_b);
    return 0;
}
