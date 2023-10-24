#include <iostream>



bool foo(int i){
    return (i || ~(i));
}


int main(){
    int i;

    std::cout<<foo(i);
}