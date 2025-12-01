#include <iostream>

int main() {
    for (int i = 0; i <= 10; i++)
    {
        index_out_of_bounds(i);
    }  
}


// If x is greater than 9 this will segfault
void index_out_of_bounds(int x) {
    int buffer[10];
    buffer[x] = 1;
    std::cout << buffer[x] << std::endl;
}
