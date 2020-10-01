# Práctica 02. La criba de Eratóstenes

### Objetivos
Los objetivos de esta práctica son: 


* Ser capaz de desarrollar, editar remotamente usando VSC, compilar y ejecutar programas escritos en C++ en su VM
* Ser capaz de usar comandos de la shell de GNU/Linux para trabajar en la Máquina Virtual de la asignatura
* Introducir las reglas de estilo de código a utilizar en las prácticas de la asignatura
* Profundizar en los conocimientos de Visual Studio Code (VSC)
* Ser capaz de editar ficheros de forma remota usando VSC
* Practicar conocimientos de programación en C++

### Rúbrica de evaluacion de esta práctica
Se señalan a continuación los aspectos más relevantes (la lista no es exhaustiva)
que se tendrán en cuenta a la hora de evaluar esta práctica:

* Ha de acreditar que es capaz de conectarse a la VM de la asignatura y ejecutar comandos
básicos de Linux para al menos: copiar, borrar y editar ficheros, crear directorios y compilar su programa.
* Ser capaz de desarrollar, editar remotamente usando VSC, compilar y ejecutar programas escritos en C++ en su VM
* El alumnado ha de acreditar que es capaz de editar ficheros remotos en la VM de la asignautra usando VSC
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
imprescindible que lo tenga Ud. en su ordenador de trabajo habitual.
Si trabaja Ud. en GNU/Linux (como se recomienda) siga las instrucciones correspondientes a
["Debian and Ubuntu based distributions"](https://code.visualstudio.com/docs/setup/linux#_debian-and-ubuntu-based-distributions) para instalar VSC.

Siga a continuación 
[estas instrucciones](https://code.visualstudio.com/docs/cpp/config-linux)
para instalar/configurar en su ordenador de trabajo (tenga en cuenta que en las salas del Centro de Cálculo esta instalación es local a cada usuario) la extensión para trabajar con C/C++ en VSC.
* Compruebe que el compilador gcc/g++ esté instalado en su máquina Virtual (VM) de la asignatura.
* Estudie la
[User Interface documentation](https://code.visualstudio.com/docs/getstarted/userinterface)
para conocer los detalles de la interfaz de VSC y ser capaz de manejarse con la misma.

Si no lo hizo en la práctica anterior, siga 
[estas instrucciones](https://code.visualstudio.com/docs/remote/ssh)
para configurar la edición remota de ficheros alojados en su máquina virtual.
De ese modo podrá editar todos los ficheros de su proyecto en la VM usando VSC.

Para compilar su programa, acceda a su VM, y en el directorio de trabajo invoque al compilador:

`$ g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc`

Esta compilación la puede realizar estableciendo una conexión ssh con la VM en una terminal independiente o utilizando la pestaña `Terminal` de VSC.

### Referencias
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) La guía de estilo de código que
  se usará en la asignatura
* [How to parse command line parameters](http://www.cplusplus.com/articles/DEN36Up4/) Explica cómo pasar parámetros a un programa C o C++ desde la línea de comandos.
* [C++ Tutor](http://pythontutor.com/cpp.html#mode=display) Visualización online de la ejecución de código C++
