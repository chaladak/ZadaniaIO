#include <iostream>

using namespace std;

int main() {
    int AA[10];
    int ujemne;
    int pominiete;
    int* BB = new int;
    int j = 0;
    for (int i = 0; i < 10; i++) {
        cout << "wprowadz liczbe: "<< endl;
        cin >> AA[i];
        if(AA[i] < 0) {
            ujemne++;
            BB[j] = AA[i];
            j++;
         }
         else {
            pominiete++;
         }
            
    }
    cout << "Liczb pominietych:" << pominiete <<endl;
    cout << "Liczb ujemnych: " << ujemne <<endl;
    cout << "Liczby ujemne: ";
    for (j=j-1;j !=-1; j--) {
        cout << BB[j] << "  ";
    }
    return 0;

}