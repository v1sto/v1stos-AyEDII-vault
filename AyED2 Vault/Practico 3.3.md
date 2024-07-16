![[Pasted image 20240710221200.png]]
1)
//CODIGO ORIGINAL
fun cambio(j : Nat, C: Set of Nat) ret S : Nat 
     var c : Nat 
     var C_aux : Set of Nat 
     if j = 0 then 
          S := 0 
     else if is_empty(C) then 
          S := ∞ 
     else 
         C_aux:= set_copy(C)
         c := get(C)
         elim(C_aux,c)
          if (c ≤ j) then 
               S := min(1+cambio(j-c,C),cambio(j,C_aux)) 
          else 
           S := cambio(j,C_aux) 
           f i 
           set_destroy(C_aux) 
     f i 
end fun

//CAMBIADO
type Plata = tuple 
          cantidad : nat
          monedas : List of nat
           end tuple
           
fun cambio(j : Nat, C: Set of Nat) ret S : Plata
     var c : Nat 
     var C_aux : Set of Nat 
     if j = 0 then 
          S := 0 
     else if is_empty(C) then 
          S.cantidad := ∞ 
          S.monedas = empty_list()
     else 
         C_aux:= set_copy(C)
         c := get(C)
         elim(C_aux,c)
          if (c ≤ j) then
                if  (1+cambio(j-c,C).cantidad < cambio(j,C_aux).cantidad) then 
                     addr(S.monedas, c)
                     concat(S.monedas, cambio(j-c,C).monedas)
                     S.cantidad = cambio(j-c,C).cantidad + 1
                else
                    S = cambio(j,C_aux)
                fi
          else 
           S := cambio(j,C_aux) 
           f i 
           set_destroy(C_aux) 
     f i 
end fun

![[Pasted image 20240710221210.png]]
 2)
68 = 23 + 23 + 23 y pierdo 1 -> 3
74 = 29 + 29 + 23 y pierdo 7 -> 3
83 = 29 + 29 + 29 y pierdo 4 -> 3
88 = 29 + 29 + 23 + 15 y pierdo 8 -> 4
89 =29 + 29 + 23 + 15 y pierdo 7 -> 4
compro el de 68 y utilizo 3 monedas de 23

![[Pasted image 20240710221224.png]]
3)
- El enunciado:
- n pedidos con importes m1,m2,....,mn y requieren h1,h2,...,hn harina.
- H es la cantidad de harina en buen estado que nos queda en el deposito.

Determinar el MAXIMO importe total que es posible obtener con la harina disponible.

- Antes de resolverlo, pensemos un ejemplo.
    
4 pedidos  
m1= 3   h1= 10
m2= 5   h2= 8
m3= 2   h3=9
m4= 3   h4=6
H = 15

tengo que probar TODAS las combinaciones
- horneo 1-> ganancia 3 
- horneo 2 y 4-> ganancia 8
- horneo 3 y 4 -> ganancia 5
    
 Nos quedamos con la que cumple con el criterio óptimo, en este caso, con la opción que tiene valor de ganancia máximo. O sea  
Hornear 2 y 4, ganando 8 pesos.

Ahora sí, resolvamos el problema con un algoritmo recursivo.
- Identifiquemos qué parámetros toma la función recursiva, y qué calcula en función de esos parámetros. IMPORTANTE: el algoritmo deberá obtener el MAYOR importe a ganar, pero no qué facturas horneo.

definiré una función  
  
factura(i,h) = “el máximo importe posible que puedo generar con la harina disponible haciendo algunos pedidos entre 1 e i, de manera tal que su costo de harina sea menor o igual a h”  
  
“llamada” a la función que resuelve el problema del ejercicio.

factura(n,H) -> retorna mi ganancia

- Definamos la función 

factura(i,h) | si h = 0 o i = 0             ----> 0  
              | si i > 0, h > 0, hi > h    ----> factura(i-1,h)
              | si i > 0, h > 0, hi <= h  ---->  
                                               -- probemos hornear la factura  
                                                max( mi + factura(i-1,h-hi),  
                                               -- probemos NO hornear la factura 
                                                factura(i-1,h) )

