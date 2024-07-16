[[Constructores y operaciones de TADs]]

![[Pasted image 20240709220054.png]]

1) 
spec Stack of T where 
constructors

fun empty_stack() ret s : Stack of T 
{- crea una pila vacía. -} 

proc push (in e : T, in/out s : Stack of T) 
{- agrega el elemento e al tope de la pila s. -}

operations 

fun is_empty_stack(s : Stack of T) ret b : Bool 
{- Devuelve True si la pila es vacía -} 

{- PRE: not is_empty_stack(s) -} 
fun top(s : Stack of T) ret e : T 
{- Devuelve el elemento que se encuentra en el tope de s. -} 

{- PRE: not is_empty_stack(s) -}
proc pop (in/out s : Stack of T) 
{- Elimina el elemento que se encuentra en el tope de s. -} 

Implement Stack of T where
type Stack of T = List of T

fun empty_stack() ret s : Stack of T{
     s = empty()
end fun
}

proc push (in e : T, in/out s : Stack of T){
     addl(s,e)
end proc
}

fun is_empty_stack(s : Stack of T) ret b : Bool {
    b = is_empty(s)
end fun
}

fun top(s : Stack of T) ret e : T{
     e = head(s)
end fun
}

proc pop (in/out s : Stack of T){
      tail(s)
end proc
}

![[Pasted image 20240709220103.png]]

Implement Stack of T where
type Node of T = tuple 
               elem : T
               next : pointer to (Node of T)
               end tuple
type Stack of T = pointer to (Node of T)

fun empty_stack() ret s : Stack of T{
     s = null
end fun
}

proc push (in e : T, in/out s : Stack of T){
     var p : pointer to Node of T
     alloc(p)
     p->elem = e
     p->next = s
     s = p
end proc
}

fun is_empty_stack(s : Stack of T) ret b : Bool {
     b = s == null
end fun
}

fun top(s : Stack of T) ret e : T{
     e = s->elem
end fun
}

proc pop (in/out s : Stack of T){
      var p : pointer to Node of T
      p = s
      s = s->next
      free(s)
      s = null
end proc
}

![[Pasted image 20240709220114.png]]

3-a) 
spec Queue of T where 

constructors 

fun empty_queue() ret q : Queue of T 
{-crea una cola vacía. -} 

proc enqueue (in/out q : Queue of T, in e : T) 
{- agrega el elemento e al final de la cola q. -}

destroy (skip)

operations 

fun is_empty_queue(q : Queue of T) ret b : Bool 
{- Devuelve True si la cola es vacía -} 

{- PRE: not is_empty_queue(q) -} 
fun first(q : Queue of T) ret e : T 
{- Devuelve el elemento que se encuentra al comienzo de q. -}

{- PRE: not is_empty_queue(q) -}
proc dequeue (in/out q : Queue of T) 
{- Elimina el elemento que se encuentra al comienzo de q. -} 

end spec

Implement Queue of T where 
type Queue of T = tuple 
           elems : array[0..N-1] of T
           size : nat 
end tuple

fun empty_queue() ret q : Queue of T{
      q.size = 0
end fun
}

proc enqueue (in/out q : Queue of T, in e : T){
     q.size = q.size + 1
     q.elems[size] = e
end proc
}

fun is_empty_queue(q : Queue of T) ret b : Bool {
     b = q.size == 0
end fun
}

{- PRE: not is_empty_queue(q) -} 
fun first(q : Queue of T) ret e : T{
     e = q.elems[0]
end fun
}

{- PRE: not is_empty_queue(q) -}
proc dequeue (in/out q : Queue of T){
     if(q.size>1) then ->    
	    for i = 0 to q.size-1 do ->
            q.elems[i] = q.elems[i+1]
        od
     fi
     q.size = q.size-1
end proc
}

b) 
Implement Queue of T where 
type Queue of T = tuple 
           elems : array[0..N-1] of T
           size : nat 
           start : nat
end tuple

fun empty_queue() ret q : Queue of T{
      q.size = 0
      q.start = 0
end fun
}

proc enqueue (in/out q : Queue of T, in e : T){
       var pos : nat
        pos := (q.start + q.size) % N
         q.elems[pos] := e
         q.size := q.size + 1
end proc
}

fun is_empty_queue(q : Queue of T) ret b : Bool {
     b = q.size == 0
end fun
}

{- PRE: not is_empty_queue(q) -} 
fun first(q : Queue of T) ret e : T{
     e = q.elems[q.start]
end fun
}

{- PRE: not is_empty_queue(q) -}
proc dequeue (in/out q : Queue of T){
       q.start := (q.start + 1) % N
       q.size := q.size - 1
end proc
}

![[Pasted image 20240709220132.png]]

4)
type Direction = enumerate 
                Left 
                Right 
end enumerate 
type Path = List of Direction 

spec Tree of T where 

constructors 

fun empty_tree() ret t : Tree of T 
{- crea una árbol vacío. -} 

