![[Pasted image 20240710220726.png]]
1)
type Objeto = tuple
      id    : Nat 
      value : Float 
      weight: Float 
end tuple 

Función alterada para que no acepte fraccionamiento de objetos
fun mochila(W: Float, C: Set of Objeto) ret L : List of Objeto
      var o_m : Objeto 
      var resto : Float 
      var C_aux : Set of Objeto 
      S:= empty_list() 
      C_aux:= set_copy(C) 
      resto:= W 
       do (resto > 0) → 
             o_m := select_obj(C_aux)
             if o_m.weight > resto then
                   elim(C_aux,o_m)
            else
                   resto := resto - o_m.weight
                   addl(S,o_m) 
                   elim(C_aux,o_m) 
            fi
      od 
      set_destroy(C_aux)
end fun 

fun select_obj(C: Set of Objeto) ret r : Objeto 
       var C_aux : Set of Objeto 
       var o : Objeto 
       var m : Float 
       m := -∞ 
       C_aux := set_copy(C) 
       do (not is_empty_set(C_aux)) → 
            o := get(C_aux) 
            if (o.value/o.weight > m) then 
                   m := o.value/o.weight 
                   r := o 
             fi 
             elim(C_aux,o) 
       od 
       set_destroy(C_aux)
end fun 

CONTRAEJEMPLO
Espacio Mochila = 12
Lápiz(8,5) = 1.6
Papel(11,6) = 1.83
Tijera(12,7) = 1.71
Mochila = (Papel,Lápiz)
   12        6     1    ← espacio que le queda a la mochila
    0        11    19   ← valor final
Pero lo más óptimo era:
Mochila = (Tijera,Lápiz)
   12        5      0    ← espacio que le queda a la mochila
    0        12     20   ← valor final

![[Pasted image 20240710220742.png]]

2)
fun cambio(m: Nat,C: Set of Nat) ret S : List of Nat 
    var c, resto: Nat 
    var C_aux : Set of Nat 
    S:= empty_list() 
    C_aux:= set_copy(C) 
    resto:= m 
    do (not is_empty_set(C_aux)) → 
       c := “elemento máximo de C_aux” 
       if c > resto then 
             elim(C_aux,c) 
       else 
             resto := resto - c 
             addl(S,c) 
        fi 
    od 
    set_destroy(C_aux) 
end fun 

MONEDAS
1      5     12
Quiero pagar 15 pesos (ojala)
Opción óptima
5 - 3    |     3 monedas
Opción dada por el algoritmo
12 - 1    |
1 - 3     |     4 monedas**

![[Pasted image 20240710220753.png]]

3)
1. Entender enunciado: datos.
- autonomía A
- n localidades, empezamos por l0 y pasamos por l1...ln-1 hasta llegar a ln
- distancia entre localidades <= A
- existe una estacion de combustible en todas las localidades

Se pide dar el menor numero de veces posible que es necesario cargar combustible y las localidades donde se carga.

2. Criterio de selección:  
     Cargo combustible solo cuando no sea posible llegar a la siguiente localidad con el combustible que me queda.
Ejemplo
Localidades = 5
Autonomía 11 km
Tanque vacío
Loc0 -> Cargo combustible: 11 km disponibles
5 km
Loc1 -> 6 km disponibles. La siguiente loc está a 7 km (7>6) debo cargar combustible. Cargo combustible: 11 km disponibles
7 km
Loc2->  4 km disponibles.
3 km
Loc3 -> 1 km disponibles. La siguiente loc está a 6 km (6>4) debo cargar combustible. Cargo combustible: 11 km disponibles
6 km
Loc4 -> 7 km disponibles. Llegó a destino
Cargo combustible 3 veces

3. Estructuras de datos y tipo de la función.
    
type Localidad = tuple 
        localidad: Nat
        siguiente_localidad_a: Nat
             end tuple

type Recorrido = List of Localidad

fun viajecito(r: Recorrido, A: Nat) ret cargas: Recorrido
end fun

4. Implementar el algoritmo
fun viajecito(r: Recorrido, A: Nat) ret cargas: Recorrido
      var comb_disp : nat
      cargas = empty_list()
      comb_disp = 0
      for (i= 1 to lenght(r)-1 ) do
         if(index(r,i).siguiente_localidad_a > comb_disp) then ->
              comb_disp= A
              addr(index(r,i),cargas)
          fi
          comb_disp = comb_disp - index(r,i).siguiente_localidad_a
       od