Testeo "rápido" con:
1- h = 6 -> m = 6
2- h = 4 -> m = 4
3- h = 10 -> m = 8
H = 12

factura(3,12)
max(  8  + <u>factura(2, 2)</u>, factura(2, 12))

max( 8 + 0, <u>factura(2, 12)</u>)

max( 8 , max(4  + <u>factura(1, 8)</u>, factura(1, 12)))

max( 8, max(4 + max(6 + <u>factura(0, 2)</u>, <u>factura(0, 8)</u>), factura (1, 12)))

max( 8, max( 4 + <u>max( 6 + 0, 0)</u>), <u>factura(1,12)</u>)

max( 8, max(<u>4+6</u>, max(6 + <u>factura(0,6)</u>, <u>factura(0,12)</u>))) 

max ( 8, max(10, max(6+0,0)))

max ( 8, max(10, 6))

10

![[Pasted image 20240710221235.png]]

4)
 - El enunciado:
- n objetos con pesos p1,p2,....,pn y valores v1,v2,...,vn.
- P es la cantidad de peso minima que debemos tirar para llegar sanos.

Determinar el MENOR valor total que es necesario arrojar para llegar sanos y salvos.

- Antes de resolverlo, pensemos un ejemplo.
    
4 objetos
p1= 3   v1= 10
p2= 5   v2= 8
p3= 2   v3=9
p4= 3   v4=6
P = 7

tengo que probar TODAS las combinaciones
- tiro todo. pierdo 13 kilos de peso y 33 puntos
- no tiro nada. no pierdo peso y conservo 33 puntos pero el globo se cae
- tiro 1,2. pierdo 8kg y 19 puntos
- tiro 1,3,2. pierdo 10kg y 27 puntos
- tiro 1,3,4. pierdo 8kg y 25 puntos
- tiro 1,4,2. pierdo 11kg y 24 puntos
- tiro 2,3. pierdo 7kg y 17 puntos
- tiro 2,4. pierdo 8kg y 14 puntos
 Nos quedamos con la que cumple con el criterio óptimo, en este caso, con la opción que tiene valor de perdida minimo. O sea
 Tirar 2,4. pierdo 8kg y 14 puntos

Ahora sí, resolvamos el problema con un algoritmo recursivo.
- Identifiquemos qué parámetros toma la función recursiva, y qué calcula en función de esos parámetros. IMPORTANTE: el algoritmo deberá obtener el MENOR numero de puntos que es necesario perder, pero no qué objetos tiro.

definiré una función  
  
globo(i,p) = “el menor valor posible que puedo perder tirando algunos objetos entre 1 e i, de manera tal que el peso que tiro sea mayor o igual a p”  
  
“llamada” a la función que resuelve el problema del ejercicio.

globo(n,P) -> retorna minimo valor

- Definamos la función 

globo(i,p)   | si p <= 0         ----> 0  
              | si p > 0 && pi = 0   ----> infinito
              | si p > 0 && pi > 0   ---->  
                                               -- probemos tirarlo
                                                min(vi + globo(i-1, p-pi),
                                               -- probemos NO tirarlo 
                                                globo(i-1,p))

Testeo "rápido" con:
p1 = 2
p2 = 4
p3 = 10
P = 8

globo(3,8)

min(v3 + globo(2, -2), globo(2, 8))

min(v3, globo(2, 8))

min(v3, min(v2 + globo(1, 4), globo(1, 8)))

min(v3, min(v2 + min(v1 + globo(0, 2), globo(0, 4)), globo(1, 8)))

min(v3, min(v2 + min(v1 + inf, inf), globo(1, 8)))

