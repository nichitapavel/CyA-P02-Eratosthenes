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
 * @brief  Class defining a tuple of a integer number and it's primeness status,
 *         basically if it's prime or not.
 */

#ifndef SRC_NUMBERS_H_
#define SRC_NUMBERS_H_

#include <vector>
#include "NumberAndStatus.h"

class Numbers {
 private:
  std::vector<NumberAndStatus> numbers;
  int length;
  int currentPrimePosition;

 public:
  explicit Numbers(int length);
  ~Numbers();
  int getNextPrime();
  bool sieve(int number_to_sieve);
  int getPositionOfNumber(int number);
  void remove();
  int last_number();
  // std::ostream & operator<< (std::ostream &out, Token const &t)
  friend std::ostream& operator << (std::ostream &co, const Numbers &numbers);
};

#endif  // SRC_NUMBERS_H_
