/* $Id$
***************************************************************************

   LibGG - implementations of splay and red-black trees

***************************************************************************
*/

/* This code has been imported to GGI from NetBSD-current 2004-10-27 */

/*
 * Copyright 2002 Niels Provos <provos@citi.umich.edu>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef	GG_TREE_H_
#define	GG_TREE_H_

/*
 * This file defines data structures for different types of trees:
 * splay trees and red-black trees.
 *
 * A splay tree is a self-organizing data structure.  Every operation
 * on the tree causes a splay to happen.  The splay moves the requested
 * node to the root of the tree and partly rebalances it.
 *
 * This has the benefit that request locality causes faster lookups as
 * the requested nodes move to the top of the tree.  On the other hand,
 * every lookup causes memory writes.
 *
 * The Balance Theorem bounds the total access time for m operations
 * and n inserts on an initially empty tree as O((m + n)lg n).  The
 * amortized cost for a sequence of m accesses to a splay tree is O(lg n);
 *
 * A red-black tree is a binary search tree with the node color as an
 * extra attribute.  It fulfills a set of conditions:
 *	- every search path from the root to a leaf consists of the
 *	  same number of black nodes,
 *	- each red node (except for the root) has a black parent,
 *	- each leaf node is black.
 *
 * Every operation on a red-black tree is bounded as O(lg n).
 * The maximum height of a red-black tree is 2lg (n+1).
 */

#define GG_SPLAY_HEAD(name, type)						\
struct name {								\
	struct type *sph_root; /* root of the tree */			\
}

#define GG_SPLAY_INITIALIZER(root)						\
	{ NULL }

#define GG_SPLAY_INIT(root) do {						\
	(root)->sph_root = NULL;					\
} while (/*CONSTCOND*/ 0)

#define GG_SPLAY_ENTRY(type)						\
struct {								\
	struct type *spe_left; /* left element */			\
	struct type *spe_right; /* right element */			\
}

#define GG_SPLAY_LEFT(elm, field)	(elm)->field.spe_left
#define GG_SPLAY_RIGHT(elm, field)	(elm)->field.spe_right
#define GG_SPLAY_ROOT(head)		(head)->sph_root
#define GG_SPLAY_EMPTY(head)		(GG_SPLAY_ROOT(head) == NULL)

/* GG_SPLAY_ROTATE_{LEFT,RIGHT} expect that tmp hold GG_SPLAY_{RIGHT,LEFT} */
#define GG_SPLAY_ROTATE_RIGHT(head, tmp, field) do {			\
	GG_SPLAY_LEFT((head)->sph_root, field) = GG_SPLAY_RIGHT(tmp, field);	\
	GG_SPLAY_RIGHT(tmp, field) = (head)->sph_root;			\
	(head)->sph_root = tmp;						\
} while (/*CONSTCOND*/ 0)

#define GG_SPLAY_ROTATE_LEFT(head, tmp, field) do {			\
	GG_SPLAY_RIGHT((head)->sph_root, field) = GG_SPLAY_LEFT(tmp, field);	\
	GG_SPLAY_LEFT(tmp, field) = (head)->sph_root;			\
	(head)->sph_root = tmp;						\
} while (/*CONSTCOND*/ 0)

#define GG_SPLAY_LINKLEFT(head, tmp, field) do {			\
	GG_SPLAY_LEFT(tmp, field) = (head)->sph_root;			\
	tmp = (head)->sph_root;						\
	(head)->sph_root = GG_SPLAY_LEFT((head)->sph_root, field);	\
} while (/*CONSTCOND*/ 0)

#define GG_SPLAY_LINKRIGHT(head, tmp, field) do {			\
	GG_SPLAY_RIGHT(tmp, field) = (head)->sph_root;			\
	tmp = (head)->sph_root;						\
	(head)->sph_root = GG_SPLAY_RIGHT((head)->sph_root, field);	\
} while (/*CONSTCOND*/ 0)

