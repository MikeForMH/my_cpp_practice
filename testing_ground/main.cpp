#include <iostream>
#include <iomanip>      // std::setw

using namespace std;

int main()
{
    int num,i,count,n;
    //cout << "Enter max range: ";
    cin >> n;
    for(num = 1;num<n;num++){
        count = 0;
        for(i=2;i<=num/2;i++){
            if(num%i==0){
                count++;
                break;
            }
        }
        
        if(count==0 && num!= 1)
            cout << num << endl;
    }
    return 0;
}

/*
 OUTPUT:
 Enter max range: 30
 2  3  5  7 11 13 17 19 23 29
 */