end fun


![[Pasted image 20240710220805.png]]

4)
1. Entender enunciado: datos.
- n ballenas
- tiempos de vida s1,...,sn, 
- salvar una ballena requiere tiempo t
- la ballena no muere mientras está siendo rescatada
- 
Se pide salvar a la mayor cantidad de ballenas posible, y dar el orden en que lo hacemos.

2. Criterio de selección:  
    Elijo en cada momento la ballena que le queda menos tiempo de vida.

3. Estructuras de datos y tipo de la función.
    
type Ballena = tuple 
        id: Nat
        tiempoRestante: Nat
  end tuple

fun salvarBallenas(B: Set of Ballena, t: Nat) ret rescatadas: List of Ballena
end fun

4. Implementar el algoritmo

fun salvarBallenas(B: Set of Ballena, t: Nat) ret rescatadas: List of Ballena
    var ballenasAunVivas: Set of Ballena
    var hora: Nat
    var ballena: Ballena
    hora:= 0
    ballenasAunVivas:= set_copy(B)
    rescatadas := empty_list()
    {- Invariante: toda ballena en ballenasAunVivas está viva, es decir      
 tiempoRestante >= hora, y NO está salvada, es decir no está en rescatadas   -}
    while not is_empty_set(ballenasAunVivas) do
        ballena := elegirBallena(ballenasAunVivas)
        addR(rescatadas, ballena)
        elim_set(ballenasAunVivas, ballena)
        hora := hora + t
        quitarMuertas(ballenasAunVivas, hora)
end fun

proc quitarMuertas(in/out B: Set of Ballena, hora: Nat)
    var D: Set of Ballena
    var b: Ballena
    D := copy_set(B)
    while not is_empty_set(D) do
       {- agarro una ballena del conjunto D -}
       b := get(D)
       if b.tiempoRestante < hora then
           elim(B,b)
       fi
       elim(D,b)
    end
    destroy_set(D)
end proc

{- elijo la ballena candidata según criterio de selección: la ballena con menor tiempo de vida. PRE: B es no vacío -}

fun elegirBallena(B: Set of Ballena) ret b: Ballena
    var ball_aux : Ballena
    var min_tiempo_restante : nat
    var B_aux : Set of Ballena
    min_tiempo_restante := infinito
    B_aux := copy_set(B)
    while not is_empty_set(B_aux) do
        ball_aux := get(B_aux)
        if ball_aux.tiempoRestante < min_tiempo_restante then
            min_tiempo_restante := ball_aux.tiempoRestante
            b := ball_aux
        fi
        elim_set(B_aux, ball_aux)
    od
    destroy_set(B_aux)
end fun

![[Pasted image 20240710220816.png]]

5)
1. Entender enunciado: datos.
- n amigos 
- días de partida (pi) y de regreso (ri)
- cuando alguien lo devuelve, recien a partir del dia siguiente puede usarlo otra persona 

Se pide prestar el celular a la mayor cantidad de amigos posible.

2. Criterio de selección:  
Prestarselo al amigo que vuelve antes y su ida es despues de la vuelta del anterior amigo al que le presté

Ejemplo

| Amigo | Pi  | Ri  |
| ----- | --- | --- |
| Gaby  | 1   | 3   |
| Fede  | 4   | 6   |
| Pedro | 4   | 14  |
| Santi | 7   | 13  |
| Cami  | 15  | 16  |
| Abril | 17  | 20  |
| Ana   | 18  | 19  |
| Fer   | 20  | 25  |

Opcion óptima: Gaby,Fede,Santi,Cami,Ana,Fer
Dandoselo al que primero se va: Gaby, Fede,Santi,Cami,Abril
Dandole al que menos dias se queda: Gaby,Fede,Cami,Ana,Fer
Dandole al que vuelve antes y su ida es despues de la vuelta del anterior amigo al que preste
Gaby, Fede,Santi,Cami,Ana,Fer. Encontramos la óptima

3. Estructuras de datos y tipo de la función.
    
type amigo = tuple 
         partida : Nat
         regreso : Nat
            end tuple