fun node (tl : Tree of T, e : T, tr : Tree of T) ret t : Tree of T 
{- crea el nodo con elementos e y subárboles tl y tr. -}

proc destroy_t (in/out t : Tree of T )
{- Libera memoria en caso de ser necesario. -}

operations

fun is_empty_tree(t : Tree of T) ret b : Bool 
{- Devuelve True si el árbol es vacío -} 

{- PRE: not is_empty_tree(t) -} 
fun root(t : Tree of T) ret e : T 
{- Devuelve el elemento que se encuentra en la raíz de t. -} 

{- PRE: not is_empty_tree(t) -} 
fun left(t : Tree of T) ret tl : Tree of T 
{- Devuelve el subárbol izquierdo de t. -} 

{- PRE: not is_empty_tree(t) -} 
fun right(t : Tree of T) ret tl : Tree of T 
{- Devuelve el subárbol derecho de t. -} 

fun height(t : Tree of T) ret n : Nat 
{- Devuelve la dist. que hay entre la raíz de t y la hoja más profunda. -} 

fun is_path(t : Tree of T, p : Path) ret b : Bool 
{- Devuelve True si p es un camino válido en t -} 

fun subtree_at(t : Tree of T, p : Path) ret t0 : Tree of T 
{- Devuelve el subárbol que se encuentra al recorrer el camino p en t. -} 

{- PRE: is_path(t,p) -}
fun elem_at(t : Tree of T, p : Path) ret e : T 
{- Devuelve el elemento que se encuentra al recorrer el camino p en t. -} 

implement Tree of T where 
type Node of T = tuple 
         left: pointer to (Node of T)
         value: T 
         right: pointer to (Node of T) 
 end tuple 

type Tree of T = pointer to (Node of T)

constructors 

fun empty_tree() ret t : Tree of T{
      t = null
end fun
}

fun node (tl : Tree of T, e : T, tr : Tree of T) ret t : Tree of T{
       alloc(t)
       t->value = e
       t->left = tl
       t->right = tr
end fun
}

operations

fun is_empty_tree(t : Tree of T) ret b : Bool{
     b = t == null
}

destroy

proc destroy_tree(in/out t : Tree of T){
      if(not(is_empty_tree(t))) then ->
          destroy_tree(tl)
          destroy_tree(tr)
          free(t)
      fi
end proc
}

fun copy_tree(t : Tree of T) ret copy: Tree of T{
     alloc(copy)
     copy->value = t->value
     copy->left = t->left
     copy->right = t->right
end fun
}

{- PRE: not is_empty_tree(t) -} 
fun root(t : Tree of T) ret e : T{
     e = t->value
end fun
}

{-PRE: not is_empty_tree(t) -}
fun left(t : Tree of T) ret tl : Tree of T{
      tl = copy_tree(t->left)
end fun
}

{-PRE: not is_empty_tree(t) -}
fun right(t : Tree of T) ret tr : Tree of T{
      tr = copy_tree(t->right)
end fun
}

