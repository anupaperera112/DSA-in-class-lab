//#include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> SSSP(int sourceVertex, vector<vector<int>> adjMatrix){
    vector<int> ssp;
    vector<bool> visited(6, false);
    visited[sourceVertex] = true;
    int currentVertex, index = 0;
    ssp.resize(6, INT_MAX);
    ssp[sourceVertex] = 0;
    while(true){
        visited[sourceVertex] = true;
        vector<int> raw = adjMatrix[sourceVertex];
        
        for(int i = 0; i < 6; i++){
            if(raw[i] != 0){ 
                if(ssp[sourceVertex] + raw[i] < ssp[i]) 
                    ssp[i] += raw[i];
            }
        }
        while(visited[index] == true){
            int temp = *min_element(ssp.begin(), ssp.end());
            auto it = find(ssp.begin(), ssp.end(), temp);
            index = it - ssp.end();
        }
        sourceVertex = index;
    }
    return ssp;
}

int main(){
    vector<vector<int>> adjMatrix;
    adjMatrix = {{0, 10, 0, 0, 15, 5}, {10, 0, 10, 30, 0, 0}, {0, 10, 0, 12, 5, 0}, {0, 30, 12, 0, 0, 20}, {15, 0, 5, 0, 0, 0}, {5, 0, 0, 20, 0, 0}};
    int sourceVertex = 0;
    vector<int> SSP = SSSP(sourceVertex, adjMatrix);
    cout << "Source Vertex is " << sourceVertex << endl;
    for(int el : SSP){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}