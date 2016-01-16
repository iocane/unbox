NB. utilities for J GPL source release test
NB. assumes J GPL source folder is current directory
NB. see test/tsu.ijs for additional info

0!:0 <'test/tsu.ijs'

9!:21[1e8       NB. limit error rather than long memory thrash (g400)
threshold=: 0.1 NB. timer threshold failures less likely
NB. libtsdll=: jpath ' ',~(1!:43''),'/libtsdll.',>(UNAME-:'Darwin'){'so';'dylib'

TDIR=:0&{::
RDIR=:1&{::
TEST=:2&{::
testpass=: 0['1' 1!:2 <@(RDIR,TEST,'.pass'"_)
testfail=: 1[1!:2&2@(TDIR,TEST,': failed',(10{a.),13!:12@(''"_))
runtest=: testfail ` testpass @. (0!:3@<@(TDIR,TEST))
runtests=: 2!:55@:(*./@:,)@:(runtest@:,"1 0)
failedtests=: {."1@(1!:0)@(],'*.fail'"_)

