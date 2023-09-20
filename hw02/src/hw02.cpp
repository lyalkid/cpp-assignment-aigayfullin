#include <hw02.h>
//#include <iostream>


int poisk(std::string str, char target){
    int counter = 0;
    for(int i = 0; i < str.size(); i++){
        if (str[i] == target ){
            counter++;
        }
        if(counter == 2){
            return i;
        }
    }
    return -1;
} 



std::string hw02(std::string input_str)
{

    for(int i = 0; i < input_str.size(); i++){
        char target = input_str[i];
        int check = poisk(input_str, target);
        if(check != -1){
            for(int j = check; j < input_str.size()-1; j++){
                char tmp = input_str[j];
                input_str[j] = input_str[j+1];
                input_str[j+1] = tmp;
            }
            int last_index = input_str.size() - 1; 
            input_str.erase(last_index);
        }
    }
     return input_str;
}