#define GG_SPLAY_ASSEMBLE(head, node, left, right, field) do {		\
	GG_SPLAY_RIGHT(left, field) = GG_SPLAY_LEFT((head)->sph_root, field);	\
	GG_SPLAY_LEFT(right, field) = GG_SPLAY_RIGHT((head)->sph_root, field);\
	GG_SPLAY_LEFT((head)->sph_root, field) = GG_SPLAY_RIGHT(node, field);	\
	GG_SPLAY_RIGHT((head)->sph_root, field) = GG_SPLAY_LEFT(node, field);	\
} while (/*CONSTCOND*/ 0)

/* Generates prototypes and inline functions */

#define GG_SPLAY_PROTOTYPE(name, type, field, cmp)			\
void name##_SPLAY(struct name *, struct type *);			\
void name##_SPLAY_MINMAX(struct name *, int);			\
struct type *name##_SPLAY_INSERT(struct name *, struct type *);	\
struct type *name##_SPLAY_REMOVE(struct name *, struct type *);	\
									\
/* Finds the node with the same key as elm */				\
static __inline struct type *						\
name##_SPLAY_FIND(struct name *head, struct type *elm)		\
{									\
	if (GG_SPLAY_EMPTY(head))					\
		return(NULL);						\
	name##_SPLAY(head, elm);					\
	if ((cmp)(elm, (head)->sph_root) == 0)				\
		return (head->sph_root);				\
	return (NULL);							\
}									\
									\
static __inline struct type *						\
name##_SPLAY_NEXT(struct name *head, struct type *elm)			\
{									\
	name##_SPLAY(head, elm);					\
	if (GG_SPLAY_RIGHT(elm, field) != NULL) {			\
		elm = GG_SPLAY_RIGHT(elm, field);			\
		while (GG_SPLAY_LEFT(elm, field) != NULL) {		\
			elm = GG_SPLAY_LEFT(elm, field);		\
		}							\
	} else								\
		elm = NULL;						\
	return (elm);							\
}									\
									\
static __inline struct type *						\
name##_SPLAY_MIN_MAX(struct name *head, int val)			\
{									\
	name##_SPLAY_MINMAX(head, val);					\
        return (GG_SPLAY_ROOT(head));					\
}

/* Main splay operation.
 * Moves node close to the key of elm to top
 */
#define GG_SPLAY_GENERATE(name, type, field, cmp)			\
struct type *								\
name##_SPLAY_INSERT(struct name *head, struct type *elm)		\
{									\
    if (GG_SPLAY_EMPTY(head)) {						\
	    GG_SPLAY_LEFT(elm, field) = GG_SPLAY_RIGHT(elm, field) = NULL;	\
    } else {								\
	    int __comp;							\
	    name##_SPLAY(head, elm);					\
	    __comp = (cmp)(elm, (head)->sph_root);			\
	    if(__comp < 0) {						\
		    GG_SPLAY_LEFT(elm, field) = GG_SPLAY_LEFT((head)->sph_root, field);\
		    GG_SPLAY_RIGHT(elm, field) = (head)->sph_root;	\
		    GG_SPLAY_LEFT((head)->sph_root, field) = NULL;	\
	    } else if (__comp > 0) {					\
		    GG_SPLAY_RIGHT(elm, field) = GG_SPLAY_RIGHT((head)->sph_root, field);\
		    GG_SPLAY_LEFT(elm, field) = (head)->sph_root;	\
		    GG_SPLAY_RIGHT((head)->sph_root, field) = NULL;	\
	    } else							\
		    return ((head)->sph_root);				\
    }									\
    (head)->sph_root = (elm);						\
    return (NULL);							\
}									\
									\
