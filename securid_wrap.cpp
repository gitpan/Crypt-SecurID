/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.17u-20030124-1156
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#ifdef __cplusplus
template<class T> class SwigValueWrapper {
    T *tt;
public:
    inline SwigValueWrapper() : tt(0) { }
    inline ~SwigValueWrapper() { if (tt) delete tt; } 
    inline SwigValueWrapper& operator=(const T& t) { tt = new T(t); return *this; }
    inline operator T&() const { return *tt; }
    inline T *operator&() { return tt; }
};                                                    
#endif

/***********************************************************************
 * common.swg
 *
 *     This file contains generic SWIG runtime support for pointer
 *     type checking as well as a few commonly used macros to control
 *     external linkage.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 *
 * Copyright (c) 1999-2000, The University of Chicago
 * 
 * This file may be freely redistributed without license or fee provided
 * this copyright message remains intact.
 ************************************************************************/

#include <string.h>

#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) extern a
#               else
#                       define SWIGEXPORT(a) __declspec(dllexport) a
#                       define SWIGIMPORT(a) extern a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define SWIGEXPORT(a) a _export
#                       define SWIGIMPORT(a) a _export
#               else
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) a
#               endif
#       endif
#else
#       define SWIGEXPORT(a) a
#       define SWIGIMPORT(a) a
#endif

#ifdef SWIG_GLOBAL
#define SWIGRUNTIME(a) SWIGEXPORT(a)
#else
#define SWIGRUNTIME(a) static a
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

typedef struct swig_type_info {
  const char             *name;                 
  swig_converter_func     converter;
  const char             *str;
  void                   *clientdata;	
  swig_dycast_func        dcast;
  struct swig_type_info  *next;
  struct swig_type_info  *prev;
} swig_type_info;

#ifdef SWIG_NOINCLUDE

SWIGIMPORT(swig_type_info *) SWIG_TypeRegister(swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeCheck(char *c, swig_type_info *);
SWIGIMPORT(void *)           SWIG_TypeCast(swig_type_info *, void *);
SWIGIMPORT(swig_type_info *) SWIG_TypeDynamicCast(swig_type_info *, void **);
SWIGIMPORT(swig_type_info *) SWIG_TypeQuery(const char *);
SWIGIMPORT(void)             SWIG_TypeClientData(swig_type_info *, void *);

#else

static swig_type_info *swig_type_list = 0;

/* Register a type mapping with the type-checking */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeRegister(swig_type_info *ti)
{
  swig_type_info *tc, *head, *ret, *next;
  /* Check to see if this type has already been registered */
  tc = swig_type_list;
  while (tc) {
    if (strcmp(tc->name, ti->name) == 0) {
      /* Already exists in the table.  Just add additional types to the list */
      if (tc->clientdata) ti->clientdata = tc->clientdata;	
      head = tc;
      next = tc->next;
      goto l1;
    }
    tc = tc->prev;
  }
  head = ti;
  next = 0;

  /* Place in list */
  ti->prev = swig_type_list;
  swig_type_list = ti;

  /* Build linked lists */
 l1:
  ret = head;
  tc = ti + 1;
  /* Patch up the rest of the links */
  while (tc->name) {
    head->next = tc;
    tc->prev = head;
    head = tc;
    tc++;
  }
  head->next = next;
  return ret;
}

/* Check the typename */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeCheck(char *c, swig_type_info *ty)
{
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  do {
    if (strcmp(s->name,c) == 0) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
	s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      return s;
    }
    s = s->next;
  } while (s && (s != ty->next));
  return 0;
}

/* Cast a pointer up an inheritance hierarchy */
SWIGRUNTIME(void *) 
SWIG_TypeCast(swig_type_info *ty, void *ptr) 
{
  if ((!ty) || (!ty->converter)) return ptr;
  return (*ty->converter)(ptr);
}

/* Dynamic pointer casting. Down an inheritance hierarchy */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) 
{
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
     ty = (*ty->dcast)(ptr);
     if (ty) lastty = ty;
  }
  return lastty;
}

