#include <iostream>
using namespace std;

int main()
try {
    //cout << "Sikerült!\n";
    //cout << "Sikerült!\n";
    //cout << "Sikerült!" << "!\n";
    //cout << "Sikerült!" << '\n';
    //int res = 7; vector<int> v(10); v[5] = res; cout << "Sikerült!\n";
    //vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Sikerült!\n";
    //if (true) cout << "Sikerült!\n"; else cout << "Sikertelen!\n";
    //bool c = false; if (!c) cout << "Sikerült!\n"; else cout << "Sikertelen!\n";
    //string s = "ape"; bool c = "fool" > s; if (c) cout << "Sikerült!\n";
    //string s = "ape"; if (s != "fool") cout << "Sikerült!\n";
    //string s = "ape"; if (s != "fool") cout << "Sikerült!\n";
    //string s = "ape"; if ("fool") cout << "Sikerült!\n";
    //vector<char> v(1); for (int i=0; i<v.size(); ++i) cout << "Sikerült!\n";
    //vector<char> v(5); for (int i=4; i<v.size(); ++i) cout << "Sikerült!\n";
    //string s = "Sikerült!\n"; for (int i=0; i<10; ++i) cout << s[i];
    //if (true) cout << "Sikerült!\n"; else cout << "Sikertelen!\n";
    //int x = 2000; int c = x; if (c==2000) cout << "Sikerült!\n";
    //string s = "Sikerült!\n"; for (int i=0; i<10; ++i) cout << s[i];
    //vector<int> v(0); for (int i=0; i<=v.size(); ++i) cout << "Sikerült!\n";
    //int i=0; int j=9; while (i<10) ++i; if (j<i) cout << "Sikerült!\n";
    //int x = 2; double d = 5/(x/2); if (d==2*(x+0.5)) cout << "Sikerült!\n";
    //string s = "Sikerült!\n"; for (int i=0; i<10; ++i) cout << s[i];
    //int i = 0; while (i<10) ++i; if (i) cout << "Sikerült!\n";
    //int x = 4; double d = 5.0/(x-2); if (d==2+0.5) cout << "Sikerült!\n";
    cout << "Sikerült!\n";

    return 0;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Jajj: ismeretlen kivétel!\n";
    return 2;
}
