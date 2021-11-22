#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;
////////////////FUNCION HASH//////////////////
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
    ///////////////////INSERT///////////////////////
    bool Insert(K key, O pos)
    {
        int i = funcionhash(key, size);
        cout << "Se inserto elemento en la posición:" << i << endl;
        m_list[i].push_back(pos);
        return true;
    }
    ///////////////////BUSCAR///////////////////////
    void buscar(K key)
    {
        int i = funcionhash(key, size);
        for (auto it = m_list[i].begin(); it != m_list[i].end(); it++)
        {
            cout << *it << "->";
        }
    }
    ///////////////////PRINT///////////////////////
    void print()
    {
        bool band;
        for (int i = 0; i < size; i++)
        {
            band = false;
            // cout<<"["<<i<<"]: ";
            for (auto it = m_list[i].begin(); it != m_list[i].end(); it++)
            {
                cout << "[" << i << "]: ";
                if (*it != -1)
                {
                    cout << (*it) << "->";
                    band = true;
                }
                cout << endl;
            }
            if (band)
                cout << endl;
        }
    }
    ///////////////////ELIMINAR///////////////////////

    void Delete(K key, O pos)
    {
        int i = funcionhash(key, size);
        bool band = false;
        for (auto it = m_list[i].begin(); it != m_list[i].end(); it++)
        {
            if (*it == pos)
            {
                it = m_list[i].erase(it);
                band = true;
                cout << endl
                     << key << " Fue eliminado de posicion " << pos << endl;
            }
        }

        if (band == false)
        {
            cout << "valor no encontrado";
        }
    }
};

///////////////////LECTURA DE ARCHIVO FASTA///////////////////////
void leerArchivo(Hash<int, string> &table)
{
    string cadena;
    ifstream datos("sequence.fasta"); // sequence.fasta cadena.txt
    if (datos.fail())
    {
        cout << "Texto entrada no existe" << endl;
    }
    else
    {
        string cad3;
        int posi = 1;
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
    }
}

int main()
{
    Hash<int, string> table;
    cout << "-----------" << endl;
    int x;
    int a, b;
    string gen;
    do
    {
        cout << endl;
        cout << "\nMENU\n";
        cout << "1) Leer archivo e insertar datos\n";
        cout << "2) Imprimir \n";
        cout << "3) Buscar\n";
        cout << "4) Eliminar registro\n";
        cout << "5) SALIR\n";
        cout << "\nIngrese la opcion: ";
        cin >> a;
        switch (a)
        {
        case 1:
            leerArchivo(table);
            break;

        case 2:
            cout << "\nImprimiendo Tabla Hash" << endl;
            table.print();
            break;

        case 3:

            cout << "\n- Ingrese la cadena de genomas a buscar: ";
            cin >> gen;
            table.buscar(gen);
            break;

        case 4:
            table.Delete("ATTAAAGG", 1);
            break;

        case 5:
            cout << endl;
            cout << "\n- Seguro que quiere salir?(SI=1)(NO=0) :";
            cin >> b;
            cout << endl;
            if (b == 1)
                a = 0;
            else if (b == 0)
                break;
        }
    } while (a != 0);

    return 0;
}
