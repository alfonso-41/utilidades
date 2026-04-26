////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIAN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia coleccion de subprogramas utiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VALIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CODIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la funcion vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinonimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningun valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta funcion.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void descartarEntrada (void);
//
//  USO:
//
//    Sirve para borrar lo que haya escrito el usuario en el teclado.
//	
//
//  DETALLES:
//
//    Esta función llama a vaciarBuffer(), que es la que realmente hace el
//    trabajo.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningun valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      
//
////////////////////////////////////////////////////////////////////////////////
void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro codigo ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningun valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estandar ("prefabricado") que hace la logistica de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacÃ­o
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void borrarPantalla (void);
//
//  USO:
//
//    Limpia la pantalla
//
//  DETALLES:
//
//    Llama a la función limpiarPantalla(), que es la que borra la pantalla.
//   
//   
//    
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningun valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    limpiarPantalla();
//
////////////////////////////////////////////////////////////////////////////////
void borrarPantalla (void)
{
  limpiarPantalla();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void limpiarPantalla (void);
//
//  USO:
//
//    Borra la pantalla usando un comando del sistema.
//
//  DETALLES:
//
//    Usa la función system() junto con BORRAR para limpiar la pantalla.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    system()
//
////////////////////////////////////////////////////////////////////////////////

void limpiarPantalla (void)
{
  system(BORRAR);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas lÃ­neas como se le indique.
//
//  DETALLES:
//
//    Crea tantas lineas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribira¡ texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el codigo ASCII de salto de linea '\n' Ã³ 0x10.
//
//  PARAMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibira¡ del exterior el numero de lineas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningun valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estandar ("prefabricado") que hace la logistica de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque creariamos un bucle de llamadas.
    
    nlineas--;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void abajo (int nfils);
//
//  USO:
//
//    Baja el cursor varias líneas.
//
//  DETALLES:
//
//    Llama a la función bajar(). 
//
//  PARAMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas que se quiere bajar.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void saltar (int nfils);
//
//  USO:
//
//    Salta varias líneas en la pantalla.
//
//  DETALLES:
//
//    Hace lo mismo que bajar().
//
//  PARAMETROS DE ENTRADA:
//
//    nfils
//
//      Número de líneas que se quieren saltar.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void saltar (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarFils (int nfils);
//
//  USO:
//
//    Desplaza el cursor hacia abajo varias filas.
//
//  DETALLES:
//
//  Llama a bajar(). Hace exactamente lo mismo.
//
//  PARAMETROS DE ENTRADA:
//
//    nfils
//
//      Número de filas a mover.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarFils (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarV (int nfils);
//
//  USO:
//
//    Baja el cursor varias líneas.
//
//  DETALLES:
//
//    Llama a la función bajar(). 
//
//  PARAMETROS DE ENTRADA:
//
//    nfils -> número de líneas a bajar.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////
void desplazarV (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarY (int nfils);
//
//  USO:
//
//    Baja el cursor varias líneas.
//
//  DETALLES:
//
//    Hace lo mismo que bajar().
//
//  PARAMETROS DE ENTRADA:
//
//    nfils -> número de líneas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
////////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void indentar (int ncolumnas);
//
//  USO:
//
//    Mueve el cursor hacia la derecha.
//
//  DETALLES:
//
//    Imprime espacios en blanco para desplazar el texto.
//
//  PARAMETROS DE ENTRADA:
//
//    ncolumnas -> número de espacios.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
////////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearÃ­amos un bucle de llamadas.
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void derecha (int ncols);
//
//  USO:
//
//    Mueve el cursor a la derecha.
//
//  DETALLES:
//
//    Llama a indentar(). 
//
//  PARAMETROS DE ENTRADA:
//
//    ncols -> número de columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void derecha (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void tabular (int ncols);
//
//  USO:
//
//    Mueve el cursor a la derecha.
//
//  DETALLES:
//
//    Llama a indentar(). 
//
//  PARAMETROS DE ENTRADA:
//
//    ncols -> número de columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
////////////////////////////////////////////////////////////////////////////////
void tabular (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarCols (int ncols);
//
//  USO:
//
//    Mueve el cursor a la derecha.
//
//  DETALLES:
//
//    Es igual que indentar().
//
//  PARAMETROS DE ENTRADA:
//
//    ncols -> número de columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarX (int ncols);
//
//  USO:
//
//    Mueve el cursor a la derecha.
//
//  DETALLES:
//
//    Igual que indentar().
//
//  PARAMETROS DE ENTRADA:
//
//    ncols -> número de columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void desplazarX (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarH (int ncols);
//
//  USO:
//
//    Mueve el cursor a la derecha.
//
//  DETALLES:
//
//    Hace lo mismo que indentar().
//
//  PARAMETROS DE ENTRADA:
//
//    ncols -> número de columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void desplazarH (int ncols)
{
  indentar(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void posicionar (int nfils, int ncols);
//
//  USO:
//
//    Coloca el cursor en una posición.
//
//  DETALLES:
//
//    Baja líneas y luego se mueve a la derecha.
//
//  PARAMETROS DE ENTRADA:
//
//    nfils -> número de líneas.
//    ncols -> número de columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazar (int nfils, int ncols);
//
//  USO:
//
//    Mueve el cursor.
//
//  DETALLES:
//
//    Es igual que posicionar().
//
//  PARAMETROS DE ENTRADA:
//
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void desplazarXY (int nfils, int ncols);
//
//  USO:
//
//    Mueve el cursor.
//
//  DETALLES:
//
//    Hace lo mismo que posicionar().
//
//  PARAMETROS DE ENTRADA:
//
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void retardoSegundos (int segundosmax);
//
//  USO:
//
//    Hace una pausa en segundos.
//
//  DETALLES:
//
//    Usa bucles para crear una espera.
//
//  PARAMETROS DE ENTRADA:
//
//    segundosmax -> tiempo.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en funciÃ³n de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void retardoMilisegundos (int milisegundosmax);
//
//  USO:
//
//    Crea un retardo en milisegundos
//
//  DETALLES:
//
//    Usa bucles para esperar.
//
//  PARAMETROS DE ENTRADA:
//
//    milisegundosmax -> tiempo.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void retrasoMilisegundos (int milisegundos);
//
//  USO:
//
//    Hace un retraso en milisegundos.
//
//  DETALLES:
//
//    Usa clock() para medir el tiempo.
//
//  PARAMETROS DE ENTRADA:
//
//    milisegundos -> tiempo.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void esperarSegundos (int segundos);
//
//  USO:
//
//    Paara el programa unos segundos determinados.
//
//  DETALLES:
//
//    
//
//  PARAMETROS DE ENTRADA:
//
//    segundos -> tiempo.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void esperarMilisegundos (int milisegundos);
//
//  USO:
//
//    Para el programa unos milisegundos determinados.
//
//  DETALLES:
//
//    
//
//  PARAMETROS DE ENTRADA:
//
//    milisegundos -> tiempo.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void pausa (void);
//
//  USO:
//
//    Hace una pausa en el programa.
//
//  DETALLES:
//
//    Llama a pausaEstandar() una fila hacia abajo y dos columnas hacia la derecha. 
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void pausa (void)
{
  pausaEstandar(1, 2);
}
////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void pausaEstandar (int nfils, int ncols);
//
//  USO:
//
//    Muestra un mensaje de pausa.
//
//  DETALLES:
//
//    Llama a pausaGenerica() con el mensaje de pausa. El numero de filas y columnas lo manda directamente a pausa genérica.
//
//  PARAMETROS DE ENTRADA:
//
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Muestra un mensaje y espera ENTER llamando esperarINTRO()
//
//  DETALLES:
//
//    Escribe el mensaje en pantalla y espera a que el usuario pulse INTRO.
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> mensaje de texto.
//    nfils -> lineas.
//    ncols -> columnas.
//    Boolean nuevalinea -> Determina si cambiamos de linea o no
// 
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void texto (char msjtxt[]);
//
//  USO:
//
//    Muestra texto en pantalla (vector de letras)
//
//  DETALLES:
//
//    Usa puts().
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void texto (char msjtxt[])
{
  puts(msjtxt);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void separar (void);
//
//  USO:
//
//    Hace un salto de linea.
//
//  DETALLES:
//
//    Muestra una línea en blanco (INTRO).
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void separar()
{
  mostrar("\n");
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void nuevaLinea (void);
//
//  USO:
//
//    Baja una linea.
//
//  DETALLES:
//
//    Llama a saltar(1).
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void nuevaLinea (void)
{
  saltar(1);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void mostrar (char msjtxt[]);
//
//  USO:
//
//    Muestra texto. Es como un printf simple.
//
//  DETALLES:
//
//    Llama a mostrar_x_y().
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra texto en una posicion.
//
//  DETALLES:
//
//    Llama a mensaje_x_y().
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void escribir (char msjtxt[]);
//
//  USO:
//
//    Muestra texto.
//
//  DETALLES:
//
//    Simplificación de mostrar(). Llama a mensaje_x_y.
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void escribir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra texto en una posición.
//
//  DETALLES:
//
//    Llama a mensaje_x_y().
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void imprimir (char msjtxt[]);
//
//  USO:
//
//    Muestra texto.
//
//  DETALLES:
//
//    Igual que escribir().
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra texto en una posición.
//
//  DETALLES:
//
//    Llama a mensaje_x_y().
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void mensaje (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra un mensaje en una posición (filas y columnas).
//
//  DETALLES:
//
//    Llama a mensaje_x_y(). El 4 parámetro lo aporta esta.
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//    nfils -> líneas.
//    ncols -> columnas.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Muestra un mensaje en una posición.
//
//  DETALLES:
//
//    Baja líneas (saltar()), mueve a la derecha (tabular()) y muestra el texto (printf()).
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> texto.
//    nfils -> líneas.
//    ncols -> columnas.
//    nuevalinea -> indica si añade salto de línea.
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////
void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    void iniciaAleatorizador (void);
//
//  USO:
//
//    Pone en marcha programas internos para generar los números aleatorios.
//
//  DETALLES:
//
//    Usa la hora actual para generar números diferentes cada vez -> Sinónimo de srand
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve nada.
//
////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int generaAleatorioEntero (int limite);
//
//  USO:
//
//    Genera un número aleatorio.
//
//  DETALLES:
//
//    Genera un número entre 0 y limite - 1, nunca llega al limite.
//
//  PARAMETROS DE ENTRADA:
//
//    limite -> valor máximo.
//
//  VALOR DE SALIDA:
//
//    Número aleatorio.
//
////////////////////////////////////////////////////////////////////////////////
int generaAleatorioEntero (int limite)
{
  // GenerarÃ un numero entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitucion mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La funcion scanf() no retira el codigo ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras despues de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra funcion creada en esta libreria,
//    vaciarBuffer() para ello. No muestra ningon mensaje por pantalla.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la funcion scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estandar ("prefabricado") que hace la logistica de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    char obtenerCaracterASCII (void);
//
//  USO:
//
//    Lee un carácter.
//
//  DETALLES:
//
//    Llama a obtenerLetra() -> Sinónimo.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Carácter leído.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    char obtenerLetra (void);
//
//  USO:
//
//    Lee una letra válida.
//
//  DETALLES:
//
//    Solo acepta caracteres ASCII válidos. Es un getchar() mejorado. 
//    Si la letra en los códigos ASCII está entre 0 y 128 devuelve la letra, es decir,
//    hace una comprobación.
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve Letra leída.
//
////////////////////////////////////////////////////////////////////////////////
char obtenerLetra (void)   // Solo ASCII VÃLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CODIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de multiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un numero de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() mas un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. Tambien impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    funcion obtenerEntero().
//
//  PARAMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibira el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibira del exterior el numero de espacios en
//      blanco a aÃ±adir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    funcion ha recibido desde la funcion obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para aÃ±adir en pantalla un texto adicional despuÃ©s del mensaje.
//
//    obtenerEntero()
//
//      Es la funciÃ³n que se encarga en la prÃ¡ctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Pide un número positivo.
//
//  DETALLES:
//
//    Repite mediante un bucle hasta que el número sea válido. 
//
//  PARAMETROS DE ENTRADA:
//
//    mensaje:Variable de tipo vector de caracteres donde se recibira el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    ncols : Numero de columnas a desplazar a la derecha
//
//    boolean mostrar error: 
//
//  VALOR DE SALIDA:
//
//    Número válido.
//
////////////////////////////////////////////////////////////////////////////////
int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int pedirEnteroIntervalo (...);
//
//  USO:
//
//    Pide un número dentro de un intervalo.
//
//  DETALLES:
//
//    Repite hasta que esté dentro del rango.
//
//  PARAMETROS DE ENTRADA:
//
//    mensaje 
//    ncols 
//    min y max.
//
//  VALOR DE SALIDA:
//
//    Número válido.
//
////////////////////////////////////////////////////////////////////////////////
int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra);
//
//  USO:
//
//    Pide una letra concreta.
//
//  DETALLES:
//
//    Repite hasta que el usuario escriba la letra correcta.
//
//  PARAMETROS DE ENTRADA:
//
//    msjtxt -> mensaje.
//    ncols -> posición.
//    mostrarerror -> muestra error si la letra no es correcta.
//    letra -> letra correcta.
//
//  VALOR DE SALIDA:
//
//    Letra introducida.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayÃºsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Pide confirmar (SI o NO). SI está definida como "S"; NO está definido como "N"
//
//  DETALLES:
//
//    Solo acepta dos letras válidas.
//
//  PARAMETROS DE ENTRADA:
//
//    mensaje, ncols y boolean mostrar error.
//
//  VALOR DE SALIDA:
//
//    Letra elegida.
//
////////////////////////////////////////////////////////////////////////////////
int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayusculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si dos letras son iguales.
//
//  DETALLES:
//
//    Puede ignorar mayúsculas/minúsculas.
//
//  PARAMETROS DE ENTRADA:
//
//    original, dada, modo.
//
//  VALOR DE SALIDA:
//
//    TRUE o FALSE.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si una letra está en un conjunto.
//
//  DETALLES:
//
//    Recorre un array de letras.
//
//  PARAMETROS DE ENTRADA:
//
//    letra, conjunto y modo.
//
//  VALOR DE SALIDA:
//
//    TRUE o FALSE.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    char *cadenaOpcionesDisponibles (char entrada[]);
//
//  USO:
//
//    Crea un texto con opciones separadas por '/'.
//
//  DETALLES:
//
//    
//
//  PARAMETROS DE ENTRADA:
//
//    entrada -> texto.
//
//  VALOR DE SALIDA:
//
//    Nueva cadena.
//
////////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas mÃ¡ximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacÃ­a, asÃ­ que generamos vacÃ­a. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la Ãºltima '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Pide una letra de varias opciones.
//
//  DETALLES:
//
//    Pide una letra de un conjunto de texto.
//    Recurre a free(editada) y a otros programas.
//
//  PARAMETROS DE ENTRADA:
//
//    mensaje, ncols, boolean mostrarerror, selección (conjunto), boolean sensible a mayusculas.
//
//  VALOR DE SALIDA:
//
//    Letra válida.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con Â«seleccionÂ» a valor NULL.
  
  // Usar Â«cadenaOpcionesDisponibles()Â» implica luego liberar memoria con Â«free()Â».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayÃºsculas, siempre la devolvemos mayÃºscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

#include <conio.h>

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo cÃ³digo. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // NormalizaciÃ³n de teclas conflictivas no estÃ¡ndar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCION:
//
//    obtenerTeclaInteractiva(void)
//
//  USO:
//
//    Comprueba un carácter
//
//  DETALLES:
//
//    Obtiene la config de la terminal y el programa se detiene hasta recibir un caracter, lo comprueba y lo devuelve.
//    
//
//  PARAMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve un carácter
//
////////////////////////////////////////////////////////////////////////////////


#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuracion actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canonico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aqui hasta recibir un caracter.
  // Las flechas envi­an una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // Â¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer codigo de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era solo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuracion original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
