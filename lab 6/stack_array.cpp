// Online C++ compiler to run C++ program online
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


void push(int element);
int pop();
void display();

int top = 0;
int stack_arr[10];
    
int main() {
    auto start = high_resolution_clock::now();
     push(8);
     push(10);
     push(5);
     push(11);
     push(15);
     push(23);
     push(6);
     push(18);
     push(20);
     push(17);
     display();
     cout << pop() << endl;
     cout << pop() << endl;
     cout << pop() << endl;
     cout << pop() << endl;
     cout << pop() << endl;
     push(4);
     push(30);
     push(3);
     push(1);
     display();
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}

void push(int element){
    if(top == 10){
        cout << "Stack Overflow" << endl;
    }
    stack_arr[top] = element;
    top++;
}

int pop(){
    if(top <= 0){
        cout << "Stack Underflow" << endl;
    }
    top--;
    return stack_arr[top];
    
}

void display(){
    cout << "[";
    for(int i = 0; i < top; i++){
        cout << stack_arr[i] << ", ";
    }
    cout << "]" << endl;
}
