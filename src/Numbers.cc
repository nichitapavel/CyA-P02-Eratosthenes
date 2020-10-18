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

#include "Numbers.h"

Numbers::Numbers(int length) {
  this->length = length;
  this->numbers = std::vector<NumberAndStatus>(length);
  int drift = 2;
  int position = 0;
  for (auto& item : this->numbers) {
    item.setNumber(position + drift);
    position++;
  }
  this->currentPrimePosition = -1;
}

Numbers::~Numbers() {
  length = 0;
  currentPrimePosition = 0;
  numbers.clear();
}

int Numbers::getNextPrime() {
  for (int i = currentPrimePosition + 1; i < length; i++) {
    NumberAndStatus number = numbers[i];
    if (number.isPrime()) {
      currentPrimePosition = i;
      return number.getNumber();
    }
  }
  return -1;
}

bool Numbers::sieve(int number_to_sieve) {
  int position = getPositionOfNumber(number_to_sieve);
  if (position == -1) {
    return false;
  }
  for (int i = position + number_to_sieve; i < length; i += number_to_sieve) {
    numbers[i].setPrimeness(false);
  }
  return true;
}

int Numbers::getPositionOfNumber(int number) {
  // TODO(pavelnichita) a risky way to get position
  // it can be called independently of
  // getNextPrime() method
  int i = currentPrimePosition;
  for (; i < length; i++) {
    if (numbers[i].getNumber() == number) {
      return i;
    }
  }
  return -1;
}

void Numbers::remove() {
  int size = numbers.size();
  int i = 0;
  while (i < size) {
    if (!numbers[i].isPrime()) {
      numbers.erase(numbers.begin() + i);
      i--;
      size--;
    }
    i++;
  }
  length = numbers.size();
  currentPrimePosition = 0;
}

int Numbers::last_number() {
  NumberAndStatus last_number = numbers.back();
  return last_number.getNumber();
}

// std::ostream & operator<< (std::ostream &out, Token const &t)
std::ostream& operator << (std::ostream &co, const Numbers &numbers) {
  for (const auto& foo : numbers.numbers) {
    co << foo << "\n";
  }
  return co;
}
