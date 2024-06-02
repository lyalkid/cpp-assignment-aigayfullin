#include <string>
#include <iostream>
#include <vector>
#include <limits.h>

void solution(std::vector<std::string> strings);
std::vector<std::string> buble_sort(std::vector<std::string> strings);


int main(){

    std::vector<std::string> stringVector;
    for (int i = 0; i < 20; ++i) {
        stringVector.push_back("String " + std::to_string(i));
    }

    solution(stringVector);
}

void solution(std::vector<std::string> strings){
    
    std::vector<std::string> sorted_vector = buble_sort(strings);

    size_t size = sorted_vector.size();
    int max_len = sorted_vector[size-1].size();

    for(size_t i = 0; i < size; i++){
        if(max_len == sorted_vector[i].size()){
            std::cout<<sorted_vector[i]<< std::endl;
        }
    }
}



std::vector<std::string> buble_sort(std::vector<std::string> strings){
    size_t size = (strings).size();

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(strings[i].size() > strings[j].size()){
                std::string tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
    }

    return strings;
}
