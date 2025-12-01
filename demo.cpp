#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;

void index_out_of_bounds(int x);
vector<int>* bad_lifetime();

int main() {
    char *str;

    for (int i = 0; i <= 1; i++)
    {
        index_out_of_bounds(i);
    }  

    vector<int>* vec = bad_lifetime();
    vector<int> deref_vec = *vec;
    cout << deref_vec[0] << endl;
}


///////////////////////////
//  Index out of Bounds  //
///////////////////////////

// If x is greater than 9 this will segfault
void index_out_of_bounds(int x) {
    int buffer[10];
    buffer[x] = 1;
}


////////////////////////////////////
//  Returning ptrs to local vars  //
////////////////////////////////////

// This function produces a compiler warning
vector<int>* bad_lifetime_warning() {
    vector<int> v = {1,2,3,4,5};
    return &v;
}

// This function does not produce a compiler warning
vector<int>* bad_lifetime() {
    vector<int> v = {1,2,3,4,5};
    vector<int>* v_ptr = &v;
    return v_ptr;
}
