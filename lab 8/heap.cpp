#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int max = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;
  //int temp;

  if(left <= n && arr[left] > arr[root]){
      max = left;
  }
  if(right <= n && arr[right] > arr[root]){
      max = right;
  }

  if(max != root){
      swap(arr[root], arr[max]);
      heapify(arr, n, max);
  }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--){
      heapify(arr, n, i);
   }
        
  
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=n-1; i>-1; --i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int x;
   vector <int> heap_vec;
   while (true)
   {
      cout << "enter number: ";
      cin >> x;
      if(x < 0){
         break;
      }
      heap_vec.push_back(x);
   }
   int l = heap_vec.size();
   int heap_arr[l];
  for (int i = 0; i < l; i++) {
        heap_arr[i] = heap_vec[i];
    }
   //int [] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

}