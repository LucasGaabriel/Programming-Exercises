#include <iostream>

using namespace std;

int main(){
    int n, A, G, ai, gi;
    cin >> n;

    A = 0;
    G = 0;

    for(int i=0; i<n; i++){

        cin >> ai >> gi;

        if(A + ai - G <= 500){
            cout << "A";
            A += ai;
        } else {
            cout << "G";
            G += gi;
        }
    }
    
    cout << endl;

    return 0;
}