type Viajes = Set of amigo

fun prestar(v: Viajes) ret prestamos: Queue of amigo
end fun

4. Implementar el algoritmo
fun prestar(v: Viajes) ret prestamos: Queue of amigo
     var a: amigo
     var amigo_previo : amigo
     var v_aux : Viajes
	prestamos = empty_queue()
     v_aux = copy_set(v)
     amigo_previo.regreso = -inf 
     prestamos = empty_queue()
     while not is_empty(v_aux) do 
         a = elegir_amigo(v,amigo_previo)
         amigo_previo = a
         enqueue(prestamos,a)
         elim(v_aux, amigo_previo)
     od
     destroy_set(v_aux)
end fun

fun elegir_amigo(v: Viajes, amigo_previo: amigo) ret amigo : amigo
     var a_aux : amigo
     var min_regreso : nat
     var v_aux = Viajes
     min_regreso = inf
     v_aux = copy_set(v)
     while not is_empty_set(v_aux) do
         a_aux = get(v_aux)
         if(a_aux.partida > amigo_previo.regreso && min_regreso > a_aux.regreso) then 
             min_regreso = a_aux.regreso
             amigo = a_aux
         fi
         elim(v_aux, a_aux)
     od
     destroy_set(v_aux)
end fun

![[Pasted image 20240710220826.png]]

6) 1. Entender enunciado: datos.
- n facturas
- cada factura tiene tiempo minimo necesario de coccion ti y tiempo máximo admisible de cocción Ti. ti <= Ti
- abrir el horno y sacar facturas no consume tiempo

Se pide extraer todas las piezas del horno en perfecto estado y abrir el horno la menor cantidad de veces.

2. Criterio de selección:  
Abro el horno justo cuando la factura que primero se quemaría este por quemarse

Ejemplo: 
6 facturas
F1 = 3,7
F2 = 5,8
F3 = 1,4
F4 = 8,10
F5 = 7,9
F6 = 4,9
Abro el horno justo cuando la factura que primero se quemaría este por quemarse
MIN   4               8 
      F3,F1,F6   F2,F5,F4

3. Estructuras de datos y tipo de la función.
    
type Factura = tuple 
         no_cruda: Nat
         no_quemada: Nat
  end tuple

fun vida_del_repostero(F: Set of Factura) ret aperturas: Nat
end fun

4. Implementar el algoritmo
fun vida_del_repostero(F: Set of Factura) ret aperturas: Nat
      var f_aux : Set of Factura
      var listas : Set of Factura
      f_aux = copy_set(F)
      aperturas = 0
      while not is_empty(f_aux) do
          listas = sacar_facturas(f_aux)
          f_aux = diferencia(f_aux, listas)
          aperturas = aperturas +1
      od
      destroy_set(f_aux)
end fun

fun sacar_facturas(F:Set of Factura, hora : Nat)ret perfectas : Set of Facturas
      var f_aux : Set of Factura
      var hora: nat
      var factura : Factura
      perfectas = empty_set()
      f_aux = copy_set(F)
      f2_aux = copy_set(F)
      hora = inf
      while not is_empty(f_aux) do
           factura = get(f_aux)
           if (hora > factura.no_quemada &&) then
               hora = factura.no_quemada
           fi
           elim(factura, f_aux)
      od
      while not is_empty(f2_aux) do
           factura = get(f2_aux)
           if (hora >= factura.no_cruda  && hora <= factura.no_quemada) then
               add_set(factura,perfectas)
           fi
           elim(factura, f2_aux)
      od
      destroy_set(f_aux)
      destroy_set(f2_aux)
end fun

![[Pasted image 20240710220837.png]]

7-a)
1. Entender enunciado: datos.
- n sobrevivientes
- cantidad ci de oxigeno por minuto consumida por cada sobreviviente
- cada rescate lleva t minutos y solo se puede salvar de a una persona
- total C de oxigeno

Se pide salvar a la mayor cantidad de sobrevivientes antes de que se agote el total C de oxigeno.

2. Criterio de selección:  
Salvo a quienes consuman mas oxigeno por minuto.

Ejemplo: 
C = 210
6 sobrevivientes
t = 3
S1 = 5
S2 = 7
S3 = 5
S4 = 8
S5 = 3
S6 = 9

