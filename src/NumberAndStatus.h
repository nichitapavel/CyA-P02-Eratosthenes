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
 * @brief  Header for NumberAndStatus.cc file
 * 
 */

#ifndef SRC_NUMBERANDSTATUS_H_
#define SRC_NUMBERANDSTATUS_H_

#include <ostream>

class NumberAndStatus {
 private:
  int number_;
  bool primeness_;

 public:
  NumberAndStatus();
  explicit NumberAndStatus(int number);
  int getNumber(void);
  bool isPrime(void);
  void setNumber(int number);
  void setPrimeness(bool primeness);
  friend std::ostream& operator << (std::ostream& co,
                                    const NumberAndStatus &number_and_status);
};

#endif  // SRC_NUMBERANDSTATUS_H_