struct type *								\
name##_SPLAY_REMOVE(struct name *head, struct type *elm)		\
{									\
	struct type *__tmp;						\
	if (GG_SPLAY_EMPTY(head))					\
		return (NULL);						\
	name##_SPLAY(head, elm);					\
	if ((cmp)(elm, (head)->sph_root) == 0) {			\
		if (GG_SPLAY_LEFT((head)->sph_root, field) == NULL) {	\
			(head)->sph_root = GG_SPLAY_RIGHT((head)->sph_root, field);\
		} else {						\
			__tmp = GG_SPLAY_RIGHT((head)->sph_root, field);\
			(head)->sph_root = GG_SPLAY_LEFT((head)->sph_root, field);\
			name##_SPLAY(head, elm);			\
			GG_SPLAY_RIGHT((head)->sph_root, field) = __tmp;\
		}							\
		return (elm);						\
	}								\
	return (NULL);							\
}									\
									\
void									\
name##_SPLAY(struct name *head, struct type *elm)			\
{									\
	struct type __node, *__left, *__right, *__tmp;			\
	int __comp;							\
\
	GG_SPLAY_LEFT(&__node, field) = GG_SPLAY_RIGHT(&__node, field) = NULL;\
	__left = __right = &__node;					\
\
	while ((__comp = (cmp)(elm, (head)->sph_root)) != 0) {		\
		if (__comp < 0) {					\
			__tmp = GG_SPLAY_LEFT((head)->sph_root, field);	\
			if (__tmp == NULL)				\
				break;					\
			if ((cmp)(elm, __tmp) < 0){			\
				GG_SPLAY_ROTATE_RIGHT(head, __tmp, field);\
				if (GG_SPLAY_LEFT((head)->sph_root, field) == NULL)\
					break;				\
			}						\
			GG_SPLAY_LINKLEFT(head, __right, field);	\
		} else if (__comp > 0) {				\
			__tmp = GG_SPLAY_RIGHT((head)->sph_root, field);\
			if (__tmp == NULL)				\
				break;					\
			if ((cmp)(elm, __tmp) > 0){			\
				GG_SPLAY_ROTATE_LEFT(head, __tmp, field);\
				if (GG_SPLAY_RIGHT((head)->sph_root, field) == NULL)\
					break;				\
			}						\
			GG_SPLAY_LINKRIGHT(head, __left, field);	\
		}							\
	}								\
	GG_SPLAY_ASSEMBLE(head, &__node, __left, __right, field);	\
}									\
									\
/* Splay with either the minimum or the maximum element			\
 * Used to find minimum or maximum element in tree.			\
 */									\
void name##_SPLAY_MINMAX(struct name *head, int __comp) \
{									\
	struct type __node, *__left, *__right, *__tmp;			\
\
	GG_SPLAY_LEFT(&__node, field) = GG_SPLAY_RIGHT(&__node, field) = NULL;\
	__left = __right = &__node;					\
\
	while (1) {							\
		if (__comp < 0) {					\
			__tmp = GG_SPLAY_LEFT((head)->sph_root, field);	\
			if (__tmp == NULL)				\
				break;					\
			if (__comp < 0){				\
				GG_SPLAY_ROTATE_RIGHT(head, __tmp, field);\
				if (GG_SPLAY_LEFT((head)->sph_root, field) == NULL)\
					break;				\
			}						\
			GG_SPLAY_LINKLEFT(head, __right, field);	\
		} else if (__comp > 0) {				\
			__tmp = GG_SPLAY_RIGHT((head)->sph_root, field);\
			if (__tmp == NULL)				\
				break;					\
			if (__comp > 0) {				\
				GG_SPLAY_ROTATE_LEFT(head, __tmp, field);\
				if (GG_SPLAY_RIGHT((head)->sph_root, field) == NULL)\
					break;				\
			}						\
			GG_SPLAY_LINKRIGHT(head, __left, field);	\
		}							\
	}								\
	GG_SPLAY_ASSEMBLE(head, &__node, __left, __right, field);	\
}

#define GG_SPLAY_NEGINF	-1
#define GG_SPLAY_INF	1

