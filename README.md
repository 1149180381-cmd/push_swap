*Este proyecto ha sido creado como parte del currículo de 42 por apaniagu, xinyu.*

# Push_swap

## 📝 Descripción

Push_swap es un proyecto de algoritmia puro y optimización del currículo de la Escuela 42. El objetivo es ordenar un conjunto de números enteros utilizando dos pilas (Stack A y Stack B) y un repertorio muy limitado de instrucciones de manipulación de memoria.
El programa debe calcular y mostrar por pantalla la secuencia de instrucciones más corta posible para ordenar el Stack A de menor a mayor. El gran desafío radica en que la puntuación del proyecto depende directamente de la eficiencia, penalizando severamente cada movimiento innecesario.

---

## ⚙️ Decisiones Técnicas y Algoritmos Seleccionados

Para maximizar la puntuación y superar los estrictos límites de movimientos de la evaluación (Moulinette), el proyecto implementa un enfoque adaptativo inteligente que analiza dinámicamente el tamaño de la pila y su grado matemático de caos para dispatchar el algoritmo más óptimo:

### 1. Small Sort (Casos pequeños: de 2 a 5 elementos)
* **Justificación:** Para colecciones diminutas, los algoritmos generales generan demasiadas instrucciones redundantes.
* **Estrategia:** Se utiliza un árbol de decisión fijo (hardcoded). Para 3 números, se analizan los 5 escenarios posibles resolviéndolos en un máximo de 2 o 3 movimientos. Para 4 y 5 números, se detectan los elementos con los índices más pequeños (0 y 1), se suben al top en base a la línea media y se aíslan temporalmente en el Stack B, reduciendo el problema a un caso controlado de 3 números.

### 2. Selection Sort (Complejidad O(n²))
* **Justificación:** Se activa en pilas grandes que presentan un desorden muy bajo (< 20%).
* **Estrategia:** Recorre la pila buscando el índice menor que falta por posicionar, calcula el camino más corto hacia la parte superior (usando rotaciones normales o inversas) y lo desplaza al Stack B. Es óptimo aquí porque apenas requiere reestructuraciones profundas de memoria.

### 3. Chunk Sort / Bloques (Complejidad \(O(n\sqrt{n})\))
* **Justificación:** Seleccionado para pilas con un desorden moderado (entre 20% y 50%). Es el motor principal para pasar la prueba de 100 números.
* **Estrategia:** Divide el total de números en bloques basados en la raíz cuadrada de la pila. Los envía al Stack B segmentados. Posee un optimizador posicional: si el elemento enviado es menor que el punto medio del bloque, ejecuta un rb mandándolo al fondo de B. Esto preordena el Stack B por densidades, reduciendo drásticamente el coste de las rotaciones durante la fase de rescate.

### 4. Radix Sort Binario (Complejidad \(O(n \cdot \log n)\))
* **Justificación:** Seleccionado para pilas grandes con un caos masivo (> 50%). Es la estrategia más consistente para la prueba de 500 números.
* **Estrategia:** Clasifica los números procesando sus índices bit a bit, desde el bit menos significativo al más significativo. Al espiar cada columna binaria, los números con bit 0 se envían temporalmente a B y los que tienen bit 1 se quedan en A. Al regresarlos, los ceros se apilan de forma natural encima de los unos. Su rendimiento es matemáticamente predecible y no le afecta el caos inicial.

---

## 🚀 Instrucciones

### Compilación e Instalación
El proyecto incluye un script de compilación automatizado Makefile compatible con los estándares de la Escuela 42.

```bash
# Clonar el repositorio e ingresar a la carpeta
git clone https://github.com
cd push_swap

# Compilar el programa principal
make
```

### Ejecución Básica
El programa recibe como argumentos la lista de enteros únicos que componen el Stack A:

```bash
./push_swap 4 67 3 87 23
```

### Uso del Modificador de Modo y Benchmark
Este desarrollo cuenta con una arquitectura de instrumentación que permite forzar un comportamiento o auditar su rendimiento mediante flags especiales pasados por consola antes de la lista de números:

* **Elegir algoritmo manualmente:**
  ```bash
  ./push_swap --simple 5 2 8 1     # Fuerza Selection Sort
  ./push_swap --medium 90 23 12 ... # Fuerza Chunk Sort
  ./push_swap --complex 45 12 ...   # Fuerza Radix Sort
  ```

* **Activar el sistema de Benchmark:**
  Al usar el flag `--bench`, el programa imprimirá por la salida de error estándar (stderr) un informe estadístico detallado con el porcentaje inicial de caos, la estrategia adoptada, el coste Big-O y el desglose de movimientos exactos realizados:
  ```bash
  ./push_swap --bench 4 67 3 87 23
  ```

---

## 📚 Recursos

### Referencias Clásicas
* **Tutorial de Push_swap y listado de operaciones:** 42 Cursus Guide - Push_swap
* **Análisis de Algoritmos por Bloques:** A y B Stack Partitioning Techniques for Sorting
* **Visualizador del proyecto:** push_swap_visualizer de o-reo

### Uso de Inteligencia Artificial (IA)
En el desarrollo de este proyecto se ha utilizado Inteligencia Artificial con fines didácticos, de auditoría estructural y depuración de código en las siguientes áreas:
* **Análisis de casos límite en listas enlazadas:** Se empleó para auditar las mutaciones manuales de los punteros top y bottom en base_operations.c, asegurando que operaciones críticas como base_reverse_rotate respondan sin desincronizaciones de memoria ante stacks mínimos de exactamente 2 elementos.
* **Refactorización anti-leaks en el Parser:** Utilizada para depurar el bucle de validación en check_dups dentro de argv_num_checker.c, aislando los flags personalizados de benchmark de la entrada numérica pura de argumentos.
