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

#include <iostream>
#include <vector>


class NumberAndStatus {
 private:
  int number_;
  bool primeness_;

 public:
  NumberAndStatus() {
    number_ = 0;
    primeness_ = true;
  }

  explicit NumberAndStatus(int number) {
    this->number_ = number;
    this->primeness_ = false;
  }

  int getNumber(void) {
    return number_;
  }

  bool isPrime(void) {
    return primeness_;
  }

  void setNumber(int number) {
    this->number_ = number;
  }

  void setPrimeness(bool primeness) {
    this->primeness_ = primeness;
  }

  void toString(void) {
    std::string prime_status = primeness_ ? "Prime" : "NOT Prime";
    std::cout << number_
              << " "
              << prime_status
              << std::endl;
  }
};

class Numbers {
 private:
  std::vector<NumberAndStatus> numbers;
  int length;
  int currentPrimePosition;

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
    this->currentPrimePosition = -1;
  }

  ~Numbers() {
    length = 0;
    currentPrimePosition = 0;
    numbers.clear();
  }

  int getNextPrime() {
    for (int i = currentPrimePosition + 1; i < length; i++) {
      NumberAndStatus number = numbers[i];
      if (number.isPrime()) {
        currentPrimePosition = i;
        return number.getNumber();
      }
    }
    return -1;
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
      return false;
    }
    for (int i = position + number_to_sieve; i < length; i += number_to_sieve) {
      numbers[i].setPrimeness(false);
    }
    return true;
  }

  int getPositionOfNumber(int number) {
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

  void remove() {
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

  int last_number() {
    NumberAndStatus last_number = numbers.back();
    return last_number.getNumber();
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
  int prime_number = 0;
  // Stop condition: prime_number * prime_number > n
  // for n = 40
  // 2 * 2 = 4 < 40
  // 3 * 3 = 9 < 40
  // 5 * 5 = 25 < 40
  // 7 * 7 = 49 > 40 STOP
  do {
    prime_number = numbers.getNextPrime();
    numbers.sieve(prime_number);
  } while ( prime_number * prime_number < calculate_prime_up_to);
  numbers.remove();
  numbers.toString();

  exit(EXIT_SUCCESS);
}
