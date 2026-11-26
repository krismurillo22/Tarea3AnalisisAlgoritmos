# Análisis de Algoritmos de Ordenamiento

## Descripción

Proyecto académico desarrollado en C++ para implementar y comparar diferentes algoritmos de ordenamiento, mediante pruebas de rendimiento con distintos tamaños de entrada.

El programa genera arreglos de números enteros aleatorios, ejecuta los algoritmos, mide sus tiempos de ejecución y verifica que los datos hayan sido ordenados correctamente. Los registros obtenidos se almacenan automáticamente en un archivo CSV para su posterior análisis.

## Características

- Implementación desde cero de seis algoritmos de ordenamiento.
- Generación automática de números enteros aleatorios.
- Configuración de diferentes tamaños de entrada.
- Ejecución de múltiples repeticiones por algoritmo.
- Uso de los mismos datos de entrada para cada algoritmo dentro de una repetición.
- Medición del tiempo de ejecución en milisegundos.
- Validación automática de los resultados.
- Exportación de los registros en formato CSV.
- Soporte para pruebas de estrés con grandes cantidades de datos.
- Código modular y organizado por algoritmo.
- Compilación mediante CMake y Ninja.

## Algoritmos implementados

| Algoritmo | Complejidad promedio | Peor caso | 
|---|---|---|
| Merge Sort | O(n log n) | O(n log n) |
| Selection Sort | O(n²) | O(n²) | 
| Bubble Sort | O(n²) | O(n²) | 
| Quick Sort | O(n log n) | O(n²) | 
| Heap Sort | O(n log n) | O(n log n) |
| Insertion Sort | O(n²) | O(n²) |


## Tecnologías utilizadas

- C++17
- GCC / MinGW-w64
- CMake
- Ninja
- Git
- Microsoft Excel

## Estructura del proyecto

```text
Tarea3AnalisisAlgoritmos/
├── include/
│   ├── sorting.h
│   └── benchmark.h
├── src/
│   ├── main.cpp
│   ├── benchmark.cpp
│   ├── merge_sort.cpp
│   ├── selection_sort.cpp
│   ├── bubble_sort.cpp
│   ├── quick_sort.cpp
│   ├── heap_sort.cpp
│   └── insertion_sort.cpp
├── results/
├── CMakeLists.txt
├── .gitignore
└── README.md
```

### Descripción de los directorios

| Directorio | Descripción |
|---|---|
| `src/` | Código fuente de los algoritmos y del sistema de pruebas. |
| `include/` | Archivos de encabezado y declaraciones de funciones. |
| `results/` | Archivos CSV y documentos de análisis. |
| `build/` | Archivos generados durante la compilación. |

## Requisitos

Antes de compilar el proyecto, es necesario tener instaladas las siguientes herramientas:

- Compilador GCC con soporte para C++17.
- CMake.
- Ninja.
- Git.

En Windows se recomienda utilizar MSYS2 para instalar el compilador y las herramientas de compilación.

### Verificar las herramientas

Ejecutar los siguientes comandos desde una terminal:

```bash
g++ --version
cmake --version
ninja --version
git --version
```

Si todos los comandos muestran sus respectivas versiones, el entorno está listo para compilar el proyecto.

## Instalación

### 1. Clonar el repositorio

Copiar la URL del repositorio desde GitHub y ejecutar:

```bash
git clone URL_DEL_REPOSITORIO
```

Ingresar al directorio del proyecto:

```bash
cd Tarea3AnalisisAlgoritmos
```

### 2. Configurar el proyecto

Desde la carpeta raíz, ejecutar:

```bash
cmake -S . -B build -G "Ninja" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++
```

Se recomienda utilizar el modo Release para habilitar las optimizaciones del compilador durante las pruebas de rendimiento.

### 3. Compilar el proyecto

```bash
cmake --build build
```

Una vez finalizada la compilación, el archivo ejecutable estará disponible dentro del directorio `build`.

