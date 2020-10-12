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
 * @brief  Executable for Sieve of Eratosthenes.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>


class NumberAndStatus {
 private:
  int number;
  bool primeness;

 public:
  NumberAndStatus() {
    number = 0;
    primeness = false;
  }

  explicit NumberAndStatus(int number) {
    this->number = number;
    this->primeness = false;
  }

  int getNumber(void) {
    return number;
  }

  bool isPrime(void) {
    return primeness;
  }

  void setNumber(int number) {
    this->number = number;
  }

  void setPrimeness(bool primeness) {
    this->primeness = primeness;
  }

  void toString(void) {
    std::cout << number << " " << primeness << std::endl;
  }
};

class Numbers {
 private:
  std::vector<NumberAndStatus> numbers;
  int length;

 public:
  explicit Numbers(int length) {
    this->length = length;
    this->numbers = std::vector<NumberAndStatus>(length);
    int drift = 2;
    int position = 0;
    for (auto& item : this->numbers) {
      item.setNumber(position + drift);
      position++;
    }
  }

  ~Numbers() {
    length = 0;
    numbers.clear();
  }

  // std::ostream & operator<< (std::ostream &out, Token const &t)
  void toString(void) {
    for (auto& foo : numbers) {
      foo.toString();
    }
    std::cout << std::endl;
  }

  bool sieve(int number_to_sieve) {
    int position = getPositionOfNumber(number_to_sieve);
    if (position == -1) {
      std::cout << "Sieve cannot be done with number: "
                << number_to_sieve
                << std::endl;
      return false;
    }
    for (int i = position + number_to_sieve; i < length; i += number_to_sieve) {
      numbers[i].setPrimeness(true);
    }
    return true;
  }

  int getPositionOfNumber(int number) {
    int position = 0;
    for (auto& item : numbers) {
      if (item.getNumber() == number) {
        return position;
      }
      position += 1;
    }
    return -1;
  }

  void remove() {
    int size = numbers.size();
    int i = 0;
    while (i < size) {
      if (numbers[i].isPrime()) {
        numbers.erase(numbers.begin() + i);
        i--;
        size = numbers.size();
      }
      i++;
    }
  }
};

static void show_usage(std::string name) {
  std::cerr << "The program prints a subsequence of the prime "
            << "numbers sequence defined by one parameter.\n\n"
            << "Usage: "
            << name
            << " UpperLimit"
            << std::endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int calculate_prime_up_to;

  if (argc != 2) {
    show_usage(argv[0]);
    exit(EXIT_FAILURE);
  } else {
    calculate_prime_up_to = atoi(argv[1]);
  }

  Numbers numbers = Numbers(calculate_prime_up_to);
  numbers.sieve(2);
  numbers.sieve(3);
  numbers.sieve(4);
  numbers.sieve(5);
  numbers.sieve(6);
  numbers.sieve(7);
  numbers.toString();
  numbers.remove();
  // numbers.
  /* Other code omitted */
  exit(EXIT_SUCCESS);
}