min(v3, min(inf, globo(1, 8))

min(v3, min(inf, min(v1 + globo(0, 6), globo(0,8)))

min(v3, min(inf, min(v1 + inf, inf))

min(v3, min(inf, inf))

min(v3, +infinito) 

v3

![[Pasted image 20240710221243.png]]
5)
- El enunciado:
- n amigos con partidas p1,p2,....,pn, regresos r1,r2,...,rn y montos m1....mn.

Determinar el MENOR valor total que es necesario arrojar para llegar sanos y salvos.

- Antes de resolverlo, pensemos un ejemplo.
    
4 amigos
p1= 4   r1= 7    m1 = 5
p2= 8   r2= 12    m2 = 7
p3=10  r3= 15     m3 = 4
p4= 3   r4=10   m4 = 3

tengo que probar TODAS las combinaciones
- presto a 1,2 . Gano 4x5 + 5x7 = 55
- presto a 1,3 . Gano 4x5 + 6x4 = 44
- presto a 4 . Gano 8x3 = 24
 Nos quedamos con la que cumple con el criterio óptimo, en este caso, con la opción que tiene valor de ganancia maximo. O sea
 Prestar a 1,2 . Gano 4x5 + 5x7 = 55

Ahora sí, resolvamos el problema con un algoritmo recursivo.
- Identifiquemos qué parámetros toma la función recursiva, y qué calcula en función de esos parámetros. IMPORTANTE: el algoritmo deberá obtener la MAYOR ganancia posible, pero no a que amigos se lo presto.

definiré una función  
  
rataColuda(d) = “la mayor ganancia posible que puedo obtener prestandole el telefono a mis amigos”  
  
“llamada” a la función que resuelve el problema del ejercicio.

rataColuda(d) -> mayor ganancia

- Definamos la función 

rataColuda(d)   | si noExisteUn ri > d         ----> 0  
                 | si d > 0 && ParaTodo pi > d   ----> rataColuda(d+1)
                 | si d > 0 && ExisteUn pi = d 
                                               -- probemos prestarlo
                                                max(mi*(ri-pi+1) + rataColuda(ri +1),
                                               -- probemos NO prestarlo 
                                                rataColuda(d+1))

Testeo "rápido" con:
**p1=1 r1=2 m1=3  
p2=3 r2=4 m2=2  
p3=4 r3=7 m3=5  
p4=2 r4=8 m4=6  
p5=6 r5=8 m5=8  
p6=4 r6=8 m6=5**

rataColuda(0) =
rataColuda(1) = 
max(2x3 + rataColuda(3), rataColuda(2)) =
max(2x3 + max(2x2 + rataColuda(5), rataColuda(4)), max(7x6 + rataColuda(9), rataColuda(3)))) =
max(2x3 + max(2x2+rataColuda(6),max(4x5+rataColuda(8),rataColuda(5), 5x5 + rataColuda(9))),max(7x6 , rataColuda(3)))=
max(2x3 + max(2x2 + 3x8, max(4x5, 3x8, 5x5)), max(7x6, rataColuda(3)))
max(2x3 + max(28, 25), max(7x6, 28))
max(6 + 28, 42)
42

![[Pasted image 20240710221308.png]]
6)
- El enunciado:
- materia prima de dos tipos: A y B. 
- Dispone de una cantidad MA y MB de cada una de ellas. 
- n productos p1,p2,....,pn con valores de venta v1,v2,....,vn y requiere para su elaboración cantidades  a1,a2,...,an   de materia A y b1,b2,...,bn  de materia B 
-  determinar el mayor valor (ganancia) alcanzable con las cantidades de materia prima disponible
- Antes de resolverlo, pensemos un ejemplo.
4 pedidos  
p1 =  a1= 7    b1= 6     v1= 10
p2 =  a2= 6   b2= 4     v2= 8
p3 =  a3= 6    b3= 5     v3=9
p4 =  a4= 3    b4= 3      v4=6
MA = 15   MB= 13
tengo que probar TODAS las combinaciones
- no preparo nada. Tengo 0 de ganancia, peor opción 
-  1            ,   2            -> ganancia 18
- MA=8,MB=7  MA=2,MB=3
-  2            ,   3            ,   4          -> ganancia 23
- MA=9,MB=9   MA=3,MB=4    MA=0,MB=1
-  2            ,   3            -> ganancia 17
- MA=9,MB=9   MA=3,MB=4    
- … voy a obviar las que son hacer 1 solo producto, (las ganancias en cada caso son el v del p)
- 3                 ,  4         -> ganancia 15
- MA=9,MB=8  MA=6,MB=5

