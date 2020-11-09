#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <iostream>
#include <stdlib.h> 
#include <vector>
#include "computadora.h"

class Laboratorio
{
private:
  vector<Computadora> arreglo;
public:
  Laboratorio();
  void agregarComputadora(const Computadora &c);
  void mostrar();
  void respaldar_tabla();
  void respaldar();
  void recuperar();

  void insertar(const Computadora &c, size_t pos);
  size_t size();
  void inicializar(const Computadora &c, size_t n);
  void eliminar(size_t pos);
  void ordenar();
  Computadora* buscar(const Computadora &c);

  friend Laboratorio& operator<<(Laboratorio& lab, const Computadora& c)
  {
    lab.agregarComputadora(c);

    return lab;
  }
};

#endif