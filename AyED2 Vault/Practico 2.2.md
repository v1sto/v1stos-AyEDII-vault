[[Constructores y operaciones de TADs]]

![[Pasted image 20240708001508.png]]

1)
spec List of T where:

**constructors**

fun empty() ret l : List of T
{-Crea una lista vacía-}

proc addl(in e: T, in/out l: List of T)
{-Agrega un elemento a la izquierda de la lista-}

**destroy**

proc destroy(in/out l:List of T)
{-Libera memoria en caso de ser necesario-}

**operations**

fun is_empty(l : List of T) ret b : bool 
{- Devuelve True si l es vacía. -} 

fun head(l : List of T) ret e : T 
{- Devuelve el primer elemento de la lista l -} 

{- PRE: not is_empty(l) -}
proc tail(in/out l : List of T) 
{- Elimina el primer elemento de la lista l -}

{- PRE: not is_empty(l) -} 
proc addr (in/out l : List of T,in e : T) 
{- agrega el elemento e al final de la lista l. -}

fun length(l : List of T) ret n : nat 
{- Devuelve la cantidad de elementos de la lista l -}

proc concat(in/out l : List of T,in l0 : List of T)
{- Agrega al final de l todos los elementos de l0 en el mismo orden.-}

fun index(l : List of T,n : nat) ret e : T 
{- Devuelve el n-ésimo elemento de la lista l -}

{- PRE: length(l) > n -}
proc take(in/out l : List of T,in n : nat) 
{- Deja en l sólo los primeros n elementos, eliminando el resto -}

proc drop(in/out l : List of T,in n : nat) 
{- Elimina los primeros n elementos de l -}

fun copy_list(l1 : List of T) ret l2 : List of T 
{- Copia todos los elementos de l1 en la nueva lista l2 -}

end spec

Implement List of T:
type Node of t = Tuple
           elem: T
           next: pointer to (Node of T)
end tuple
type list  of T = pointer to Node of T

fun empty() ret l: list of T{
   l := null
end fun
}

proc addl (in e :T, in/out l : List of T){
   var p : pointer to (Node of T)
   alloc(p)
   p->elem = e
   p->next = l
   l = p
end proc

proc destroy(in/out l:List of T){
    var p : pointer to Node of T
    do 
    if (l != null) then ->
       do (l !=null) ->
        p = l -> next
        free(l)
        l = p
       od
     fi
end proc
}

fun is_empty(l : List of T) ret b : bool {
     b := (l = null)
end fun
}

fun head(l : List of T) ret e : T {
    e = l->elem
end fun
}

{- PRE: not is_empty(l) -}
proc tail(in/out l : List of T){
     var p : pointer to Node of T
     p = l 
     l = l->next
     free(p)
end proc
}

{- PRE: not is_empty(l) -} 
proc addr (in/out l : List of T,in e : T) {
      var p, q : pointer to Node of T  
      alloc(q)
      q->elem = e
      q->next = null 
      if(is_empty(l)) then ->
        l = q
       []->
         p = l 
         do(p->next != null) ->
             p = p->next
        od
         p->next = q 
       fi
end proc
}

fun length(l : List of T) ret n : nat {
     var p : pointer to Node of T
     var i : nat
     i = 0
     p = l
    do (p != null) ->
         p = p->next
         i = i + 1
    od
end fun 
}

proc concat(in/out l : List of T,in l0 : List of T){
     var p: pointer to Node of T
     if (is_empty(l)) then ->
         l = l0
     [] ->
        p = l
        do (p-> next !=null) ->
           p = p->next
        od
        p->next = l0
      fi
end proc
}

{- PRE: length(l) > n -}
fun index(l : List of T,n : nat) ret e : T {
     var p: pointer to Node of T
     p = l
     if (n>1) then ->
        for i = 1 to n-1 do
            p = p->next   
        od
     fi
     e = p->elem
end fun
}

{- PRE: length(l) > n -}
proc take(in/out l : List of T,in n : nat){
      var p : pointer to Node of T
      var i : nat
      if(l !=null) then ->
         if(n=0) then ->
             destroy(l)
         else if(n>0) then ->
             i = 1
             p = l
             do (i<n) ->
                 p=p->next
                 i = i+1
             od
             do(p!=null)
                 a = p
                 p = p->next
                 free(a)
              od
           fi
       fi
end proc            
}

proc drop(in/out l : List of T,in n : nat) {
     var i : nat
     i = 1
     do(i<=n) ->
         tail(l)
         i = i+1
     od
end proc
}

fun copy_list(l1 : List of T) ret l2 : List of T {
     var p : pointer to Node of T
     p = l1
     l2 = empty_list()
     if(not(is_empty(l1))) then ->
        do(p!=null)
            addr(l2, p->elem)
            p = p->next
         od
      fi
end fun
}


![[Pasted image 20240708182410.png]]

2)

