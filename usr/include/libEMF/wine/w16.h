/*
 * These are some left-over definitions which are not supported
 * in WINE any more, but still show up in metafiles. They are
 * not exposed as API.
 */
#ifndef W16_H
#define W16_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard data types */

typedef short           INT16;
typedef unsigned short  UINT16;
typedef unsigned short  BOOL16;

typedef HDC		HDC16;

/* The POINT structure */

typedef struct
{
    INT16  x;
    INT16  y;
} POINT16, *PPOINT16, *LPPOINT16;

typedef struct {
    EMR    emr;
    RECTL  rclBounds;
    DWORD  cpts;
    POINT16 apts[1];
} EMRPOLYLINE16,     *PEMRPOLYLINE16,
  EMRPOLYBEZIER16,   *PEMRPOLYBEZIER16,
  EMRPOLYGON16,      *PEMRPOLYGON16,
  EMRPOLYBEZIERTO16, *PEMRPOLYBEZIERTO16,
  EMRPOLYLINETO16,   *PEMRPOLYLINETO16;

typedef struct {
    EMR    emr;
    RECTL  rclBounds;
    DWORD  nPolys;
    DWORD  cpts;
    DWORD  aPolyCounts[1];
    POINT16 apts[1];
} EMRPOLYPOLYLINE16,     *PEMRPOLYPOLYLINE16,
  EMRPOLYPOLYGON16,      *PEMRPOLYPOLYGON16;

BOOL      WINAPI PolyBezier16(HDC16,const POINT16*,INT16);
BOOL      WINAPI PolyBezierTo16(HDC16,const POINT16*,INT16);
BOOL      WINAPI Polyline16(HDC16,const POINT16*,INT16);
BOOL      WINAPI PolylineTo16(HDC16,const POINT16*,INT16);
BOOL      WINAPI Polygon16(HDC16,const POINT16*,INT16);
BOOL      WINAPI PolyPolygon16(HDC16,const POINT16*,const INT*,UINT16);
#ifdef __cplusplus
}
#endif


#endif /* W16_H */