Sacando el de minimo oxigeno
MIN   0               3            6           9  
C       210  102  108  87   21   72   0   
      S5            S1          S3                 
Sacando el de maximo oxigeno 
MIN   0               3            6            9         12     15
C       210   84   126  60   66  39    27   24   3   9    0
      S6            S4          S2          S1         S3

3. Estructuras de datos y tipo de la función.
    
type Sobreviviente = Nat

fun salvavidas(S : Set of Sobreviviente, C : Nat, t : nat) ret Salvados : List of Sobreviviente
end fun

4. Implementar el algoritmo
fun salvavidas(S : Set of Sobreviviente, C : Nat, t : nat) ret Salvados : List of Sobreviviente
      var s_aux : Set of Sobreviviente
      var s2_aux : Set of Sobreviviente    
      var sobreviviente : Sobreviviente}
      var resto : Sobreviviente 
      Salvados = empty_list()
      s_aux = copy_set(S)
      while not is_empty(s_aux) && C > 0 do
          sobreviviente = elegir_sobreviviente(S)
          addr(Salvados,sobreviviente)
          elim(sobreviviente, s_aux)
          s2_aux = copy_set(s_aux)
          while not is_empty(s2_aux) do
             resto = get(s2_aux)
             C = C - t * resto
             elim(resto, s2_aux)
           od
      od
      destroy_set(s_aux)
      destroy_set(s2_aux)
end fun

fun elegir_sobreviviente(S: Set of Sobreviviente) ret elegido : Sobreviviente
       var s_aux : Set of Sobreviviente 
       var mayor_oxigeno : Sobreviviente
       var sobreviviente : Sobreviviente
       elegido = - inf
       s_aux = copy_set(s)
       while not is_empty(s_aux)
          sobreviviente = get(s_aux)
          if (elegido < sobreviviente) then
             elegido = sobreviviente
          fi
          elim(sobreviviente, s_aux)
       od
       destroy_set(s_aux)
end fun
 b )
 fun salvavidas(S : Set of Sobreviviente, C : Nat, t : nat, m : nat) ret Salvados : List of Sobreviviente
      var s_aux : Set of Sobreviviente
      var s2_aux : Set of Sobreviviente    
      var sobreviviente : Sobreviviente}
      var resto : Sobreviviente
      var i : nat
      Salvados = empty_list()
      i = 1 
      s_aux = copy_set(S)
      while not is_empty(s_aux) && C > 0 do
          while i <= m && not is_empty(s_aux) do
             sobreviviente = elegir_sobreviviente(s_aux)
             addr(Salvados,sobreviviente)
             elim(sobreviviente, s_aux)
             i = i + 1
          od
          s2_aux = copy_set(s_aux)
          while not is_empty(s2_aux) do
             resto = get(s2_aux)
             C = C - t * resto
             elim(resto, s2_aux)
           od
      od
      destroy_set(s_aux)
      destroy_set(s2_aux)
end fun

fun elegir_sobreviviente(S: Set of Sobreviviente) ret elegido : Sobreviviente
       var s_aux : Set of Sobreviviente 
       var mayor_oxigeno : Sobreviviente
       var sobreviviente : Sobreviviente
       elegido = - inf
       s_aux = copy_set(s)
       while not is_empty(s_aux)
          sobreviviente = get(s_aux)
          if (elegido < sobreviviente) then
             elegido = sobreviviente
          fi
          elim(sobreviviente, s_aux)
       od
       destroy_set(s_aux)
end fun

![[Pasted image 20240710220846.png]]

8)
1. Entender enunciado: datos.
- n troncos 
- cada tronco irradia una temperatura k y dura una cantidad t encendido
- 22 y 6 temperatra no menor a K1 
- 6 y 12 temperatura no menor a K2
- asumimos K1>K2

Se pide el orden en que se usaran la menor cantidad de troncos a quemar entre las 22 y las 12 del dia siguiente asegurando que entre las 22 y las 6 la estufa debe irradiar temperatra no menor a K1 y entre las 6 y 12 am una temperatura no menor a K2.

2. Criterio de selección:  
Entre las 22 y 6 elijo el tronco que mas dure con una temperatura mayor a K1
Entre las 6 y 12 elijo el tronco que mas dure con una temperatura mayor a K2

