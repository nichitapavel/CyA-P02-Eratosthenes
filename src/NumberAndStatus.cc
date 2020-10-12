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

#include <iostream>

#ifndef SRC_NUMBERANDSTATUS_H_
#define SRC_NUMBERANDSTATUS_H_

#include "NumberAndStatus.h"

#endif  // SRC_NUMBERANDSTATUS_H_

NumberAndStatus::NumberAndStatus(int number) {
  number = number;
  primeness = false;
}


int NumberAndStatus::getNumber() {
  return number;
}

bool NumberAndStatus::isPrime() {
  return primeness;
}

void NumberAndStatus::setNumber(int number) {
  number = number;
}

void NumberAndStatus::setPrimeness(bool primeness) {
  primeness = primeness;
}

void NumberAndStatus::toString() {
  std::cout << number << " " << primeness << std::endl;
}
