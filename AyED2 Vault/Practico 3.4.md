****![[Pasted image 20240710221409.png]]
1)
- Llamada principal: 
- Denominaciones d_1…. d_n
- Dar cambio por un monto total k
- cambio(n+1,k+1) (le pones el 0 más adelante)
- En esta versión, “cambio” es una sola recursión que considera todas las posibles  monedas de una denominación fija (incluido cantidad cero)

Ejemplo d_1 = 25, d_2 = 50
cambio(2,200) = min( q en 0, 1, 2, 3, 4 = j / d_2 )

- Tabla a llenar: 
Es una tabla n * k.
Esta tabla se llena de arriba hacia abajo si o si, pq usamos el valor de i-1 siempre.
Se puede llenar de izquierda a derecha o  viceversa mientras sea de arriba a abajo
Las filas corresponden a las monedas y su denominación
Las columnas corresponden a el valor del cambio a dar

fun cambio(d : array[1..n] of nat, k : nat) ret r : nat  
  var cam: array[0..n,0..k] of nat  // n+1 filas, k+1 columnas  
  for i := 0 to n do cam[i, 0] := 0 od  
  for j := 1 to k do cam[0, j] := inf od  
  for i := 1 to n do               # llenamos cada fila  
    for j := 1 to k do             # en fila i, llenar columnas  
      min_cam := inf  
      for q := 0 to (j % d[i]) do  
        min_cam := min(min_cam, q + cam[i-1, j-q*d[i]])  
      od  
      cam[i, j] := min_cam  
    od  
  od  
  r := cam[n, k]  
end fun

Versión con cálculo de la solución:
fun cambio( d: array[1..n] of nat, k: Nat ) ret r: List of nat
{- variables -}
    var cam: array[0..n,0..k] of nat
    var solucion:  array[0..n,0..k] of (List of nat)
    var aux_min: nat
{- casos base -}
    for i := 0 to n do cam[i,0] := 0, solucion[i,0] := empty_list() od
    for j := 0 to n do cam[0,j] := inf, {- no hay solución -} od
{- casos recursivos -}
    for i := 1 to n do
         for j := 1 to k do
            var aux_min := inf
            for q := 0 to j / d[i] do
                if q + cam[i-1, j-q*d[i]] < aux_min then
                    aux_min := q + cam[i-1, j-q*d[i]]
                    q_min := q
                fi
            od
            cam[i,j] := aux_min
{- quiero poner q veces d[i] para el q elegido y además todos los elementos de la solución[i-1,j-q*d[i]] -}
            if aux_min < infinito then
                solución[i,j] := armar_solucion(q_min, d[i], solución[i-1, j-q*d[i]])
            fi
        od
    od
{- resultado: llamada principal cam[i,j] ≡ cambio[i,j] para todo i,j-}
{- y solución[i,j] tiene la solución correspondiente-}
    r := copy_list(solución[n,k]) {- si no hay solución, no hay nada -}
    for i := 0 to n do
        for j := 0 to k do
            if tabla[i,j] < infinito then
                destroy_list(solución)
            fi
        od
    od
end fun

fun armar_solucion(q: nat, d: nat, sol_ant: List of nat)
    ret sol: List of nat
{- copia la solución anterior y agregamos q monedas de denominación d (podria ser q = 0) -}
    sol := copy_list(sol_ant)
    for i:= 1 to n do
        addr(sol, d)
    od
end fun

![[Pasted image 20240710221417.png]]
2) De abajo hacia arriba no es posible, ya que siempre revisamos el elemento anterior en las columnas. De derecha a izquierda si es posible

