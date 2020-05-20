#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

class name
{
ifstream plik1;
ofstream plik2;


  public:
name();
~name();

void sprawdz();

};

name::name()
{
    plik1.open("plik1.txt");
    plik2.open("plik2.json");
}

	void name::sprawdz()
{
    bool x = true;


    regex reg("[A-Z][a-z]+-[A-Z][a-z]+");

    string w;

		plik2<<"["<<endl;

		while(!plik1.eof())
     {
        plik1>>w;
        if(regex_match(w, reg))
    {
        cout<<w<<endl;
if(x)
{
plik2<<"{\"nazwisko_podwojne\":\""<<w<<"}";
x = false;
}
else
{
    plik2<<","<<endl;

    plik2<<"{\"nazwisko_podwojne\":\""<<w<<"}";
}

}
}
    plik2<<endl<<"]";
}

  name::~name()
{
plik1.close();
plik2.close();
}


int main(int argc, char** argv)
{

name t1;
t1.sprawdz();
	  return 0;
}
