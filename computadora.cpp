#include "computadora.h"

using namespace std;

Computadora::Computadora() { }
Computadora::Computadora(const string& os, 
              const int RAM,
              const string& m, 
              const float cst)
{
  sistemaOperativo = os;
  memoriaRAM = RAM;
  marca = m;
  costo = cst;
}

void Computadora::setSistemaOperativo(const string& os)
{
  sistemaOperativo = os;
}

void Computadora::setMemoriaRAM(const int RAM)
{
  memoriaRAM = RAM;
}

void Computadora::setMarca(const string& m)
{
  marca = m;
}

void Computadora::setCosto(const float cst)
{
  costo = cst;
}

std::string Computadora::getSistemaOperativo()
{
  return sistemaOperativo;
}

int Computadora::getMemoriaRAM()
{
  return memoriaRAM;
}

std::string Computadora::getMarca()
{
  return marca;
}

float Computadora::getCosto()
{
  return costo;
}