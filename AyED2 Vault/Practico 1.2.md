[[Algoritmos de ordenación]]

![[Pasted image 20240706210311.png]]
1-a)  

| [<font color="#c00000">7, 1, 10, 3, 4, 9, 5</font>]                                                           | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,7</font>, <font color="#95b3d7">10</font>, <font color="#c00000">4</font>, <font color="#c00000">9</font>,<font color="#c00000"> 5</font>] |
| ------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [<font color="#c00000">7, 1, 10, 3,</font> 4, 9, 5]                                                           | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,7</font>, <font color="#95b3d7">10</font>, <font color="#c00000">4</font>, <font color="#c00000">9</font>, 5]                              |
| [<font color="#c00000">7</font>, <font color="#ff0000">1</font>, 10, 3, 4, 9, 5]                              | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,7</font>, <font color="#95b3d7">10</font>, <font color="#c00000">4</font>, 9, 5]                                                           |
| [<font color="#c00000">7</font>, 1, 10, 3, 4, 9, 5]                                                           | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,7</font>, <font color="#95b3d7">10</font>, <font color="#c00000">4</font>,<font color="#76923c"> 9</font>, 5]                              |
| [<font color="#95b3d7">7</font>,<font color="#c00000"> 1</font>, 10, 3, 4, 9, 5]                              | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,7</font>, <font color="#95b3d7">10</font>, <font color="#c00000">4</font>, 5, 9]                                                           |
| [<font color="#95b3d7">7</font>, <font color="#76923c">1</font>, 10, 3, 4, 9, 5]                              | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,7</font>, <font color="#95b3d7">10</font>, <font color="#c00000">4</font>, 5, 9]                                                           |
| [<font color="#95b3d7">1, 7</font>, <font color="#c00000">10, 3</font>, 4, 9, 5]                              | [<font color="#95b3d7">1, </font><font color="#95b3d7">3 ,4</font>, <font color="#95b3d7">5</font>, <font color="#c00000">7</font>, 9, 10]                                                           |
| [<font color="#95b3d7">1, 7</font>, <font color="#c00000">10, </font>3, 4, 9, 5]                              | [<font color="#76923c">1, 3  4, 5, 7, 9, 10</font>]                                                                                                                                                  |
| [<font color="#95b3d7">1, 7</font>, <font color="#95b3d7">10, </font><font color="#c00000">3</font>, 4, 9, 5] |                                                                                                                                                                                                      |
| [<font color="#95b3d7">1, 7</font>, <font color="#95b3d7">3, </font><font color="#76923c">10</font>, 4, 9, 5] |                                                                                                                                                                                                      |
b)
merge_sort_rec(a,1,4)
merge_sort_rec(a,1,2)
merge_sort_rec(a,1,1)
merge_sort_rec(a,1,1),merge_sort_rec(a,2,2)
merge_sort_rec(a,3,4)
merge_sort_rec(a,3,3),merge_sort_rec(a,4,4)
merge_sort_rec(a,1,4)
merge_sort_rec(a,5,7)
merge_sort_rec(a,5,6)
merge_sort_rec(a,5,5),merge_sort_rec(a,6,6)
merge_sort_rec(a,7,7)
merge_sort_rec(a,5,7)
merge_sort_rec(a,1,7)


![[Pasted image 20240706210327.png]]

2-a) proc intercalar_cada(in/out a:array[1..2^n] of int ; in  i : nat)
        var tam, izq, der, med : nat
         tam = 2^n 
         izq = 1
         der = 2^(i+1) 
         med = (izq + der)/2
         do (der<= tam) ->
            merge(a,izq,med,der)
             izq = der + 1
             der = der + 2^(i+1)
          od 
    end proc 
b)   proc merge_sort(in/out a:array[1..2^n] of T)
     for i=0 to n-1 do
        intercalar_cada(a,i)
     od
     end proc


![[Pasted image 20240706210340.png]]

3-a)

| [<font color="#e36c09">7</font>, 1, 10, 3, 4, 9, 5]                                                           | [3, 1, <font color="#e36c09">4</font>, 5, <font color="#e36c09">7</font>, <font color="#e36c09">9</font>, 10]                                                           |     |
| ------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --- |
| [<font color="#e36c09">7</font>, 1, 5, 3, 4, 9, 10]                                                           | [<font color="#e36c09">3</font>, 1, <font color="#e36c09">4</font>, <font color="#e36c09">5</font>, <font color="#e36c09">7</font>, <font color="#e36c09">9</font>, 10] |     |
| [4, 1, 5, 3, <font color="#e36c09">7</font>, 9, 10]                                                           | [1, <font color="#e36c09">3</font>, <font color="#e36c09">4</font>, <font color="#e36c09">5</font>, <font color="#e36c09">7</font>, <font color="#e36c09">9</font>, 10] |     |
| [<font color="#e36c09">4</font>, 1, 5, 3, <font color="#e36c09">7</font>, 9, 10]                              |                                                                                                                                                                         |     |
| [<font color="#e36c09">4</font>, 1, 3, 5, <font color="#e36c09">7</font>, <font color="#e36c09">9</font>, 10] |                                                                                                                                                                         |     |

b) 
quick_sort_rec(a,1,7)
quick_sort_rec(a,1,4)
quick_sort_rec(a,1,2)
quick_sort_rec(a,4,4)
quick_sort_rec(a,6,7)

![[Pasted image 20240706210352.png]]

4) proc partition_trucho(in/out a:array[1..n]of int; in lft,rgt : nat; out ppiv:nat)
     var med : nat
     med = (lft + rgt) / 2
     if(a[lft] <= a[rgt]) then ->
       if(a[lft] <= a[med]) then ->
         if(a[med] <= a[rgt]) then -> 
             ppiv = med
         []-> ppiv = rgt
         fi
        [] -> ppiv = lft
        fi 
     [] -> if(a[rgt]<= a[med]) then ->
             if(a[med] <= a[lft]) then ->
                 ppiv = med
             [] -> ppiv = lft
             fi
         []-> ppiv = rgt
         fi
     fi
     i:= lft
     j:= rgt
     do i ≤ j ->
        if (a[i] ≤ a[ppiv]) then ->
            i:= i+1
        else if (a[ppiv] ≤ a[j]) then
            j:= j-1
        else if (a[i] > a[ppiv] ∧ a[j] < a[ppiv]) then
            swap(a,i,j)
            i:= i+1
            j:= j-1
        fi
     od
     swap(a,ppiv,j)
     ppiv:= j
   end proc

![[Pasted image 20240706210405.png]]

5)  Pre  {- k <= n -} 
    proc medio_partition(in/out a:array[1..n]of int;  in k : nat; out e : int) 
      var izq, der, ppiv : nat
      izq = 1
      der = n 
      do(der > izq)  ->
         partition(a,izq,der, ppiv)
         if(ppiv<k) then ->
             izq = ppiv +1
          []-> der = ppiv - 1
         fi 
        od
        e = a[k]  
    end proc

![[Pasted image 20240706210415.png]]

6) 