#define GG_SPLAY_INSERT(name, x, y)	name##_SPLAY_INSERT(x, y)
#define GG_SPLAY_REMOVE(name, x, y)	name##_SPLAY_REMOVE(x, y)
#define GG_SPLAY_FIND(name, x, y)	name##_SPLAY_FIND(x, y)
#define GG_SPLAY_NEXT(name, x, y)	name##_SPLAY_NEXT(x, y)
#define GG_SPLAY_MIN(name, x)		(GG_SPLAY_EMPTY(x) ? NULL	\
					: name##_SPLAY_MIN_MAX(x, GG_SPLAY_NEGINF))
#define GG_SPLAY_MAX(name, x)		(GG_SPLAY_EMPTY(x) ? NULL	\
					: name##_SPLAY_MIN_MAX(x, GG_SPLAY_INF))

#define GG_SPLAY_FOREACH(x, name, head)					\
	for ((x) = GG_SPLAY_MIN(name, head);				\
	     (x) != NULL;						\
	     (x) = GG_SPLAY_NEXT(name, head, x))

/* Macros that define a red-black tree */
#define GG_RB_HEAD(name, type)						\
struct name {								\
	struct type *rbh_root; /* root of the tree */			\
}

#define GG_RB_INITIALIZER(root)						\
	{ NULL }

#define GG_RB_INIT(root) do {						\
	(root)->rbh_root = NULL;					\
} while (/*CONSTCOND*/ 0)

#define GG_RB_BLACK	0
#define GG_RB_RED	1
#define GG_RB_ENTRY(type)						\
struct {								\
	struct type *rbe_left;		/* left element */		\
	struct type *rbe_right;		/* right element */		\
	struct type *rbe_parent;	/* parent element */		\
	int rbe_color;			/* node color */		\
}

#define GG_RB_LEFT(elm, field)		(elm)->field.rbe_left
#define GG_RB_RIGHT(elm, field)		(elm)->field.rbe_right
#define GG_RB_PARENT(elm, field)	(elm)->field.rbe_parent
#define GG_RB_COLOR(elm, field)		(elm)->field.rbe_color
#define GG_RB_ROOT(head)		(head)->rbh_root
#define GG_RB_EMPTY(head)		(GG_RB_ROOT(head) == NULL)

#define GG_RB_SET(elm, parent, field) do {				\
	GG_RB_PARENT(elm, field) = parent;				\
	GG_RB_LEFT(elm, field) = GG_RB_RIGHT(elm, field) = NULL;	\
	GG_RB_COLOR(elm, field) = GG_RB_RED;				\
} while (/*CONSTCOND*/ 0)

#define GG_RB_SET_BLACKRED(black, red, field) do {			\
	GG_RB_COLOR(black, field) = GG_RB_BLACK;			\
	GG_RB_COLOR(red, field) = GG_RB_RED;				\
} while (/*CONSTCOND*/ 0)

#ifndef GG_RB_AUGMENT
#define GG_RB_AUGMENT(x)
#endif

#define GG_RB_ROTATE_LEFT(head, elm, tmp, field) do {			\
	(tmp) = GG_RB_RIGHT(elm, field);				\
	if ((GG_RB_RIGHT(elm, field) = GG_RB_LEFT(tmp, field)) != NULL) {\
		GG_RB_PARENT(GG_RB_LEFT(tmp, field), field) = (elm);	\
	}								\
	GG_RB_AUGMENT(elm);						\
	if ((GG_RB_PARENT(tmp, field) = GG_RB_PARENT(elm, field)) != NULL) {\
		if ((elm) == GG_RB_LEFT(GG_RB_PARENT(elm, field), field))\
			GG_RB_LEFT(GG_RB_PARENT(elm, field), field) = (tmp);\
		else							\
			GG_RB_RIGHT(GG_RB_PARENT(elm, field), field) = (tmp);\
	} else								\
		(head)->rbh_root = (tmp);				\
	GG_RB_LEFT(tmp, field) = (elm);					\
	GG_RB_PARENT(elm, field) = (tmp);				\
	GG_RB_AUGMENT(tmp);						\
	if ((GG_RB_PARENT(tmp, field)))					\
		GG_RB_AUGMENT(GG_RB_PARENT(tmp, field));		\
} while (/*CONSTCOND*/ 0)