Nos quedamos con la que cumple con el criterio óptimo, en este caso, con la opción que tiene ganancia máxima. O sea  
2, 3, 4 -> ganancia 23

Ahora sí, resolvamos el problema con un algoritmo recursivo.
- Identifiquemos qué parámetros toma la función recursiva, y qué calcula en función de esos parámetros. IMPORTANTE: el algoritmo deberá obtener la MAYOR ganancia posible, pero no qué productos preparo.

definiré una función  
  
artesania(i,ma,mb) = “la mayor ganancia posible que puedo obtener preparando productos”  
  
“llamada” a la función que resuelve el problema del ejercicio.

artesania(n, MA,MB) -> mayor ganancia

- Definamos la función 

artesania(i,ma,mb)    | si  i = 0 o ma y mb = 0  ----> 0   
                     | si  i > 0 && ai>ma o bi>mb ----> artesania(i-1,ma,mb)
                     | si  i > 0 && ai<=ma y bi<=mb 
                                               -- probemos prepararlo
                                                max(vi + artesania(i-1,ma-ai, mb-bi),
                                               -- probemos NO prepararlo 
                                                 artesania(i-1,ma,mb))

Testeo "rápido" con:
p1 =  a1= 7    b1= 6     v1= 10
p2 =  a2= 6   b2= 4     v2= 8
p3 =  a3= 6    b3= 5     v3=9
p4 =  a4= 3    b4= 3      v4=6
MA = 15   MB= 13

artesania(4,15,13) =
max(6 + <u>artesania(3,12,10)</u>, artesania(3,15,13))

