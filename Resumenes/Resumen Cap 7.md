# Sorting

## Insertion sort
Insertion es uno de los métodos más sencillos para ordenar datos.
### Algoritmo
```
1. void Insertion_sort(int* t)
{
	int i, j;
	int actual;
    
    for (i = 1; i < 20; i++) {
	    actual = t[i];
         for (j = i; j > 0 && t[j - 1] > actual; j--) {
	         t[j] = t[j - 1];
	         }
	     t[j] = actual;
	}
}
```
Aquí tenemos una función para ordenar un arreglo de 20 elementos. 
En lo que consiste insertion es en tomar el elemento del índice 1 (el segundo elemento del arreglo) y compararlo con el anterior, si el elemento anterior es mayor al actual, el elemento actual se inserta un, el elemento actual ocupa la posición del anterior, así recorre el arreglo hasta que se da el caso en el que el elemento anterior es menor al elemento actual. Cuando eso sucede, el elemento actual se queda en el lugar que está. Una vez terminado el proces, se repite pero esta vez con el siguiente elemento (relativo a la posición original del elemento que se acaba de mover)

Este proceso se repite hasta que todos los elementos del arreglo han sido comparados y acomodados en su respectivo lugar.
### Complejidad Temporal y espacial
Podemos ver que en el código tenemos dos ciclos anidados, por lo que la complejidad temporal de insertion sort es cuadrática $O(n^2)$

En cambio si hablamos de la complejidad espacial, esta es lineal $O(n)$ . Ya que no requerimos memoria adicional para guardar datos externos que no se nos den por el arreglo.

### Cuando usar insertion sort
Debido a la complejidad temporal cuadrática podría ser tentador usar un método diferente, pero insertion sort funciona bien principalmente en dos casos, el primero es cuando la lista de elementos es pequeña, incluso puede ser de un tamaño moderado si también se cumple la siguiente condición y esa es que la lista no esté muy desordenada.


## Shellsort
Shellsort es un algoritmo un poco más complicado, en cuanto a complejidad se verá muy parecido a insertion pero tienen sus pequeñas diferencias.

### Algoritmo
```
void tri_insertion(int* t, int gap, int debut)
{
    int j,en_cours;
    for (int i = gap + debut; i < 20; i+=gap) {
        en_cours = t[i];
        for (j = i; j >= gap && t[j - gap] > en_cours; j-=gap) {
            t[j] = t[j - gap];
        }
        t[j] = en_cours;
    }
}
 
void tri_shell(int* t) {
    int intervalles[5]={6,4,3,2,1};
    for (int ngap=0;ngap<5;ngap++) {
        for (int i=0;i<intervalles[ngap];i++)
            tri_insertion(t,intervalles[ngap],i);
    }
}
```
Shell sort funciona de la siguiente manera: primero se define una *gap* o brecha, y se realizarán comparaciones entre cada dato que coincida en esa brecha.

Por ejemplo, tenemos un arreglo de 10 elementos y una brecha de 5. Nos quedarían los elementos asignados de esta manera:
![[Pasted image 20231119112815.png]]
Por lo que vemos que se formaron parejas entre el 5 y7, 8 y9, 2 y3, etc. Ahora lo que hacemos es comparar si el elemento de la izquierda es menor que el de la derecha, en caso de que sea menor así se quedan los elementos, en caos de que sea mayor los elementos cambian de lugar. 
Por ejemplo 5<7 por lo tanto estos elementos se quedan así, pero cómo 6<3 no se cumple 6 y 3 cambiana de lugar. Esto se repite hasta que no haya ningún intercambio de lugar.

Una vez que se recorre el arreglo y no hubo intercambios, la brecha se reduce a la mitad, en este caso 5/2 = 2.5 pero lo tomaremos cómo dos. Ahora la brecha es de dos y repetimos el mismo proceso de comparar. Esto se hace hasta que la brecha es 1, y se vuelve a recorrer el arreglo hasta que no haya cambios, una vez el arreglo se recorre con brecha 1 y no hubo cambios, significa que el arreglo está ordenado.
### Complejidad Temporal y espacial
La complejidad temporal y espacial son las mismas que en insert. Con una complejidad temporal de $O(n^2)$ y una complejidad espacial lineal $O(n)$ 

