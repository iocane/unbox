/* Copyright 1990-2011, Jsoftware Inc.  All rights reserved. */
/* License in license.txt.                                   */
/*                                                                         */
/* Verbs: Atomic (Scalar) Dyadic                                           */

#include "j.h"
#include "ve.h"


static VA va[]={
/*       */ {
 {{(VF)0,0}, {(VF)0,0}, {(VF)0,0},                                /* BB BI BD              */
  {(VF)0,0}, {(VF)0,0}, {(VF)0,0},                                /* IB II ID              */
  {(VF)0,0}, {(VF)0,0}, {(VF)0,0},                                /* DB DI DD              */
  {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}},                        /* ZZ XX QQ Symb         */
 {{(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}},   /* ins: B I D Z X Q Symb */
 {{(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}},   /* pfx: B I D Z X Q Symb */
 {{(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}, {(VF)0,0}} }, /* sfx: B I D Z X Q Symb */

/* 10    */ {
 {{(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI+VII}, 
  {(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI},     {(VF)bw0000II,  VI+VII},
  {(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI+VII},
  {(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI+VII}, {(VF)bw0000II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0000insI,VI+VII}, {(VF)bw0000insI,VI}},
 {{(VF)bw0000pfxI,VI+VII}, {(VF)bw0000pfxI,VI}},
 {{(VF)bw0000sfxI,VI+VII}, {(VF)bw0000sfxI,VI}} },

/* 11    */ {
 {{(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI+VII}, 
  {(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI},     {(VF)bw0001II,  VI+VII},
  {(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI+VII},
  {(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI+VII}, {(VF)bw0001II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0001insI,VI+VII}, {(VF)bw0001insI,VI}},
 {{(VF)bw0001pfxI,VI+VII}, {(VF)bw0001pfxI,VI}},
 {{(VF)bw0001sfxI,VI+VII}, {(VF)bw0001sfxI,VI}} },

/* 12    */ {
 {{(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI+VII}, 
  {(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI},     {(VF)bw0010II,  VI+VII},
  {(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI+VII},
  {(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI+VII}, {(VF)bw0010II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0010insI,VI+VII}, {(VF)bw0010insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw0010sfxI,VI+VII}, {(VF)bw0010sfxI,VI}} },

/* 13    */ {
 {{(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI+VII}, 
  {(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI},     {(VF)bw0011II,  VI+VII},
  {(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI+VII},
  {(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI+VII}, {(VF)bw0011II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0011insI,VI+VII}, {(VF)bw0011insI,VI}},
 {{(VF)bw0011pfxI,VI+VII}, {(VF)bw0011pfxI,VI}},
 {{(VF)bw0011sfxI,VI+VII}, {(VF)bw0011sfxI,VI}} },

/* 14    */ {
 {{(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI+VII}, 
  {(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI},     {(VF)bw0100II,  VI+VII},
  {(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI+VII},
  {(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI+VII}, {(VF)bw0100II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0100insI,VI+VII}, {(VF)bw0100insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw0100sfxI,VI+VII}, {(VF)bw0100sfxI,VI}} },

/* 15    */ {
 {{(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI+VII}, 
  {(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI},     {(VF)bw0101II,  VI+VII},
  {(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI+VII},
  {(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI+VII}, {(VF)bw0101II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0101insI,VI+VII}, {(VF)bw0101insI,VI}},
 {{(VF)bw0101pfxI,VI+VII}, {(VF)bw0101pfxI,VI}},
 {{(VF)bw0101sfxI,VI+VII}, {(VF)bw0101sfxI,VI}} },

/* 16    */ {
 {{(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI+VII}, 
  {(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI},     {(VF)bw0110II,  VI+VII},
  {(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI+VII},
  {(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI+VII}, {(VF)bw0110II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0110insI,VI+VII}, {(VF)bw0110insI,VI}},
 {{(VF)bw0110pfxI,VI+VII}, {(VF)bw0110pfxI,VI}},
 {{(VF)bw0110sfxI,VI+VII}, {(VF)bw0110sfxI,VI}} },

/* 17    */ {
 {{(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI+VII}, 
  {(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI},     {(VF)bw0111II,  VI+VII},
  {(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI+VII},
  {(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI+VII}, {(VF)bw0111II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw0111insI,VI+VII}, {(VF)bw0111insI,VI}},
 {{(VF)bw0111pfxI,VI+VII}, {(VF)bw0111pfxI,VI}},
 {{(VF)bw0111sfxI,VI+VII}, {(VF)bw0111sfxI,VI}} },

/* 18    */ {
 {{(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI+VII}, 
  {(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI},     {(VF)bw1000II,  VI+VII},
  {(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI+VII},
  {(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI+VII}, {(VF)bw1000II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1000insI,VI+VII}, {(VF)bw1000insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw1000sfxI,VI+VII}, {(VF)bw1000sfxI,VI}} },

/* 19    */ {
 {{(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI+VII}, 
  {(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI},     {(VF)bw1001II,  VI+VII},
  {(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI+VII},
  {(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI+VII}, {(VF)bw1001II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1001insI,VI+VII}, {(VF)bw1001insI,VI}},
 {{(VF)bw1001pfxI,VI+VII}, {(VF)bw1001pfxI,VI}},
 {{(VF)bw1001sfxI,VI+VII}, {(VF)bw1001sfxI,VI}} },

/* 1a    */ {
 {{(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI+VII}, 
  {(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI},     {(VF)bw1010II,  VI+VII},
  {(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI+VII},
  {(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI+VII}, {(VF)bw1010II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1010insI,VI+VII}, {(VF)bw1010insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw1010sfxI,VI+VII}, {(VF)bw1010sfxI,VI}} },

/* 1b    */ {
 {{(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI+VII}, 
  {(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI},     {(VF)bw1011II,  VI+VII},
  {(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI+VII},
  {(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI+VII}, {(VF)bw1011II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1011insI,VI+VII}, {(VF)bw1011insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw1011sfxI,VI+VII}, {(VF)bw1011sfxI,VI}} },

/* 1c    */ {
 {{(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI+VII}, 
  {(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI},     {(VF)bw1100II,  VI+VII},
  {(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI+VII},
  {(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI+VII}, {(VF)bw1100II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1100insI,VI+VII}, {(VF)bw1100insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw1100sfxI,VI+VII}, {(VF)bw1100sfxI,VI}} },

/* 1d    */ {
 {{(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI+VII}, 
  {(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI},     {(VF)bw1101II,  VI+VII},
  {(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI+VII},
  {(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI+VII}, {(VF)bw1101II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1101insI,VI+VII}, {(VF)bw1101insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw1101sfxI,VI+VII}, {(VF)bw1101sfxI,VI}} },

/* 1e    */ {
 {{(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI+VII}, 
  {(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI},     {(VF)bw1110II,  VI+VII},
  {(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI+VII},
  {(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI+VII}, {(VF)bw1110II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1110insI,VI+VII}, {(VF)bw1110insI,VI}},
 {{(VF)0,0}},
 {{(VF)bw1110sfxI,VI+VII}, {(VF)bw1110sfxI,VI}} },

/* 1f    */ {
 {{(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI+VII}, 
  {(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI},     {(VF)bw1111II,  VI+VII},
  {(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI+VII},
  {(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI+VII}, {(VF)bw1111II,  VI+VII}, {(VF)0,0}}, 
 {{(VF)bw1111insI,VI+VII}, {(VF)bw1111insI,VI}},
 {{(VF)bw1111pfxI,VI+VII}, {(VF)bw1111pfxI,VI}},
 {{(VF)bw1111sfxI,VI+VII}, {(VF)bw1111sfxI,VI}} },

/* 21 !  */ {
 {{(VF)leBB, VB        }, {(VF)binDD,VD+VDD+VRI}, {(VF)binDD,VD+VDD}, 
  {(VF)binDD,VD+VDD+VRI}, {(VF)binDD,VD+VDD+VRI}, {(VF)binDD,VD+VDD}, 
  {(VF)binDD,VD+VDD    }, {(VF)binDD,VD+VDD    }, {(VF)binDD,VD    }, 
  {(VF)binZZ,VZ+VZZ}, {(VF)binXX,VX+VXX}, {(VF)binQQ,VX+VQQ}, {(VF)0,0}}, 
 {{(VF)leinsB,VB}},
 {{(VF)lepfxB,VB}},
 {{(VF)lesfxB,VB}} },

/* 25 %  */ {
 {{(VF)divBB,VD}, {(VF)divBI,VD}, {(VF)divBD,VD},
  {(VF)divIB,VD}, {(VF)divII,VD}, {(VF)divID,VD},
  {(VF)divDB,VD}, {(VF)divDI,VD}, {(VF)divDD,VD}, 
  {(VF)divZZ,VZ+VZZ}, {(VF)divXX,VX+VXX}, {(VF)divQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)divinsD,VD+VDD}, {(VF)divinsD,VD+VDD}, {(VF)divinsD,VD}, {(VF)divinsZ,VZ}},
 {{(VF)divpfxD,VD+VDD}, {(VF)divpfxD,VD+VDD}, {(VF)divpfxD,VD}, {(VF)divpfxZ,VZ}},
 {{(VF)divsfxD,VD+VDD}, {(VF)divsfxD,VD+VDD}, {(VF)divsfxD,VD}, {(VF)divsfxZ,VZ}} },

/* 2a *  */ {
 {{(VF)andBB,  VB}, {(VF)tymesBI,VI}, {(VF)tymesBD,VD},
  {(VF)tymesIB,VI}, {(VF)tymesII,VI}, {(VF)tymesID,VD},
  {(VF)tymesDB,VD}, {(VF)tymesDI,VD}, {(VF)tymesDD,VD}, 
  {(VF)tymesZZ,VZ+VZZ}, {(VF)tymesXX,VX+VXX}, {(VF)tymesQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)andinsB,VB}, {(VF)tymesinsI,VI}, {(VF)tymesinsD,VD}, {(VF)tymesinsZ,VZ}, {(VF)0,0},          {(VF)0,0},          {(VF)0,0}},
 {{(VF)andpfxB,VB}, {(VF)tymespfxI,VI}, {(VF)tymespfxD,VD}, {(VF)tymespfxZ,VZ}, {(VF)tymespfxX,VX}, {(VF)tymespfxQ,VQ}, {(VF)0,0}},
 {{(VF)andsfxB,VB}, {(VF)tymessfxI,VI}, {(VF)tymessfxD,VD}, {(VF)tymessfxZ,VZ}, {(VF)tymessfxX,VX}, {(VF)tymessfxQ,VQ}, {(VF)0,0}} },

/* 2b +  */ {
 {{(VF)plusBB,VI    }, {(VF)plusII,VI+VII}, {(VF)plusBD,VD}, 
  {(VF)plusII,VI+VII}, {(VF)plusII,VI    }, {(VF)plusID,VD}, 
  {(VF)plusDB,VD    }, {(VF)plusDI,VD    }, {(VF)plusDD,VD}, 
  {(VF)plusZZ,VZ+VZZ}, {(VF)plusXX,VX+VXX}, {(VF)plusQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)plusinsB,VI}, {(VF)plusinsI,VI}, {(VF)plusinsD,VD}, {(VF)plusinsZ,VZ}, {(VF)0,0},         {(VF)0,0},         {(VF)0,0}},
 {{(VF)pluspfxB,VI}, {(VF)pluspfxI,VI}, {(VF)pluspfxD,VD}, {(VF)pluspfxZ,VZ}, {(VF)pluspfxX,VX}, {(VF)pluspfxQ,VQ}, {(VF)0,0}},
 {{(VF)plussfxB,VI}, {(VF)plussfxI,VI}, {(VF)plussfxD,VD}, {(VF)plussfxZ,VZ}, {(VF)plussfxX,VX}, {(VF)plussfxQ,VQ}, {(VF)0,0}} },

/* 2d -  */ {
 {{(VF)minusBB,VI    }, {(VF)minusII,VI+VII}, {(VF)minusBD,VD}, 
  {(VF)minusII,VI+VII}, {(VF)minusII,VI    }, {(VF)minusID,VD},
  {(VF)minusDB,VD    }, {(VF)minusDI,VD    }, {(VF)minusDD,VD}, 
  {(VF)minusZZ,VZ+VZZ}, {(VF)minusXX,VX+VXX}, {(VF)minusQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)minusinsB,VI}, {(VF)minusinsI,VI}, {(VF)minusinsD,VD}, {(VF)minusinsZ,VZ}, {(VF)0,0},          {(VF)0,0},          {(VF)0,0}},
 {{(VF)minuspfxB,VI}, {(VF)minuspfxI,VI}, {(VF)minuspfxD,VD}, {(VF)minuspfxZ,VZ}, {(VF)minuspfxX,VX}, {(VF)minuspfxQ,VQ}, {(VF)0,0}},
 {{(VF)minussfxB,VI}, {(VF)minussfxI,VI}, {(VF)minussfxD,VD}, {(VF)minussfxZ,VZ}, {(VF)0,0},          {(VF)0,0},          {(VF)0,0}} },

/* 3c <  */ {
 {{(VF)ltBB,VB}, {(VF)ltBI,VB}, {(VF)ltBD,VB},
  {(VF)ltIB,VB}, {(VF)ltII,VB}, {(VF)ltID,VB},
  {(VF)ltDB,VB}, {(VF)ltDI,VB}, {(VF)ltDD,VB}, 
  {(VF)ltDD,VB+VDD}, {(VF)ltXX,VB+VXFC}, {(VF)ltQQ,VB+VQQ}, {(VF)ltSS,VB}},
 {{(VF)ltinsB,VB}},
 {{(VF)ltpfxB,VB}},
 {{(VF)ltsfxB,VB}} },

/* 3d =  */ {
 {{(VF)eqBB,VB}, {(VF)eqBI,VB}, {(VF)eqBD,VB},
  {(VF)eqIB,VB}, {(VF)eqII,VB}, {(VF)eqID,VB},
  {(VF)eqDB,VB}, {(VF)eqDI,VB}, {(VF)eqDD,VB}, 
  {(VF)eqZZ,VB+VZZ}, {(VF)eqXX,VB+VXEQ}, {(VF)eqQQ,VB+VQQ}, {(VF)eqII,VB}},
 {{(VF)eqinsB,VB}},
 {{(VF)eqpfxB,VB}},
 {{(VF)eqsfxB,VB}} },

/* 3e >  */ {
 {{(VF)gtBB,VB}, {(VF)gtBI,VB}, {(VF)gtBD,VB},
  {(VF)gtIB,VB}, {(VF)gtII,VB}, {(VF)gtID,VB},
  {(VF)gtDB,VB}, {(VF)gtDI,VB}, {(VF)gtDD,VB}, 
  {(VF)gtDD,VB+VDD}, {(VF)gtXX,VB+VXCF}, {(VF)gtQQ,VB+VQQ}, {(VF)gtSS,VB}},
 {{(VF)gtinsB,VB}},
 {{(VF)gtpfxB,VB}},
 {{(VF)gtsfxB,VB}} },

/* 5e ^  */ {
 {{(VF)geBB, VB}, {(VF)powBI,VD}, {(VF)powBD,VD},
  {(VF)powIB,VI}, {(VF)powII,VD}, {(VF)powID,VD},
  {(VF)powDB,VD}, {(VF)powDI,VD}, {(VF)powDD,VD}, 
  {(VF)powZZ,VZ+VZZ}, {(VF)powXX,VX+VXX}, {(VF)powQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)geinsB,VB}},
 {{(VF)gepfxB,VB}},
 {{(VF)gesfxB,VB}} },

/* 7c |  */ {
 {{(VF)ltBB, VB    }, {(VF)remII,VI+VII}, {(VF)remDD,VD+VDD},
  {(VF)remII,VI+VII}, {(VF)remII,VI    }, {(VF)remID,VI    },
  {(VF)remDD,VD+VDD}, {(VF)remDD,VD+VDD}, {(VF)remDD,VD    }, 
  {(VF)remZZ,VZ+VZZ}, {(VF)remXX,VX+VXX}, {(VF)remQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)ltinsB,VB}},
 {{(VF)ltpfxB,VB}},
 {{(VF)ltsfxB,VB}} },

/* 82 <. */ {
 {{(VF)andBB,VB}, {(VF)minBI,VI}, {(VF)minBD,VD},
  {(VF)minIB,VI}, {(VF)minII,VI}, {(VF)minID,VD},
  {(VF)minDB,VD}, {(VF)minDI,VD}, {(VF)minDD,VD}, 
  {(VF)minDD,VD+VDD}, {(VF)minXX,VX+VXX}, {(VF)minQQ,VQ+VQQ}, {(VF)minSS,VSB}},
 {{(VF)andinsB,VB}, {(VF)mininsI,VI}, {(VF)mininsD,VD}, {(VF)mininsD,VD+VDD}, {(VF)mininsX,VX}, {(VF)0,0},        {(VF)mininsS,VSB}},
 {{(VF)andpfxB,VB}, {(VF)minpfxI,VI}, {(VF)minpfxD,VD}, {(VF)minpfxD,VD+VDD}, {(VF)minpfxX,VX}, {(VF)minpfxQ,VQ}, {(VF)minpfxS,VSB}},
 {{(VF)andsfxB,VB}, {(VF)minsfxI,VI}, {(VF)minsfxD,VD}, {(VF)minsfxD,VD+VDD}, {(VF)minsfxX,VX}, {(VF)minsfxQ,VQ}, {(VF)minsfxS,VSB}}},

/* 83 <: */ {
 {{(VF)leBB,VB}, {(VF)leBI,VB}, {(VF)leBD,VB},
  {(VF)leIB,VB}, {(VF)leII,VB}, {(VF)leID,VB},
  {(VF)leDB,VB}, {(VF)leDI,VB}, {(VF)leDD,VB}, 
  {(VF)leDD,VB+VDD}, {(VF)leXX,VB+VXCF}, {(VF)leQQ,VB+VQQ}, {(VF)leSS,VB}},
 {{(VF)leinsB,VB}},
 {{(VF)lepfxB,VB}},
 {{(VF)lesfxB,VB}} },

/* 84 >. */ {
 {{(VF) orBB,VB}, {(VF)maxBI,VI}, {(VF)maxBD,VD},
  {(VF)maxIB,VI}, {(VF)maxII,VI}, {(VF)maxID,VD},
  {(VF)maxDB,VD}, {(VF)maxDI,VD}, {(VF)maxDD,VD}, 
  {(VF)maxDD,VD+VDD}, {(VF)maxXX,VX+VXX}, {(VF)maxQQ,VQ+VQQ}, {(VF)maxSS,VSB}},
 {{(VF)orinsB,VB}, {(VF)maxinsI,VI}, {(VF)maxinsD,VD}, {(VF)maxinsD,VD+VDD}, {(VF)maxinsX,VX}, {(VF)0,0},        {(VF)maxinsS,VSB}},
 {{(VF)orpfxB,VB}, {(VF)maxpfxI,VI}, {(VF)maxpfxD,VD}, {(VF)maxpfxD,VD+VDD}, {(VF)maxpfxX,VX}, {(VF)maxpfxQ,VQ}, {(VF)maxpfxS,VSB}},
 {{(VF)orsfxB,VB}, {(VF)maxsfxI,VI}, {(VF)maxsfxD,VD}, {(VF)maxsfxD,VD+VDD}, {(VF)maxsfxX,VX}, {(VF)maxsfxQ,VQ}, {(VF)maxsfxS,VSB}}},

/* 85 >: */ {
 {{(VF)geBB,VB}, {(VF)geBI,VB}, {(VF)geBD,VB},
  {(VF)geIB,VB}, {(VF)geII,VB}, {(VF)geID,VB},
  {(VF)geDB,VB}, {(VF)geDI,VB}, {(VF)geDD,VB}, 
  {(VF)geDD,VB+VDD}, {(VF)geXX,VB+VXFC}, {(VF)geQQ,VB+VQQ}, {(VF)geSS,VB}},
 {{(VF)geinsB,VB}},
 {{(VF)gepfxB,VB}},
 {{(VF)gesfxB,VB}} },

/* 88 +. */ {
 {{(VF) orBB,VB    }, {(VF)gcdII,VI+VII}, {(VF)gcdDD,VD+VDD},
  {(VF)gcdII,VI+VII}, {(VF)gcdII,VI    }, {(VF)gcdDD,VD+VDD},
  {(VF)gcdDD,VD+VDD}, {(VF)gcdDD,VD+VDD}, {(VF)gcdDD,VD    }, 
  {(VF)gcdZZ,VZ+VZZ}, {(VF)gcdXX,VX+VXX}, {(VF)gcdQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)orinsB,VB}},
 {{(VF)orpfxB,VB}},
 {{(VF)orsfxB,VB}} },

/* 89 +: */ {
 {{(VF)norBB,VB    }, {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB},
  {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB},
  {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB}, 
  {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB}, {(VF)norBB,VB+VBB}, {(VF)0,0}},
 {{(VF)norinsB,VB}},
 {{(VF)norpfxB,VB}},
 {{(VF)norsfxB,VB}} },

/* 8a *. */ {
 {{(VF)andBB,VB    }, {(VF)lcmII,VI+VII}, {(VF)lcmDD,VD+VDD},
  {(VF)lcmII,VI+VII}, {(VF)lcmII,VI    }, {(VF)lcmDD,VD+VDD},
  {(VF)lcmDD,VD+VDD}, {(VF)lcmDD,VD+VDD}, {(VF)lcmDD,VD    }, 
  {(VF)lcmZZ,VZ+VZZ}, {(VF)lcmXX,VX+VXX}, {(VF)lcmQQ,VQ+VQQ}, {(VF)0,0}},
 {{(VF)andinsB,VB}},
 {{(VF)andpfxB,VB}},
 {{(VF)andsfxB,VB}} },

/* 8b *: */ {
 {{(VF)nandBB,VB    }, {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB},
  {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB},
  {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB}, 
  {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB}, {(VF)nandBB,VB+VBB}, {(VF)0,0}},
 {{(VF)nandinsB,VB}},
 {{(VF)nandpfxB,VB}},
 {{(VF)nandsfxB,VB}} },

/* 95 ~: */ {
 {{(VF)neBB,VB}, {(VF)neBI,VB}, {(VF)neBD,VB},
  {(VF)neIB,VB}, {(VF)neII,VB}, {(VF)neID,VB},
  {(VF)neDB,VB}, {(VF)neDI,VB}, {(VF)neDD,VB}, 
  {(VF)neZZ,VB+VZZ}, {(VF)neXX,VB+VXEQ}, {(VF)neQQ,VB+VQQ}, {(VF)0,0}},
 {{(VF)neinsB,VB}},
 {{(VF)nepfxB,VB}},
 {{(VF)nesfxB,VB}} },

/* d1 o. */ {
 {{(VF)cirDD,VD+VDD}, {(VF)cirDD,VD+VDD}, {(VF)cirBD,VD},
  {(VF)cirDD,VD+VDD}, {(VF)cirDD,VD+VDD}, {(VF)cirID,VD},
  {(VF)cirDD,VD+VDD}, {(VF)cirDD,VD+VDD}, {(VF)cirDD,VD}, 
  {(VF)cirZZ,VZ+VZZ+VRD}, {(VF)cirDD,VD+VDD}, {(VF)cirDD,VD+VDD}, {(VF)0,0}},
 {{(VF)0,0}},
 {{(VF)0,0}},
 {{(VF)0,0}} }
};

static UC vaptr[256]={
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* 0 */
 1,  2,  3,  4,  5,  6,  7,  8,    9, 10, 11, 12, 13, 14, 15, 16, /* 1 */
 0, 17,  0,  0,  0, 18,  0,  0,    0,  0, 19, 20,  0, 21,  0,  0, /* 2 */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0, 22, 23, 24,  0, /* 3 */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* 4 */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0, 25,  0, /* 5 */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* 6 */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0, 26,  0,  0,  0, /* 7 */
 0,  0, 27, 28, 29, 30,  0,  0,   31, 32, 33, 34,  0,  0,  0,  0, /* 8 */
 0,  0,  0,  0,  0, 35,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* 9 */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* a */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* b */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* c */
 0,  0,  0, 36,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* d */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* e */
 0,  0,  0,  0,  0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0, /* f */
};   /* index in va[] for each ID */
/*   1   2   3   4   5   6   7     8   9   a   b   c   d   e   f   */

C jtvaid(J jt,A w){A x;C c;I k;V*v;
 v=VAV(w); c=v->id;
 if(c==CBDOT){x=v->f; if(INT&AT(x)&&!AR(x)&&(k=*AV(x),16<=k&&k<=31))c=(C)k;}
 R vaptr[(UC)c]?c:0;
}

static A jtva2(J,A,A,C);

F2(jtbitwise0000){R va2(a,w,(C)16);}
F2(jtbitwise0001){R va2(a,w,(C)17);}
F2(jtbitwise0010){R va2(a,w,(C)18);}
F2(jtbitwise0011){R va2(a,w,(C)19);}

F2(jtbitwise0100){R va2(a,w,(C)20);}
F2(jtbitwise0101){R va2(a,w,(C)21);}
F2(jtbitwise0110){R va2(a,w,(C)22);}
F2(jtbitwise0111){R va2(a,w,(C)23);}

F2(jtbitwise1000){R va2(a,w,(C)24);}
F2(jtbitwise1001){R va2(a,w,(C)25);}
F2(jtbitwise1010){R va2(a,w,(C)26);}
F2(jtbitwise1011){R va2(a,w,(C)27);}

F2(jtbitwise1100){R va2(a,w,(C)28);}
F2(jtbitwise1101){R va2(a,w,(C)29);}
F2(jtbitwise1110){R va2(a,w,(C)30);}
F2(jtbitwise1111){R va2(a,w,(C)31);}

F2(jteq     ){R va2(a,w,CEQ     );}
F2(jtlt     ){R va2(a,w,CLT     );}
F2(jtminimum){R va2(a,w,CMIN    );}
F2(jtle     ){R va2(a,w,CLE     );}
F2(jtgt     ){R va2(a,w,CGT     );}
F2(jtmaximum){R va2(a,w,CMAX    );}
F2(jtge     ){R va2(a,w,CGE     );}
F2(jtplus   ){R va2(a,w,CPLUS   );}
F2(jtgcd    ){R va2(a,w,CPLUSDOT);}
F2(jtnor    ){R va2(a,w,CPLUSCO );}
F2(jttymes  ){R va2(a,w,CSTAR   );}
F2(jtlcm    ){R va2(a,w,CSTARDOT);}
F2(jtnand   ){R va2(a,w,CSTARCO );}
F2(jtminus  ){R va2(a,w,CMINUS  );}
F2(jtdivide ){R va2(a,w,CDIV    );}
F2(jtexpn2  ){R va2(a,w,CEXP    );}
F2(jtne     ){R va2(a,w,CNE     );}
F2(jtoutof  ){R va2(a,w,CBANG   );}
F2(jtcircle ){R va2(a,w,CCIRCLE );}
F2(jtresidue){RZ(a&&w); R INT&AT(w)&&equ(a,num[2])?intmod2(w):va2(a,w,CSTILE);}

F1(jtnot   ){R w&&AT(w)&B01+SB01?va2(zero,w,CEQ):va2(one,w,CMINUS);}
F1(jtnegate){R va2(zero,  w,     CMINUS);}
F1(jtdecrem){R va2(w,     one,   CMINUS);}
F1(jtincrem){R va2(one,   w,     CPLUS );}
F1(jtduble ){R va2(num[2],w,     CSTAR );}
F1(jtsquare){R va2(w,     w,     CSTAR );}
F1(jtrecip ){R va2(one,   w,     CDIV  );}
F1(jthalve ){R va2(w,     num[2],CDIV  );}

static void zeroF(J jt,B b,I m,I n,B*z,void*x,void*y){memset(z,C0,m*n);}
static void  oneF(J jt,B b,I m,I n,B*z,void*x,void*y){memset(z,C1,m*n);}

A jtcvz(J jt,I cv,A w){I t;
 t=AT(w);
 if(cv&VRD&&t!=FL )R pcvt(FL,w);
 if(cv&VRI&&t!=INT)R icvt(w);
 R w;
}    /* convert result */

I atype(I cv){
 if(!(cv&VBB+VII+VDD+VZZ+VQQ+VXX+VXEQ+VXCF+VXFC))R 0;
 R cv&VBB?B01:cv&VII?INT:cv&VDD?FL:cv&VZZ?CMPX:cv&VQQ?RAT:XNUM;
}    /* argument conversion */
     
I rtype(I cv){R cv&VB?B01:cv&VI?INT:cv&VD?FL:cv&VZ?CMPX:cv&VQ?RAT:cv&VX?XNUM:SBT;}
     /* result type */

     
#define VAF(fname,ptr,fp,fm,ft)   \
 void fname(J jt,C id,I t,VF*ado,I*cv){VA2*p;  \
  if(jt->jerr==EWOV){                          \
   jt->jerr=0;                                 \
   *ado=(id==CPLUS?fp:id==CMINUS?fm:ft);       \
   *cv=VD;                                     \
  }else if(t&NUMERIC+SBT){                     \
   p=(va+vaptr[(UC)id])->ptr+(t&B01?0:t&INT?1:t&FL?2:t&CMPX?3:t&XNUM?4:t&RAT?5:6);  \
   *ado=p->f; *cv=p->cv;                       \
  }else *ado=0;                                \
 }

VAF(jtvains,pins, plusinsO,minusinsO,tymesinsO)
VAF(jtvapfx,ppfx, pluspfxO,minuspfxO,tymespfxO)
VAF(jtvasfx,psfx, plussfxO,minussfxO,tymessfxO)

#define VARCASE(e,c) (70*(e)+(c))

B jtvar(J jt,C id,A a,A w,I at,I wt,VF*ado,I*cv){B b;I j,t,x;VA*q;VA2 p;
 if(jt->jerr){
  switch(VARCASE(jt->jerr,id)){
   default:      R 0;
   case VARCASE(EWIMAG,CCIRCLE ): *ado=(VF)cirZZ;   *cv=VZ+VZZ+VRD; break;
   case VARCASE(EWIMAG,CEXP    ): *ado=(VF)powZZ;   *cv=VZ+VZZ+VRD; break;
   case VARCASE(EWIRR ,CBANG   ): *ado=(VF)binDD;   *cv=VD+VDD;     break;
   case VARCASE(EWIRR ,CEXP    ): *ado=(VF)powDD;   *cv=VD+VDD;     break;
   case VARCASE(EWRAT ,CDIV    ): *ado=(VF)divQQ;   *cv=VQ+VQQ;     break;
   case VARCASE(EWRAT ,CEXP    ): *ado=(VF)powQQ;   *cv=VQ+VQQ;     break;
   case VARCASE(EWDIV0,CDIV    ): *ado=(VF)divDD;   *cv=VD+VDD;     break;
   case VARCASE(EWOV  ,CPLUS   ): *ado=(VF)plusIO;  *cv=VD+VII;     break;
   case VARCASE(EWOV  ,CMINUS  ): *ado=(VF)minusIO; *cv=VD+VII;     break;
   case VARCASE(EWOV  ,CSTAR   ): *ado=(VF)tymesIO; *cv=VD+VII;     break;
   case VARCASE(EWOV  ,CPLUSDOT): *ado=(VF)gcdIO;   *cv=VD+VII;     break;
   case VARCASE(EWOV  ,CSTARDOT): *ado=(VF)lcmIO;   *cv=VD+VII;     break;
   case VARCASE(EWOV  ,CSTILE  ): *ado=(VF)remDD;   *cv=VD+VDD;     break;
  }
  RESETERR;
 }else if(at&NUMERIC&&wt&NUMERIC){
  t=at|wt; b=1&&t&RAT+XNUM+XD+XZ;
  j=t&CMPX ? 9 : b ? (t&XZ?13:t&XD?12:t&FL?8:t&RAT?11:10) : 
      (at&B01?0:at&INT?3:6)+(wt&B01?0:wt&INT?1:2);
  q=va+vaptr[(UC)id];
  p=(q->p2)[j];
  *ado=p.f; *cv=x=p.cv; if(b&&t&FL&&!(x&VZZ))*cv+=VDD;
 }else{
  b=!HOMO(at,wt); *cv=VB;
  jt->rela=ARELATIVE(a)*(I)a;
  jt->relw=ARELATIVE(w)*(I)w;
  switch(id){
   case CEQ: *ado=b?(VF)zeroF:at&SBT?(VF)eqII:at&BOX?(VF)eqAA:
                  at&LIT?(wt&LIT?(VF)eqCC:(VF)eqCS):wt&LIT?(VF)eqSC:(VF)eqSS; break;
   case CNE: *ado=b?(VF) oneF:at&SBT?(VF)neII:at&BOX?(VF)neAA:
                  at&LIT?(wt&LIT?(VF)neCC:(VF)neCS):wt&LIT?(VF)neSC:(VF)neSS; break;
   default:
    ASSERT(at&SBT&&wt&SBT,EVDOMAIN);
    q=va+vaptr[(UC)id]; p=(q->p2)[12];
    ASSERT(p.f,EVDOMAIN);
    *ado=p.f; *cv=x=p.cv;
 }}
 R 1;
}    /* function and control for rank */

static A jtva2(J jt,A a,A w,C id){A z;B b,c,sp=0;C*av,*wv,*zv;I acr,af,ak,an,ar,*as,at,cv,f,m,
     mf,n,nf,*oq=jt->rank,r,*s,*sf,t,wcr,wf,wk,wn,wr,*ws,wt,zk,zn,zt;VF ado;
 RZ(a&&w);
 an=AN(a); ar=AR(a); as=AS(a); at=an?AT(a):B01; 
 wn=AN(w); wr=AR(w); ws=AS(w); wt=wn?AT(w):B01;
 if(id==CEXP&&1==wn&&FL&wt&&0.5==*DAV(w))R sqroot(a);
 if(SPARSE&at){sp=1; at=DTYPE(at);}
 if(SPARSE&wt){sp=1; wt=DTYPE(wt);}
 RZ(var(id,a,w,at,wt,&ado,&cv)); zt=rtype(cv); t=atype(cv);
 if(t&&!sp){
  b=1&&t&XNUM;
  if(t!=at)RZ(a=b?xcvt(cv&VXEQ?XMEXMT:cv&VXFC?XMFLR:cv&VXCF?XMCEIL:XMEXACT,a):cvt(t,a));
  if(t!=wt)RZ(w=b?xcvt(cv&VXEQ?XMEXMT:cv&VXCF?XMFLR:cv&VXFC?XMCEIL:XMEXACT,w):cvt(t,w));
 }
 if(jt->rank){I acn,q,wcn,zcn;
  r=jt->rank[0]; acr=MIN(ar,r); af=ar-acr; acn=prod(acr,as+af);
  r=jt->rank[1]; wcr=MIN(wr,r); wf=wr-wcr; wcn=prod(wcr,ws+wf); jt->rank=0;
  ASSERT(!ICMP(as,ws,MIN(af,wf))&&!ICMP(as+af,ws+wf,MIN(acr,wcr)),EVLENGTH);
  c=af<=wf; f=c?wf:af; q=c?af:wf; sf=c?ws:as;
  b=acr<=wcr; zcn=b?wcn:acn; m=b?acn:wcn; n=m?zcn/m:0; r=b?wcr:acr; s=b?ws+wf:as+af;
  if(zcn){RE(mf=prod(q,sf)); RE(nf=prod(f-q,q+sf));}else mf=nf=0;
  if(!sp){RE(zn=mult(mf,mult(nf,zcn))); zk=zcn*bp(zt); ak=acn*bp(AT(a)); wk=wcn*bp(AT(w));}
 }else{
  ASSERT(!ICMP(as,ws,MIN(ar,wr)),EVLENGTH);
  ak=wk=zk=af=wf=f=c=0; acr=ar; wcr=wr; sf=0; mf=nf=1;
  b=ar<=wr; zn=b?wn:an; m=b?an:wn; n=m?zn/m:0; r=b?wr:ar; s=b?ws:as;
 }
 if(sp){z=vasp(a,w,id,ado,cv,t,zt,af,acr,wf,wcr,f,r); if(!jt->jerr)R z;}
 else{
  GA(z,zt,zn,f+r,sf); ICPY(f+AS(z),s,r); 
  if(!zn)R z;
  av=CAV(a); wv=CAV(w); zv=CAV(z);
  if(1==nf) DO(mf,        ado(jt,b,m,n,zv,av,wv); zv+=zk; av+=ak; wv+=wk;)
  else if(c)DO(mf, DO(nf, ado(jt,b,m,n,zv,av,wv); zv+=zk;         wv+=wk;); av+=ak;)
  else      DO(mf, DO(nf, ado(jt,b,m,n,zv,av,wv); zv+=zk; av+=ak;        ); wv+=wk;);
  if(!jt->jerr)R cv&VRI+VRD?cvz(cv,z):z;
 }
 R NEVM<jt->jerr?(jt->rank=oq,va2(a,w,id)):0;
}    /* scalar fn primitive and f"r main control */

/*
 acn wcn zcn  # atoms in a cell
 acr wcr r    cell rank
 af  wf  f    frame
 ak  wk  zk   # bytes in a cell
 an  wn  zn   overall # atoms
 ar  wr  f+r  overall rank

 b    1 iff cell rank of a <= cell rank of w
 c    1 iff frame     of a <= frame of w
 m    # of atoms in the cell with the smaller rank
 mf   agreed # of frames
 n    excess # of cell atoms
 nf   excess # of frames
 f    max of frame of a, frame of w
 q    min of frame of a, frame of w
 r    max of cell rank  of a, cell rank  of w
 s    max of cell shape of a, cell shape of w
 sf   max of frame shape of a, frame shape of w
*/



static DF2(jtsumattymes){A z;B b;I an,ar,*as,at,m,n,nn,r,*s,t,wn,wr,*ws,wt,zn;
 RZ(a&&w&&self);
 an=AN(a); ar=AR(a); as=AS(a); at=an?AT(a):B01;
 wn=AN(w); wr=AR(w); ws=AS(w); wt=wn?AT(w):B01; 
 t=maxtype(at,wt); b=ar<=wr; r=b?wr:ar; s=b?ws:as; nn=*s;
 zn=(b?wn:an)/nn; m=(b?an:wn)/nn; m=m?m:1; n=zn/m;
 switch(t){
  case B01:
   {B*av=BAV(a),u,*wv=BAV(w);I*zu,*zv;
    GA(z,INT,zn,r-1,1+s); zu=AV(z);
    if(1==n){
              zv=zu; DO(m,                     *zv++ =*av++**wv++;);
     DO(nn-1, zv=zu; DO(m,                     *zv+++=*av++**wv++;););
    }else if(b){
              zv=zu; DO(m, u=*av++;      DO(n, *zv++ =u**wv++;););
     DO(nn-1, zv=zu; DO(m, u=*av++; if(u)DO(n, *zv+++=u**wv++;) else wv+=n;););
    }else{
              zv=zu; DO(m, u=*wv++;      DO(n, *zv++ =u**av++;););
     DO(nn-1, zv=zu; DO(m, u=*wv++; if(u)DO(n, *zv+++=u**av++;) else av+=n;););
   }}
   break;
#if !SY_64
  case INT:
   {D u,*zu,*zv;I*av=AV(a),*wv=AV(w);
    GA(z,FL,zn,r-1,1+s); zu=DAV(z);
    if(1==n){
              zv=zu; DO(m,                        *zv++ =*av++*(D)*wv++;);
     DO(nn-1, zv=zu; DO(m,                        *zv+++=*av++*(D)*wv++;););
    }else if(b){
              zv=zu; DO(m, u=(D)*av++;      DO(n, *zv++ =u**wv++;););
     DO(nn-1, zv=zu; DO(m, u=(D)*av++; if(u)DO(n, *zv+++=u**wv++;) else wv+=n;););
    }else{
              zv=zu; DO(m, u=(D)*wv++;      DO(n, *zv++ =u**av++;););
     DO(nn-1, zv=zu; DO(m, u=(D)*wv++; if(u)DO(n, *zv+++=u**av++;) else av+=n;););
    }
    RZ(z=icvt(z));
   }
   break;
#endif
  case FL:   
   {D*av=DAV(a),u,v,*wv=DAV(w),*zu,*zv;
    GA(z,FL,zn,r-1,1+s); zu=DAV(z);
    NAN0;
    if(1==n){
              zv=zu; DO(m, u=*av++;            v=*wv++; *zv++ =u&&v?u*v:0;  );
     DO(nn-1, zv=zu; DO(m, u=*av++;            v=*wv++; *zv+++=u&&v?u*v:0;  ););
    }else if(b){
              zv=zu; DO(m, u=*av++;      DO(n, v=*wv++; *zv++ =u&&v?u*v:0;););
     DO(nn-1, zv=zu; DO(m, u=*av++; if(u)DO(n, v=*wv++; *zv+++=   v?u*v:0;) else wv+=n;););
    }else{
              zv=zu; DO(m, u=*wv++;      DO(n, v=*av++; *zv++ =u&&v?u*v:0;););
     DO(nn-1, zv=zu; DO(m, u=*wv++; if(u)DO(n, v=*av++; *zv+++=   v?u*v:0;) else av+=n;););
    }
    NAN1;
 }}
 R z;
}    /* a +/@:* w for non-scalar a and w */

static C sumbf[]={CSTARDOT,CMIN,CSTAR,CPLUSDOT,CMAX,CEQ,CNE,CSTARCO,CPLUSCO,CLT,CLE,CGT,CGE};

#define SUMBFLOOPW(BF)     \
 {DO(q, memset(tv,C0,p); DO(255, DO(dw,tv[i]+=BF(*u,*v); ++u; ++v;);); DO(zn,zv[i]+=tu[i];));  \
        memset(tv,C0,p); DO(r,   DO(dw,tv[i]+=BF(*u,*v); ++u; ++v;);); DO(zn,zv[i]+=tu[i];) ;  \
 }
#define SUMBFLOOPX(BF)     \
 {DO(q, memset(tv,C0,p); DO(255, DO(dw,tv[i]+=BF(*u,*v); ++u; ++v;);                           \
                               av+=zn; u=(UI*)av; wv+=zn; v=(UI*)wv;); DO(zn,zv[i]+=tu[i];));  \
        memset(tv,C0,p); DO(r,   DO(dw,tv[i]+=BF(*u,*v); ++u; ++v;);                           \
                               av+=zn; u=(UI*)av; wv+=zn; v=(UI*)wv;); DO(zn,zv[i]+=tu[i];) ;  \
 }
#if SY_ALIGN
#define SUMBFLOOP(BF)   SUMBFLOOPW(BF)
#else
#define SUMBFLOOP(BF)   if(zn%SZI)SUMBFLOOPX(BF) else SUMBFLOOPW(BF)
#endif

static A jtsumatgbool(J jt,A a,A w,C id){A t,z;B*av,*wv;I dw,n,p,q,r,*s,zn,*zv;UC*tu;UI*tv,*u,*v;
 RZ(a&&w);
 s=AS(w); n=*s;
 zn=AN(w)/n; dw=(zn+SZI-1)/SZI; p=dw*SZI;
 q=n/255; r=n%255;
 GA(z,INT,zn,AR(w)-1,1+s); zv=AV(z); memset(zv,C0,zn*SZI);
 GA(t,INT,dw,1,0); tu=(UC*)AV(t); tv=(UI*)tu;
 av=BAV(a); u=(UI*)av; 
 wv=BAV(w); v=(UI*)wv;
 switch(id){
  case CMIN: 
  case CSTAR: 
  case CSTARDOT: SUMBFLOOP(AND ); break;
  case CMAX:
  case CPLUSDOT: SUMBFLOOP(OR  ); break;
  case CEQ:      SUMBFLOOP(EQ  ); break;
  case CNE:      SUMBFLOOP(NE  ); break;
  case CSTARCO:  SUMBFLOOP(NAND); break;
  case CPLUSCO:  SUMBFLOOP(NOR ); break;
  case CLT:      SUMBFLOOP(LT  ); break;
  case CLE:      SUMBFLOOP(LE  ); break;
  case CGT:      SUMBFLOOP(GT  ); break;
  case CGE:      SUMBFLOOP(GE  ); break;
 }
 R z;
}    /* a +/@:g w  for boolean a,w where a-:&(* /@$)w; see also plusinsB */

DF2(jtfslashatg){A fs,gs,y,z;B b,bb,sb=0;C*av,c,d,*wv;I ak,an,ar,*as,at,cv,cvf,m,
     n,nn,r,*s,t,wk,wn,wr,*ws,wt,yt,zn,zt;V*sv;VF ado,adof;
 RZ(a&&w&&self);
 an=AN(a); ar=AR(a); as=AS(a); at=an?AT(a):B01; sv=VAV(self); 
 wn=AN(w); wr=AR(w); ws=AS(w); wt=wn?AT(w):B01; b=ar<=wr; r=b?wr:ar; s=b?ws:as; nn=r?*s:1;
 ASSERT(!ICMP(as,ws,MIN(ar,wr)),EVLENGTH);
 if(SPARSE&(at|wt)||!an||!wn||2>nn){b=CFORK==sv->id; R df1(df2(a,w,b?sv->h:sv->g),b?sv->g:sv->f);}
 zn=(b?wn:an)/nn; m=(b?an:wn)/nn; m=m?m:1; n=zn/m;
 if(CFORK==sv->id){fs=sv->g; gs=sv->h;}else{fs=sv->f; gs=sv->g;}
 y=VAV(fs)->f; c=ID(y); d=ID(gs);
 RZ(var(d,mtv,mtv,at,wt,&ado, &cv )); yt=rtype(cv ); t=atype(cv);
 RZ(var(c,mtv,mtv,yt,yt,&adof,&cvf)); zt=rtype(cvf);
 if(c==CPLUS){
  if(at&B01&&wt&B01&&1==n&&(0==zn%SZI||!SY_ALIGN)&&strchr(sumbf,d))R sumatgbool(a,w,d);
  if(d==CSTAR){
   if(ar&&wr&&at==wt&&at&B01+FL+(INT*!SY_64))R sumattymes(a,w,self);
   if(!ar||!wr){
    z=!ar?tymes(a,df1(w,fs)):tymes(w,df1(a,fs));
    if(jt->jerr==EVNAN)RESETERR else R z;
  }}
  sb=1&&yt&B01;
 }
 if(!(sb||yt==zt))R df1(df2(a,w,gs),fs);
 if(t){
  bb=1&&t&XNUM;
  if(t!=at)RZ(a=bb?xcvt(cv&VXEQ?XMEXMT:cv&VXFC?XMFLR:cv&VXCF?XMCEIL:XMEXACT,a):cvt(t,a));
  if(t!=wt)RZ(w=bb?xcvt(cv&VXEQ?XMEXMT:cv&VXCF?XMFLR:cv&VXFC?XMCEIL:XMEXACT,w):cvt(t,w));
 }
 ak=(an/nn)*bp(AT(a)); wk=(wn/nn)*bp(AT(w));  
 GA(y,yt,zn,1,0); 
 GA(z,zt,zn,r-1,1+s);
 if(sb){A t;I j,tn,*zv;UC*tc;UI*ti,*yv;  /* +/@:g for boolean-valued g */
  av=CAV(a); wv=CAV(w); yv=(UI*)AV(y); zv=AV(z); memset(zv,C0,zn*SZI);
  tn=(zn+SZI-1)/SZI; GA(t,INT,tn,1,0); tc=(UC*)AV(t); ti=(UI*)tc;
  for(j=nn;0<j;j-=255){
   memset(ti,C0,tn*SZI); 
   DO(MIN(j,255), ado(jt,b,m,n,yv,av,wv); av+=ak; wv+=wk; DO(tn,ti[i]+=yv[i];););
   DO(zn, zv[i]+=tc[i];);
 }}else{A z1;B p=0;C*yv,*zu,*zv;
  av=CAV(a)+ak*(nn-1); wv=CAV(w)+wk*(nn-1); yv=CAV(y); zv=CAV(z);
  GA(z1,zt,zn,r-1,1+s); zu=CAV(z1);
  ado(jt,b,m,n,zv,av,wv);
  DO(nn-1, av-=ak; wv-=wk; ado(jt,b,m,n,yv,av,wv); adof(jt,b,zn,1L,p?zv:zu,yv,p?zu:zv); p=!p;);
  if(NEVM<jt->jerr){jt->jerr=0; z=df1(df2(a,w,gs),fs);}else if(p)z=z1;
 }
 RE(0); R z;
}    /* a f/@:g w */
