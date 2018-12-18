//
//  main.cpp
//  find_same_username
//
//  Created by Michael Hui on 16/12/2018.
//  Copyright © 2018 Michael Hui. All rights reserved.
//

# include <iostream>
# include <string>
# include <cstring>
# include <cmath>
# include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Hash_Table{
private:
    vector <string> *_element;
    int _size;
    bool case_insensitive_compare(const string &str_1, const string &str_2){
        if(str_1.length() != str_2.length()){
            return false;
        }
        for(size_t i = 0; i < str_1.length(); ++i){
            if(tolower(str_1[i]) != tolower(str_2[i])){
                return false;
            }
        }
        return true;
    }
public:
    Hash_Table(){
        _size = 200000;
        _element = new vector <string>[_size];
    }
    ~Hash_Table(){
        delete [] _element;
    }
    int get_hash(const string &input_string){
        int hash_value = 0, ascii_value;
        for(size_t i = 0; i < input_string.length(); ++i){
            ascii_value = input_string[i];
            if(ascii_value < 91){
                ascii_value += 32;
            }
            hash_value = (hash_value * 256 + ascii_value + 128) % _size;
        }
        return hash_value;
    }
    void insert(const string &input_string){
        int hash_value = get_hash(input_string);
        if(_element[hash_value].empty()){
            _element[hash_value].push_back(input_string);
            cout << "No" << endl;
            return;
        }
        else{
            for(int i = 0; i < _element[hash_value].size(); ++i){
                if(case_insensitive_compare(input_string, _element[hash_value][i])){
                    cout << "Yes" << endl;
                    return;
                }
            }
            _element[hash_value].push_back(input_string);
            cout << "No" << endl;
            return;
        }
    }
};

int main(){
    int number_of_users;
    string input_string;
    Hash_Table hash_table;
    cin >> number_of_users;
    for(int i = 0; i < number_of_users; ++i){
        cin >> input_string;
        hash_table.insert(input_string);
    }
    return 0;
}
