#include "std_lib_facilities.h"
using namespace std;


int main(){

int birth_year = 2002;
int age = 19;
int a;
int b;
int c;
int d;
double num = 1234567.89;

cout << "decimal: " << birth_year << '\t'<< oct << "octal: " << birth_year << '\t' << hex << "hexadecimal: " << birth_year << '\n';
cout << dec << "decimal: " << age << '\t'<< oct << "octal: " << age << '\t' << hex << "hexadecimal: " << age << '\n';                  //Az 'age' átváltásnál külön meg kell adni h decimális legyen, különben marad hex-ben.


cin >> a >>oct >> b >> hex >> c >> d;                       //'a' változót decimal-ból hexadecimalba váltja, 'b'-t octal-ból hexa-ba, 'c'-t és 'd'-t hexa-ból hexa-ba.
cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;

cout << dec << defaultfloat << num << '\t'<< fixed << num << '\t'<< scientific << num << '\n';


cout << setw(10) << "Nagy" << " | " << "István" << " | " << setw(16) << "+36701234555" << " | " << setw(29) << "nagyistvan12@gmail.com\n"
     << setw(10) << "Lesi" << " | " << setw(8) << "László" << " | " << setw(16) << "+36701234544" << " | " << setw(30) << "lesi.lacika@gmail.com\n"
     << setw(10) << "Kiss" << " | " << setw(7) << "Ignác" << " | " << setw(16) <<"+36701234533" << " | " << setw(30) << "ignac1999@gmail.com\n"
     << setw(10) << "Veres" << " | " << setw(7) << "Péter" << " | " << setw(16) << "+36701234522" << " | " << setw(30) << "veresp@gmail.com\n"
     << setw(11) << "Kovács" << " | " << setw(7) << "Emír" << " | " << setw(16) << "+36701234511" << " | " << setw(30) << "kovemi34@bluewin.ch\n"
     << setw(11) << "Tóth" << " | " << setw(7) << "Réka" << " | " << setw(16) << "+36701234500" << " | " << setw(30) << "toth.rekaa12@gmail.com\n";

return 0;
}
