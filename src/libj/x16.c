/* Copyright 1990-2011, Jsoftware Inc.  All rights reserved. */
/* Copyright 2016, Thomas Costigliola.  All rights reserved. */
/* License in license.txt.                                   */
/*                                                                         */
/* Xenos: CSV Parsing                                                      */

#include "j.h"
#include "x.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

F1(jcsvread1);
F2(jcsvread2);
static A csvread(J jt, C *fn, I db, I da, B h, C *t, I tn);
static void csvscan(FILE *f, char *b, size_t n, I db, I da, B h, size_t *nb, I *nrows, I *ncols);
static void csvparse(FILE *f, char *b, size_t n, I db, I da, B h, I maxcols, J jt, A *zv, C *ct, I ctn);

#define csvread1(x)   jtcsvread1(jt,(x))
#define csvread2(x,y) jtcsvread2(jt,(x),(y))

F1(jtcsvread1){
  RZ(w);
  R csvread2(str(1,"l"),w);
}

F2(jtcsvread2){A y, z, *zv;C *b; size_t n; I db, da; B h; I rows, cols; FILE *f;
    RZ(a&&w);
    ASSERT(LIT&AT(a), EVDOMAIN);
    if(AR(a)>1||AR(w)>0)R rank2ex(mtv,w,0L,1L,0L,jtcsvread2);
    //y=csvread(jt, CAV(str0(AAV0(w))), 0, 0, 1, CAV(a), AN(a));
    n = 1024;
    b = (C *)malloc(sizeof(C) * n);
    f = fopen(CAV(str0(AAV0(w))), "r");
    csvscan(f, b, n, 0, 0, 0, &n, &rows, &cols);
    rewind(f);

    GA(z,BOX, rows * cols, 2, 0);
    z->s[0] = rows;
    z->s[1] = cols;
    zv = AAV(z);
    //printf("%lldx%lld\n", rows, cols);

    a = reitem(sc(cols),a);

    csvparse(f, b, n, 0, 0, 0, cols, jt, zv, CAV(a), cols);
    
    free(b);
    
    R z;
}

static void csvscan(FILE *f, char *b, size_t n, I db, I da, B h, size_t *nb, I *nrows, I *ncols)
{
  char *p, *q; // Positions of previous and next delimiters in b
  size_t m; // Current read ahead 
  char *d = "\n\",";
  bool s = false;
  int rows = 0, cols = 1, maxcols = 1;

  p = q = b;
  m = n;
  while(fread(p, 1, m, f) > 0) {
    m = n;
    while((q = strpbrk(p, d)) != NULL) {
      if(*q == '\"') {
	if(s && *(q+1) == '\"') {
	  q++;
	} else {
	  s = !s;
	}
      } 
      else if(*q == ',' && !s) {
	cols++;
	if(cols > maxcols) maxcols = cols;
      }
      else if(*q == '\n' && !s) {
	cols = 0;
	rows++;
      }
      p = q + 1;
    }
    if(p == b) {
      // Resize the scanning buffer
      n = 2*n;
      b = (char *)realloc(b, n);
      p = b + n;
    } else {
      memmove(b, p, n - (p - b));
      p = b;
    }
  }

  *nrows = rows;
  *ncols = maxcols;
  *nb = n;
}
// f  - File pointer
// b  - Buffer for file scanning
// n  - Buffer size
// db - # of rows to drop rows from beginning of file
// da - # of rows to drop at end of file
// h  - True if the first non-dropped row is a header row

static void csvparse(FILE *f, char *b, size_t n, I db, I da, B h, I maxcols, J jt, A *zv, C *ct, I ctn)
{
  char *p, *q; // Positions of previous and next delimiters in b
  size_t m; // Current read ahead 
  char *d = "\n\",", *ctc = "ln";
  bool s = false, ignore = false;
  int row = 0, col = 0;
  A y;

  p = q = b;
  m = n;
  while(fread(p, 1, m, f) > 0) {
    m = n;
    while((q = strpbrk(p, d)) != NULL) {
      if(*q == '\"') {
	if(s) {
	  if(*(q+1) == '\"') {
	    *zv = over(*zv, str(1, "\""));
	    q++;
	  } else {
	    *zv++ = str(q - p, p);
	    s = false;
	    ignore = true;
	  }
	} else {
	  s = true;
	}
      }
      else if(*q == ',' && !s) {
	if(!ignore) {
	  y = ct[col] == 'n' ? connum(q - p, p) : str(q - p, p);
	  if(!y) {
	    RESETERR;
	    y = str(q - p, p);
	  }
	  *zv++ = y;
	}
	col++;
	ignore = false;
      }
      else if(*q == '\n' && !s) {
	if(!ignore) {
	  y = ct[col] == 'n' ? connum(q - p, p) : str(q - p, p);
	  if(!y) {
	    RESETERR;
	    y = str(q - p, p);
	  }
	  *zv++ = y;
	}
	col++;
	while(col < maxcols) {
	  *zv++ = str(0, "");
	  col++;
	}
	col = 0;
	row++;
	ignore = false;
      }
      p = q + 1;
    }
    if(p == b) {
      // Resize the scanning buffer
      n = 2*n;
      b = (char *)realloc(b, n);
      p = b + n;
    } else {
      memmove(b, p, n - (p - b));
      p = b;
    }
  }  
}
// f  - File pointer
// b  - Buffer for file scanning
// n  - Buffer size
// db - # of rows to drop rows from beginning of file
// da - # of rows to drop at end of file
// h  - True if the first non-dropped row is a header row
// ct - Column types: l - literal, n - numeric
// ctn - # of columns in specified by ct
