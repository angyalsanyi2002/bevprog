#include "std_lib_facilities.h"
using namespace std;

void print_array_n(ostream& os, int* a, int n){
    for (int i = 0; i<n; i++){
        cout << a[i] << " ";
    }
}
int main(){

int p = 7;                                                //1. Allocate an int, initialize it to 7, and assign its address to a variable p1.
int* p1 = &p;                                             //2. Print out the value of p1 and of the int it points to.
cout << "pointer " << p1 << " points to " << *p1 << '\n';

int* p2 = new int[7];

    p = 1;
    for (int i = 0; i < 7; ++i) {
        p2[i] = p;
        p *= 2;
    }

    cout << "address " << p2 << '\n';

    for (int j = 0; j < 7; ++j)
        cout << p2[j] << ' ';

    cout << '\n';

int* p3 = p2;                        //5. Declare an int* called p3 and initialize it with p2.
p2 = p1;                             // 6. Assign p1 to p2.
p2 = p3;                             // 7. Assign p3 to p2.

cout << "pointer " << p1 << " points to " << *p1 << '\n';    //8. Print out the values of p1 and p2 and of what they point to.
cout << "pointer " << p2 << " points to " << *p2 << '\n';
delete [] p2;                                        // 9. Deallocate all the memory you allocated from the free store.

p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};   //10. Allocate an array of ten ints; initialize it to 1-512; address --> var p1.
p2 = new int[10];                       // 11. Allocate an array of ten ints, and assign its address to a variable p2.

for (int y = 0; y < 10; y++)         //12. Copy the values from the array pointed to by p1 
        p2[y] = p1[y];                //into the array pointed to by p2.
    for (int z = 0; z < 10; z++)
        cout << p2[z] << " ";
    cout << '\n';

//VECTORS
vector<int> v1 {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> v2 (10);
    v2 = v1;
    for (int v : v2) cout << v << ' ';
    cout << '\n';
}