max(6 + max(9 + <u>artesania(2,6,5)</u>, artesania(2,12,10), artesania(3,15,13))

max(6 + max(9 + max(8 + <u>artesania(1,0,1)</u>, <u>artesania(1,6,5)</u>), artesania(2,12,10), artesania(3,15,13))

max(6 + max(9 + max(8, <u>artesania(0,6,5)</u>), artesania(2,12,10)), artesania(3,15,13))

max(6 + max(9 + 8, <u>artesania(2,12,10)</u>), artesania(3,15,13))

max(6 + max(9 + 8, max(8 + <u>artesania(1,6,6)</u>, <u>artesania(1,12,10)</u>)), artesania(3,15,13))

max(6 + max(9 + 8, max(8, 10), <u>artesania(3,15,13)</u>)

max(6 + <u>max(17 , 10)</u>, max(9 + <u>artesania(2,9,8)</u>, artesania(2,15,13))

max(<u>6 + 17</u>, max(9 + <u>max(8, 10)</u>, <u>artesania(2,15,13)</u>)

max(23, max(19, max(8 + 10, 10))

max(23, max(19,18))

23

![[Pasted image 20240710221319.png]]
7)
- El enunciado:
- dos mochilas con capacidad W1 y W2.  
- n objetos o1,o2,....,on con valores v1,v2,....,vn y pesos w1...wn. 
-  determinar el mayor valor alcanzable al seleccionar objetos para cargar en ambas mochilas

- Antes de resolverlo, pensemos un ejemplo.

tengo que probar TODAS las combinaciones
- 

Nos quedamos con la que cumple con el criterio óptimo, en este caso, con la opción que tiene ganancia máxima. O sea  
2, 3, 4 -> ganancia 23

Ahora sí, resolvamos el problema con un algoritmo recursivo.
- Identifiquemos qué parámetros toma la función recursiva, y qué calcula en función de esos parámetros. IMPORTANTE: el algoritmo deberá obtener la MAYOR ganancia posible, pero no qué productos preparo.

definiré una función  
  
doble_mochila(i,m1,m2) = “el maximo valor posible que puedo obtener metiendo objetos en mis 2 mochilas”  
  
“llamada” a la función que resuelve el problema del ejercicio.

doble_mochila(n, W1, W2) -> mayor valor

- Definamos la función 

doble_mochila(i, m1, m2)   
| si  i = 0 o (m1=0 y m2 = 0)  ----> 0   
| si   i > 0 y (m1 < wi y m2 < wi) ----> doble_mochila(i-1,m1,m2)
| si i > 0 y (m1<wi y m2>=wi)-->max(vi + doble_mochila(i-1,m1,m2-wi), doble_mochila(i-1,m1,m2))
| si i >0 y (m2<wi y m1 >= wi)--> max(vi + doble_mochila(i-1,m1,m2-wi), doble_mochila(i-1,m1,m2)
| si   i >0 y (wi<=m1 y wi<=m2) 
                                               -- probemos meterlo en la mochila w1
                                                  max(vi + doble_mochila(i-1,m1-wi,m2),
                                               -- probemos meterlo en la mochila w1
                                                    vi + doble_mochila(i-1,m1,m2-w2),
                                               -- probemos NO meterlo en ninguna mochila
                                                     doble_mochila(i-1, m1, m2))
												 

Testeo "rápido" con:
Espacio W1 = 19
Espacio W2 = 12

1)Lápiz(8,5) 
2)Papel(11,6)
3)Tijera(12,7)

doble_mochila(3,19,12) =
max(7 + <u>artesania(2,7,12)</u>, 7 + artesania(2,19,0), doble_mochila(2,19,12))

max(7 + max(6 + <u>artesania(1,7,1)</u>, <u>artesania(1,7,12)</u>), 7 + artesania(2,19,0), doble_mochila(2,19,12))

max(13 , 7 + <u>artesania(2,19,0)</u>, doble_mochila(2,19,12))

max(13 , 7 + max( 6 +<u> artesania(1,8,0)</u>, <u>artesania(1,19,0)</u>), doble_mochila(2,19,12))

max(13 , 7 + max( 6 + 5, 5),<u> doble_mochila(2,19,12)</u>)

max(13 , 18, max(6 + artesania(1,8,12), 6 + artesania(1,19,0), artesania(1,19,12)))

max(13 , 18, max(6 + 5, 6 + 5, 5))

max(13,18,11)

18

![[Pasted image 20240710221330.png]]
8)
- El enunciado:
- dos lineas de ensamblaje E1 y E2.  
-  cada una tiene n estaciones de trabajo, S11...S1n y S21...S2n. 
-  dos estaciones S1i y S2i (para i=1..n) hacen el mismo trabajo con distintos costos a1i y a2i.
- para fabricar un auto pasamos por n estaciones de trabajo no necesariamente de la misma linea
- transferir el auto de una linea a otra cuesta tij

definiré una función  
  
autito(i,j) = “Menor costo de fabricar el auto desde la estación j en la línea i, hasta la estación n, en alguna de las dos líneas”  
  
“llamada” a la función que resuelve el problema del ejercicio.

min ( autito(1,1) , autito(2,1) ) -> mayor valor

- Definamos la función 

autito(i, j)   
| si  j = n   ----> ain   
| si j < n y i = 1----> a1j + min( autito(1,j+1), t1j + autito(2,j+1))
| si j < n y i = 2 --> a2j + min( autito(2,j+1), t2j + autito(1,j+1))
												 

![[Pasted image 20240710221347.png]]

definiré una función  
  
tablero(i,j) = “Mejor puntaje al empezar en el casillero (columnas,filas)[i,j] hasta que j = n”  
  
“llamada” a la función que resuelve el problema del ejercicio.

max( tablero(1,1) , tablero(1,2)...., tablero(1,n) ) -> mayor valor

- Definamos la función 

tablero(i, j)   
| si  j = n   ----> cin   
| si  j < n  y i > 1 y i < n
                                               -- probemos ir arriba
                                                  cij + max( tablero(i,j+1),
                                               -- probemos ir a la izquierda
                                                    tablero(i+1,j+1),
                                               -- probemos ir a la derecha
                                                     tablero(i-1,j+1))
| si  j < n  y i = 1
                                               -- probemos ir arriba
                                                  cij + max( tablero(1,j+1),
                                               -- probemos ir a la izquierda
                                                    tablero(2,j+1))
| si  j < n  y i = n
                                               -- probemos ir arriba
                                                  cij + max( tablero(n,j+1),
                                               -- probemos ir a la derecha
                                                    tablero(n-1,j+1))


![[Pasted image 20240714001743.png]]