fun cambio(d : array[1..n] of nat, k : of nat)  ret r : List of nat  
          var tabla : array[0..n,0..k] of nat  
          var solucion : array[0..n,0..k] of (List of nat)  
          var mimin, q_min : nat  
  {- casos base -}  
      for i := 0 to n do  
          tabla[i, 0] := 0  
           solucion[i, 0] := empty_list()  
     od  
      for j := k to 1 do  
          tabla[0, j] := infinito  {- no hay solucion -}  
      od  
  {- caso recursivo -}  
     for i := 1 to n do  
         for j := k to 1 od  
      {- acá hay que calcular un min con varios q posibles -}  
            mimin := infinito  
            for q := 0 to (j / d[i]) do  
                 if q + tabla[i-1, j-q*d[i]] < mimin:  
                     mimin :=  q + tabla[i-1, j-q*d[i]]  
                     q_min := q  
                  fi
            od  
            tabla[i, j] := mimin  
{- quiero poner q veces d[i] para el q elegido,  
        y ademas los elementos de solucion[i-1,j-q*d[i]]. -}  
            if mimin < infinito then  
                 solucion[i, j] := armar_solucion(q_min, d[i], solucion[i-1,j-q_min*d[i]])  
            fi  
        od  
      od  
  {-  ahora, tabla[i, j] = cambio(i, j) para todo i, j  -}  
  {-  y solucion[i, j] tiene la solucion correpondiente -}  
      if tabla[n, k] < infinito then  
        r := copy_list(solucion[n, k])  
      fi  
      {- si no hay solucion no sabemos qué se devuelve -}  
{- ACÁ FALTA LIBERAR MEMORIA!! -}  
      for i := 0 to n do  
         for j := k to 0 do  
              if tabla[i, j] < infinito then  
               destroy_list(solucion)  
          fi  
       od  
     od  
end fun  

fun armar_solucion(q: nat, d: nat, sol_ant: List of nat)  
                  ret sol: List of nat  
  {- copiamos la solucion anterior y agregamos q monedas de  
    denomiacion d (podría ser q=0) -}  
  sol := copy_list(sol_nat)  
  for i := 1 to q do  
    addr(sol, d)  
  od  
end fun  


![[Pasted image 20240710221426.png]]
3-a)
- Llamada principal: 
- Denominaciones d_1…. d_n
- Dar cambio por un monto total k
- cambio(n+1,k+1) (le pones el 0 más adelante)

- En esta versión, “cambio” tiene una sola recursión
- si j > 0, entonces para todo i’ desde 1,2,....,i me quedo con la mínima denominación anterior a i tq se cumpla  di’ ≤  j, es decir siempre que haya algo para dar cambio, vamos a utilizar las monedas con menor valor posible menor igual a j. No restamos la cantidad de monedas, sabemos que i’ es la moneda con menor denominación que podemos pagar, así que continuamos pagando con esa.
- Ejemplo d_1 = 25, d_2 = 50 cambio(2,200) = min( i en 0, 1, 2 ) nos da 8 (usamos 8 veces la moneda de 25)
- Tabla a llenar: 
- Es una tabla n * k.
- Esta tabla se llena de izquierda a derecha, ya que nuestro caso base es la columna 0
- Se puede llenar desde abajo o desde arriba, no estamos mirando la anterior fila, si no que estamos viendo la fila con el i tq d[i] sea el mínimo que cumpla d[i] ≤ j


| i,j | 0   | 1   | 2   | 3   | k   |
| --- | --- | --- | --- | --- | --- |
| 0   | 0   | inf | inf | inf | inf |
| 1   | 0   |     |     |     |     |
| 2   | 0   |     |     |     |     |
| 3   | 0   |     |     |     |     |
| n   | 0   |     |     |     |     |

fun cambio(d: array[1..n] of nat, k : nat) ret res : nat
      var cambio : array[0...n,0..k] of nat
      var aux_min : nat
      {-caso base-}
      for i = 0 to n do cambio[i,0] = 0 od
      {-caso recursivo-}
      for i = 1 to n do
         for j = 1 to k do
             aux_min = inf
             for i´ = 1 to i do 
                 if (d[i´] <= j) then
                     aux_min = min( aux_min, 1 + cambio[i´, j - d[i´]])
                 fi
             od
            cambio[i,j] = aux_min
          od
     od
     res = cambio[n,k]
end fun

b)
- El algoritmo se basa en la idea general del algoritmo original solo que enves de recorrer la la “lista” de denominaciones de derecha a izquierda 0, …, n lo hace al revés, es decir, desde n, n-1, n-1,...,0
    
- Esto nos dice que la tabla se completa de derecha a izquierda y desde abajo hacia arriba, puesto que los casos bases están en i = n y j = 0
    

| i       j | 0   | 1   | 2   | 3   | k   |
| --------- | --- | --- | --- | --- | --- |
| 0         | 0   |     |     |     |     |
| 1         | 0   |     |     |     |     |
| 2         | 0   |     |     |     |     |
| n         | 0   | inf | inf | inf | inf |


