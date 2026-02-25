#include <iostream>
#include <string>
#define SIZE 12

using namespace std;

int studentAges[12];
int stackSize = 0;
int top = -1;

bool isEmpty(){
    if (top == -1 || stackSize == 0){
        return true;

    }
    else{
        return false;
    }
}

int size(){
    return stackSize;
}

int topElement(){
    return studentAges[top];
}

void pop(){
    if(isEmpty()){
        cout << "Stack Underflow" << endl;
    }
    else{
        studentAges[top] = 0; //value will be replaced anyway with the next call of the pop function
        top--;
        stackSize--;
    }
}

void push(int x){
    if (top == SIZE-1){
        cout << "Stack Overflow" << endl;
    }
    else{
        top++;
        studentAges[top] = x;
        stackSize++;
    }
}

int main(){
    //The stack is empty at this point so the message "Stack Underflow" should be output to the user
    pop();

    push(15);
    push(18);
    push(21);
    push(23);

    cout << "The current size of the stack is "<< size() << endl;
    cout << "The current top element in the stack is the student age " << topElement() << endl;

    pop();

    cout << "The current top element after calling the pop() function is " << topElement() << endl;
    return 0;
}


