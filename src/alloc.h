/*!
 * \file alloc.h
 *
 * \date
 *
 * External definitions for memory allocation subsystem
 */

#include "copyright.h"

#ifndef __ALLOC_H
#define __ALLOC_H

#define XMALLOC(s, v) __xmalloc(s, __FILE__, __LINE__, __func__, v)
#define XNMALLOC(s) __xmalloc(s, NULL, 0, NULL, NULL)

#define XCALLOC(n, s, v) __xcalloc(n, s, __FILE__, __LINE__, __func__, v)
#define XNCALLOC(n, s) __xcalloc(n, s, NULL, 0, NULL, NULL)

#define XREALLOC(p, s, v) __xrealloc(p, s, __FILE__, __LINE__, __func__, v)
#define XNREALLOC(p, s) __xrealloc(p, s, NULL, 0, NULL, NULL)
#define XFREE(p) __xfree(p)

#define XSTRDUP(s, v) __xstrdup(s, __FILE__, __LINE__, __func__, v)
#define XNSTRDUP(s) __xstrdup(s, NULL, 0, NULL, NULL)

#define XSPRINTF(v, f, ...) __xsprintf(__FILE__, __LINE__, __func__, v, f, __VA_ARGS__)
#define XNSPRINTF(f,...) __xsprintf(NULL, 0, NULL, NULL, f, __VA_ARGS__);

typedef struct tracemem_header
{
    void *bptr;
    const char *file;
    int line;
    const char *function;
    const char *var;
    size_t size;
    struct tracemem_header *next;
} MEMTRACK;

#define HBUF_SIZE 32768 /*!< Huge buffer size */
#define LBUF_SIZE 8192  /*!< Large buffer size */
#define GBUF_SIZE 1024  /*!< Generic buffer size */
#define MBUF_SIZE 512   /*!< Standard buffer size */
#define SBUF_SIZE 64    /*!< Small buffer size */

#endif /* __ALLOC_H */
