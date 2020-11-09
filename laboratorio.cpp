#include "laboratorio.h"
#include <fstream>
#include <algorithm>

using namespace std;

Laboratorio::Laboratorio()
{
  
}

void Laboratorio::agregarComputadora(const Computadora& co)
{
  arreglo.push_back(co);
}

void Laboratorio::mostrar()
{
  cout << left;
  cout << setw(20) << "Sistema Operativo";
  cout << setw(15) << "Memoria RAM";
  cout << setw(15) << "Marca";
  cout << setw(15) << "Costo";
  cout << endl;

  for (size_t i = 0; i < arreglo.size(); i++)
  { 
    Computadora &co = arreglo[i];
    cout << co;
    /*
    cout << "Sistema Operativo: " << co.getSistemaOperativo() << endl;
    cout << "Memoria RAM: " << co.getMemoriaRAM() << "GB" <<endl;
    cout << "Marca: " << co.getMarca()<< endl;
    cout << "Costo: " << '$' << co.getCosto() << endl;
    */
    cout << endl;
  }
}

void Laboratorio::respaldar_tabla()
{
  ofstream archivo("computadoras_tabla.txt");

  if(archivo.is_open())
  {
    archivo << left;
    archivo << setw(20) << "Sistema Operativo";
    archivo << setw(15) << "Memoria RAM";
    archivo << setw(15) << "Marca";
    archivo << setw(15) << "Costo";
    archivo << endl;

    for (size_t i = 0; i < arreglo.size(); i++)
    { 
      Computadora &co = arreglo[i];
      archivo << co;
    }
  }

  archivo.close();
}


void Laboratorio::respaldar()
{
  ofstream archivo("computadoras.txt");

  if(archivo.is_open())
  {

    for (size_t i = 0; i < arreglo.size(); i++)
    { 
      Computadora &co = arreglo[i];
      archivo << co.getSistemaOperativo() << endl;
      archivo << co.getMemoriaRAM() << endl;
      archivo << co.getMarca() << endl;
      archivo << co.getCosto() << endl;
    }
  }
  
  archivo.close();
}

void Laboratorio::recuperar()
{
  ifstream archivo("computadoras.txt");
  if (archivo.is_open())
  {
    string temp;
    float costo;
    int RAM;
    Computadora co;

    while(true)
    {
      getline(archivo, temp);
      if (archivo.eof()) 
      {
        break;
      }
      co.setSistemaOperativo(temp);

      getline(archivo, temp);
      RAM = stoi(temp);
      co.setMemoriaRAM(RAM);

      getline(archivo, temp);
      co.setMarca(temp);
      
      getline(archivo, temp);
      costo = stof(temp);
      co.setCosto(costo);

      agregarComputadora(co);
    }
  }
  archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos)
{
  arreglo.insert(arreglo.begin() + pos, c);
}

size_t Laboratorio::size()
{
  return arreglo.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n)
{
  arreglo = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
  arreglo.erase(arreglo.begin() + pos);
}

void Laboratorio::ordenar()
{
  sort(arreglo.begin(), arreglo.end());
}

Computadora* Laboratorio::buscar(const Computadora &c)
{
  auto it = find(arreglo.begin(), arreglo.end(), c);

  if (it == arreglo.end())
  {
    return nullptr;
  }
  else 
  {
    return &(*it);
  }
}