Implement List of T:
type List of T = Tuple
           elem : array[1..n] of T
           size : nat
end tuple

fun empty() ret l: list of T{
   l.size = 0
end fun
}

**{- PRE: l.size < N -}**
proc addl (in e :T, in/out l : List of T){
   for i = l.size downto 1 do
     l.elem[i+1] = l.elem[i]
   od
   l.elem[1] = e
   l.size = l.size + 1 
end proc

proc destroy(in/out l:List of T){
    skip
end proc
}

fun is_empty(l : List of T) ret b : bool {
     b := (l.size == 0)
end fun
}

fun head(l : List of T) ret e : T {
    e = l.elem[1]
end fun
}

{- PRE: not is_empty(l) -}
proc tail(in/out l : List of T){
     if (length(l)>1) then ->
        for i = 1 to l.size - 1 do
            l.elem[i] = l.elem[i+1]
        od
     fi
     l.size = l.size - 1
end proc
}

{- PRE: not is_empty(l) -} 
proc addr (in/out l : List of T,in e : T) {
      l.size = l.size + 1
      l.elem[l.size] = e 
end proc
}

fun length(l : List of T) ret n : nat {
     n = l.size
end fun 
}

proc concat(in/out l : List of T,in l0 : List of T){
     for i = 1 to l0.size do ->
         l.elem[l.size +i] = l0.elem[i]
     od
     l.size = l.size + l0.size
end proc
}

{- PRE: length(l) > n -}
fun index(l : List of T,n : nat) ret e : T {
    e = l.elem[n]
end fun
}

{- PRE: length(l) > n -}
proc take(in/out l : List of T,in n : nat){
    l.size = n
end proc            
}

proc drop(in/out l : List of T,in n : nat) {
     var i : nat
     i = 1
     do(i<=n) ->
         tail(l)
         i = i+1
     od
end proc
}

fun copy_list(l1 : List of T) ret l2 : List of T {
     l2 = empty_list()
     l2.size = l1.size
     if(not(is_empty(l1))) then ->
        for i = 1 to length(l1)
             l2.elem[i] = l1.elem[i]
         od
      fi
end fun
}

![[Pasted image 20240708182422.png]]

3) proc add_at(in/out l: List of T, in n: nat, in e : T){
        var l2 : List of T
        l2 = copy_list(l1) 
        drop(l2,n-1)
        addl(l2,e)
        take(l1,n-1)
        concat(l1,l2)
    end proc
   }
   
![[Pasted image 20240708182434.png]]

4-a) 
spec Tablero where:

**constructors**

fun start() ret t : Tablero
{-Crea un tablero vacío-}

proc tanto_A(in/out t: Tablero)
{-Agrega un tanto al equipo A-}

proc tanto_B(in/out t: Tablero)
{-Agrega un tanto al equipo B-}

**destroy**

proc destroy(in/out t:Tablero)
{-Libera memoria en caso de ser necesario-}

**operations**

fun is_init(t: Tablero)ret b: bool
{-Verifica si el tanteador esta en 0-}

fun not_init_A(t: Tablero)ret b: bool
{-Verifica si el equipo A anoto un tanto -}

fun not_init_A(t: Tablero)ret b: bool
{-Verifica si el equipo B anoto un tanto -}

fun A_wins(t:Tablero)ret b: bool
{-Verifica si A esta ganando-}

fun B_wins(t:Tablero)ret b: bool
{-Verifica si A esta ganando-}

fun tie(t:Tablero)ret b: bool
{-Verifica si hay un empate-}

proc score_n_A(in/out t:Tablero ; n : nat)
{- Anota n tantos a A-}

proc score_n_B(in/out t:Tablero ; n : nat)
{- Anota n tantos a B-}

proc punish_n_A(in/out t:Tablero ; n : nat)
{- Resta n tantos a A-}

proc punish_n_B(in/out t:Tablero ; n : nat)
{- Resta n tantos a B-}