#define GG_RB_ROTATE_RIGHT(head, elm, tmp, field) do {			\
	(tmp) = GG_RB_LEFT(elm, field);					\
	if ((GG_RB_LEFT(elm, field) = GG_RB_RIGHT(tmp, field)) != NULL) {\
		GG_RB_PARENT(GG_RB_RIGHT(tmp, field), field) = (elm);	\
	}								\
	GG_RB_AUGMENT(elm);						\
	if ((GG_RB_PARENT(tmp, field) = GG_RB_PARENT(elm, field)) != NULL) {\
		if ((elm) == GG_RB_LEFT(GG_RB_PARENT(elm, field), field))\
			GG_RB_LEFT(GG_RB_PARENT(elm, field), field) = (tmp);\
		else							\
			GG_RB_RIGHT(GG_RB_PARENT(elm, field), field) = (tmp);\
	} else								\
		(head)->rbh_root = (tmp);				\
	GG_RB_RIGHT(tmp, field) = (elm);				\
	GG_RB_PARENT(elm, field) = (tmp);				\
	GG_RB_AUGMENT(tmp);						\
	if ((GG_RB_PARENT(tmp, field)))					\
		GG_RB_AUGMENT(GG_RB_PARENT(tmp, field));		\
} while (/*CONSTCOND*/ 0)

/* Generates prototypes and inline functions */
#define GG_RB_PROTOTYPE(name, type, field, cmp)				\
void name##_RB_INSERT_COLOR(struct name *, struct type *);	\
void name##_RB_REMOVE_COLOR(struct name *, struct type *, struct type *);\
struct type *name##_RB_REMOVE(struct name *, struct type *);		\
struct type *name##_RB_INSERT(struct name *, struct type *);		\
struct type *name##_RB_FIND(struct name *, struct type *);		\
struct type *name##_RB_NEXT(struct type *);				\
struct type *name##_RB_MINMAX(struct name *, int);			\
									\

/* Main rb operation.
 * Moves node close to the key of elm to top
 */
#define GG_RB_GENERATE(name, type, field, cmp)				\
void									\
name##_RB_INSERT_COLOR(struct name *head, struct type *elm)		\
{									\
	struct type *parent, *gparent, *tmp;				\
	while ((parent = GG_RB_PARENT(elm, field)) != NULL &&		\
	    GG_RB_COLOR(parent, field) == GG_RB_RED) {			\
		gparent = GG_RB_PARENT(parent, field);			\
		if (parent == GG_RB_LEFT(gparent, field)) {		\
			tmp = GG_RB_RIGHT(gparent, field);		\
			if (tmp && GG_RB_COLOR(tmp, field) == GG_RB_RED) {\
				GG_RB_COLOR(tmp, field) = GG_RB_BLACK;	\
				GG_RB_SET_BLACKRED(parent, gparent, field);\
				elm = gparent;				\
				continue;				\
			}						\
			if (GG_RB_RIGHT(parent, field) == elm) {	\
				GG_RB_ROTATE_LEFT(head, parent, tmp, field);\
				tmp = parent;				\
				parent = elm;				\
				elm = tmp;				\
			}						\
			GG_RB_SET_BLACKRED(parent, gparent, field);	\
			GG_RB_ROTATE_RIGHT(head, gparent, tmp, field);	\
		} else {						\
			tmp = GG_RB_LEFT(gparent, field);		\
			if (tmp && GG_RB_COLOR(tmp, field) == GG_RB_RED) {\
				GG_RB_COLOR(tmp, field) = GG_RB_BLACK;	\
				GG_RB_SET_BLACKRED(parent, gparent, field);\
				elm = gparent;				\
				continue;				\
			}						\
			if (GG_RB_LEFT(parent, field) == elm) {		\
				GG_RB_ROTATE_RIGHT(head, parent, tmp, field);\
				tmp = parent;				\
				parent = elm;				\
				elm = tmp;				\
			}						\
			GG_RB_SET_BLACKRED(parent, gparent, field);	\
			GG_RB_ROTATE_LEFT(head, gparent, tmp, field);	\
		}							\
	}								\
	GG_RB_COLOR(head->rbh_root, field) = GG_RB_BLACK;		\
}									\
									\
