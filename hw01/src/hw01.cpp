#include <hw01.h>

bool is_prime(int n){
    int bort = n/2;
    for(int i = 2; i < bort + 1; i++){
        if (n % i == 0)
        return false;
    }
    return true;
}

int hw01(int start, int end)
{
    bool statement = (start > 9) && (start < 100) && (end > 9) && (end < 100);
    
    if (!statement){
        return -1;
    }

    int sum = 0;

    for(int i = start; i < end + 1; i++){
        if(is_prime(i)){
            sum += i;
        }
    }   

    return sum;
}