- La llamada principal es cambio(n,k) y su solución se encuentra en la tabla en la posición cam[0,k]
- La llamada recursiva es cambio(i,j)

fun cambio(d: array[1..n] of nat, k : nat) ret res : nat
      var cambio : array[0...n,0..k] of nat
      var aux_min : nat
      {-casos base-}
      for i = 0 to n do cambio[i,0] = 0 od
      for j = 1 to k do camio[i,0] = inf od
      {-casos recursivos-}
      for i = n-1 downto 0 do
         for j = 1 to d[i]-1 do
            if (j < d[i]) then
                cambio[i,j] = cambio[i+1,j]
             else 
                cambio[i,j] = min(cambio[i+1,j],1 +cambio[i,j-d[i]]
             fi
          od
     od
     res = cambio[0,k]
end fun

![[Pasted image 20240710221443.png]]
4-3) factura(i,h) = “el máximo importe posible que puedo generar con la harina disponible haciendo algunos pedidos entre 1 e i, de manera tal que su costo de harina sea menor o igual a h” 
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

La tabla se completará de arriba hacia abajo 

| i       h | 0   | 1   | 2   | 3   | H   |
| --------- | --- | --- | --- | --- | --- |
| 0         | 0   | 0   | 0   | 0   | 0   |
| 1         | 0   |     |     |     |     |
| 2         | 0   |     |     |     |     |
| n         | 0   |     |     |     |     |
fun factura(h : array[1...n], m : array[1..n] of nat, H : nat) ret res : nat
     var fac : array[0...n,0...H] of nat
     {-caso base-}
     for i = 0 to n do fac[i,0] = 0 od
     for h1 = 1 to H do fac[0,h] = 0 od
     {-casos recursivos-} 
     for i = 1 to n do 
         for h1 = 1 to H do 
             if h[i] > h1 then
                 fac[i,h1] = fac[i-1,h1]
             else 
                 fac[i,h1] = max(fac[i-1,h1], m[i] + fac[i-1,h1-h[i]])
             fi
         od
      od
      res = fac[n,H]
end fun

versión con los pedidos que hago
fun factura(h : array[1...n], m : array[1..n] of nat, H : nat) ret res : List of nat
     var fac : array[0...n,0...H] of nat
     var solucion : array[0...n, 0..H] of List of nat
     res = empty_list()
     {-caso base-}
     for i = 0 to n do
         fac[i,0] = 0
         solucion[i,0] = empty_list()
    od
     for h1 = 1 to H do
         fac[0,h] = 0
         solucion[0,h] = empty_list()
     od
     {-casos recursivos-} 
     for i = 1 to n do 
         for h1 = 1 to H do 
             if h[i] > h1 then
                 fac[i,h1] = fac[i-1,h1]
                 solucion[i,h1] = solucion[i-1,h1]
             else 
                 fac[i,h1] = max(fac[i-1,h1], m[i] + fac[i-1,h1-h[i]])
                 if (fac[i-1,h1] > m[i] + fac[i-1,h1-h[i]]) then
                     solucion[i,h1] = solucion[i-1,h1]
                 else 
                     solucion[i,h1] = copy_list(solucion[i-1,h1 - h[i]], solucion[i,h1])
                     addr(solucion[i,h1], i)
             fi
         od
      od
      res = fac[n,H]
end fun

--------------------------------------------------------------------------
4)definiré una función  
  
globo(i,p) = “el menor valor posible que puedo perder tirando algunos objetos entre 1 e i, de manera tal que el peso que tiro sea mayor o igual a p”  
  
“llamada” a la función que resuelve el problema del ejercicio.

globo(n,P) -> retorna minimo valor

- Definamos la función 

globo(i,p)   | si p <= 0         ----> 0  
              | si p > 0 && i = 0   ----> infinito
              | si p > 0 && i > 0   ---->  
                                               -- probemos tirarlo
                                                min(vi + globo(i-1, p-pi),
                                               -- probemos NO tirarlo 
                                                globo(i-1,p))

La tabla se completará de arriba hacia abajo 

