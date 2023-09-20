
#include <hw02.h>
//#include <iostream>


bool poisk(std::string str, char target){
    for(int i = 0; i < str.size(); i++){
        if(str[i] == target){
            return true;
        }
    }
    return false;
} 

std::string hw02(std::string input_str)
{
    std::string str = "";
    for(int i = 0; i < input_str.size(); i++){
        bool check = poisk(str, input_str[i]);
        if(!check){
            str += input_str[i];
        }
    }
    return str;
}



// int main(){
//     std::string j = hw02("hello");
//     std::cout << j << std::endl;
// }