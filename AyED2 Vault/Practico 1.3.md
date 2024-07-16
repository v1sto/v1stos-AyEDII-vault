[[Divide y vencerás + complejidades]]
![[Pasted image 20240708000443.png]]

1-a) Tamaño del dato de entrada = n
Operación a contar = asignaciones a t 
Definimos r(n), función que calcula la cantidad de asignaciones a t que ocurren al ejecutar f1 con n.
Vemos que se llama recursivamente a f1, por lo que se trata de divide y vencerás.
r(n)   | 0                                                  n <= 1
    | **Σ** i =1..8 r(n/2) + **Σ** i =1..n^3 1     n > 1
    |  8 * r(n/2) + n^3 
Identificamos a, b, y k
a = 8
b = 2
g(n) = n^3 => k = 3
Como a = b^k => r(n) es del orden n^3 log n

b) Tamaño del dato de entrada = n
Operación a contar = asignaciones a t 
Definimos r(n), función que calcula la cantidad de asignaciones a t que ocurren al ejecutar f1 con n.
Vemos que se llama recursivamente a f1, por lo que se trata de divide y vencerás.
r(n)   | **Σ** i =1..n (**Σ** j =1..i 1)               n <= 0
    | **Σ** i =1..n i                                n <= 0
    | (n * (n+1)) / 2 aprox n^2       n <= 0
    | n^2 +  **Σ** i =1..4 r(n/2)            n > 0
    |  n^2 +  4  * r(n/2)                   n > 0
Identificamos a, b, y k
a = 4
b = 2
g(n) = n^2 => k = 2
Como a = b^k => r(n) es del orden n^2 log n

![[Pasted image 20240708000454.png]]
![[Pasted image 20240708000511.png]]
![[Pasted image 20240708000523.png]]
![[Pasted image 20240708000541.png]]
![[Pasted image 20240708000555.png]]
![[Pasted image 20240708000606.png]]