| i       p | 0   | 1   | 2   | 3   | H   |
| --------- | --- | --- | --- | --- | --- |
| 0         | 0   | inf | inf | inf | inf |
| 1         | 0   |     |     |     |     |
| 2         | 0   |     |     |     |     |
| n         | 0   |     |     |     |     |
fun globo(p1 : array[1...n] of nat, v : array[1..n] of nat, P : nat) ret res : nat
     var tabla : array[0...n,0...P] of nat
     {-caso base-}
     for i = 0 to n do tabla[i,0] = 0 od
     for p = 1 to P do tabla[0,p] = inf od
     {-casos recursivos-} 
     for i = 1 to n do 
         for  p  = 1 to P do 
             tabla[i,p] = min(tabla[i-1,p], v[i] + tabla[i-1,p-p1[i]])
         od
      od
      res = tabla[n,P]
end fun

--------------------------------------------------------------------------
5)definiré una función  
  
rataColuda(d) = “la mayor ganancia posible que puedo obtener prestandole el telefono a mis amigos”  
  
“llamada” a la función que resuelve el problema del ejercicio.

rataColuda(d) -> mayor ganancia

- Definamos la función 

rataColuda(d)    | si ParaTodo pi < d   ----> 0
                 | si no 
                                               -- probemos prestarlo
                                          max(maximo_{i tal que p_i = d}(mi*(ri-pi+1) + rataColuda(ri +1)),
                                               -- probemos NO prestarlo 
                                                rataColuda(d+1))
La tabla se completará de abajo hacia arriba 

| d   |     |
| --- | --- |
| 0   |     |
| 1   |     |
| 2   |     |
| n   | 0   |
fun rataColuda(p:array[1...n]of nat,r:array[1..n]of nat,m:array[1..n]ofnat,ultima_partida:nat,ultimo:nat)
             ret res:nat
     var tabla : array[0...ultimo] of nat
     var max_gano : nat
     {-caso base-}
     for d= ultima_partida+1 to ultimo do
         tabla[i] = 0
     od
     {-casos recursivos-} 
     for d = ultima_partida downto 0 do 
           max_gano = 0
           for i = 1 to n do
             if (p[i] = d)  then  
                max_gano = max(max_gano, m[i] * (r[i] - p[i] + 1) + tabla[r[i]+1])
             fi
          od
         tabla[d] = max(tabla[d+1], max_gano)
      od
      res = tabla[0]
end fun

versión con los amigos a los que les presto
fun rataColuda(p:array[1...n]of nat,r:array[1..n]of nat,m:array[1..n]ofnat,ultima_partida:nat,ultimo:nat)
             ret res: List of nat
     var tabla : array[0...ultimo] of nat
     var max_gano : nat
     res = empty_list()
     {-caso base-}
     for d= ultima_partida+1 to ultimo do
         tabla[i] = 0
     od
     {-casos recursivos-} 
     for d = ultima_partida downto 0 do 
           max_gano = 0
           for i = 1 to n do
             if (p[i] = d)  then  
                max_gano = max(max_gano, m[i] * (r[i] - p[i] + 1) + tabla[r[i]+1])
             fi
          od
         tabla[d] = max(tabla[d+1], max_gano)
      od
      res = tabla[0]
end fun
nose

--------------------------------------------------------------------------
6)definiré una función  
  
artesania(i,ma,mb) = “la mayor ganancia posible que puedo obtener preparando productos”  
  
“llamada” a la función que resuelve el problema del ejercicio.

artesania(n, MA,MB) -> mayor ganancia

- Definamos la función 

artesania(i,ma,mb)    | si  i = 0   ----> 0   
                     | si  i > 0 && ai>ma o bi>mb ----> artesania(i-1,ma,mb)
                     | si  i > 0 && ai<=ma y bi<=mb 
                                               -- probemos prepararlo
                                                max(vi + artesania(i-1,ma-ai, mb-bi),
                                               -- probemos NO prepararlo 
                                                 artesania(i-1,ma,mb))

La tabla se completará de arriba hacia abajo 

i = 0

| ma      mb | 0   | 1   | 2   | 3   | MB  |
| ---------- | --- | --- | --- | --- | --- |
| 0          | 0   | 0   | 0   | 0   | 0   |
| 1          | 0   | 0   | 0   | 0   | 0   |
| 2          | 0   | 0   | 0   | 0   | 0   |
| MA         | 0   | 0   | 0   | 0   | 0   |
i >0
nada definido

