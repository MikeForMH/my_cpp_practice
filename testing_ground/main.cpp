# include <iostream>
# include <iomanip>
# include <vector>
# include <queue>
# include <iterator>
# include <string>
# include <algorithm>
using namespace std;

int main(){
    vector <int> list;
    int temp;
    while(cin >> temp){
        list.push_back(temp);
    }
    sort(list.begin(), list.end()); 
    for(int var: list){
        cout << " " << var;
    }
    cout << endl;
    return 0;
}
