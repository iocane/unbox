NB. Constants
LF=: 10{a.
CR=: 13{a.
CRLF=: CR,LF
TAB=: 9{a.

NB. Basic utilities
each=: &.>
deb=: #~ (+. (1: |. (> </\)))@(' '&~:)
boxopen=: <^:(L. = 0:)
toJ=: ((10{a.) I.@(e.&(13{a.))@]} ])@:(#~ -.@((13 10{a.)&E.@,))
pick=: >@{
fboxname=: boxopen
boxxopen=: <^:(L. < *@#)
coname_z_=: 18!:5
cocurrent_z_=: 18!:4@boxxopen f.
coinsert_z_=: 3 : 0
n=. ;: :: ] y
p=. ; (, 18!:2) @ < each n
p=. ~. (18!:2 coname''), p
(p /: p = <,'z') 18!:2 coname''
)
   
ic=: 3!:4
fc=: 3!:5
cd=: 15!:0
cder=: 15!:10
memr=: 15!:1
memw=: 15!:2
mema=: 15!:3
memf=: 15!:4
JINT=: 4

fgets=: 3 : 0
y=. (-(26{a.)={:y) }. y
if. 0=#y do. '' return. end.
y,LF -. {:y=. toJ y
)

freads=: 3 : 0
'' freads y
:
dat=. fread y
if. (dat -: _1) +. 0=#dat do. return. end.
dat=. fgets dat
if. 'b'e.x do. dat=. <;._2 dat
elseif. 'm'e.x do. dat=. ];._2 dat
end.
)

fread=: 3 : 0
if. 1 = #y=. boxopen y do.
  1!:1 :: _1:  y
else.
  1!:11 :: _1: ({.y),{:y
end.
:
x freads y
)

stringreplace=: 4 : 0
txt=. ,y
t=. _2 [\ ,x
old=. {."1 t
new=. {:"1 t
oldlen=. # &> old
newlen=. # &> new

if. *./ 1 = oldlen do.

  hit=. (;old) i. txt
  ndx=. I. hit < #old

  if. 0 e. $ndx do. txt return. end.

  cnt=. 1
  exp=. hit { newlen,1
  hnx=. ndx { hit
  bgn=. ndx + +/\ 0, (}: hnx) { newlen - 1

else.

  hit=. old I. @ E. each <txt
  cnt=. # &> hit

  if. 0 = +/ cnt do. txt return. end.

  bgn=. set=. ''

  pick=. > @ {
  diff=. }. - }:

  for_i. I. 0 < cnt do.
    ln=. i pick oldlen
    cx=. (i pick hit) -. set, ,bgn -/ i.ln
    while. 0 e. b=. 1, <:/\ ln <: diff cx do. cx=. b#cx end.
    hit=. (<cx) i} hit
    bgn=. bgn, cx
    set=. set, ,cx +/ i.ln
  end.

  cnt=. # &> hit
  msk=. 0 < cnt
  exp=. (#txt) $ 1
  del=. newlen - oldlen

  if. #add=. I. msk *. del > 0 do.
    exp=. (>: (add{cnt) # add{del) (;add{hit) } exp
  end.

  if. #sub=. I. msk *. del < 0 do.
    sbx=. ; (;sub{hit) + each (sub{cnt) # i. each sub{del
    exp=. 0 sbx } exp
  end.

  hit=. ; hit
  ind=. /: (#hit) $ 1 2 3
  hnx=. (/: ind { hit) { ind
  bgn=. (hnx { hit) + +/\ 0, }: hnx { cnt # del

end.

ind=. ; bgn + each hnx { cnt # i.each newlen
rep=. ; hnx { cnt # new
rep ind} exp # txt
)

rplc=: stringreplace~

cutopen=: 3 : 0
y cutopen~ (' ',LF) {~ LF e. ,y
:
if. L. y do. y return. end.
if. 1 < #$y do. <"_1 y return. end.
(<'') -.~ (y e.x) <;._2 y=. y,1{.x
)

fwrites=: 4 : '(fputs x) (#@[ [ 1!:2) :: _1: fboxname y'

fputs=: 3 : 0
dat=. ":y
if. 0 e. $dat do.
  ''
else.
  if. 1>:#$dat do.
    toHOST dat,(-.({:dat) e. CRLF) # LF
  else.
    ,dat,"1 toHOST LF
  end.
end.
)

toHOST=: ]

 
