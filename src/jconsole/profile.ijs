NB. Global switches
IF64=:64=9!:64''
UNAME=: >(;:'Linux Win WinCE')#~'IFUNIX IFWIN IFWINCE'=: 5 6 7 = 9!:12''

0!:0 <BINPATH,'/util.ijs'

NB. Run the scirpt in the first argument
3 : 0''
 if. 2>#ARGV do. return. end.
 if. '-'={.runscript=:1{::ARGV do. return. end.
 9!:27'0!:0 <runscript'
 9!:29]1
)

NB. Handle the -sym2ijs flag
3 : 0''
 if. -.ARGV e.~ <'-sym2ijs' do. return. end.
 NB. -sym2ijs path symfile
 0!:0 <'src/libj/defs/sym2ijs.ijs'
 NB. -test [inputdir [outputdir [script1 script2...]]]
 t=. ARGV (>:@i.}.[) <'-sym2ijs'
 if. 0=#t do. return. end.
 sympath=: '/',~0{::t
 if. 1=#t do. return. end.
 symfile=: 1{::t
 9!:27'2!:55[0[sympath sym2ijs symfile'
 9!:29]1
)

NB. Handle the -js flag
3 : 0''
 if. -.ARGV e.~ <'-js' do. return. end.
 runsentence=: ;ARGV (>:@i.{[) <'-js'
 9!:27 runsentence
 9!:29]1
)

NB. Handle -test flag
3 : 0''
 if. -.ARGV e.~ <'-test' do. return. end.
 0!:0 <'test/test.ijs'
 NB. -test [inputdir [outputdir [script1 script2...]]]
 t=. ARGV (>:@i.}.[) <'-test'
 if. 0=#t do. return. end.
 testpath=: '/',~0{::t
 if. 1=#t do. return. end.
 resultpath=: '/',~1{::t
 if. 2=#t do. return. end.
 testscripts=: 2}.t
 9!:27'(testpath;resultpath) runtests testscripts'
 9!:29]1
)

NB. Handle the -debug flag
3 : 0''
 if. -.ARGV e.~ <'-debug' do. return. end.
 0!:0 <'test/test.ijs'
 NB. -debug script
 debugscript=: ARGV (>:@i.}.[) <'-debug'
 9!:27'0!:2{.debugscript'
 9!:29]1
)

