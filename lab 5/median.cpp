#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main() {
 vector<int> arr = { 4, 3, 5, 2, 1, 3, 2, 3 };
 int n = 8;
 int i = 0;
 int k;
 float median;
 int temp;
 vector<int> sort_arr;
 
 for (int element:arr){
 
 sort_arr.insert(sort_arr.begin() + i, element);
 sort(sort_arr.begin(), sort_arr.end());
 
 if((i+1) % 2 == 1){
 k = (i+1)/2;
 median = sort_arr.at(k);
 }else{
 k = (i+1)/2;
 median =(sort_arr.at(k-1) + sort_arr.at(k))/2;
 }
 i++;
 }
 for(int k :sort_arr){
 cout << k << " ";
 }
 cout << endl;
 cout << median;
 return 0;
}
