**KDTree**
======

![IMAGE](https://github.com/iMawe/EstructuraDatos/blob/master/K-D%20Tree/Files/kdtree.png?raw=true)

- En ciencias de la computación, un Árbol kd (abreviatura de árbol k-dimensional) es una estructura de datos de particionado del espacio que organiza los puntos en un Espacio euclídeo de k dimensiones. 
- Un árbol kd emplea sólo planos perpendiculares a uno de los ejes del sistema de coordenadas.
- Todos los nodos de un árbol kd, desde el nodo raíz hasta los nodos hoja, almacenan un punto.
- La idea es mantener la noción de un árbol binario, pero cortando el espacio usando un solo hiperplano ortogonal. En cada nivel del árbol variamos el eje de corte

Por ejemplo:

En 2 dimensiones en la raíz cortamos perpendicular al eje x; en el siguiente nivel cortamos perpendicular al
eje y, etc.

![IMAGE](https://github.com/iMawe/EstructuraDatos/blob/master/K-D%20Tree/Files/kdtree2.png?raw=true)

Para representar esta estructura, se guarda un nodo por cada corte hecho. Cada nodo tiene 2
hijos. Todos los puntos menores que el punto de corte actual p, de acuerdo al eje discriminado,
se guardan en los hijos de la izquierda, y en los de la derecha los mayores ( si el eje de un punto
es igual a p, se puede insertar en cualquiera de los dos hijos. Esto es para tratar de balancear los
subárboles ). Cuando se llega a un punto o a un número peque~no de puntos (menor o igual al
tama~no del bucket), se almacena en las hojas.

**¿Cómo elegimos el valor de corte?** 

Para un mejor rendimiento, la descomposición del espacio
deberá ser lo más balanceada posible. El método más común utilizado para ello es seleccionar
el valor de corte basado en la mediana del eje de corte. Esto produce un árbol de altura *O*(log n).
Con un procedimiento recursivo se puede construir el árbol en *O*(n log n). El costo más alto es
determinar la mediana del eje.

**Consulta del Vecino más próximo**

Dado un punto de consulta *q*, para buscar el vecino
más práximo primero descendemos por el árbol. Mantenemos un punto candidato a ser el más
práximo *nn* y una distancia de valor máximo *dist*. Para cada nodo visitado revisamos este punto,
actualizándolo en caso necesario.
Luego necesitamos chequear los subárboles. Si *q* está en el lado inferior del hiperplano, nos
vamos a la izquierda, en caso contrario a la derecha. Después de visitar el subárbol izquierdo
hemos modificado el punto candidato *nn* y la distancia a este punto *dist*.

## **Usos KDTree**

**Búsqueda ortogonal en un árbol kd**

Usar un KDTree para encontrar todos los puntos que se encuentran en un rectángulo determinado (o análogo de más dimensiones). Esta operación también se denomina rango de búsqueda ortogonal.

**Determinar dónde evaluar una superficie**
En las regresiones locales es común evaluar la superficie contenida directamente sólo por los vértices del KDTree e interpolar en algún punto. Este uso, reflejado en la imagen de arriba, busca asegurar que sólo se realizarán las evaluaciones directas necesarias. Como los KDTree se "adaptan" al espacio, este método puede suministrar una excelente aproximación a las verdaderas superficies de regresión local. Si la aproximación es pobre, puede mejorarse con más subdivisiones.






