void									\
name##_RB_REMOVE_COLOR(struct name *head, struct type *parent, struct type *elm) \
{									\
	struct type *tmp;						\
	while ((elm == NULL || GG_RB_COLOR(elm, field) == GG_RB_BLACK) &&\
	    elm != GG_RB_ROOT(head)) {					\
		if (GG_RB_LEFT(parent, field) == elm) {			\
			tmp = GG_RB_RIGHT(parent, field);		\
			if (GG_RB_COLOR(tmp, field) == GG_RB_RED) {	\
				GG_RB_SET_BLACKRED(tmp, parent, field);	\
				GG_RB_ROTATE_LEFT(head, parent, tmp, field);\
				tmp = GG_RB_RIGHT(parent, field);	\
			}						\
			if ((GG_RB_LEFT(tmp, field) == NULL ||		\
			    GG_RB_COLOR(GG_RB_LEFT(tmp, field), field) == GG_RB_BLACK) &&\
			    (GG_RB_RIGHT(tmp, field) == NULL ||		\
			    GG_RB_COLOR(GG_RB_RIGHT(tmp, field), field) == GG_RB_BLACK)) {\
				GG_RB_COLOR(tmp, field) = GG_RB_RED;	\
				elm = parent;				\
				parent = GG_RB_PARENT(elm, field);	\
			} else {					\
				if (GG_RB_RIGHT(tmp, field) == NULL ||	\
				    GG_RB_COLOR(GG_RB_RIGHT(tmp, field), field) == GG_RB_BLACK) {\
					struct type *oleft;		\
					if ((oleft = GG_RB_LEFT(tmp, field)) \
					    != NULL)			\
						GG_RB_COLOR(oleft, field) = GG_RB_BLACK;\
					GG_RB_COLOR(tmp, field) = GG_RB_RED;	\
					GG_RB_ROTATE_RIGHT(head, tmp, oleft, field);\
					tmp = GG_RB_RIGHT(parent, field);	\
				}					\
				GG_RB_COLOR(tmp, field) = GG_RB_COLOR(parent, field);\
				GG_RB_COLOR(parent, field) = GG_RB_BLACK;	\
				if (GG_RB_RIGHT(tmp, field))		\
					GG_RB_COLOR(GG_RB_RIGHT(tmp, field), field) = GG_RB_BLACK;\
				GG_RB_ROTATE_LEFT(head, parent, tmp, field);\
				elm = GG_RB_ROOT(head);			\
				break;					\
			}						\
		} else {						\
			tmp = GG_RB_LEFT(parent, field);		\
			if (GG_RB_COLOR(tmp, field) == GG_RB_RED) {	\
				GG_RB_SET_BLACKRED(tmp, parent, field);	\
				GG_RB_ROTATE_RIGHT(head, parent, tmp, field);\
				tmp = GG_RB_LEFT(parent, field);	\
			}						\
			if ((GG_RB_LEFT(tmp, field) == NULL ||		\
			    GG_RB_COLOR(GG_RB_LEFT(tmp, field), field) == GG_RB_BLACK) &&\
			    (GG_RB_RIGHT(tmp, field) == NULL ||		\
			    GG_RB_COLOR(GG_RB_RIGHT(tmp, field), field) == GG_RB_BLACK)) {\
				GG_RB_COLOR(tmp, field) = GG_RB_RED;	\
				elm = parent;				\
				parent = GG_RB_PARENT(elm, field);	\
			} else {					\
				if (GG_RB_LEFT(tmp, field) == NULL ||	\
				    GG_RB_COLOR(GG_RB_LEFT(tmp, field), field) == GG_RB_BLACK) {\
					struct type *oright;		\
					if ((oright = GG_RB_RIGHT(tmp, field)) \
					    != NULL)			\
						GG_RB_COLOR(oright, field) = GG_RB_BLACK;\
					GG_RB_COLOR(tmp, field) = GG_RB_RED;	\
					GG_RB_ROTATE_LEFT(head, tmp, oright, field);\
					tmp = GG_RB_LEFT(parent, field);	\
				}					\
				GG_RB_COLOR(tmp, field) = GG_RB_COLOR(parent, field);\
				GG_RB_COLOR(parent, field) = GG_RB_BLACK;	\
				if (GG_RB_LEFT(tmp, field))		\
					GG_RB_COLOR(GG_RB_LEFT(tmp, field), field) = GG_RB_BLACK;\
				GG_RB_ROTATE_RIGHT(head, parent, tmp, field);\
				elm = GG_RB_ROOT(head);			\
				break;					\
			}						\
		}							\
	}								\
	if (elm)							\
		GG_RB_COLOR(elm, field) = GG_RB_BLACK;			\
}									\
									\
