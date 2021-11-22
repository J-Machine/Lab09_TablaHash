#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

int funcionhash(string key, int n)
{
    int clave = 0;
    char *caracteres = (char *)key.c_str();
    while (*caracteres)
    {
        clave += int(*caracteres);
        caracteres++;
    }
    return clave % n;
}

template <class O, class K, const int size = 71>

class Hash
{
private:
    list<O> m_list[size];

public:
    Hash(){};
    bool Insert(K key, O pos) 
    {
        int i = funcionhash(key, size);
        cout << "Se inserto elemento en el indice: " << i << endl;
        m_list[i].push_back(pos);
        return true;
    }

    void Delete(int index, int value )
    {
            auto it = m_list[index].begin();
            bool no_found = true;
            
            for (; it != m_list[index].end(); it++)
            {
                if ((*it) == value)
                {
                    cout << "Eliminado -> "<< (*it);
                    it = m_list[index].erase(it);
                    no_found = false;
                }
            }               
            if(no_found)
                cout << "Valor no encontrado \n";
    }

    void print()
    {
        bool band;
        for (int i = 0; i < size; i++)
        {
            band = false;
            for (auto it = m_list[i].begin(); it != m_list[i].end(); it++)
            {
                cout << "[" << i << "]: ";
                if (*it != -1)
                {
                    cout << (*it) << "->";
                    band = true;
                }
                cout << endl; //#
            }
            if (band)
                cout << endl;
        }
    }
};



void leerArchivo(Hash<int, string> table)
{
    string cadena;
    ifstream datos("sequence.txt"); // sequence.fasta #
    if (datos.fail())
    {
        cout << "Texto entrada no existe" << endl;
    }
    else
    {
        string cad3;
        int posi = 0;
        while (!datos.eof())
        {
            getline(datos, cadena);
            for (int i = 0; i < cadena.length(); i = i + 7)
            {
                cad3 = cadena.substr(i, 7);
                cout << cad3 << " -> ";
                table.Insert(cad3, posi);
                posi = posi + 1;
            }
        }
        table.print();
        table.Delete(70, 4182);
        // table.print();

    }
}

int main()
{
    // std::cout << "Hello, World!";
    Hash<int, string> table;
    leerArchivo(table);

    cout << "\nDelete\n";
    return 0;
}
