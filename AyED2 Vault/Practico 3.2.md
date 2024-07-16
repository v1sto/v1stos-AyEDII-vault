[[Algoritmo de Prim y Algoritmo de Dijkstra]]

![[Pasted image 20240710220926.png]]
![[Pasted image 20240710222428.png]]


![[Pasted image 20240710220935.png]]
![](https://lh7-us.googleusercontent.com/docsz/AD_4nXcwskEHqucKRz1gNKfFc15KSAbo5wtVpR75rKfmA28Rgpmdm25uZogIEaRDODyNfXD684q6JJM_W079_hFLwJBelYiJpCVsf4FctkQDhhf8NUA7oZgNZU3ra8LKIYU8Xe1BvXQMG_0ZN7HjEDSWiCBkbrI?key=1Kp3nMCAQkjkUlYCmkcKbw)
**![](https://lh7-us.googleusercontent.com/docsz/AD_4nXes73XpwqzKiMTn9JHv6lBSlpoVD7orcLcYhgbj_opXNfTXQR0HGmiTiWx-fjLihfJsCD-rmYJ97qNPKiPFwOxAL7Kij3yuG3zXsVo-ROLVJn5iFefnxP8_eavLlLmdzEs1I25Zz2akEuyT9ZOyvUwS8deX?key=1Kp3nMCAQkjkUlYCmkcKbw)**
![[Pasted image 20240710220948.png]]
![[Pasted image 20240712171229.png]]

3)

fun viaje_dijkstra(E : array[1..n,1..n] of Nat, C : Set of Vortex, v : Vortex, L : Nat) ret D : Set of Vortex
        var costos : array[1..n] of nat
         var c_aux : Set of Vortex
         var llegable : Vortex
		 c_aux = copy_set(C)
		 D = empty_set()
         costos = dijkstra(E,v)
         while not is_empty_set(c_aux) do
              llegable = get(c_aux)
              if costos[llegable] <= L then 
                 add_set(D,llegable)
              fi
              elim(llegable,c_aux)
         od
         destroy_set(c_aux)
end fun

b)
![[Pasted image 20240712172022.png]]
![[Pasted image 20240712172200.png]]
