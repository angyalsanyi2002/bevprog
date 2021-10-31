#include "std_lib_facilities.h"

struct Token            //konstruktorok
{
    char kind;
	double value;
	string name;

	Token(char ch) : kind(ch), value(0) { }
	Token(char ch, double val) : kind(ch), value(val) { }
	Token(char ch, string s) : kind(ch), name(s) {}         //construktor hiányzik
};


class Token_stream {
	bool full;
	Token buffer;
public:
                                    // konstruktor
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};
     
     
                                //változók
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squart = 's';
const char powch = 'p';

const string quitKey = "exit";
const string sqrtKey = "sqrt";
const string letKey = "let";
const string powKey = "pow";


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch)
	{
	case '(': case ')':
	case '+': case '-':
	case '*': case '/':
	case '=': case ',':
	case let: case print: case quit:
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;

			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.unget();

			if (s == letKey)
				return Token(let);
			else if (s == quitKey)
				return Token(quit);
			else if (s == sqrtKey)
				return Token(squart);
			else if (s == powKey)
				return Token(powch);

			return Token(name, s);
		}
		error("Nem megfelelő token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;


double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error(s, " nics definiálva. Foytatás: ';'");
}


void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
		{
			names[i].value = d;
			return;
		}
	error(s, " nincs definiálva. Folytatás: ';'");
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

double define_name(string var, double val)
{
	if (is_declared(var))
		error(var, " has already been declared");
	names.push_back(Variable{ var,val });

	return val;
}

Token_stream ts;

double expression();


                    //négyzetgyök
double squareRoot()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();

		if (d <= 0)                                             //ha 0 vagy kisebb a négyzetgyök, errort ad
			error(to_string(d), "Nem lehet gyököt vonni. Folytatás: ';'");

		t = ts.get();
		if (t.kind != ')')
			error(" Várt karakter: ')'. Folytatás: ';'");
		return sqrt(d);
	}
	default:
		error(" Várt karakter: '('. Folytatás ';'");
	}
}

double powpow()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();

		t = ts.get();
		if (t.kind != ',')
			error("Várt karakter: ','. Folytatás: ';'");

		double d2 = expression();

		t = ts.get();
		if (t.kind != ')')
			error(" Várt karakter: ')'. Folytatás: ';'");

		return pow(d, d2);
	}
	default:
		error(" Várt karakter: '('. Folytatás: ';'");
	}
}

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error(" Várt karakter: ')'");
		return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case squart:
		return squareRoot();
	case powch:
		return powpow();
	default:
		error("primary expected.");
	}
}

double term()
{
	double left = primary();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("Osztás nullával. Folytatás: ';'");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true)
	{
		Token t = ts.get();
		switch (t.kind)
		{
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration. Folytatás: ';'");

	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice. Folytatás: ';'");

	Token t2 = ts.get();
	if (t2.kind != '=')
		error(name, "= missing in declaration. Folytatás ';'");

	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	cout << prompt;

	while (true)
		try
	{
		Token t = ts.get();

		while (t.kind == print)
		{
			cout << prompt;
			t = ts.get();
		}

		if (t.kind == quit)
			return;
		ts.unget(t);

		cout << result << statement() << endl;
	}
	catch (runtime_error& e)
	{
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
try
{
	
	define_name("k", 1000);

	cout << "//------------------------------------------------------------------------------//" << endl;
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers." << endl;
	cout << "Operators available: {}, (), +, -, /, *" << endl;
	cout << "Pre-defined names: k = 1000 || sqrt() || pow(,)" << endl;
	cout << "Define your own names using " << letKey << " name = number;" << endl;
	cout << "use ';' to print and 'Q' or 'exit' to quit" << endl;
	cout << "//------------------------------------------------------------------------------//" << endl;

	calculate();
	return 0;
}
catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...)
{
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}