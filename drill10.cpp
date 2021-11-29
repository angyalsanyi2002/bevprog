#include "std_lib_facilities.h"
struct Point{
    double x;
    double y;
};
void compare(vector<Point> original_points, vector<Point> processed_points)
{
    if (original_points.size() != processed_points.size())
    {
        cout << "Something's wrong!";
    }
    for (int i = 0; i < original_points.size(); i++){
        if (original_points[i].x != processed_points[i].x){         //orig. és proc. i-edik elemeinek x értékeit hasonlítja össze
            cout << "Something's wrong!\n";

        }
        if (original_points[i].y != processed_points[i].y){         //orig. és proc. i-edik elemeinek y értékeit hasonlítja össze
            cout << "Something's wrong!\n";
        }
    }
};
int main ()
{
   double x;
   double y;
   vector<Point> original_points; 

    int value = 0;
    cout << "Enter values like this: x y";
    while(value != 7){
       cin >> x >> y;
       original_points.push_back(Point{x,y});                   //original_point-ba rakja bele a pontokat
       value++;
    }

    string ofname = "mydata.txt";
    ofstream ost {ofname};
   // if(!ost) error("Can't open ofile,", ofname);
    for(int i = 0; i<original_points.size(); i++)
	{
		ost<<original_points[i].x<<" "<<original_points[i].y<<endl;          //fájlba kiírja a pontokat, fontos, hogy ne legyen benne zárójel
	}

    ost.close(); 

    // processed_points létrehozása fájlból

    vector<Point> processed_points; 
    string ifname = "mydata.txt";
	ifstream ist {ifname};
	// if (!ist) error("Can't open input file ", ifname);
    while(ist >> x >> y){
    processed_points.push_back(Point{x,y});     //processed_point-ba rakja bele a pontokat
    }
    ist.close(); 
    cout << "original_points: \n";
     for(int i = 0; i<original_points.size(); i++)
	{
		cout<<'('<<original_points[i].x<<", "<<original_points[i].y<<')'<<endl;
	}

    cout << "processed_points: \n";
    for(int i = 0; i<processed_points.size(); i++)
	{
		cout<<'('<<processed_points[i].x<<", "<<processed_points[i].y<<')'<<endl;
	}

    compare(original_points, processed_points);             //összehasonlítja a két vectort
    return 0;
}
