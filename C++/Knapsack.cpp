#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

ll N, W;
vector<ll> Ws;
vector<ll> Vs;
vector<vector<ll>> F;

ll MFKsnapsack(int i, int j){
    if(F[i][j] < 0){
        ll value;
        if(j < Ws[i]){
            value = MFKsnapsack(i-1, j);
        } else {
            value = max(MFKsnapsack(i-1, j), Vs[i]+MFKsnapsack(i-1, j-Ws[i]));
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main(){
    cin >> N >> W;

    Ws.push_back(0);
    Vs.push_back(0);

    for(int i=1; i<N+1; i++){
        ll x, y;
        cin >> x >> y;
        Ws.push_back(x), Vs.push_back(y);
    }

    // Constroi tabela
    for(int i=0; i<Vs.size(); i++){
        vector<ll> line;

        for(int j=0; j<W+1; j++){
            if(i == 0 || j == 0){
                line.push_back(0);
            }
            else {
                line.push_back(-1);
            }
        }
        F.push_back(line);
    }
    
    cout << MFKsnapsack(N, W) << endl;
}
