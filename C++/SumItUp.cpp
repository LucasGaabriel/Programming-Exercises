#include <iostream>
#include <vector>
#include <set>

using namespace std;

int X = 0;
int N = 0;
int S[12] = {0};
bool combs[12];
set<vector<int>> sums;

void createVector(vector<int> &sumset){
    for(int i=0; i<N; i++){
        if(combs[i])
            sumset.push_back(S[i]);
    }
}

bool solve(int begin, int n, int somaAtual) {
	if (begin >= n) {
		if (somaAtual == X){
            vector<int> sumset;
            createVector(sumset);
            sums.insert(sumset);
            return true;
        }
        return false;
    } else if (somaAtual > X) {
        return false;   
    } else {
		combs[begin] = false;
		bool without = solve(begin + 1, n, somaAtual);
		combs[begin] = true;
		bool with = solve(begin + 1, n, somaAtual + S[begin]);
        return with or without;
	}
}

int main() {
	while(true){
        cin >> X >> N;

        if(X == 0 && N == 0)
            break;

        for(int i=0; i<N; i++){
            cin >> S[i];
        }

        solve(0, N, 0);

        cout << "Sums of " << X << ":\n";

        if(!sums.empty()){
            for(auto ss = sums.rbegin(); ss != sums.rend(); ss++){
                for(int i=0; i < ss->size(); i++){
                    if(i > 0)
                        cout << "+";
                    cout << ss->at(i);
                }
                cout << endl;
            }

        } else {
            cout << "NONE" << endl;
        }
        
        sums.clear();
    }

    return 0;
}