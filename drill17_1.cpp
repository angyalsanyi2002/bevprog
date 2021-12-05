#include "std_lib_facilities.h"
using namespace std;

void print_array10(ostream& os, int* a){    //4. Write a function print_array10(ostream& os, int* a) that prints out the 
    for (int i = 0; i<10; i++){             // values of a (assumed to have ten elements) to os.
        cout << a[i] << " ";
        if(i>8){
        cout <<'\n';}
    }
}
void print_array_n(ostream& os, int* a, int n){    // 7. Write a function print_array(ostream& os, int* a, int n) that prints out the 
    for (int i = 0; i<n; i++){                     // values of a (assumed to have n elements) to os.   
        cout << a[i] << " ";
        if(i>n-1){
        cout <<'\n';}
    }
}
void print_vector(ostream& os, vector <int> v){
    for (int i = 0; i < v.size(); i++){
        if (i != v.size()-1)
            cout << v[i] << " ";
        else (cout << '\n');
    }
}

int main(){

int* tomb = new int[10];            //1. Allocate an array of ten ints on the free store using new.
for (int i = 0; i<10; i++){         //2. Print the values of the ten ints to cout.
    cout << tomb[i] << " ";
    if(i>8){
        cout <<'\n';
    }
}
delete [] tomb;             //3. Deallocate the array (using delete[]).

int* a = new int[10] {100,101,102,103,104,105,106,107,108,109};      //5. Allocate an array of ten ints on the free store; initialize it with the values
print_array10(cout, a);                                              //100, 101, 102, etc.; and print out its values.
delete [] a;

int* b = new int[11] {100,101,102,103,104,105,106,107,108,109,110};  //6. Allocate an array of 11 ints on the free store; initialize it with the values 
for (int i = 0; i<11; i++)                                           //100, 101, 102, etc.; and print out its values.
    {
    cout << b[i] << " ";
    if(i>9){
        cout <<'\n';
        }
    }
delete [] b;

int* c = new int[20] {101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,115,116,116,117,118};   //8. Allocate an array of 20 ints on the free store; initialize it with
print_array_n(cout, c, 20);                                                                                 // the values 100, 101, 102, etc.; and print out its values.                                                               
delete [] c;                                                  

vector <int> v1 {100,101,102,103,104,105,106,107,108,109};    //10. Do 5, 6, and 8 using a vector instead of an array
print_vector(cout, v1);
vector <int> v2 {100,101,102,103,104,105,106,107,108,109,110};
print_vector(cout, v2);
vector <int> v3 {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
print_vector(cout, v3);
}