### 4. Ejecutar el programa

En Windows, desde PowerShell:

```powershell
.\build\sorting_benchmark.exe
```

El programa comenzará a ejecutar las pruebas configuradas y almacenará los registros en la carpeta `results`.

## Configuración de las pruebas

Los tamaños de entrada y la cantidad de repeticiones pueden modificarse desde el archivo:

```text
src/main.cpp
```

Por ejemplo, para realizar una prueba sencilla se puede utilizar la siguiente configuración:

```cpp
std::vector<int> sizes = {
    100,
    1000,
    10000
};

int repetitions = 5;

runBenchmark(sizes, repetitions);
```

Esta configuración permite ejecutar los algoritmos con tres tamaños de entrada y cinco repeticiones por cada tamaño.

Después de modificar la configuración, es necesario volver a compilar el proyecto:

```bash
cmake --build build
```

## Funcionamiento del programa

El programa realiza el siguiente proceso:

1. Genera un arreglo de números enteros aleatorios.
2. Crea una copia de los datos para cada algoritmo.
3. Inicia la medición del tiempo.
4. Ejecuta el algoritmo de ordenamiento.
5. Finaliza la medición del tiempo.
6. Verifica que el resultado sea correcto.
7. Registra la información en el archivo CSV.
8. Continúa con la siguiente prueba.

La generación de datos y la validación del ordenamiento no forman parte del tiempo de ejecución medido.

## Medición del tiempo

Para medir el tiempo de ejecución se utiliza la biblioteca estándar `chrono` de C++, específicamente:

```cpp
std::chrono::steady_clock
```

Esta herramienta permite medir el tiempo transcurrido durante la ejecución de cada algoritmo.

Los tiempos se registran en milisegundos.

## Validación de los algoritmos

Cada algoritmo fue implementado de manera independiente.

Para comprobar que el ordenamiento sea correcto, el resultado obtenido se compara con un arreglo de referencia ordenado mediante `std::sort`.

Esta función se utiliza únicamente para la validación y no forma parte de las implementaciones evaluadas.

## Formato de salida

Los registros se almacenan en un archivo CSV con la siguiente estructura:

```csv
Algoritmo,N,Repeticion,Tiempo_ms,Estado
```

| Campo | Descripción |
|---|---|
| `Algoritmo` | Nombre del algoritmo ejecutado. |
| `N` | Cantidad de elementos del arreglo. |
| `Repeticion` | Número de repetición de la prueba. |
| `Tiempo_ms` | Tiempo de ejecución en milisegundos. |
| `Estado` | Estado de la validación: OK o ERROR. |

El archivo CSV puede importarse en Microsoft Excel para calcular promedios, generar gráficos y realizar comparaciones.

## Pruebas de estrés

El programa permite configurar tamaños de entrada de hasta millones de elementos, dependiendo de los recursos disponibles en el equipo.

Se recomienda comenzar con tamaños pequeños y aumentarlos progresivamente.

Los algoritmos con complejidad cuadrática pueden requerir tiempos de ejecución considerablemente mayores al trabajar con grandes cantidades de datos.

## Recomendaciones

Para obtener mediciones bajo condiciones similares, se recomienda:

- Compilar siempre en modo Release.
- Cerrar aplicaciones innecesarias antes de ejecutar las pruebas.
- Mantener las mismas condiciones de ejecución.
- Utilizar varias repeticiones por cada tamaño de entrada.
- Verificar que todas las pruebas tengan el estado `OK`.
- Respaldar o renombrar el CSV anterior antes de iniciar una nueva sesión de pruebas, ya que el programa agrega registros al archivo existente.
- Evitar ejecutar otros procesos que consuman grandes cantidades de CPU o memoria.

## Propósito académico

Este proyecto fue desarrollado como parte de la asignatura de Análisis de Algoritmos, con el propósito de aplicar los conocimientos sobre algoritmos de ordenamiento, complejidad computacional y medición experimental del rendimiento.