end spec

Implement Tablero:
type Tablero = Tuple
           equipoA : counter
           equipoB : counter
end tuple

**constructors**

fun start() ret t : Tablero{
     t.equipoA = init()
     t.equipoB = init()
end fun
}

proc tanto_A(in/out t: Tablero){
     incr(t.equipoA)
end proc
}

proc tanto_B(in/out t: Tablero){
    incr(t.equipoB)
end proc
}

**destroy**

proc destroy(in/out t:Tablero){
     destroy(t.equipoA)
     destroy(t.equipoB)
end proc
}

**operations**

fun is_init_t(t: Tablero)ret b: bool{
    b = is_init(t.equipoA) && is_init(t.equipoB)
end fun
}

fun not_init_A(t: Tablero)ret b: bool{
    b = not(is_init(t.equipoA))
end fun
}

fun not_init_B(t: Tablero)ret b: bool{ 
     b = not(is_init(t.equipoB))
end fun
}
version con copy de tablero
fun A_wins(t:Tablero)ret b: bool{
     t2 = copy_tab(t)
     do(not_init_A(t2) && not_init_B(t2)) ->
         decr(t.equipoA)
         decr(t.equipoB)
       od
       b = not_init_A(t2) && not(not_init_B(t2))
end fun
}
versión con copy pero de counter
fun B_wins(t:Tablero)ret b: bool{
     var a,b : counter
     a = copy_counter(t.equipoA)
     b = copy_counter(t.equipoB)
    do(not(is_init(a)) && not(is_init(b))) ->
         decr(a)
         decr(b)
       od
       b = not(is_init(b)) && is_init(a)
end fun
}

fun tie(t:Tablero)ret b: bool{
     b = not(B_wins(t)) && not(A_wins(t))
end fun
}

proc score_n_A(in/out t:Tablero ; n : nat){
     for i = 1 to n do 
         tantoA(t)
     od
end proc
}

proc score_n_B(in/out t:Tablero ; n : nat){
    for i = 1 to n do 
         tantoB(t)
     od
end proc
}

proc punish_n_A(in/out t:Tablero ; n : nat){
     var t2 : Tablero
     var i : nat
     i = 0
     t2 = copy_tab(t)
     do(not_init_A(t2)) ->
         decr(t2.equipoA)
         i = i + 1
      od
      if(i<=n) then ->
         for j = 1 to i do ->
             decr(t.equipoA)
         od
      [] ->
         for j = 1 to n do ->
             decr(t.equipoA)
         od
      fi
       destroy(t2)
end proc
}

proc punish_n_B(in/out t:Tablero ; n : nat){
 var t2 : Tablero
     var i : nat
     i = 1
     b = true
     do( i <= n && b) ->
         if (is_init(t.equipoB)) then ->
             b = false
         [] ->
             decr(t.equipoB)
         fi
         i = i + 1
      od
end proc
}

b)

Implement Tablero:
type Tablero = Tuple
           equipoA : nat
           equipoB : nat
end tuple

**constructors**

fun start() ret t : Tablero{
     t.equipoA = 0
     t.equipoB = 0
end fun
}

proc tanto_A(in/out t: Tablero){
     t.equipoA = t.equipoA + 1
end proc
}

proc tanto_B(in/out t: Tablero){
     t.equipoB = t.equipoB + 1
end proc
}

**destroy**

proc destroy(in/out t:Tablero){
     skip
end proc
}

**operations**

fun is_init_t(t: Tablero)ret b: bool{
    b = t.equipoA == 0 && t.equipoB == 0
end fun
}

fun not_init_A(t: Tablero)ret b: bool{
     b = t.equipoA != 0
end fun
}

fun not_init_B(t: Tablero)ret b: bool{ 
     b = t.equipoB != 0
end fun
}

fun A_wins(t:Tablero)ret b: bool{
    b = t.equipoA > t.equipoB
end fun
}

fun B_wins(t:Tablero)ret b: bool{
     b = t.equipoB > t.equipoA
end fun
}

fun tie(t:Tablero)ret b: bool{
     b = t.equipoA == t.equipoB
end fun
}

proc score_n_A(in/out t:Tablero ; n : nat){
     t.equipoA = t.equipoA + n
end proc
}

proc score_n_B(in/out t:Tablero ; n : nat){
     t.equipoB = t.equipoB + n
end proc
}

