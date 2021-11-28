#include "std_lib_facilities.h"
using namespace std;


struct Point{
    int x;
    int y;
};

istream& operator>>(istream& istr, Point& p){

    char ch1;
    if (istr >> ch1 && ch1 != '('){
        istr.unget();
        istr.clear(ios_base::failbit);
    return istr;
    }
    char ch2;
    char ch3;
    int xx;
    int yy;
    istr >> xx >> ch2 >> yy >> ch3;
    if (!istr || ch3 != ')'){
        if (istr.eof()) return istr;
        error("wrong point");
    }
    p.x = xx;
    p.y = yy;
    return istr;
}

ostream& operator<< (ostream& ostr, Point& p)
{
    return ostr << '(' << p.x << ',' << p.y << ')';
}

void read_from_file(vector<Point>& points, string& name)
{
    ifstream ist {name};
    ist.exceptions(ist.exceptions()|ios_base::badbit);
    if (!ist) error("A bemeneti fájlt nem lehet megnyitni.", name);
    for (Point p; ist >> p;)
        points.push_back(p);
}
int main(){
try
{
     cout << "Please give seven (x,y) pairs!\n";
     vector<Point> original_points;

     while (original_points.size()<7){
         Point p;
         cin >> p;
         original_points.push_back(p);
     }
    for (Point p : original_points)
        cout << p;
        cout << '\n';
    
    string file_name = "mydata.txt";
    ofstream ostr { file_name};
    if (!ostr) error (file_name, "Can't open the file.");

    for (Point p: original_points)
        ostr << p;
    ostr.close();

    vector<Point> processed_points;
    read_from_file(processed_points, file_name);

    for (Point p: processed_points)
        cout << p;
        cout << '\n';

    if (original_points.size() != processed_points.size())
        cout << "Something's wrong.\n";
}
catch (exception& e){
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...){
    cerr << "Something's wrong.\n";
    return 2;
}
}