#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size;
    int length;
    Type *data;
public:
    Vector(int input_size) {
        size = input_size;
        data = new Type [size];
        length = 0;
    }
    ~Vector() {
        delete [] data;
    }
    void insert(int position, int value) {
        if (position < 0 || position > length){
            cout << "failed" << endl;
            return;
        }
        if (size == length){
            expand();
        }
        for (int i = length - 1; i >= position; --i){
            data[i + 1] = data[i];
        }
        data[position] = value;
        length++;
        cout << "success" << endl;
        return;
    }
    void expand() {
        size *= 2;
        Type *temp_data = data;
        data = new Type [size];
        for (int i = 0; i <= length - 1; i++){
            data[i] = temp_data[i];
        }
        delete [] temp_data;
        return;
    }
    void search(int value) {
        for (int i = 0; i <= length - 1; ++i){
            if (data[i] == value){
                cout << "success" << endl;
                return;
            }
        }
        cout << "failed" << endl;
        return;
    }
    void remove(int position) {
        if (position < 0 || position >= length){
            cout << "failed" << endl;
            return;
        }
        for (int i = position; i <= length - 1; i++){
            data[i] = data[i + 1];
        }
        --length;
        cout << "success" << endl;
        return;
    }
    void print() {
        for (int i = 0; i <= length - 1; ++i){
            if (i > 0){
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
        return;
    }
};
int main() {
    Vector<int> v(20);
    int m;
    int position, value;
    int t;
    cin >> m;
    for (int i = m; i > 0; --i){
        cin >> t;
        switch(t){
            case 1:
                cin >> position >> value;
                v.insert(position, value);
                break;
            case 2:
                cin >> position;
                v.remove(position);
                break;
            case 3:
                cin >> value;
                v.search(value);
                break;
            case 4:
                v.print();
                break;
        }
    }
    return 0;
}
