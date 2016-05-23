NB. parsing edge cases ----------------------------------

'syntax error' -: ex 'a =: 5 b =: )' [  a =: 0
a = 5

'domain error' -: ex '''a'' 2 : ''u'' 3 =. 6'
a = 5
6 -: ex '(''a'' 2 : ''u'' 3) =. 6'
a = 6

'syntax error' -: ex ') 5'
'syntax error' -: ex ') +'
'syntax error' -: ex ') &'
'syntax error' -: ex ') /'
'syntax error' -: ex ') ('

NB. test nvr management: many names on a line, and multiple identical nvrs
a =: 1
4097 = ". 'a' ,~ ; 4096 # <'a + '

a =: 1e7$2
multi =: 3 : 'a =: a =: a [ a + a'
a -: multi^:100 a


4!:55 ;:'a'


