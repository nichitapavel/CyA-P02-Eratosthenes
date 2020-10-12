/**
 * Copyright 2020 Copyright Owner Pavel Nichita
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Pavel Nichita
 * @date 12 Oct 2020
 * @brief  Class that manages a list of numbers, applying Sieve of Eratosthenes
 * to find primer numbers.
 */

#include <stdio.h>
#include <vector>
#include <iostream>
#include "NumberAndStatus.h"

#ifndef SRC_PRIMES_H_
#define SRC_PRIMES_H_

/**
 * La función `Sieve` operará sobre la lista de valores e irá marcando en ella como no primos los múltiplos de
 * 2, los de 3, los de 5, etc. 
 * 
 * Para ello localizará un valor que sea primo e invocará la función `Remove` que marcará desde ese punto de
 * la lista en adelante todos los valores múltiplos del elegido, como no primos.
 * 
 * Utilice una función adicional para eliminar de la lista todos los números que que no sean primos.
 * Desarolle también una función que permita imprimir en pantalla en cualquier momento el estado de la lista. 
 * Esta función escribirá cada uno de los valores presentes en la lista indicando si es primo o no.
 * 
 */  

class Numbers {
 private:
  std::vector<NumberAndStatus> numbers;
  int length;

 public:
  explicit Numbers(int length);
  ~Numbers();

  // std::ostream & operator<< (std::ostream &out, Token const &t)
  void print();
  void sieve(int);
  int getPositionOfFirstPrime();
};
#endif  // SRC_PRIMES_H_