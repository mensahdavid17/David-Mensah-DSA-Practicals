#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 12



int size = 0;
int studentID [12]; //an array to contain the student ID's of twelve students


bool Isempty(){
    if (Listsize() == 0){
        return true;
    }
    else{
        return false;
    }
}

int Listsize(){

    for (int i = 0; i < SIZE ; i++){
        if(studentID[i] != NULL){
            size++;

        }
    }
    return size;
}

int get(int index){
    if (studentID[index] = NULL){
        return studentID[index];
    }
    else{
         printf("Wrong index");
    }
}

int indexOf(int ID) {
    for (int i = 0; i < Listsize()-1 ; i++){
        if (studentID[i] == ID){
            return i;
            break;
        }
    }
}

void delete(int index){
    if (index == Listsize()-1){
        studentID[index] = NULL;
        size--;
    }
    else{
        for(int i = index; i < Listsize()-1 ; i++){
            studentID[i] = studentID[i+1];
            size--;
        }
    }
}

void insert(int index, int x){
    if (index == size){
        studentID[index] = x;
        size++;
    }
    else{
        for (int i = size-1 ; i < index ; i++){
            studentID[i+1] = studentID[1];
            studentID[index] = x;
            size++;
        }

    }

}

int output(){
    for (int i = 0; i < size-1 ; i++){
        return studentID[i];
    }
}





int main(){


    return 0;
}