struct type *								\
name##_RB_REMOVE(struct name *head, struct type *elm)			\
{									\
	struct type *child, *parent, *old = elm;			\
	int color;							\
	if (GG_RB_LEFT(elm, field) == NULL)				\
		child = GG_RB_RIGHT(elm, field);			\
	else if (GG_RB_RIGHT(elm, field) == NULL)			\
		child = GG_RB_LEFT(elm, field);				\
	else {								\
		struct type *left;					\
		elm = GG_RB_RIGHT(elm, field);				\
		while ((left = GG_RB_LEFT(elm, field)) != NULL)		\
			elm = left;					\
		child = GG_RB_RIGHT(elm, field);			\
		parent = GG_RB_PARENT(elm, field);			\
		color = GG_RB_COLOR(elm, field);			\
		if (child)						\
			GG_RB_PARENT(child, field) = parent;		\
		if (parent) {						\
			if (GG_RB_LEFT(parent, field) == elm)		\
				GG_RB_LEFT(parent, field) = child;	\
			else						\
				GG_RB_RIGHT(parent, field) = child;	\
			GG_RB_AUGMENT(parent);				\
		} else							\
			GG_RB_ROOT(head) = child;			\
		if (GG_RB_PARENT(elm, field) == old)			\
			parent = elm;					\
		(elm)->field = (old)->field;				\
		if (GG_RB_PARENT(old, field)) {				\
			if (GG_RB_LEFT(GG_RB_PARENT(old, field), field) == old)\
				GG_RB_LEFT(GG_RB_PARENT(old, field), field) = elm;\
			else						\
				GG_RB_RIGHT(GG_RB_PARENT(old, field), field) = elm;\
			GG_RB_AUGMENT(GG_RB_PARENT(old, field));	\
		} else							\
			GG_RB_ROOT(head) = elm;				\
		GG_RB_PARENT(GG_RB_LEFT(old, field), field) = elm;	\
		if (GG_RB_RIGHT(old, field))				\
			GG_RB_PARENT(GG_RB_RIGHT(old, field), field) = elm;\
		if (parent) {						\
			left = parent;					\
			do {						\
				GG_RB_AUGMENT(left);			\
			} while ((left = GG_RB_PARENT(left, field)) != NULL); \
		}							\
		goto color;						\
	}								\
	parent = GG_RB_PARENT(elm, field);				\
	color = GG_RB_COLOR(elm, field);				\
	if (child)							\
		GG_RB_PARENT(child, field) = parent;			\
	if (parent) {							\
		if (GG_RB_LEFT(parent, field) == elm)			\
			GG_RB_LEFT(parent, field) = child;		\
		else							\
			GG_RB_RIGHT(parent, field) = child;		\
		GG_RB_AUGMENT(parent);					\
	} else								\
		GG_RB_ROOT(head) = child;				\
color:									\
	if (color == GG_RB_BLACK)					\
		name##_RB_REMOVE_COLOR(head, parent, child);		\
	return (old);							\
}									\
									\
