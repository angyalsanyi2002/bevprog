#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
/*
    double elso =0.0, masodik=0.0;
    cout << "Adjon meg két számot. " <<endl;
    cin >> elso >> masodik;

    double kisebb =0.0, nagyobb=0.0;
    if (elso>masodik)
    {
        nagyobb=elso;
        kisebb=masodik;

        cout << "A nagyobb érték: " << nagyobb << endl;
        cout << "A kisebb érték: " << kisebb << endl;
    }
    else if (masodik>elso)
    {
        nagyobb=masodik,
        kisebb=elso;

        cout << "A nagyobb érték: " << nagyobb << endl;
        cout << "A kisebb érték: " << kisebb << endl;
    }
    else
    {
        cout << "A két szám egyenlő. \n";
    }
    double kulonbozet=1.0/100.0;
    if ((nagyobb-kisebb)<=0.010000000000000009)
    {
        cout << "A két szám majdnem egyenlő. \n";
    }
*/

//6-11. feladatig
cout << "Adj meg egy számot mértékegységgel." << endl;

	string mertekegyseg="";
	double a, osszeg=0, min = 2147483647, max = 0;
	vector<double> szamok;

	map<string, double> convertalo = {
		{"cm",1.0/100},
		{"m",1},
		{"in",2.54/100},
		{"ft",2.54*12/100}
	};


	while(cin >> a >> mertekegyseg){

		double convertalt = convertalo[mertekegyseg]*a;
		szamok.push_back(convertalt);

		osszeg += convertalt;
		cout << "Beírt érték: " << a << endl;
		if(a < min){
			cout << "Az eddigi legkisebb " << endl;
			min = a;
		}
		if(a > max){
			cout << "Az eddigi legnagyobb " << endl;
			max = a;
		}
	}

	cout << "Legkisebb szám: " << min << endl
		 << "Legnagyobb szám: " << max << endl
		 << "Számok összege (m): " << osszeg << endl << endl;

	cout << "Számok: " << endl;
	sort(szamok.begin(),szamok.end());
	for(auto num : szamok){
		cout << num << " ";    
	}
    cout << endl;
    return 0;
}