Esto es GNU CLISP, una implementación de Common Lisp.


¿ Qué es LISP ?
---------------

LISP es un lenguaje de programación inventado por J. McCarthy en
1959. Aunque ha habido muchos dialectos de él, actualmente se ha
estandarizado y difundido ampliamente gracias al estandar industrial
COMMON LISP. Hay aplicaciones en los dominios del procesamiento del
conocimiento simbólico (IA), cálculo numérico (MACLISP generaba código
tan bueno como el de FORTRAN), y en programas ampliamente utilizados
como editores (EMACS) y CAD (AUTOCAD). Si lo desea, puede consultar la
introducción al lenguaje LISP:

  Sheila Hughes: Lisp. Pitman Publishing Limited, London 1986.
  107 pages.

Después de un rato, necesitará el texto estandar que contiene la
definición del lenguaje:

Guy L. Steele Jr.: Common Lisp - The Language. Digital Press.
  1. edition 1984, 465 pages.
  2. edition 1990, 1032 pages.

Este libro está disponible en formato HTML via FTP en:
  ftp.cs.cmu.edu:/user/ai/lang/lisp/doc/cltl/cltl_ht.tgz

y puede consultarse a través de WWW en:

  http://www-2.cs.cmu.edu/Groups/AI/html/cltl/cltl2.html o
  http://www-2.cs.cmu.edu/afs/cs/project/ai-repository/ai/html/cltl/cltl2.html .

Nota para los expertos: Este texto estandar se ha convertido en un
estándar ANSI, que puede obtenerse <<<exceptionally>>> sin cargo alguno en:

  http://www.lisp.org/HyperSpec/FrontMatter/

LISP se ejecuta en un entorno interactivo. Usted introduce formas, que
serán evaluadas de inmediato. Por lo tanto, puede inspeccionar
variables, invocar funciones con unos argumentos concretos o definir
sus propias funciones.


Contenidos:
-----------

Consta de los siguientes ficheros:

   base/lisp.a            programa principal, listo para ser enlazado
   base/lispinit.mem      imagen de memoria necesaria para la inicialización
   doc/clisp.1            manual en formato man de Unix
   doc/clisp.man          manual
   doc/clisp.html         manual en format HTML
   doc/impnotes.html      notas de la implementación
   doc/clreadline.3       manual de edición de línea en formato man de Unix
   doc/clreadline.man     manual de edición de línea
   doc/LISP-tutorial.txt  tutorial de LISP para aprendices
   doc/CLOS-guide.txt     breve guía de CLOS
   README                 este texto
   SUMMARY                pequeña descripción de CLISP
   ANNOUNCE               declaración
   NEWS                   lista de modificaciones desde la última versión
   COPYRIGHT              derechos de autor <<<copyright>>>
   GNU-GPL                licencia de software libre
   doc/readline.dvi       documentación de la librería GNU readline
                          en formato DVI
   doc/editors.txt        Lista de editores que soportan Lisp
   emacs/*.el             personalización de Emacs, véase doc/editors.txt
   src/clisp.c            fuentes del programa
   src/config.lisp        configuración dependiente del lugar

y - cuando le apetezca, si le gusta leer código fuente -

   src/*.lisp             el código fuente de lispinit.mem
   src/*.fas              los mismos ficheros, una vez compilados

Para crear el ejecutable, también necesitará:

   base/libreadline.a     librería GNU readline

o

   base/libnoreadline.a   sustituto ficticio de la librería GNU readline


Instalación:
------------

Teclee

         make

Cambie las cadenas en SRC/CONFIG.LISP, empleando para ello un editor de
textos.
Luego ejecute

         base/lisp.run -M base/lispinit.mem

Cuando aparezca el inductor de comandos

      > _

teclee

      (without-package-lock ()
        (compile-file "src/config.lisp")
        (load "src/config.fas"))

y luego

        (cd "base/")
        (saveinitmem)

para sobreescribir el fichero LISPINIT.MEM con su configuración. A
continuación

        (exit)

El resto se hace simplemente con

        make install

En vez de esto, puede hacerlo usted mismo, paso por paso:

Luego cree un directorio, y ponga en él el ejecutable con la imagen de
memoria.
Le recomiendo /usr/local/lib/lisp :

   mkdir /usr/local/lib/lisp
   mv base/lisp.run /usr/local/lib/lisp
   mv base/lispinit.mem /usr/local/lib/lisp

Y cree el programa que ejeute lisp:

   ./hardcode -DLISPLIBDIR='/usr/local/lib/lisp' \
              -DLOCALEDIR='/usr/local/share/locale' \
              clisp /usr/local/bin/clisp

Ahora, instale las páginas de man.

   mv doc/clisp.1 /usr/local/man/man1/clisp.1
   mv doc/clreadline.3 /usr/local/man/man3/clreadline.3

and try

   man clisp

Cuando encuentre problemas:
---------------------------

Después de un error, se encontrará en el depurador:

     1. Break> _

En él, usted puede evaluar formas como siempre. Más aún:

     Help
               invoca la ayuda
     Abort     o
     Unwind
               retrocede hasta el bucle de entrada más reciente
     Backtrace
               muestra los contenidos de la pila, útil para la depuración

Y puede consultar el valor de las variables de las funciones donde se
produjo el error.

Cuando los problemas sean mayores, por ejemplo `core dumps', por favor
envíe una descripción del error y una descripción de cómo reproducir
el error a los autores o al "mantenedor". Por favor, acompañe su mensaje
de la versión de CLISP que puede obtener invocando la función
(lisp-implementation-version).


Código fuente:
--------------

El código fuente de CLISP está disponible en
     ftp://clisp.cons.org/pub/lisp/clisp/source/clispsrc*


Lista de correo:
----------------

<<<There are three mailing lists for users of CLISP. You find subscription
information and archives on the homepage http://clisp.cons.org/.>>>


Agradecimientos:
----------------

Estamos muy agradecidos a
  * Guy L. Steele y otros muchos por la especificación de Common Lisp.
  * El proyecto GNU de Richard Stallman para el GCC, Autoconf y la librería
    readline.


Autores:
--------

        Bruno Haible
        Michael Stoll

Email: clisp-list@lists.sourceforge.net

"Mantenedor":
-------------

        Sam Steingold

Email: clisp-list@lists.sourceforge.net
