[[Algoritmos de ordenación]]

![[Pasted image 20240706182240.png]]

1-a)  **proc** cero (in/**out** a:**array**[1..n] **of nat**)
      var i = 1
      do (i <= n)
          a[i]= 0
          i = i+1
      od
     **end proc**
 b) **proc** natpos (in/**out** a:**array**[1..n] **of nat**)
       var i = 1
       **do** (i<= n)
         a[i] = i
         i = i + 1
       **od**
    **end proc**
c) **proc** natimp (in/**out** a:**array**[1..n] **of nat**)
       var i = 1
       **do** (i<= n)
         a[i] = (i * 2) - 1
         i = i + 1
       **od**
    **end proc**
d) **proc** impincr (in/**out** a:**array**[1..n] **of nat**)
       var i = 1
       **do** (i<= n)
         a[i] = a[i] + 1
         i = i + 2
       **od**
    **end proc**
    ****
![[Pasted image 20240706184248.png]]

2-a)  **proc** cerofor (in/**out** a:**array**[1..n] **of nat**)
      for i = 1 to n do
          a[i]= 0
      od
     **end proc**
 b) **proc** natposfor (in/**out** a:**array**[1..n] **of nat**)
       for i = 1 to n do
         a[i] = i
       **od**
    **end proc**
c) **proc** natimpfor (in/**out** a:**array**[1..n] **of nat**)
       for i = 1 to n do
         a[i] = (i * 2) - 1
       **od**
   **end proc**
d) **proc** impincrfor (in/**out** a:**array**[1..n] **of nat**)
      for i = 1 to n do
        if (i mod 2 == 1) then
            a[i] = a[i] + 1
         fi
       **od**
   **end proc**

![[Pasted image 20240706184753.png]]

3) **fun is_ord (in a:array**[1..n] **of nat**) **ret** b:**bool**
      b := True
	  for i = 1 to n-1 do
         b = b && a[i] <= a[i+1] 
       **od**
   **end proc**
 El algoritmo verifica si el arreglo dado está ordenado de menor a mayor.
 Lo hace recorriendo el arreglo desde la primera posición hasta la posición n-1 y verificando si el primer elemento es menor a su siguiente y así con todos los elementos del mismo.

![[Pasted image 20240706185954.png]]

4-a) Ordenación por selección 
     [7, <font color="#ff0000">1</font>, 10, 3, 4, 9, 5]
     [<font color="#76923c">1</font>, 7, 10, 3, 4, 9, 5]
     [<font color="#76923c">1</font>, 7, 10, <font color="#c00000">3</font>, 4, 9, 5]
     [<font color="#76923c">1</font>, <font color="#76923c">3</font>, 10, 7, 4, 9, 5]
     [<font color="#76923c">1</font>, <font color="#76923c">3</font>, 10, 7, <font color="#c00000">4</font>, 9, 5]
     [<font color="#76923c">1</font>, <font color="#76923c">3</font>, <font color="#76923c">4</font>, 7, 10, 9, 5]
     [<font color="#76923c">1</font>, <font color="#76923c">3</font>, <font color="#76923c">4</font>, 7, 10, 9, <font color="#c00000">5</font>]
     [<font color="#76923c">1</font>, <font color="#76923c">3</font>, <font color="#76923c">4</font>, <font color="#76923c">5</font>, 10, 9, <font color="#c00000">7</font>]
     [<font color="#76923c">1</font>, <font color="#76923c">3</font>, <font color="#76923c">4</font>, <font color="#76923c">5</font>, <font color="#76923c">7</font>, <font color="#76923c">9</font>, <font color="#76923c">10</font>]

![[Pasted image 20240706190642.png]]
[[OPS]]
5-a) 
ops(t=0) + ops(for i=1 to n do (...))
1 + ops( **Σ** i=1..n  ops (**Σ** j=1..n^2 ops(**Σ** k=1..n^3 ops(t = t+1))))
1 + ops( **Σ** i=1..n  ops(**Σ** j=1..n^2 ops(**Σ** k=1..n^3 1)))
1 + ops( **Σ** i=1..n  ops(**Σ** j=1..n^2 n^3)
1 + ops( **Σ** i=1..n  n^2 * n^3) 
1 + n^6 

b)
ops(t=0) + ops(for i=1 to n do (...))
1 + ops(**Σ** i=1..n  ops(**Σ** j=1..i ops(**Σ** k=j..j+3 ops(t = t+1))))
1 + ops(**Σ** i=1..n  ops(**Σ** j=1..i ops(**Σ** k=j..j+3 1))
1 + ops(**Σ** i=1..n  ops(**Σ** j=1..i 4)
1 + ops(**Σ** i=1..n  4i)
1 + ops(4 * **Σ** i=1..n i)
1 + 4 * (n * n+1)/2
1 + 2 * (n * n +1)

![[Pasted image 20240706193559.png]]

6)  La fun f obtiene el índice del mayor elemento del arreglo 
    El proc p ordena un arreglo de una forma similar a selection sort pero empezando desde el final del arreglo

    proc inv_selection_sort (in/out a:array[1..n] of T)
      var x: nat
      for i = n downto 2 do
         x = f(a,i)
         swap(a,i,x)
        od
    end proc

    fun max_indice (a: array[1..n] of T, i: nat) ret x: nat
      max = 1
      for j = 2 to i do
         if a[j] > a[max] then max=j fi
     od
   end fun

![[Pasted image 20240706195451.png]]

7) Ordenación por inserción  
     [<font color="#76923c">7</font>, <font color="#c00000">1</font>, 10, 3, 4, 9, 5]
     [<font color="#76923c">1</font>, <font color="#76923c">7</font>, 10, <font color="#c00000">3</font>, 4, 9, 5]
     [<font color="#76923c">1</font>,<font color="#76923c"> 7</font>, <font color="#c00000">3</font>, 10, 4, 9, 5]
     [<font color="#76923c">1, 3</font>, 7, 10, <font color="#c00000">4</font>, 9, 5]
     [<font color="#76923c">1, 3,</font> <font color="#76923c">7,</font> <font color="#c00000">4</font>, 10, 9, 5]
     [<font color="#76923c">1, 3, 4, 7, 10</font>, <font color="#c00000">9</font>, 5]
     [<font color="#76923c">1, 3, 4, 7, 9, 10</font>, <font color="#c00000">5</font>]
     [<font color="#76923c">1, 3, 4, 7, 9</font>, <font color="#c00000">5</font>, 10]
     [<font color="#76923c">1, 3, 4, 7,</font> <font color="#c00000">5,</font> 9, 10]
     [<font color="#76923c">1, 3, 4, 5, 7, 9, 10</font>]

![[Pasted image 20240706200340.png]]
   8-a) 

| n   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| t   | 1   | 2   | 4   | 4   | 8   | 8   | 8   | 8   | 16  | 16  | 16  |
| ops | 1   | 2   | 3   | 3   | 4   | 4   | 4   | 4   | 5   | 5   | 5   |

Observemos:
- cual es la relación entre t  y ops?    t = 2^(ops - 1). despejando, ops = log_2(t) + 1
- cuál es la relación entre n y t? son proporcionales, crecen al mismo ritmo: n ~ t (t es la potencia de 2 más chica tal que es >= n)
- ops ~ log_2(n)

b)  

| n   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| t   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  |
| ops | 2   | 3   | 3   | 4   | 4   | 4   | 4   | 5   | 5   | 5   | 5   |

Observemos:
- cual es la relación entre t  y ops?   
- cuál es la relación entre n y t? son proporcionales, crecen al mismo ritmo: n ~ t 
- ops ~ 

![[Pasted image 20240706203156.png]]

9)    b := True
	  for i = 1 to n-1 do
         b = b && a[i] <= a[i+1] 
      **od**
   ops(b=true) + ops(for i=1 to n-1 do ...)
   0 + **Σ** i=1..n-1 (ops(b = b && a[i] <= a[i+1]))
    **Σ** i=1..n-1 (ops(b = b && a[i] <= a[i+1]))
    **Σ** i=1..n-1 1
     n-1

![[Pasted image 20240706203805.png]]

10) El proc r intercambia de lugar 2 elementos del arreglo en caso de que no estén ordenados.
    El proc q recorre el arreglo y aplica r en cada iteración, lo que hace que el arreglo se ordene.
     Es un insertion sort al revés
    proc insertion_sort (in/out a:array[1..n] of T)
      for i = n-1 downto 1 do
         r(a,i)
        od
    end proc 

    proc inv_insert (in/out a: array[1..n] of T, in i: nat)
     var j: nat
     j = i
     do j < n ^ a[j] > a[j+1] -> 
        swap(a,j+1,j)
        j = j+1 
     od
    end proc