/* Search for a swig_type_info structure */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeQuery(const char *name) {
  swig_type_info *ty = swig_type_list;
  while (ty) {
    if (ty->str && (strcmp(name,ty->str) == 0)) return ty;
    if (ty->name && (strcmp(name,ty->name) == 0)) return ty;
    ty = ty->prev;
  }
  return 0;
}

/* Set the clientdata field for a type */
SWIGRUNTIME(void)
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_type_info *tc, *equiv;
  if (ti->clientdata == clientdata) return;
  ti->clientdata = clientdata;
  equiv = ti->next;
  while (equiv) {
    if (!equiv->converter) {
      tc = swig_type_list;
      while (tc) {
	if ((strcmp(tc->name, equiv->name) == 0))
	  SWIG_TypeClientData(tc,clientdata);
	tc = tc->prev;
      }
    }
    equiv = equiv->next;
  }
}
#endif

#ifdef __cplusplus
}

#endif

/* -----------------------------------------------------------------------------
 * perl5.swg
 *
 * Perl5 runtime library
 * $Header: /usr/local/home/pliam/cvsroot/securid/securid_wrap.cpp,v 1.3 2003/01/27 03:32:41 pliam Exp $
 * ----------------------------------------------------------------------------- */

#define SWIGPERL
#define SWIGPERL5
#ifdef __cplusplus
/* Needed on some windows machines---since MS plays funny
   games with the header files under C++ */
#include <math.h>
#include <stdlib.h>
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* Get rid of free and malloc defined by perl */
#undef free
#undef malloc

#ifndef pTHX_
#define pTHX_
#endif

#include <string.h>
#ifdef __cplusplus
}
#endif

/* Macro to call an XS function */

#ifdef PERL_OBJECT 
#define SWIG_CALLXS(_name) _name(cv,pPerl) 
#else 
#ifndef MULTIPLICITY 
#define SWIG_CALLXS(_name) _name(cv) 
#else 
#define SWIG_CALLXS(_name) _name(PERL_GET_THX, cv) 
#endif 
#endif 

/* Macros for low-level exception handling */
#define SWIG_fail      goto fail
#define SWIG_croak(x)  { if ((_swigerr = (const char *) x)) goto fail; }
#define SWIG_MAX_ERRMSG 256

/* Note: SwigMagicFuncHack is a typedef used to get the C++
   compiler to just shut up already */

#ifdef PERL_OBJECT
#define MAGIC_PPERL  CPerlObj *pPerl = (CPerlObj *) this;
typedef int (CPerlObj::*SwigMagicFunc)(SV *, MAGIC *);

#ifdef __cplusplus
extern "C" {
#endif
typedef int (CPerlObj::*SwigMagicFuncHack)(SV *, MAGIC *);
#ifdef __cplusplus
}
#endif

#define SWIG_MAGIC(a,b) (SV *a, MAGIC *b)
#define SWIGCLASS_STATIC
#else
#define MAGIC_PPERL
#define SWIGCLASS_STATIC static
#ifndef MULTIPLICITY
#define SWIG_MAGIC(a,b) (SV *a, MAGIC *b)
typedef int (*SwigMagicFunc)(SV *, MAGIC *);

#ifdef __cplusplus
extern "C" {
#endif
typedef int (*SwigMagicFuncHack)(SV *, MAGIC *);
#ifdef __cplusplus
}
#endif


#else
#define SWIG_MAGIC(a,b) (struct interpreter *interp, SV *a, MAGIC *b)
typedef int (*SwigMagicFunc)(struct interpreter *, SV *, MAGIC *);
#ifdef __cplusplus
extern "C" {
#endif
typedef int (*SwigMagicFuncHack)(struct interpreter *, SV *, MAGIC *);
#ifdef __cplusplus
}
#endif

#endif
#endif

#if defined(WIN32) && defined(PERL_OBJECT) && !defined(PerlIO_exportFILE)
#define PerlIO_exportFILE(fh,fl) (FILE*)(fh)
#endif

/* Modifications for newer Perl 5.005 releases */