| ma      mb | 0   | 1   | 2   | 3   | MB  |
| ---------- | --- | --- | --- | --- | --- |
| 0          |     |     |     |     |     |
| 1          |     |     |     |     |     |
| 2          |     |     |     |     |     |
| MA         |     |     |     |     |     |

fun artesania(a:array[1...n] of nat, b: array[1..n] of nat, v : array[1...n] of nat MA : nat, MB) ret res : nat
     var tabla : array[0...n, 0...MA, 0...MB] of nat
     {-caso base-}
     for i = 0 to MA do 
        for j = 0 to MB do
            tabla[0,i,j] = 0 
         od
      od
     {-casos recursivos-} 
     for k = 1 to n do 
         for i = 0 to MA do
             for j = 0 to MB do 
                if (a[k] > MA or b[k] > MB) then
                    tabla[k,i,j] = tabla[k-1,i,j]
                 else
                     tabla[k,i,j] = max(tabla[k-1,i,j], v[k] + tabla[k-1, i- a[k], j - b[k])
                fi    
              od
         od  
    od
    res = tabla[n,MA,MB]
end fun

--------------------------------------------------------------------------
7)definiré una función  
  
doble_mochila(i,m1,m2) = “el maximo valor posible que puedo obtener metiendo objetos en mis 2 mochilas”  
  
“llamada” a la función que resuelve el problema del ejercicio.

doble_mochila(n, W1, W2) -> mayor valor

- Definamos la función 

doble_mochila(i, m1, m2)   
| si  i = 0   ----> 0   
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
La tabla se completará de arriba hacia abajo 

i = 0

| m1      m2 | 0   | 1   | 2   | 3   | W2  |
| ---------- | --- | --- | --- | --- | --- |
| 0          | 0   | 0   | 0   | 0   | 0   |
| 1          | 0   | 0   | 0   | 0   | 0   |
| 2          | 0   | 0   | 0   | 0   | 0   |
| W1         | 0   | 0   | 0   | 0   | 0   |
i >0
nada definido

fun doble_mochila(w:array[1..n]of nat,v:array[1..n]of nat,W1:nat,W2:nat)ret res:nat
     var tabla : array[0...n, 0...W1, 0...W2] of nat
     {-caso base-}
     for i = 0 to W1 do 
        for j = 0 to W2 do
            tabla[0,i,j] = 0 
         od
      od
     {-casos recursivos-} 
     for k = 1 to n do 
         for i = 0 to W1 do
             for j = 0 to W2 do 
                 if i == 0 and j == 0 then  
                         tabla[k, 0, 0] := 0
                 else if (w[k] > i or w[k] > j) then
                    tabla[k,i,j] = tabla[k-1,i,j]
                 else if (w[k] <= i and w[k] > j) then
                     tabla[k,i,j] = max(tabla[k-1,i,j], v[k] + tabla[k-1, i - w[k], j])
                 else if (w[k]> i and w[k] <= j) then
                     tabla[k,i,j] = max(tabla[k-1,i,j], v[k] + tabla[k-1, i, j - w[k]])
                 else if (w[k] <= i and w[k] <= j) then
                     tabla[k,i,j]=max(tabla[k-1,i,j],v[k]+tabla[k-1,i-w[k],j],v[k]+tabla[k-1,i,j-w[k]])
                fi    
              od
         od  
    od
    res = tabla[n,W1,W2]
end fun

VERSION CON OBJETOS Y MOCHILas
             