proc punish_n_A(in/out t:Tablero ; n : nat){
    if(n>t.equipoA) then ->
         t.equipoA = 0
    [] ->
         t.equipoA = t.equipoA - n
end proc
}

proc punish_n_B(in/out t:Tablero ; n : nat){
    if(n>t.equipoB) then ->
         t.equipoB = 0
    [] ->
         t.equipoB = t.equipoB - n
end proc
}

![[Pasted image 20240708182445.png]]

5)
spec Conjunto where

constructors

fun vacío() ret c : Conjunto
{- Devuelve el conjunto vacío -}

proc agregar ( in/out c : Conjunto of T, in e : T ) 
{- añade un elemento al conjunto c -}

destroy

proc destroy_con ( in/out c : Conjunto of T )
{- Procedimiento que libera memoria en caso de ser necesario -}

operations

 fun pertenece ( c : Conjunto of T, e : T ) ret b : bool
{- Función que devuelve true si un elemento e está en el conjunto s -}

fun esVacio ( c : Conjunto of T) ret b : bool
{- Función que devuelve true si el conjunto s es vacío -}

proc unir (in/out c : Conjunto of T, in c2 : Conjunto of T )
{- Procedimiento que une el conjunto c al conjunto c2 -} 

proc intersección (in/out c : Conjunto of T, in c2 : Conjunto of T)
{- Procedimiento que modifica s dejando solo los elementos comunes con c-}

proc diferencia (in/out c : Conjunto of T, in c2 : Conjunto of T)
{- Proc que modifica c quitando aquellos elementos comunes que tenga con c2 -}

end spec

![[Pasted image 20240708182456.png]]


6-a) 
Implement Conjunto of T where
type Conjunto of T = List of T

constructors

fun vacío() ret c : Conjunto{
     c = empty()
end fun
}

proc agregar ( in/out c : Conjunto of T, in e : T ) {
    addl(c,e)
end proc
}

destroy

proc destroy_con ( in/out c : Conjunto of T ){
     destroy(c)
end proc
}

operations

 fun pertenece ( c : Conjunto of T, e : T ) ret b : bool{
       var c2 : Conjunto of T
       c2 = copy_list(c)
       do(head(c2) != e or is_empty(c2)) ->
          tail(c2)
        od
        b = not(is_empty(c2))
    end fun
 }

fun esVacio ( c : Conjunto of T) ret b : bool{
     b = is_empty(c)
end fun
}

proc unir (in/out c : Conjunto of T, in c2 : Conjunto of T ){
     if(not(is_empty(c2))) ->
        for i = 1 to length(c2) do ->
            if(not(pertenece(c, index(c2,i)) then ->
                  agregar(c, index(c2,i))
            fi
        od
     fi
end proc
} 

proc intersección (in/out c : Conjunto of T, in c2 : Conjunto of T){
    var c3 : Conjunto of T
    if(not(is_empty(c2)) && not(is_empty(c))) then ->
          c3 = copy_list(c)
          drop(c, length(c)) 
          for i = 1 to length(c2) do ->
            if(pertenece(c3, index(c2,i)) then ->
                  agregar(c, index(c2,i))
            fi
        od
     else if(not(is_empty(c)) && is_empty(c2)) then->
         drop(c, length(c))
     fi
end proc
}

proc diferencia (in/out c : Conjunto of T, in c2 : Conjunto of T){
    var c3 : Conjunto of T
    if(not(is_empty(c2)) && not(is_empty(c))) then->
          c3 = copy_list(c)
          drop(c, length(c)) 
          for i = 1 to length(c2) do ->
            if(not(pertenece(c3, index(c2,i))) then ->
                  agregar(c, index(c2,i))
            fi
          od
          for i = 1 to length(c3) do ->
            if(not(pertenece(c2, index(c3,i))) then ->
                  agregar(c, index(c2,i))
            fi
          od
    else if(is_empty(c) && not(is_empty(c2))) then->
         for i = 1 to length(c2) do ->
             agregar(c, index(c2,i))
         od
     fi
end proc
}

b)

proc agregar ( in/out c : Conjunto of T, in e : T ) {
    var i : nat
     i = 1
     if(not(pertenece(c,e))) then ->
        if(index(c,1) < e) then ->
            do( index(c,i) < e) ->
                i = i + 1
            od
            add_at(c,i+1)
        []-> 
             addl(c,e)
         fi
     fi
end proc
}