#if !defined(PERL_REVISION) || ((PERL_REVISION >= 5) && ((PERL_VERSION < 5) || ((PERL_VERSION == 5) && (PERL_SUBVERSION < 50))))
#ifndef PL_sv_yes
#define PL_sv_yes sv_yes
#endif
#ifndef PL_sv_undef
#define PL_sv_undef sv_undef
#endif
#ifndef PL_na
#define PL_na na
#endif
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SWIG_NOINCLUDE

#ifndef PERL_OBJECT
extern int SWIG_ConvertPtr(SV *, void **, swig_type_info *, int flags);
extern void SWIG_MakePtr(SV *, void *, swig_type_info *, int flags);
#else
extern int _SWIG_ConvertPtr(CPerlObj *, SV *, void **, swig_type_info *,int flags);
extern void _SWIG_MakePtr(CPerlObj *, SV *, void *, swig_type_info *, int flags);
#define SWIG_ConvertPtr(a,b,c,d) _SWIG_ConvertPtr(pPerl,a,b,c,d)
#define SWIG_MakePtr(a,b,c,d) _SWIG_MakePtr(pPerl,a,b,c,d)
#endif

#else

/* Function for getting a pointer value */

#ifndef PERL_OBJECT
SWIGRUNTIME(int) 
SWIG_ConvertPtr(SV *sv, void **ptr, swig_type_info *_t, int flags)
#else
#define SWIG_ConvertPtr(a,b,c,d) _SWIG_ConvertPtr(pPerl,a,b,c,d)
SWIGRUNTIME(int)
_SWIG_ConvertPtr(CPerlObj *pPerl, SV *sv, void **ptr, swig_type_info *_t, int flags)
#endif
{
  char *_c;
  swig_type_info *tc;
  IV   tmp;

  /* If magical, apply more magic */
  if (SvGMAGICAL(sv))
    mg_get(sv);

  /* Check to see if this is an object */
  if (sv_isobject(sv)) {
    SV *tsv = (SV*) SvRV(sv);
    if ((SvTYPE(tsv) == SVt_PVHV)) {
      MAGIC *mg;
      if (SvMAGICAL(tsv)) {
	mg = mg_find(tsv,'P');
	if (mg) {
	  SV *rsv = mg->mg_obj;
	  if (sv_isobject(rsv)) {
	    tmp = SvIV((SV*)SvRV(rsv));
	  }
	}
      } else {
	return -1;
      }
    } else {
      tmp = SvIV((SV*)SvRV(sv));
    }
    if (!_t) {
      *(ptr) = (void *) tmp;
      return 0;
    }
  } else if (! SvOK(sv)) {            /* Check for undef */
    *(ptr) = (void *) 0;
    return 0;
  } else if (SvTYPE(sv) == SVt_RV) {  /* Check for NULL pointer */
    *(ptr) = (void *) 0;
    if (!SvROK(sv)) 
      return 0;
    else
      return -1;
  } else {                            /* Don't know what it is */
      *(ptr) = (void *) 0;
      return -1;
  }
  if (_t) {
    /* Now see if the types match */      
    _c = HvNAME(SvSTASH(SvRV(sv)));
    tc = SWIG_TypeCheck(_c,_t);
    if (!tc) {
      *ptr = (void *) tmp;
      return -1;
    }
    *ptr = SWIG_TypeCast(tc,(void *)tmp);
    return 0;
  }
  *ptr = (void *) tmp;
  return 0;
}
#ifndef PERL_OBJECT
SWIGRUNTIME(void) 
SWIG_MakePtr(SV *sv, void *ptr, swig_type_info *t,int flags)
#else
#define SWIG_MakePtr(a,b,c,d) _SWIG_MakePtr(pPerl,a,b,c,d)
SWIGRUNTIME(void)
_SWIG_MakePtr(CPerlObj *pPerl, SV *sv, void *ptr, swig_type_info *t, int flags)
#endif
{
  sv_setref_pv(sv, (char *) t->name, ptr);
}

#endif

typedef XS(SwigPerlWrapper);
typedef SwigPerlWrapper *SwigPerlWrapperPtr;

/* Structure for command table */
typedef struct {
  const char         *name;
  SwigPerlWrapperPtr  wrapper;
} swig_command_info;

/* Information for constant table */