### Cuando usar shellsort
Debido a la complejidad similar entre insert y shellsort podríamos pensar que no importa cuál elegir, pero básicamente shellsort es para usarse en casos que son un poco complicados para manejarse con insert, pero que no son tan complicados cómo para que valga la pena usar un método más complejo cómo mergesort o quicksort.

## Heapsort
Heapsort se basa en acomodar árboles binarios, al estar basado en árboles binarios ya sabemos que nos ayudará con la complejidad temporal.

### Análisis
```
#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(std::vector<int>& arr) {
    int n = arr.size();

    // Construir el heap (reorganizar el vector)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

```
Heapsort consiste en tomar el elemento más grande del arreglo, colocarlo en la posición 0 y después intercambiar el valor de la posición 0 (que ahora es el valor más grande del arreglo) con el valor en la última posición. A este proceso se le llama heapify.
Este proceso se repite ahora con el valor más grande pero excluyendo la última posición (ya que este elemento ya está ordenado) y así se repite, cada vez agarrando el valor más grande, excluyendo la parte ordenada del arreglo.

Ejemplo:
Tenemos el siguiente arreglo: 2, 8, 5, 3, 9, 1

Tomamos el valor más grande (9) y lo intercambiamos con el valor en la posición 0, por lo que ahora tenemos 9, 8, 5, 3, 2, 1. Y ahora cambiamos de lugar el elemento de posición 0 con el de posición 5 y tenemos: 1, 8, 5, 3, 2, 9.

Repetimos el proceso pero ahora excluyendo la parte ordenada, el elemento más grande es 8, nos quedaría 8,1,5,3,2,9. cambiamos de lugar 8 con el último elemento de la parte no ordenada y queda 2,1,5,3,8,9.
Y este proceso se repite hasta que nos queda el arreglo ordenado: 1,2,3,5,8,9.

### Complejidad Temporal y espacial
Debido a su comportamiento relacionado con los árboles bináiros sabemos que heapsort tiene una complejidad temporal de $O(nlogn)$. Su complejidad espacial al igual que los métodos anteriores es lineal $O(n)$ ya que no requiere memoria adicional.

### Cuando usar Heapsort
Si no es necesario que el algoritmo sea estable (es decir, si no importa el orden relativo de elementos iguales). También es muy útil en estructuras de tipo árbol.

## Mergesort
Merge sort es un algoritmo que se basa en dividir un arreglo y acomodarlo por secciones

### Algoritmo
```
#include 
using namespace std;

// Merge function to merge two sorted arrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// Recursive Merge Sort function to sort the array
void recursiveMergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid + 1, right);
    int leftArr[mid - left + 1], rightArr[right - mid];
    for (int i = 0; i <= mid - left; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < right - mid; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    merge(arr, leftArr, mid - left + 1, rightArr, right - mid);
}
```
Lo primero que se hace en merge sort es dividir el arreglo a la mitad (lo más exacto posible). Después tomamos la mitad izquierda y otra vez lo dividimos, hacemos esto hasta que nos queden dos arreglos de un dato cada uno, ejemplo:
![[Pasted image 20231119131359.png]]
Una vez hecho esto volvemos a juntar los datos ahora en orden, en este caso 5 y 1 regresan cómo 1 y 5. Procedemos a hacer lo mismo con el otro lado, dividiendo y ordenando 6 y 7 (en este caso ya están ordenados).
Ahora con los dos arreglos de dos ordenados, los regresamos al arreglo de 4, poniéndolos en orden. Para hacer esto, tomamos el valor más pequeño de ambos arreglos, los comparamos y el más pequeño entra al arreglo grande, repetimos esto hasta introducir todos los datos ordenados.
Nos queda lo siguiente:
![[Pasted image 20231119131647.png]]
Después hacemos el mismo proceso en la otra mitad hasta tenerla ordenada y quedaría de esta manera: 
![[Pasted image 20231119131748.png]]
Ahora con las dos mitades ordenadas haremos lo mismo para terminar de acomodar el arreglo. Hacemos el mismo proceso de tomar los datos más pequeños de ambos arreglos y compararlos, metiendo el más pequeño y repitiendo el proceso hasta que metamos todos los datos al arreglo, con esto quedarán de manera ordenada.
Resultado final
![[Pasted image 20231119132121.png]]

