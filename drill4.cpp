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

	string unit="";
	double a, sum=0, max = 2147483647, min = 0;
	vector<double> numbers;

	map<string, double> converter = {
		{"cm",1.0/100},
		{"m",1},
		{"in",2.54/100},
		{"ft",2.54*12/100}
	};


	while(cin >> a >> unit){

		double converted = converter[unit]*a;
		numbers.push_back(converted);

		sum += converted;
		cout << "The value entered: " << a << endl;
		if(a < min){
			cout << "the smallest so far " << endl;
			min = a;
		}
		if(a > max){
			cout << "the largest so far" << endl;
			max = a;
		}
	}

	cout << "Min of numbers: " << min << endl
		 << "Max of numbers: " << max << endl
		 << "Sum of the numbers (m): " << sum << endl << endl;

	cout << "Numbers: " << endl;
	sort(numbers.begin(),numbers.end());
	for(auto num : numbers){
		cout << num << " ";    
	}
    cout << endl;
    return 0;
}