#define SWIG_INT     1
#define SWIG_FLOAT   2
#define SWIG_STRING  3
#define SWIG_POINTER 4
#define SWIG_BINARY  5

/* Constant information structure */
typedef struct swig_constant_info {
    int              type;
    const char      *name;
    long             lvalue;
    double           dvalue;
    void            *pvalue;
    swig_type_info **ptype;
} swig_constant_info;

#ifdef __cplusplus
}
#endif

/* Structure for variable table */
typedef struct {
  const char   *name;
  SwigMagicFunc   set;
  SwigMagicFunc   get;
  swig_type_info  **type;
} swig_variable_info;

/* Magic variable code */
#ifndef PERL_OBJECT
#define swig_create_magic(s,a,b,c) _swig_create_magic(s,a,b,c)
  #ifndef MULTIPLICITY 
       static void _swig_create_magic(SV *sv, char *name, int (*set)(SV *, MAGIC *), int \
(*get)(SV *,MAGIC *)) { 
  #else 
       static void _swig_create_magic(SV *sv, char *name, int (*set)(struct interpreter*,\
 SV *, MAGIC *), int (*get)(struct interpreter*, SV *,MAGIC *)) { 
  #endif 
#else
#define swig_create_magic(s,a,b,c) _swig_create_magic(pPerl,s,a,b,c)
static void _swig_create_magic(CPerlObj *pPerl, SV *sv, const char *name, int (CPerlObj::*set)(SV *, MAGIC *), int (CPerlObj::*get)(SV *, MAGIC *)) {
#endif
  MAGIC *mg;
  sv_magic(sv,sv,'U',(char *) name,strlen(name));
  mg = mg_find(sv,'U');
  mg->mg_virtual = (MGVTBL *) malloc(sizeof(MGVTBL));
  mg->mg_virtual->svt_get = (SwigMagicFuncHack) get;
  mg->mg_virtual->svt_set = (SwigMagicFuncHack) set;
  mg->mg_virtual->svt_len = 0;
  mg->mg_virtual->svt_clear = 0;
  mg->mg_virtual->svt_free = 0;
}







/* -------- TYPES TABLE (BEGIN) -------- */

#define  SWIGTYPE_p_unsigned_char swig_types[0] 
#define  SWIGTYPE_p_SecurID swig_types[1] 
static swig_type_info *swig_types[3];

/* -------- TYPES TABLE (END) -------- */

#define SWIG_init    boot_Crypt__securid

#define SWIG_name   "Crypt::securidc::boot_Crypt__securid"
#define SWIG_prefix "Crypt::securidc::"

#ifdef __cplusplus
extern "C"
#endif
#ifndef PERL_OBJECT
#ifndef MULTIPLICITY
SWIGEXPORT(void) SWIG_init (CV* cv);
#else
SWIGEXPORT(void) SWIG_init (pTHXo_ CV* cv);
#endif
#else
SWIGEXPORT(void) SWIG_init (CV *cv, CPerlObj *);
#endif


#include "securid.h"

#ifdef PERL_OBJECT
#define MAGIC_CLASS _wrap_Crypt::securid_var::
class _wrap_Crypt::securid_var : public CPerlObj {
public:
#else
#define MAGIC_CLASS
#endif
SWIGCLASS_STATIC int swig_magic_readonly(pTHX_ SV *sv, MAGIC *mg) {
    MAGIC_PPERL
    sv = sv; mg = mg;
    croak("Value is read-only.");
    return 0;
}


#ifdef PERL_OBJECT
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
XS(_wrap_new_SecurID) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 0) || (items > 0)) {
            SWIG_croak("Usage: new_SecurID();");
        }
        result = (SecurID *)new SecurID();
        
        ST(argvi) = sv_newmortal();
        SWIG_MakePtr(ST(argvi++), (void *) result, SWIGTYPE_p_SecurID,0);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_new_SecurIDbin) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        unsigned char *arg1 = (unsigned char *) 0 ;
        SecurID *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: new_SecurIDbin(k);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_unsigned_char,0) < 0) {
                SWIG_croak("Type error in argument 1 of new_SecurIDbin. Expected _p_unsigned_char");
            }
        }
        result = (SecurID *)new SecurID((unsigned char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        SWIG_MakePtr(ST(argvi++), (void *) result, SWIGTYPE_p_SecurID,0);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_new_SecurIDhex) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        char *arg1 ;
        SecurID *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: new_SecurIDhex(hk);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (SecurID *)new SecurID((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        SWIG_MakePtr(ST(argvi++), (void *) result, SWIGTYPE_p_SecurID,0);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_setKey) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *arg2 ;
        int result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 2) || (items > 2)) {
            SWIG_croak("Usage: SecurID_setKey(self,hk);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_setKey. Expected _p_SecurID");
            }
        }
        if (!SvOK((SV*) ST(1))) arg2 = 0;
        else arg2 = (char *) SvPV(ST(1), PL_na);
        result = (int)(arg1)->setKey((char const *)arg2);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_key) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: SecurID_key(self);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_key. Expected _p_SecurID");
            }
        }
        result = (char *)(arg1)->key();
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        }else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_drift) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        long result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: SecurID_drift(self);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_drift. Expected _p_SecurID");
            }
        }
        result = (long)(arg1)->drift();
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_code) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        long arg2 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 2) || (items > 2)) {
            SWIG_croak("Usage: SecurID_code(self,tm);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_code. Expected _p_SecurID");
            }
        }
        arg2 = (long) SvIV(ST(1));
        result = (char *)(arg1)->code(arg2);
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        }else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_codeNow) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: SecurID_codeNow(self);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_codeNow. Expected _p_SecurID");
            }
        }
        result = (char *)(arg1)->code();
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        }else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_validate) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *arg2 ;
        long arg3 = (long) 30 ;
        int result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 2) || (items > 3)) {
            SWIG_croak("Usage: SecurID_validate(self,code,days_toler);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_validate. Expected _p_SecurID");
            }
        }
        if (!SvOK((SV*) ST(1))) arg2 = 0;
        else arg2 = (char *) SvPV(ST(1), PL_na);
        if (items > 2) {
            arg3 = (long) SvIV(ST(2));
        }
        result = (int)(arg1)->validate((char const *)arg2,arg3);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_importToken) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *arg2 ;
        char *arg3 ;
        int result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 3) || (items > 3)) {
            SWIG_croak("Usage: SecurID_importToken(self,f,sernum);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_importToken. Expected _p_SecurID");
            }
        }
        if (!SvOK((SV*) ST(1))) arg2 = 0;
        else arg2 = (char *) SvPV(ST(1), PL_na);
        if (!SvOK((SV*) ST(2))) arg3 = 0;
        else arg3 = (char *) SvPV(ST(2), PL_na);
        result = (int)(arg1)->importToken((char const *)arg2,(char const *)arg3);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_exportToken) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *arg2 ;
        char *arg3 ;
        int result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 3) || (items > 3)) {
            SWIG_croak("Usage: SecurID_exportToken(self,f,sernum);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_exportToken. Expected _p_SecurID");
            }
        }
        if (!SvOK((SV*) ST(1))) arg2 = 0;
        else arg2 = (char *) SvPV(ST(1), PL_na);
        if (!SvOK((SV*) ST(2))) arg3 = 0;
        else arg3 = (char *) SvPV(ST(2), PL_na);
        result = (int)(arg1)->exportToken((char const *)arg2,(char const *)arg3);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_SecurID_error) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: SecurID_error(self);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of SecurID_error. Expected _p_SecurID");
            }
        }
        result = (char *)(arg1)->error();
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        }else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}


