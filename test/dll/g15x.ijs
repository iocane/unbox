NB. 15!: ----------------------------------------------------------------

3 : 0 ''
if. IFUNIX do.
 lib=: '"libc.so.6"'
 socketJ=: (lib,' socket i i i i')&(15!:0)
 closesocketJ=: (lib,' close i i')&(15!:0)
else.
 lib=: '"wsock32"'
 socketJ=: (lib,' socket i i i i')&(15!:0)
 closesocketJ=: (lib,' closesocket i i')&(15!:0)
 WSAStartupJ=: (lib,' WSAStartup i i *')&(15!:0)
end.
1
)

NB. a small memory leak is expected on the next line
2 = {:15!:1 ((15!:8) 10),0 5 4  NB. reference count

0!:0 <'bin/hostdefs.ijs'
0!:0 <'bin/netdefs.ijs'

18!:4 <'base'
coinsert 'jdefs'

res=: >@:{.
sdinit=: 3 : 0''
SOCKETS=: ''
if. IFUNIX do. 0 return. end.
if. 0~:res WSAStartupJ 257;1000$' ' do. _1 else. 0 end.
)

sdclose=: 3 : 0"0
if. 0=res closesocketJ <y do.
  0[SOCKETS=: SOCKETS-.y
else.
  sdsockerror ''
end.
)

sdsocket=: 3 : 0"1
s=. res socketJ <"0 [3{.y,(0=#y)#PF_INET,SOCK_STREAM,IPPROTO_TCP
if. s=_1 do. 0;~sdsockerror'' return. end.
SOCKETS=: SOCKETS,s
0;s
)

cderx=: 15!:11
sdsockerror=: 3 : '> {. cderx '''''

NB.0 -: sdclose>1{sdsocket''  NB. all systems

test=: 1:

t=: 100 ?@$ 1e6
t -:      15!:1 (15!:14 <'t'),0,(*/$t),3!:0 t
t=: 100 4 ?@$ 0
t -: ($t)$15!:1 (15!:14 <'t'),0,(*/$t),3!:0 t

'domain error' -: 15!:6  etx <'test'
'domain error' -: 15!:6  etx ;:'t test'
'domain error' -: 15!:14 etx <'test'
'domain error' -: 15!:14 etx ;:'t test'

'value error'  -: 15!:6  etx <'undefinedname'
'value error'  -: 15!:6  etx ;:'t undefinedname'
'value error'  -: 15!:14 etx <'undefinedname'
'value error'  -: 15!:14 etx ;:'t undefinedname'

4!:55 ;:'CREATE_NEW FILE_BEGIN FILE_CURRENT FILE_END GENERIC_READ '
4!:55 ;:'GENERIC_WRITE OPEN_EXISTING '
4!:55 ;:'Fclose Fcopyto Fcreate Fcreatedir Fdelete Fdeletedir Fmoveto Fread '
4!:55 ;:'Fsetptr Fsize Fwrite '
NB. 4!:55 ;:'cderx fclose fcopyto fcreate fcreatedir fdelete fdeletedir fmoveto '
NB. 4!:55 ;:'fopen fread fsetptr fsize fwrite '
NB. 4!:55 ;:'h i pc s t test'
NB. 4!:55 ;:'res sdclose sdsocket'


