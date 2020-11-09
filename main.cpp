#include <iostream>
#include "laboratorio.h"

int main() {

  Laboratorio labo;
  string op;

  while (true)
  {
    cout << "1) Agregar al final" << endl;
    cout << "2) Mostrar" << endl;
    cout << "3) Respaldar" << endl;
    cout << "4) Recuperar" << endl;
    cout << "5) Insertar" << endl;        
    cout << "6) Inicializar" << endl;                
    cout << "7) Eliminar" << endl;     
    cout << "8) Ordenar" << endl;          
    cout << "9) Buscar" << endl;                    
    cout << "0) Salir " << endl;
    getline(cin, op);

    if (op == "1")
    {
      Computadora com;

      cin >> com;

      labo.agregarComputadora(com);
      cin.ignore();
    }

    else if (op == "2")
    {
      labo.mostrar();
    }

    else if (op == "3")
    {
      labo.respaldar();
    }

    else if (op == "4")
    {
      labo.recuperar();
    }  

    else if (op == "5")
    {
      Computadora com;
      size_t pos;

      cin >> com;

      cout << "Posición: ";
      cin >> pos; cin.ignore();

      if(pos >= labo.size())
      {
        cout << "Posición invalida" << endl;
      }
      else 
      {
        labo.insertar(com, pos);
      }
    } 

    else if (op == "6")
    {
      Computadora com;
      size_t n;

      cin >> com;

      cout << "Tam: ";
      cin >> n; cin.ignore();

      labo.inicializar(com, n);
    }  

    else if (op == "7")
    {
      size_t pos;

      cout << "Posición: ";
      cin >> pos; cin.ignore();

      if(pos >= labo.size())
      {
        cout << "Posición invalida" << endl;
      }
      else 
      {
        labo.eliminar(pos);
      }
    }

    else if (op == "8")
    {
      labo.ordenar();
    }  

    else if (op == "9")
    {
      Computadora com;
      cin >> com; cin.ignore();

      Computadora *ptr = labo.buscar(com);

      if (ptr == nullptr)
      {
        cout << "No encontrado" << endl;
      }
      else
      {
        cout << *ptr << endl;
      }
    }      

    else if (op == "0")
    {
      break;
    }  
  }
}