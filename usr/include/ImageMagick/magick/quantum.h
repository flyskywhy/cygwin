/*
  Copyright 1999-2008 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.
  obtain a copy of the License at

    http://www.imagemagick.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickCore quantum inline methods.
*/
#ifndef _MAGICKCORE_QUANTUM_H
#define _MAGICKCORE_QUANTUM_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "magick/semaphore.h"

typedef enum
{
  UndefinedEndian,
  LSBEndian,
  MSBEndian
} EndianType;

typedef enum
{
  UndefinedQuantum,
  AlphaQuantum,
  BlackQuantum,
  BlueQuantum,
  CMYKAQuantum,
  CMYKQuantum,
  CyanQuantum,
  GrayAlphaQuantum,
  GrayQuantum,
  GreenQuantum,
  IndexAlphaQuantum,
  IndexQuantum,
  MagentaQuantum,
  OpacityQuantum,
  RedQuantum,
  RGBAQuantum,
  RGBOQuantum,
  RGBQuantum,
  YellowQuantum,
  GrayPadQuantum,  /* deprecated */
  RGBPadQuantum
} QuantumType;

typedef enum
{
  UndefinedQuantumFormat,
  FloatingPointQuantumFormat,
  SignedQuantumFormat,
  UnsignedQuantumFormat
} QuantumFormatType;

typedef struct _QuantumInfo
{
  unsigned long
    quantum;

  QuantumFormatType
    format;

  double
    minimum,
    maximum,
    scale;

  size_t
    pad;

  MagickBooleanType
    min_is_white,
    pack;

  unsigned char
    *pixels;

  size_t
    extent;

  SemaphoreInfo
    *semaphore;

  unsigned long
    signature;
} QuantumInfo;

static inline Quantum RoundToQuantum(const MagickRealType value)
{
#if defined(MAGICKCORE_HDRI_SUPPORT)
  return((Quantum) value);
#else
  if (value <= 0.0)
    return((Quantum) 0);
  if (value >= QuantumRange)
    return((Quantum) QuantumRange);
  return((Quantum) (value+0.5));
#endif
}

#if (MAGICKCORE_QUANTUM_DEPTH == 8)
static inline unsigned char ScaleQuantumToChar(const Quantum quantum)
{
#if !defined(MAGICKCORE_HDRI_SUPPORT)
  return((unsigned char) quantum);
#else
  if (quantum <= 0.0)
    return(0UL);
  if (quantum >= 255.0)
    return(255);
  return((unsigned char) (quantum+0.5));
#endif
}
#elif (MAGICKCORE_QUANTUM_DEPTH == 16)
static inline unsigned char ScaleQuantumToChar(const Quantum quantum)
{
#if !defined(MAGICKCORE_HDRI_SUPPORT)
  return((unsigned char) ((quantum+128UL)/257UL));
#else
  if (quantum <= 0.0)
    return(0);
  if ((quantum/257.0) >= 255.0)
    return(255);
  return((unsigned char) (quantum/257.0));
#endif
}
#elif (MAGICKCORE_QUANTUM_DEPTH == 32)
static inline unsigned char ScaleQuantumToChar(const Quantum quantum)
{
#if !defined(MAGICKCORE_HDRI_SUPPORT)
  unsigned char
    pixel;

  pixel=(unsigned char) ((quantum+MagickULLConstant(8421504))/
    MagickULLConstant(16843009));
  return(pixel);
#else
  if (quantum <= 0.0)
    return(0);
  if ((quantum/16843009.0) >= 255.0)
    return(255);
  return((unsigned char) (quantum/16843009.0));
#endif
}
#elif (MAGICKCORE_QUANTUM_DEPTH == 64)
static inline unsigned char ScaleQuantumToChar(const Quantum quantum)
{
#if !defined(MAGICKCORE_HDRI_SUPPORT)
  return((unsigned char) ((quantum+2155839615.0)/71777214294589695.0));
#else
  return((unsigned char) (quantum/71777214294589695.0));
#endif
}
#endif

extern MagickExport QuantumInfo
  *AcquireQuantumInfo(const ImageInfo *,const Image *),
  *DestroyQuantumInfo(QuantumInfo *);

extern MagickExport size_t
  ExportQuantumPixels(Image *,const QuantumInfo *,const QuantumType,
    const unsigned char *),
  ImportQuantumPixels(Image *,const QuantumInfo *,const QuantumType,
    unsigned char *);

extern MagickExport QuantumType
  GetQuantumType(const Image *);

extern MagickExport unsigned char
  *GetQuantumPixels(const QuantumInfo *);

extern MagickExport void
  GetQuantumInfo(const ImageInfo *,QuantumInfo *);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