fun doble_mochila(w:array[1..n]of nat,v:array[1..n]of nat,W1:nat,W2:nat)ret res: List of List of nat 
     var tabla : array[0...n, 0...W1, 0...W2] of nat
     var solucion : array[0...n,0...W1,0...W2] of array[0..n] of List of nat
     {-caso base-}
     for k = 0 to n do
         for i = 0 to W1 do
             for j = 0 to W2 do
                 solucion[k,i,j] = empty_list()
              od
         od
     od 
     for i = 0 to W1 do 
        for j = 0 to W2 do
            tabla[0,i,j] = 0 
         od
      od
     {-casos recursivos-} 
     for k = 1 to n do 
         for i = 0 to W1 do
             for j = 0 to W2 do 
                if (w[k] > i or w[k] > j) then
                    tabla[k,i,j] = tabla[k-1,i,j]
                    solucion[k,i,j] = solucion[k-1,i,j]
                 else if (w[k] <= i and w[k] > j) then
                     tabla[k,i,j] = max(tabla[k-1,i,j], v[k] + tabla[k-1, i - w[k], j])
                     if(tabla[k-1,i,j] >= v[k] + tabla[k-1, i - w[k], j])
                        solucion[k,i,j] = solucion[k-1,i,j]
                     else 
                         solucion[k,i,j] = copy_list(solucion[k-1,i,j])
                         addr(solucion[k,i,j], k)
                         addr(solucion[k,i,j], k)
                     fi
                 else if (w[k]> i and w[k] <= j) then
                     tabla[k,i,j] = max(tabla[k-1,i,j], v[k] + tabla[k-1, i, j - w[k]])
                 else if (w[k] <= i and w[k] <= j) then
                     tabla[k,i,j]=max(tabla[k-1,i,j],v[k]+tabla[k-1,i-w[k],j],v[k]+tabla[k-1,i,j-w[k]])
                fi    
              od
         od  
    od
    res = tabla[n,W1,W2]
end fun
me rindo
--------------------------------------------------------------------------
8)definiré una función  
  
autito(i,j) = “Menor costo de fabricar el auto desde la estación j en la línea i, hasta la estación n, en alguna de las dos líneas”  
  
“llamada” a la función que resuelve el problema del ejercicio.

min ( autito(1,1) , autito(2,1) ) -> mayor valor

- Definamos la función 

autito(i, j)   
| si  j = n   ----> ain   
| si j < n y i = 1----> a1j + min( autito(1,j+1), t1j + autito(2,j+1))
| si j < n y i = 2 --> a2j + min( autito(2,j+1), t2j + autito(1,j+1))

La tabla se completará de derecha a izquierda 

| i      j | 1   | 2   | 3   | 4   | n   |
| -------- | --- | --- | --- | --- | --- |
| 1        |     |     |     |     |     |
| 2        |     |     |     |     |     |

fun autito(a1:array[1..n]of nat,a2:array[1..n] of nat,t1:array[1..n]of nat,t2:array[1..n] of nat)ret res:nat
     var tabla : array[1..2, 0..n] of nat
     {-caso base-}   
     {-casos recursivos-} 
     for i = 1 to 2 do
         for j = n downto 1 do 
             if (i = 1 and j < n) then
                tabla[i,j] = a1[j] + min(autito(1,j+1), t1[j] + autito[2,j+1])
            else if (i = 2 and j < n)
                 tabla[i,j] = a2[j] + min(autito(2,j+1), t2[j] + autito[1,j+1])
            else if (j = n and i = 1)
                 tabla[i,j] = a1[j]
            else if (j = n and i = 2)
                 tabla[i,j] = a2[j]
            fi
    od
    res = min(tabla[1,1], tabla[2,1])
end fun

--------------------------------------------------------------------------
9)definiré una función  
  
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

La tabla se completará de derecha a izquierda 

| j     i | 1   | 2   | 3   | 4   | n   |
| ------- | --- | --- | --- | --- | --- |
| 1       |     |     |     |     |     |
| 2       |     |     |     |     |     |
| 3       |     |     |     |     |     |
| n       |     |     |     |     |     |
puede estar medio para el orto pq yo re boluda ayer decidi hacer todo al reves 

fun tablero(c :array[1..n,1..n]of nat )ret res:nat
     var tabla : array[1..n, 1..n] of nat
     {-caso base-}   
     {-casos recursivos-} 
     for j = 1 to n do      nose en cual de los dos iba eldownto me canse
         for i = 1 to n do 
             if (j < n and i > 1 and i < n) then
                tabla[j,i] = c[j,i] + max(tablero[j+1,i], tablero[j+1,i+1], tablero[j+1,i-1])
            else if (j < n and i = 1)
                 tabla[j,1] = c[j,1] + max(tablero[j+1,1], tablero[j+1,2])
            else if (j < n and i = n)
                 tabla[j,n] = c[j,n] +max(tablero[j+1,n], tablero[j+1,n-1])
            else if (j = n)
                 tabla[n,i] = c[n,i]
            fi
    od
    res = max( tablero(1,1) , tablero(1,2)...., tablero(1,n) )
end fun

fin