/* Inserts a node into the RB tree */					\
struct type *								\
name##_RB_INSERT(struct name *head, struct type *elm)			\
{									\
	struct type *tmp;						\
	struct type *parent = NULL;					\
	int comp = 0;							\
	tmp = GG_RB_ROOT(head);						\
	while (tmp) {							\
		parent = tmp;						\
		comp = (cmp)(elm, parent);				\
		if (comp < 0)						\
			tmp = GG_RB_LEFT(tmp, field);			\
		else if (comp > 0)					\
			tmp = GG_RB_RIGHT(tmp, field);			\
		else							\
			return (tmp);					\
	}								\
	GG_RB_SET(elm, parent, field);					\
	if (parent != NULL) {						\
		if (comp < 0)						\
			GG_RB_LEFT(parent, field) = elm;		\
		else							\
			GG_RB_RIGHT(parent, field) = elm;		\
		GG_RB_AUGMENT(parent);					\
	} else								\
		GG_RB_ROOT(head) = elm;					\
	name##_RB_INSERT_COLOR(head, elm);				\
	return (NULL);							\
}									\
									\
/* Finds the node with the same key as elm */				\
struct type *								\
name##_RB_FIND(struct name *head, struct type *elm)			\
{									\
	struct type *tmp = GG_RB_ROOT(head);				\
	int comp;							\
	while (tmp) {							\
		comp = cmp(elm, tmp);					\
		if (comp < 0)						\
			tmp = GG_RB_LEFT(tmp, field);			\
		else if (comp > 0)					\
			tmp = GG_RB_RIGHT(tmp, field);			\
		else							\
			return (tmp);					\
	}								\
	return (NULL);							\
}									\
									\
/* ARGSUSED */								\
struct type *								\
name##_RB_NEXT(struct type *elm)					\
{									\
	if (GG_RB_RIGHT(elm, field)) {					\
		elm = GG_RB_RIGHT(elm, field);				\
		while (GG_RB_LEFT(elm, field))				\
			elm = GG_RB_LEFT(elm, field);			\
	} else {							\
		if (GG_RB_PARENT(elm, field) &&				\
		    (elm == GG_RB_LEFT(GG_RB_PARENT(elm, field), field)))\
			elm = GG_RB_PARENT(elm, field);			\
		else {							\
			while (GG_RB_PARENT(elm, field) &&		\
			    (elm == GG_RB_RIGHT(GG_RB_PARENT(elm, field), field)))\
				elm = GG_RB_PARENT(elm, field);		\
			elm = GG_RB_PARENT(elm, field);			\
		}							\
	}								\
	return (elm);							\
}									\
									\
struct type *								\
name##_RB_MINMAX(struct name *head, int val)				\
{									\
	struct type *tmp = GG_RB_ROOT(head);				\
	struct type *parent = NULL;					\
	while (tmp) {							\
		parent = tmp;						\
		if (val < 0)						\
			tmp = GG_RB_LEFT(tmp, field);			\
		else							\
			tmp = GG_RB_RIGHT(tmp, field);			\
	}								\
	return (parent);						\
}

#define GG_RB_NEGINF	-1
#define GG_RB_INF	1

#define GG_RB_INSERT(name, x, y)	name##_RB_INSERT(x, y)
#define GG_RB_REMOVE(name, x, y)	name##_RB_REMOVE(x, y)
#define GG_RB_FIND(name, x, y)		name##_RB_FIND(x, y)
#define GG_RB_NEXT(name, x, y)		name##_RB_NEXT(y)
#define GG_RB_MIN(name, x)		name##_RB_MINMAX(x, GG_RB_NEGINF)
#define GG_RB_MAX(name, x)		name##_RB_MINMAX(x, GG_RB_INF)

#define GG_RB_FOREACH(x, name, head)					\
	for ((x) = GG_RB_MIN(name, head);				\
	     (x) != NULL;						\
	     (x) = name##_RB_NEXT(x))

#endif	/* GG_TREE_H_ */