fun height(t : Tree of T) ret n : Nat{
     if(is_empty(t)) then ->
         n = 0
     else ->
         n = (max(height(t->left),height(t->right)) + 1
end fun
}

fun is_path(t : Tree of T, p : Path) ret b : Bool{
      var p2 : List of Direction 
      var t2 : Tree of T
      t2 = copy_tree(t)
      p2 = copy_list(p)
      if(lenght(p2) >= height(t2)) then ->
          b = false
      else ->
         do(not(is_empty(p2)) && not(is_empty_tree(t2)) ->
            if (head(p2) == left && not(is_empty(t2->left))) then ->
                 t2 = left(t2)
                 tail(t2)
             else if (head(p2) == right && not(is_empty(t2->right)) then ->
                 t2 = right(t2)
                 tail(t2)
              else if (not(is_empty(t2->right) or not(is_empty(t2->right)) then ->
                 t2 = null
              fi
         od
         b = is_empty(p2)
         destroy(p2)
end fun
}


fun subtree_at(t : Tree of T, p : Path) ret t0 : Tree of T {
     var p2 : Path
     if(is_empty_tree(t) or is_empty(path)) then ->
         t0 = t
     else ->
         p2 = copy_list(p)
         tail(p2)
         if (head(p) = Left) then ->    
			 t0 = subtree_at(t->left, p2) 
         else ->
             t0 = subtree_at(t->right, p2)
         fi
         destroy(p_aux)
       fi 
end fun
}

{- PRE: is_path(t,p) -}
fun elem_at(t : Tree of T, p : Path) ret e : T{
     e = root(subtree_at(t,p))
end fun
}

![[Pasted image 20240709220144.png]]
![[Pasted image 20240709220158.png]]
![[Pasted image 20240709220214.png]]

5-a)
spec Dict of (K,V) where 
donde K y V pueden ser cualquier tipo, asegurando que K tenga definida una función que chequea igualdad.
spec Dict of (K,V) where

constructors 

fun empty_dict( ) ret d : Dict of (K,V)
{- Crea un diccionario vacío -}

proc add_to_dict(in/out d : Dict of (K,V), in k : K, in v : V)
{- Agrega la clave k, y el valor v al diccionario -}

proc destroy_dict(in/out d : Dict of (K,V))
{- Libera memoria en caso de ser necesario -}

operations

fun is_empty_dict( d : Dict of (K,V)) ret b : Bool
{- Verifica si el diccionario es vacío -}

fun is_k( d : Dict of (K,V), k : K) ret b : Bool
{- Verifica si la clave k esta en d -}

{- PRE: is_k(d,k) -}
fun index_k ( d : Dict of (K,V), k : K ) ret v : V
{- Devuelve el valor asociado a k -}

{- PRE: is_k(d,k) -}
proc elim_elem(in/out d : Dict of (K,V), k : K)

fun k_set( d : Dict of (K,V)) ret c : Conjunto of K
{- Devuelve un conjunto de tipo k con todas las claves de d -}

b)
implement Dict of (K,V) where 
type Node of (K,V) = tuple 
                 left: pointer to (Node of (K,V)) 
                 key: K 
                 value: V 
                 right: pointer to (Node of (K,V)) 
                  end tuple 
type Dict of (K,V)= pointer to (Node of (K,V))

Constructors

fun empty_dict( ) ret d : Dict of (K,V){
     d = null
end fun
}
  
proc add_to_dict(in/out d : Dict of (K,V), in k : K, in v : V){
       if(is_empty(d)) then ->
          alloc(d)
          d->key = k
          d->value = v
          d->left = empty_dict()
          d->right = empty_dict()
      else if ( k = d->key) then ->
         d->value = v
      else if ( k < d->key) then ->
         add_to_dict(d->left, k, v)
      else ->
          add_to_dict(d->right,k,v)
      fi
end proc  
}

destroy 

proc destroy_dict(d : in/out Dict of (K, V)){
     if  not(is_empty_dict(d)) then ->
        destroy_dict(d→left)
         destroy_dict(d→right)
        free(d)
         d ≔ null
     fi
end proc
}

operations

fun is_empty_dict( d : Dict of (K,V)) ret b : Bool{
      b = d = null
end fun
}

fun is_k( d : Dict of (K,V), k : K) ret b : Bool{
      var d2 : Dict of (K,V)
      d2 = copy_dict(d)
      b = false
      if (not(is_empty(d2))) then ->
         if (k = d2->key) then ->
            b = true
        else if (k < d2->key) then ->
            b = is_k(k,d2->left)
        else ->
             b = is_k(k, d2->right)
         fi
       fi
       destroy(d2)
end fun
}

{- PRE: is_k(d,k) -}
fun index_k ( d : Dict of (K,V), k : K ) ret v : V{
    var d2 : Dict of (K,V)
    if (k = d2->key) then ->
        v = d->value
    else if (k < d2->key) then ->
            v = index_k(d2->left,k)
    else ->
         v = index_k( d2->right,k)
     fi
     destroy(d2)
end fun
}

{- PRE: is_k(d,k) -}
proc elim_elem(in/out d : Dict of (K,V), k : K){
     var d2 : pointer to Node of (K,V)
     var max_key : K
     var max_val : V
     if (d->key = k) then ->
        if d->left = null then
                d2 := d
                d := d->right
                free(d2)
         else 
             borra_max_key_val(d->left, max_key, max_val)
             d->key = max_key
             d->val = max_val
         else if d->key > k then
             elim_elem(d->left, k)
        else
             elim_elem(d->right, k)}
          fi
end proc
}

proc borra_max_key_val(in/out d : Dict of (V,K), out k : K, out v : V){
      var d2, padre_d2: pointer to Node of (K,V)
      d2 = d
      padre_d2 = null
      while(d2->right != null) do ->
            padre_d2 = d2
            d2 = d2->right   
     od
     k = d2->key
     v = d2->value
     d2 = d
     if (padre_d2 != null) then ->
         padre_d2->right = d2->left
      else
          d = d2->left 
      fi
      destroy(d2)
end proc
}

fun k_set( d : Dict of (K,V)) ret c : Conjunto of K{
      s = empty_set()
      while (not(is_empty(d)) do
          add_set(s, d->key)
          union_set(s, k_set(d->left))
          union_set(s,k_set(d->right))
      od
end fun
}


![[Pasted image 20240709220226.png]]

6)
(a) 2, 252, 401, 398, 330, 344, 397, 363. SI.
(b) 924, 220, 911, 244, 898, 258, 362, 363. SI.
(c) 925, 202, 911, 240, 912, 245, 363. NO, pues 911 < 912.
(d) 2, 399, 387, 219, 266, 382, 381, 278, 363. SI.
(e) 935, 278, 347, 621, 299, 392, 358, 363. NO, pues 294 < 347

![[Pasted image 20240709220238.png]]

![[Pasted image 20240710002317.png]]

![[Pasted image 20240709220250.png]]

8) 
22,10,35,19,6,25,52,15,4,33,49,53,11,18
22,10,35,19,6,25,52,15,4,33,53,49,18,11

