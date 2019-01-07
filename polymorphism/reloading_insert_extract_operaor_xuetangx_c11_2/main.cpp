//
//  main.cpp
//  reloading_insert_extract_operaor_xuetangx_c11_2
//
//  Created by Michael Hui on 8/1/2019.
//  Copyright © 2019 Michael Hui. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
    int id;
    string name, grade;
    Student(){};
    Student(int id, string name, string grade);
    bool operator < (const Student & s) const;
};

istream & operator >> (istream & in, Student & s){
    cin >> s.id >> s.name >> s.grade;
    return in;
}
ostream & operator << (ostream & out, Student & s){
    cout << s.id << " " << s.name << " " << s.grade << endl;
    return out;
}
bool Student::operator<(const Student &s) const{
    return this->id < s.id;
}

/*请在这里填充代码*/

int main()
{
    vector<Student> sv;
    Student temp;
    while (cin >> temp)
    {
        sv.push_back(temp);
    }
    sort(sv.begin(), sv.end());
    for (int i = 0; i < sv.size(); ++i)
        cout << sv[i];
    return 0;
}