XS(_wrap_delete_SecurID) {
    char _swigmsg[SWIG_MAX_ERRMSG] = "";
    const char *_swigerr = _swigmsg;
    {
        SecurID *arg1 = (SecurID *) 0 ;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: delete_SecurID(self);");
        }
        {
            if (SWIG_ConvertPtr(ST(0), (void **) &arg1, SWIGTYPE_p_SecurID,0) < 0) {
                SWIG_croak("Type error in argument 1 of delete_SecurID. Expected _p_SecurID");
            }
        }
        delete arg1;
        
        
        XSRETURN(argvi);
        fail:
        (void) _swigerr;
    }
    croak(_swigerr);
}



/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_unsigned_char[] = {{"_p_unsigned_char", 0, "unsigned char *", 0},{"_p_unsigned_char"},{0}};
static swig_type_info _swigt__p_SecurID[] = {{"Crypt::securid::SecurID", 0, "SecurID *", 0},{"Crypt::securid::SecurID"},{0}};

static swig_type_info *swig_types_initial[] = {
_swigt__p_unsigned_char, 
_swigt__p_SecurID, 
0
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

static swig_constant_info swig_constants[] = {
{0}
};
#ifdef __cplusplus
}
#endif
static swig_variable_info swig_variables[] = {
{0}
};
static swig_command_info swig_commands[] = {
{"Crypt::securidc::new_SecurID", _wrap_new_SecurID},
{"Crypt::securidc::new_SecurIDbin", _wrap_new_SecurIDbin},
{"Crypt::securidc::new_SecurIDhex", _wrap_new_SecurIDhex},
{"Crypt::securidc::SecurID_setKey", _wrap_SecurID_setKey},
{"Crypt::securidc::SecurID_key", _wrap_SecurID_key},
{"Crypt::securidc::SecurID_drift", _wrap_SecurID_drift},
{"Crypt::securidc::SecurID_code", _wrap_SecurID_code},
{"Crypt::securidc::SecurID_codeNow", _wrap_SecurID_codeNow},
{"Crypt::securidc::SecurID_validate", _wrap_SecurID_validate},
{"Crypt::securidc::SecurID_importToken", _wrap_SecurID_importToken},
{"Crypt::securidc::SecurID_exportToken", _wrap_SecurID_exportToken},
{"Crypt::securidc::SecurID_error", _wrap_SecurID_error},
{"Crypt::securidc::delete_SecurID", _wrap_delete_SecurID},
{0,0}
};

