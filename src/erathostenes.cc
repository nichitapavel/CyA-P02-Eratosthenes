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

#include "NumberAndStatus.h"
#include "Numbers.h"

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
  std::cout << numbers;

  exit(EXIT_SUCCESS);
}
