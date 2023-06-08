#include <iostream>
#include<vector>
#include <climits>
using namespace std;

int minVal(vector<int> key, vector<bool> MST, int numberOfVertex){
    int min = INT_MAX, minIndex;
    for(int i = 0; i < numberOfVertex; i++){
        if(min > key[i] && !MST[i]){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
} 

void printVec(vector<int> vec){
    for(int el : vec){
        cout << el << " ";
    }
    cout << endl;
}


void prims(int startVertex, vector<vector<int>> adjMatrix, int numberOfVertex){
    vector<bool> MST(numberOfVertex, false);
    vector<int> key(numberOfVertex, INT_MAX);
    vector<int> parent(numberOfVertex, -1);
    key[startVertex] = 0;
    parent[startVertex] = -1;
    for(int i = 0; i < numberOfVertex - 1; ++i){

        int k = minVal(key, MST, numberOfVertex);
        MST[k] = true;

        for(int j = 0; j < numberOfVertex; ++j){
            if(adjMatrix[k][j] && !MST[j] && adjMatrix[k][j] < key[j]){
                key[j] = adjMatrix[k][j];
                parent[j] = k;
            }
        }
    }
    cout << "key\n";
    printVec(key);
    cout << "parent\n";
    printVec(parent);
}

int main(){
    vector<vector<int>> adjMatrix;
    adjMatrix = {{0, 3, 0, 0, 0, 1,}, {3, 0, 2, 1, 10, 0}, {0, 2, 0, 3, 0, 5}, {0, 1, 3, 0, 5, 0}, {0, 10, 0, 5, 0, 4}, {1, 0, 5, 0, 4, 0}};
    int startVertex = 0;
    int numberOfVertex = 6;
    prims(startVertex, adjMatrix, numberOfVertex);
    
    return 0;
}