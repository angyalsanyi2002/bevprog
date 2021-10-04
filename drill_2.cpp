#include "std_lib_facilities.h"
int main ()
{
cout <<"Your name: ";
string first_name;
cin >>first_name;
cout <<"Dear " << first_name << " ," << endl;
cout <<"\t How are you? " << endl;
cout <<"I'm fine " << endl;
cout <<"I miss you. " << endl;
string friend_name;
cout <<"Your friend name: " ;
cin >>friend_name;
cout <<"Have you seen " << friend_name << " lately? " << endl;
char friend_sex = 0;
cout <<"Your gender female or male (type f/m): ";
cin >>friend_sex;
if(friend_sex == 'm')
{
cout <<"If you see " << friend_name << " please ask him to call me." << endl;
}
else
{
cout <<"If you see " << friend_name << " please ask her to call me." << endl;
}
cout <<"How old are you? ";
int age;
cin >>age;
if(age<=0 || age>=110)
{
simple_error("You're kidding!");
}
else
{
cout <<"I hear you just had a birthday and you are " << age << " years old. \n";
}
if(age<12)
{
cout << "Next year you will be " << age+1 << "." << endl;
}
else if(age == 17)
{
cout <<"Next year you will be able to vote." << endl;
}
else if(age>70)
{
cout << "I hope you are enjoying retirement." << endl;
}
cout << "Your sincerely " << endl;
cout << endl;
cout << "Angyal Sándor" << endl;
return 0;
}