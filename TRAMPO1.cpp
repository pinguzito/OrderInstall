#include <iostream>
#include <vector>
#define N 6
using namespace std;
 
int grafo[][N]={{0,0,0,1,0,0},
                {0,0,1,1,0,0},
                {0,0,0,1,1,0},
                {0,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0}};
int grafoC[N][N]; 
vector<int> res;

void imprimir(){
    //print the graph with each component dependencies
    cout << "Grafo:" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(j==0){
                cout << i << ":";
            }
            if(grafo[i][j] != 0 && j < N-1){
                cout << i << "->" << j << " ";
            }
            else if(grafo[i][j] != 0 && j == N-1){
                cout << i << "->" << j << endl;
            }
            else if(grafo[i][j] == 0 && j == N-1){
                cout << endl;
            }
        }
    }
}
 
void copia(){
    //copy the first graph into a new one
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grafoC[i][j] = grafo[i][j];
        }
    }
}
 
void ajuste(int rep){
    //adjust the copied graph, replacing each column and row with -1
    for(int k = 0; k < N; k++){
        grafoC[k][rep] = -1;
        grafoC[rep][k] = -1;
    }
}

void ordem_instalacao(){
    //define an installation order
    for(int i = 0; i < N; i++){
        int count = 0;
        bool tag = false;
        for(int j = 0; j < N; j++){
            if(grafoC[i][j] == -1){
                count += 1;
            }
            if(grafoC[i][j] == 1){
                tag = true;
            }
        }
        if(count == 6){
            tag = true;
        }
        if(!tag){
            res.push_back(i);
            ajuste(i);
            i = -1;
        }
    }
}
 
void resultado(){
    //prints the installation order defined in "ordem_instalacao"
    cout << "Ordem de instalacao: ";
    for(int i = 0; i < res.size(); i++){
        cout << res.at(i) << " ";
    }
    cout << endl;
    //must be 3 0 4 2 1 5 in example
}

int main(){
    imprimir();
    copia();
    ordem_instalacao();
    resultado();
    return 0;
}