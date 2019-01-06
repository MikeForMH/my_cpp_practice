# include <iostream>
# include <iomanip>
# include <vector>
# include <queue>
# include <iterator>
# include <map>

using namespace std;

int main(){
    map<int, int> maps;
    
    cout << maps.find(10)->second << endl;
    return 0;
}