#ifdef __cplusplus
extern "C"
#endif

XS(SWIG_init) {
    dXSARGS;
    int i;
    static int _init = 0;
    if (!_init) {
        for (i = 0; swig_types_initial[i]; i++) {
            swig_types[i] = SWIG_TypeRegister(swig_types_initial[i]);
        }
        _init = 1;
    }
    
    /* Install commands */
    for (i = 0; swig_commands[i].name; i++) {
        newXS((char*) swig_commands[i].name,swig_commands[i].wrapper, (char*)__FILE__);
    }
    
    /* Install variables */
    for (i = 0; swig_variables[i].name; i++) {
        SV *sv;
        sv = perl_get_sv((char*) swig_variables[i].name, TRUE | 0x2);
        if (swig_variables[i].type) {
            SWIG_MakePtr(sv,(void *)1, *swig_variables[i].type,0);
        }else {
            sv_setiv(sv,(IV) 0);
        }
        swig_create_magic(sv, (char *) swig_variables[i].name, swig_variables[i].set, swig_variables[i].get); 
    }
    
    /* Install constant */
    for (i = 0; swig_constants[i].type; i++) {
        SV *sv;
        sv = perl_get_sv((char*)swig_constants[i].name, TRUE | 0x2);
        switch(swig_constants[i].type) {
            case SWIG_INT:
            sv_setiv(sv, (IV) swig_constants[i].lvalue);
            break;
            case SWIG_FLOAT:
            sv_setnv(sv, (double) swig_constants[i].dvalue);
            break;
            case SWIG_STRING:
            sv_setpv(sv, (char *) swig_constants[i].pvalue);
            break;
            case SWIG_POINTER:
            SWIG_MakePtr(sv, swig_constants[i].pvalue, *(swig_constants[i].ptype),0);
            break;
            case SWIG_BINARY:
            /*      obj = SWIG_NewPackedObj(swig_constants[i].pvalue, swig_constants[i].lvalue, *(swig_constants[i].ptype)); */
            break;
            default:
            break;
        }
        SvREADONLY_on(sv);
    }
    
    SWIG_TypeClientData(SWIGTYPE_p_SecurID, (void*) "Crypt::securid::SecurID");
    ST(0) = &PL_sv_yes;
    XSRETURN(1);
}

