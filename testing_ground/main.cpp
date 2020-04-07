#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
using namespace std;

int main(){
    int input_1;
    string str_input;
    getline(cin, str_input);
    istringstream iss(str_input);
    while(iss >> input_1){
        cout << input_1 << ' ';
    }
    cout << endl;
    return 0;
}