Ejemplo
K1 = 36
K2 = 30

Troncos
1.K=34 T=2
2.K=38 T=5
3.K=37 T=3
4.K=32 T=1
5.K=33 T=3
6.K=34 T=4
7.K=36 T=4

| 22  | 3   | 7   | 11  |
| --- | --- | --- | --- |
| 2   | 7   | 6   | 5   |

3. Estructuras de datos y tipo de la función.
    
type Tronco = tuple
              id: nat
              calor : nat
              tiempo : nat
            end tuple

fun estufa_voraz(T : Set of Tronco, K1 : Nat, K2 : nat) ret por_quemar : Queue of Tronco
end fun

4. Implementar el algoritmo
fun estufa_voraz(T : Set of Tronco, K1 : Nat, K2 : nat) ret por_quemar : Queue of Tronco
      var t_aux : Set of Tronco
      var tronco : Tronco 
      var hora : nat
      hora = 0
      t_aux = copy_set(T)
      por_quemar = empty_queue()
      while h < 14 do
           if (h<8) then ->
             tronco = elegir_tronco(t_aux, K1)
           else 
              tronco = elegir_tronco(t_aux, K2)
           fi
          enqueue(por_quemar,tronco)
           h = h + tronco.tiempo 
          elim(tronco,t_aux)
      od
      detroy_set(t_aux)
end fun

fun elegir_tronco(T: Set of Tronco, K : nat) ret duradero : Tronco
      var t_aux : Set of Tronco
      t_aux = copy_set(T)
      var tronco : Tronco
      max_tiempo = -inf
      while not is_empty_set(t_aux) do
          tronco = get(t_aux)
          if (tronco.calor >= K && max_tiempo < tronco.tiempo) then 
              duradero = tronco
              max_tiempo = tronco.tiempo
          fi
          elim(tronco, t_aux)
      od
      destroy(t_aux)
end fun


![[Pasted image 20240710220855.png]]

9)
1. Entender enunciado: datos.
- son las 18 
- n bares
- cada bar tiene un precio P de limonada y un horario de happy hour H 
- H se mide en horas a partir de las 18
- en el happy hour la limonada vale el 50%
- tomo 2 limonadas por hora
- moverse de bar no consume tiempo
- en total tomaremos 16 pintas

Se pide el menor dinero que es posible gastar para tomar una limonada por hora desde las 18 hasta las 2 (16) eligiendo el bar que mas convenga.

2. Criterio de selección:  
Elijo el bar que mas barata tenga la limonada y que tenga el happy hour disponible

Ejemplo: 
6 bares 
b1 = 12,3
b2 = 15,4
b3 = 11,5
b4 = 16, 8
b5 = 13,6
b6 = 15,8
          b3,    b5,  b6 
18      23     24   02
          10     12   16
          
1. Estructuras de datos y tipo de la función.
    
type Bar = tuple
              hh : nat
              limonada : nat
        end tuple

fun sobredosis_limonadil(B : Set of Bar) ret derroche : nat
end fun

4. Implementar el algoritmo
fun sobredosis_limonadil(B : Set of Bar) ret derroche : nat
      var b_aux : Set of Bar 
      var bar : Bar
      var hora : nat
      hora = 0
      derroche = 0
      b_aux = copy_set(B,b_aux)
      while not is_empty_set(b_aux) && hora < 16 do
          bar = elegir_bar(b_aux,hora)
          if(bar.hh>16) then 
               derroche = derroche + bar.limonada * (16-hora) 
               hora = 16
          else 
              derroche = derroche +  bar.limonada * (bar.hh - hora)  
              hora = bar.hh
          fi
          elim_set(bar, b_aux)
      od
      destroy(b_aux)
end fun

fun elegir_bar(B: Set of Bar, h : nat) ret b : Bar
      var b_aux : Set of Bar 
      var bar : Bar
      var precio_min : nat
      precio_min = inf
      b_aux = copy_set(B,b_aux)
      while not is_empty(b_aux) do
         bar = get(b_aux)
         if  (precio_min > bar.precio && bar.horas > h)
                  precio_min = bar.precio
                  b = bar
              fi
               elim(bar,b_aux)
      od
      destroy_set(b_aux)
end fun