/* $Id: directx.h,v 1.17 2005/01/27 08:17:16 pekberg Exp $
*****************************************************************************

   LibGGI DirectX target - Header for internal functions

   Copyright (C) 1999 John Fortin       [fortinj@ibm.net]
   Copyright (C) 2004 Peter Ekberg      [peda@lysator.liu.se]

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************************
*/

#ifndef _GGI_DISPLAY_DIRECTX_H
#define _GGI_DISPLAY_DIRECTX_H

#include <ggi/internal/ggi-dl.h>
#include <windows.h>
#include <ddraw.h>

#define GGI_DISPLAY_DIRECTX_FRAMES (16)

ggifunc_getmode                 GGI_directx_getmode;
ggifunc_setmode                 GGI_directx_setmode;
ggifunc_checkmode               GGI_directx_checkmode;
ggifunc_getapi                  GGI_directx_getapi;
ggifunc_flush                   GGI_directx_flush;

/*ggifunc_setreadframe          GGI_directx_setreadframe;*/
/*ggifunc_setwriteframe         GGI_directx_setwriteframe;*/
ggifunc_setdisplayframe         GGI_directx_setdisplayframe;

/*ggifunc_fillscreen            GGI_directx_fillscreen;*/

ggifunc_drawpixel               GGI_directx_drawpixel;
ggifunc_putpixel                GGI_directx_putpixel;
ggifunc_getpixel                GGI_directx_getpixel;

ggifunc_drawline                GGI_directx_drawline;
/*ggifunc_drawhline             GGI_directx_drawhline;*/
/*ggifunc_drawvline             GGI_directx_drawvline;*/
/*ggifunc_puthline              GGI_directx_puthline;*/
/*ggifunc_putvline              GGI_directx_putvline;*/
/*ggifunc_gethline              GGI_directx_gethline;*/
/*ggifunc_getvline              GGI_directx_getvline;*/

/*ggifunc_drawbox               GGI_directx_drawbox;*/
/*ggifunc_putbox                GGI_directx_putbox;*/
/*ggifunc_getbox                GGI_directx_getbox;*/

/*ggifunc_putc                  GGI_directx16_putc;*/
/*ggifunc_putc                  GGI_directx32_putc;*/

ggifunc_setorigin               GGI_directx_setorigin;
ggifunc_setpalvec               GGI_directx_setpalvec;

typedef struct directx_priv
{
	PHYSZ_DATA

	int cursortype;
	HCURSOR hCursor;
	UINT timer_id;

	gii_input *inp;
	HANDLE cs;
	HANDLE spincs;
	int redraw;
	int setpalette;

	HANDLE hWnd, hParent;
	HANDLE hInstance;
	ATOM wndclass;
	long pitch;
	long maxX;
	long maxY;
	DWORD ColorDepth;
	int fullscreen;

	/* resizing info */
	HANDLE sizingcs;
	int xmin;
	int ymin;
	int xmax;
	int ymax;
	int xstep;
	int ystep;

	HANDLE hThread, hInit;
	DWORD nThreadID;
	LPDIRECTDRAW lpdd;
	LPDIRECTDRAW2 lpddext;
	LPDIRECTDRAWSURFACE lppdds;
	LPDIRECTDRAWSURFACE lpbdds[GGI_DISPLAY_DIRECTX_FRAMES];
	char *lpSurfaceAdd[GGI_DISPLAY_DIRECTX_FRAMES];
	LPDIRECTDRAWPALETTE lpddp;
} directx_priv;

#define GGIDIRECTX_PRIV(vis) ((directx_priv *)LIBGGI_PRIVATE(vis))

#define GGI_directx_LockCreate() \
	CreateMutex(NULL, FALSE, NULL)
#define GGI_directx_LockDestroy(lock) \
	CloseHandle(lock)
#define GGI_directx_Lock(lock) \
	WaitForSingleObject((lock), INFINITE)
#define GGI_directx_TryLock(lock) \
	(WaitForSingleObject((lock), 0) != WAIT_OBJECT_0)
#define GGI_directx_Unlock(lock) \
	ReleaseMutex(lock)


#endif /* _GGI_DISPLAY_DIRECTX_H */