### Complejidad espacial y temporal
Debido a que merge sort divide el arreglo para trabajar con datos más pequeños, eso nos da una complejidad temporal de $O(nlogn)$, y al no requerir memoria adicional, su complejidad espacial es lineal $O(n)$, requiere un poco de memoria para almacenar los arreglos más pequeños, pero al no ser copias y trabajar dentro del mismo arreglo su complejidad no sube y se mantiene constante.

### Cuando usar merge sort
Merge sort funciona bien para trabajar con arreglos de datos grandes, debido a la facilidad que le brinda su complejidad temporal, Pero es importante considerar tener un poco de memoria adicional para el proceso, ya que a pesar de que no utiliza tanta memoria cómo para subir de complejidad lineal, si puede utilizar un poco más de memoria que otros métodos. Así que cuando hay muchos datos y memoria un poco de sobra, merge sort es buena opción.

## Quicksort
La característica principal de quicksort es que este método utiliza un pivote, el pivote es un elemento que utilizaremos para acomodar los demás y para cuando terminamos de usar un pivote, este ya se encuentra en su posición final, es decir que todos los elementos a su izquierda son más pequeños y todos los elementos a su derecha son más grandes.

### Algoritmo
```
#include <iostream>
using namespace std;
 
int partition(int* arr, int start, int end)
{   
      // assuming last element as pivotElement
    int index = 0, pivotElement = arr[end], pivotIndex;
    int* temp = new int[end - start + 1]; // making an array whose size is equal to current partition range...
    for (int i = start; i <= end; i++) // pushing all the elements in temp which are smaller than pivotElement
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
 
    temp[index] = pivotElement; // pushing pivotElement in temp
    index++;
 
    for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
  // all the elements now in temp array are order : 
  // leftmost elements are lesser than pivotElement and rightmost elements are greater than pivotElement
               
     
     
    index = 0;
    for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
    {   
        if(arr[i] == pivotElement)
        {
              // for getting pivot index in the original array.
              // we need the pivotIndex value in the original and not in the temp array
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex; // returning pivotIndex
}
 
void quickSort(int* arr, int start, int end)
{  
    if(start < end)
    {   
        int partitionIndex = partition(arr, start, end); // for getting partition
        quickSort(arr, start, partitionIndex - 1); // sorting left side array
        quickSort(arr, partitionIndex + 1, end); // sorting right side array
    }
    return;
}
```
Lo primero que tenemos que hacer es tomar un pivote y moverlo al final del arreglo. Después tenemos que buscar dos datos diferentes, el primero es el primer dato que sea más grande que el pivote, contando de izquierda a derecha. Y el segundo es el primer elemento que sea más pequeño que el pivote, ahora contando de derecha a izquierda.
Ejemplo:
![[Pasted image 20231119140553.png]]
El 3 es nuestro pivote que ya está colocado al final, y vemos que el elemento de la izquierda (más grande que el pivote) fue 6 y el elemento de la derecha (más pequeño que el pivote) fue uno. Ahora lo que tenemos que hacer es intercambiar estos valores de lugar

Repetimos este proceso hasta que el dato de la derecha, tenga una posición menor que el dato de la izquierda, el resultado es el siguiente:
![[Pasted image 20231119140833.png]]
Procedemos a cambiar el item de la izquierda con el pivote, esto dejará al pivote en su posición correcta. y nos dejará dos arreglos más pequeños a la derecha y a la izquierda del pivote.
![[Pasted image 20231119141046.png]]

Finalmente lo que sigue sería repetir el proceso con los arreglos más pequeños, el arreglo de 2,1,0 y el de 8,7,6,5. Al terminar el arreglo estará acomodado.
### Cómo elegir un pivote
El pivote que elijamos es muy importante, ya que queremos un pivote que divida el arreglo a la mitad, o lo más cercano posible.

