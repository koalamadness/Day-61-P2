#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Computadora
{
private:
  std::string sistemaOperativo;
  int memoriaRAM;
  std::string marca;
  float costo;
public:
  Computadora();
  Computadora(const std::string& os, 
              const int RAM,
              const std::string& m, 
              const float cst);

  void setSistemaOperativo(const std::string& os);
  std::string getSistemaOperativo();

  void setMemoriaRAM(const int RAM);
  int getMemoriaRAM();

  void setMarca(const std::string& m);
  std::string getMarca();

  void setCosto(const float cst);
  float getCosto();

  friend ostream& operator<<(ostream& out, const Computadora& c)
  {
    out << left;
    out << setw(20) << c.sistemaOperativo;
    out << setw(15) << c.memoriaRAM;
    out << setw(15) << c.marca;
    out << setw(15) << c.costo;
    out << endl;
    return out;
  }
  
  friend istream& operator>>(istream& i, Computadora& c)
  {
    cout << "Sistema Operativo: ";
    getline(cin, c.sistemaOperativo);

    cout << "Memoria RAM: ";
    cin >> c.memoriaRAM;

    cout << "Marca: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n' );
    
    getline(cin, c.marca);

    cout << "Costo: ";
    cin >> c.costo;

    return i;
  }

  bool operator==(const Computadora& c)
  {
    return marca == c.marca;
  }

  
  bool operator==(const Computadora& c) const
  {
    return marca == c.marca;
  }

  bool operator<(const Computadora& c)
  {
    return marca < c.marca;
  }
  
  bool operator<(const Computadora& c) const
  {
    return marca < c.marca;
  }  
  
};

#endif