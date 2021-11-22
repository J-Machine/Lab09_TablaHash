#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

/* Read. Lee el archivo sequence.fasta y devuelve un string*/
string read ()
{
    ifstream file;
    string content="";
    file.open("sequence.txt", ios::in);
    if(file.fail())
    {
        cout<<"Fail open file\n";
    }
    else 
    {
        while(!file.eof())
            getline(file, content, '*');
    }
    return content;
}
void insert();
size_t find();
void remove();

size_t funcion_hash();


int main()
{
    string test = read();
    cout << test<<endl;
    // read();
    return 0;
}