Podríamos elegir un número al azar y podría funcionar, pero un método más seguro es el de la media de tres. Tomamos tres elementos, el primero, el de en medio y el último. Los acomodamos en orden y el elemento de en medio será nuestro pivote.

### Complejidad temporal y espacial
En le caso de quick sort la complejidad temporal puede variar mucho, se ve muy afectada por la buena o mala elección del pivote, ya que en el peor de los casos puede ser cuadrada $O(n^2)$ pero en mejores casos puede bajar hasta $O(nlogn)$. Caso similar la complejidad espacial ya que no genera nuevos datos pero la recursividad puede llenar un poco el espacio, así que la complejidad puede ir desde  $O(logn)$ hasta $O(n)$

### Cuando usar quick sort
En general es bueno implementar quick sort cuando se quiera trabajar con conjuntos de datos grandes y se busque un buen rendimiento. Su eficiencia promedio hace que sea bueno incluso para aplicaciones en tiempo real.



## Ordenamientos de tiempo lineal: 
### Bucket sort 
```
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{
 
    // 1) Create n empty buckets
    vector<float> b[n];
 
    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
 
        // Index in bucket
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
```
Bucket sort es una manera de usar otros métodos de ordenamiento, consiste en tomar elementos de un arreglo y meterlos en distintas cubetas o *buckets* para una vez tenerlas dentro, ordenar cada cubeta individualmente mediante algún otro método de ordenamiento.
Para separa en la cubeta es ideal que el arreglo tenga un orden conocido y podamos agrupar números que tengan algo en común. Por ejemplo en números del 10 al 100 podemos agrupar en cubetas de cada decimal, o por ejemplo si queremos  ordenar un mazo de cartas podemos separar en los 4 palos. Esto para realizar las distribuciones de manera uniforme entre los datos.

#### Complejidad temporal y espacial
Su complejidad temporal es de $O(n+k)$ donde *k* es el número de buckets que utilicemos, pero esto es sólo cuando los elementos se distribuyen de manera uniforme entre los *buckets* y cada *bucket* se ordena de manera eficiente, por ejemplo, usando un algoritmo como Insertion Sort. Cuando se falla en hacer esto, su complejidad temporal puede resultar en cuadrada $O(n^2)$.
Y en cuanto a su complejidad espacial esta es de $O(n+k)$, ya que se requiere memoria adicional para almacenar los *buckets* y los datos que contiene.

### Radix sort
```
void countsort(int arr[],int n,int place)
{
        int i,freq[range]={0};         //range for integers is 10 as digits range from 0-9
        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--)
        {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}
void radixsort(ll arr[],int n,int maxx)            //maxx is the maximum element in the array
{
        int mul=1;
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
}
```
El método de radix consiste en lo siguiente. Imaginemos que tenemos el siguiente arreglo: 62, 35, 56, 16.
Tomamos un arreglo de listas enlazadas de 10 posiciones, y cada elemento del arreglo original va a entrar en el índice que le corresponde dependiendo de su primer digito. el 62 va en el índice 2, el 35 en índice 5 y así. Nos queda lo siguiente
![[Pasted image 20231120111615.png]]
Vemos que al ser listas enlazadas el 5 y el 16 pueden ocupar el mismo espacio. Después de esto recorremos los índices y colocamos en el arreglo los datos cómo los vayamos encontrando, el nuevo arreglo quedaría: 62, 3, 35, 56, 16.

Repetimos el mismo proceso pero en lugar de fijarnos en la unidad esta vez nos fijamos en el decimal, nos quedaría de esta manera.
![[Pasted image 20231120111836.png]]
Una vez más recorremos el arreglo, acomodando los números como los encontramos y vemos que el arreglo ya estaría acomodado, el resultado sería 3, 16, 35, 56, 62.

