#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;
#include <cassert>
#include <stdlib.h>

void index_out_of_bounds(int x);
vector<int>* bad_lifetime();
bool side_effect(int* val);

int main() {
    char *str;

    for (int i = 0; i <= 1; i++)
    {
        index_out_of_bounds(i);
    }  

    // This will throw an unhandled exception
    try {
        vector<int>* vec = bad_lifetime();
        vector<int> deref_vec = *vec;
        cout << deref_vec[0] << endl;
    } catch (...) {
        cout << "Caught Exception" << endl;
    }
    
    // This will behave differently between debug and release builds
    int val = 0;
    cout << "Before Assert: " << val << endl;
    assert(side_effect(&val));
    cout << "After Assert: " << val << endl;

    // Allocate negative space?
    malloc(-1);
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


///////////////////////////////
//  Assert with Side Effect  //
///////////////////////////////

bool side_effect(int* val) {
    *val = 1;
    return true;
}
