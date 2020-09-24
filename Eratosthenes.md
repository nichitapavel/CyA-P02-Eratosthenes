# Práctica 02. La criba de Eratóstenes

### Objetivos
Los objetivos de esta práctica son: 

* Ser capaz de desarrollar, compilar y ejecutar programas escritos en C++ en el entorno de trabajo IaaS
* Profundizar en los conocimientos de Visual Studio Code (VSC)
* Ser capaz de editar ficheros de forma remota usando VSC
* Practicar conocimientos de programación en C++
* Introducir las reglas de estilo de código a utilizar en las prácticas de la asignatura
* Que el alumnado aprenda a utilizar la utilidad make para el desarrollo de programas simples

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva)
que se tendrán en cuenta a la hora de evaluar esta práctica:

* El alumnado ha de acreditar que es capaz de editar ficheros remotos en la VM de la asignautra usando VSC
* Ha de acreditar que es capaz de conectarse a la VM de la asignatura y ejecutar comandos
básicos de Linux para al menos: copiar, borrar y editar ficheros, crear directorios y compilar su programa.
* El comportamiento del programa debe ajustarse a lo solicitado en este documento.
* Capacidad del programador(a) de introducir cambios en el programa desarrollado.
* Modularidad: el programa ha de escribirse de modo que las diferentes funcionalidades
que se precisen sean encapsuladas en funciones y/o métodos cuya extensión textual se mantenga acotada.
* El código ha de estar escrito de acuerdo al estándar de la [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
Preste particular atención a los siguientes aspectos:
    1. [Reglas](https://google.github.io/styleguide/cppguide.html#Naming) de nombrado de ficheros, clases, variables, constantes, etc. 
       Todos los identificadores del código se nominarán de modo que sean significativos y de acuerdo a lo especificado en la guía.
    2. Reglas de [formato de escritura](https://google.github.io/styleguide/cppguide.html#Formatting) del código: espacios, tabuladores, posición de paréntesis, corchetes, llaves, etc.
    3. [Documentación del código](https://google.github.io/styleguide/cppguide.html#Comments)
    4. Todos los ficheros tendrán comentarios de cabecera.
    5. El código estará correctamente indentado de acuerdo a los criterios expuestos en la guía.
* El programa desarrollado deberá compilarse utilizando la herramienta `make` y un fichero `Makefile`.

Si el alumnado tiene dudas respecto a cualquiera de estos aspectos, debiera acudir al
foro de discusiones de la asignatura para plantearlas allı́. 
Se espera que, a través de ese foro, el alumnado intercambie experiencias y conocimientos, ayudándose mutuamente
a resolver dichas dudas. 
También el profesorado de la asignatura intervendrá en las discusiones que pudieran suscitarse, si fuera necesario.
    
### Introducción
La [criba de Eratóstenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) es un antiguo método para hallar números primos. 
Se escribe una lista de todos los números naturales. 
Comenzando por el 2, se tachan de la lista todos los mayores que 2 que están separados 2 posiciones (se tachan así todos los múltiplos de 2). 
A continuación se localiza el siguiente número en la lista, que es primo, el 3. 
Se tachan a continuación todos los múltiplos de 3. 
Se localiza el siguiente número, que es primo, el 5...

Siguiendo este proceso se obtiene una lista en la que los únicos números no tachados son los primos.

### Ejercicio práctico
Diseñar un programa en C++ (`erathostenes.cc`) que imprima en pantalla una lista de números primos.
El programa se invocará (por ejemplo) como:

`./erathostenes 1000`

En este caso particular el programa imprimirá en pantalla todos los números primos menores o iguales que 1000.

El programa seguirá las siguientes especificaciones:

* El programa leerá por línea de comandos un número natural `N` que será el número de valores que inicialmente
  contendrá la lista (1000 en el ejemplo anterior).
* Utilizará alguna estructura de datos para almacenar los `N` valores `[1..N]` iniciales en orden ascendente. 
  Todos estos números son considerados inicialmente primos.
* La función `Sieve` operará sobre la lista de valores e irá marcando en ella como no primos los múltiplos de
  2, los de 3, los de 5, etc. 
	Para ello localizará un valor que sea primo e invocará la función `Remove` que marcará desde ese punto de
	la lista en adelante todos los valores múltiplos del elegido, como no primos.
* Utilice una función adicional para eliminar de la lista todos los números que que no sean primos.
* Desarolle también una función que permita imprimir en pantalla en cualquier momento el estado de la lista. 
  Esta función escribirá cada uno de los valores presentes en la lista indicando si es primo o no.

### Entorno de trabajo
En las salas del CC de la ESIT ya se encuentra instalado el Visual Studio Code (VSC) pero también es 
imprescindible que lo instale Ud. en su ordenador de trabajo habitual.
Si trabaja Ud. en GNU/Linux (como se recomienda) siga las instrucciones correspondientes a
["Debian and Ubuntu based distributions"](https://code.visualstudio.com/docs/setup/linux#_debian-and-ubuntu-based-distributions) para instalar VSC.

Siga a continuación 
[estas instrucciones](https://code.visualstudio.com/docs/cpp/config-linux)
para instalar/configurar en su ordenador de trabajo (en las salas del Centro de Cálculo debería estar instalada) la extensión para trabajar con C/C++ en VSC.
* Compruebe que el compilador gcc/g++ esté instalado en su máquina Virtual (VM) de la asignatura.
* Instale (si no lo está) el depurador gdb en la VM.
* Y siga el resto de ese tutorial para crear en VSC su primer proyecto `hello_world.cc`
* En particular debe Ud. estudiar la
[User Interface documentation](https://code.visualstudio.com/docs/getstarted/userinterface)
para conocer los detalles de la interfaz de VSC y ser capaz de manejarse con la misma.
Tal como indica el tutorial, cree el fichero de texto `tasks.json` que gestiona la compilación de sus proyectos C++.
Asegúrese de que en ese fichero el compilador que utiliza es `/usr/bin/g++`.
Siga también las instrucciones de ese tutorial para crear el fichero `launch.json` que controla la depuración del código fuente desde el entorno integrado del VSC usando como depurador el gdb.
Comience los primeros pasos de la depuración del programa `hello_world.cc` usando el VSC.

Si no lo hizo en la práctica anterior, siga 
[estas instrucciones](https://code.visualstudio.com/docs/remote/ssh)
para configurar la edición remota de ficheros alojados en su máquina virtual.
De ese modo podrá editar todos los ficheros de su proyecto en la VM usando VSC.

En prácticas futuras se estudiará cómo gestionar enteramente sus proyectos C++ usando VSC pero por ahora se propone el uso de la línea de comandos
(ya sea mediante una conexión ssh con la VM o usando la pestaña "Terminal" del VSC) para compilar
sus programas C++, invocando directamente al compilador g++.

En el caso particular de esta práctica puede Ud. compilar su programa accediendo a su VM, y en el directorio
de trabajo invocando al compilador:

`$ g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc`

Estudie algún tutorial ([este podría ser un ejemplo](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/)) para aprender a utilizar
la herramienta `make` y ficheros `Makefile`.
Revise igualmente la documentación oficial correspondiente a [GNU Make](https://www.gnu.org/software/make/).

Su proyecto de programación debe contener un fichero `Makefile` de modo que al ejecutar

`$ make`

se produzca la compilación del programa y se genere el fichero ejecutable `erathostenes`, mientras que
ejecutando

`$ make clean`

se borren todos los ficheros del directorio de trabajo salvo los que contengan código fuente
(`erathostenes.*`) y el propio `Makefile`.

### Referencias
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) La guía de estilo de código que
  se usará en la asignatura
* [GNU Make](https://www.gnu.org/software/make/)
* [Ejemplo de un fichero Makefile](https://github.com/fsande/IB-class-code-examples/blob/master/IntroductionToC%2B%2B/Makefile) para compilar el programa hello_world.cc
* [A Simple Makefile Tutorial](https://cs.colby.edu/maxwell/courses/tutorials/maketutor/) De forma incremental
  explica el funcionamiento de la herramienta `make`. Utiliza el compilador de C en lugar de `g++`, pero es
	obvio cómo adaptar los ejemplos al caso de C++.
* [How to parse command line parameters](http://www.cplusplus.com/articles/DEN36Up4/) Explica cómo pasar parámetros a un programa C o C++ desde la línea de comandos.
* [C++ Tutor](http://pythontutor.com/cpp.html#mode=display) Visualización online de la ejecución de código C++