#### Complejidad temporal y espacial
La complejidad temporal es $O(d⋅(n+k))$ donde *n* es el número de elementos, *k* es el rango de los elementos (por ejemplo, el rango de valores posibles de los dígitos), y *d* es el número de dígitos en el número más largo. La complejidad temporal es lineal en relación con la longitud del número más largo y el número total de elementos.
Mientras que la complejidad temporal es $O(n+k)$ al igual que en bucket sort.

Hay que tomar en cuenta que la complejidad temporal de radix sort depende mucho de *d*. uno de los escenarios donde sería más eficiente, es ordenando números enteros positivos.
## Ordenamiento externo
Todos los algoritmos vistos hasta ahorita hacen uso de la memoria interna, pero puede haber casos en los que se reciban tantos datos que no se pueda utilizar la memoria. Para eso están los algoritmos de ordenamiento externos, que no hacen uso de la memoria. Estos se utilizan justamente para cuando se reciben inputs de datos muy grandes.

### Porque usar nuevos algoritmos

### Modelo para ordenamiento externo
Estps algoritmos funcionan en cintas, que, son probablemente el medio de almacenamiento más restrictivo. Dado que el acceso a un elemento en la cinta es. Esto se hace enrollando la cinta en la ubicación correcta. Dos métodos que utilizan cintas son el multiway merge y el polyphase merge

# Conclusiones
Es fácil ver porque para nosotros los programadores es importante conocer los métodos de ordenamiento, no importa el área de programación es muy probable que vayamos a estar trabajando con datos. Usar estos métodos para poder acceder de manera ordenada a nuestros datos y poder entenderlos mejor, será clave para realizar un mejor trabajo y ser más eficientes.

# Opinión crítica
me gustaría una mejor aclaración de cuando conviene o no usar heapsort, ya que me pareció muy buen método. Y en general tratar de ver ejemplos más prácticos cómo el que vimos en clase de tratar de acomodar un millón de datos con insert y que nunca acabó, pero con los demás algoritmos.
Algo que tampoco entendí muy bien es a que se refiere con que los modelos de ordenamiento trabajan en cinta y me gustaría aclarar bien ese tema.

# Referencias

|   |   |
|---|---|
|[1]|M. A. Weiss, _Data Structures and Algorithm Analysis in C++_, 4a ed. Upper Saddle River, NJ, Estados Unidos de América: Pearson, 2013.|
|[2]|“Algoritmos de ordenamiento”, _Free.fr_. [En línea]. Disponible en: http://lwh.free.fr/pages/algo/tri/tri_es.htm. [Consultado: 19-nov-2023].|
|[3]|ISC3BITSVA, “shell sort metodo de ordenamiento”, 27-nov-2012. [En línea]. Disponible en: https://www.youtube.com/watch?v=MHW-QNd6IUE. [Consultado: 19-nov-2023].|
|[4]|“Merge Sort in C++: Algorithm & Example (with code)”, _FavTutor_. [En línea]. Disponible en: https://favtutor.com/blogs/merge-sort-cpp. [Consultado: 19-nov-2023].|
|[5]|A. Us, “Quick Sort”, _HackerEarth_. [En línea]. Disponible en: https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/visualize/. [Consultado: 19-nov-2023].|
|[6]|“C++ program for QuickSort”, _GeeksforGeeks_, 07-ene-2014. [En línea]. Disponible en: https://www.geeksforgeeks.org/cpp-program-for-quicksort/. [Consultado: 19-nov-2023].|
|[7]|M. Sambol, “Quick sort in 4 minutes”, 14-ago-2016. [En línea]. Disponible en: https://www.youtube.com/watch?v=Hoixgm4-P4M. [Consultado: 19-nov-2023].|
|[8]|“Bucket sort - data structures and algorithms tutorials”, _GeeksforGeeks_, 26-abr-2014. [En línea]. Disponible en: https://www.geeksforgeeks.org/bucket-sort-2/. [Consultado: 20-nov-2023].|
|[9]|A. Sosa, “Ordenamiento Radix Sort”, 03-jun-2012. [En línea]. Disponible en: https://www.youtube.com/watch?v=_Xz3XyKsCaM. [Consultado: 20-nov-2023].|
