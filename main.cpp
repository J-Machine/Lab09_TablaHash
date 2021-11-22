#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

/* Read. Lee el archivo pasado como parametro string y devuelve un string*/
string read (string name_file)
{
    ifstream file;
    string content="";
    file.open(name_file, ios::in);
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

/* Hash: Funcion que dado un string devuelve una clave hash.h
        Utiliza el método de Horne.
*/
size_t funcion_hash(string key, size_t M )  // M es el tam del diccionario
{
    size_t hash = 0;
    size_t primo = 127;
    for(size_t i = 0; i < key.size(); i++)
        hash = (hash*primo  + (size_t)(key[i])) % M;
    return hash;
}



/* Genome */
struct Genome
{
    size_t genome_position;  // valor
    size_t  key;            // llave hash
};

/* Tabla Hash */
struct HashTable
{
    size_t M;       // tamaño de la tabla
    size_t nKeys;   // Nro de llaves insertadas
    Genome *tab = nullptr;
};

void insert();
size_t find();
void remove();


int main()
{
    HashTable table;
    string test = read("sequence.txt");
    cout << test<<endl;
    // read();
    return 0;
}