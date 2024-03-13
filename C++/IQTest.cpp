#include <iostream>

using namespace std;

const int N = 4;
char matriz[N][N];

int main(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matriz[i][j];
        }
    }

    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1; j++){
            int white = 0;
            int black = 0;

            matriz[i][j] == '#' ? black++ : white++;
            matriz[i][j+1] == '#' ? black++ : white++;
            matriz[i+1][j] == '#' ? black++ : white++;
            matriz[i+1][j+1] == '#' ? black++ : white++;

            if(white >= 3 || black >= 3){
                cout << "YES" << endl;
                return 0;
            }

        }
    }

    cout << "NO" << endl;

    return 0;
}