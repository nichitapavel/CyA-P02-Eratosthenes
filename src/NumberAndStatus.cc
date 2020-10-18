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

#include <string>
#include "NumberAndStatus.h"

NumberAndStatus::NumberAndStatus() {
  number_ = 0;
  primeness_ = true;
}

NumberAndStatus::NumberAndStatus(int number) {
  this->number_ = number;
  this->primeness_ = false;
}

int NumberAndStatus::getNumber(void) {
  return number_;
}

bool NumberAndStatus::isPrime(void) {
  return primeness_;
}

void NumberAndStatus::setNumber(int number) {
  this->number_ = number;
}

void NumberAndStatus::setPrimeness(bool primeness) {
  this->primeness_ = primeness;
}

std::ostream& operator << (std::ostream& co,
                           const NumberAndStatus &number_and_status) {
  std::string prime_status;
  if (number_and_status.primeness_) {
    prime_status = "Prime";
  } else {
    prime_status = "NOT Prime";
  }
  co << number_and_status.number_ << " " << prime_status << " ";
  return co;
}
