/* $Id: keyboard.h,v 1.5 2005/05/01 00:55:17 aldot Exp $
******************************************************************************

   LibGII keyboard definitions

   Copyright (C) 1998 Andrew Apted	[andrew@ggi-project.org]
   Copyright (C) 1999 Marcus Sundberg	[marcus@ggi-project.org]

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

#ifndef _GII_KEYBOARD_H
#define _GII_KEYBOARD_H

#define GII_KEY(typ,val)	(((typ) << 8) | (val))
#define GII_KTYP(x)		((x) >> 8)
#define GII_KVAL(x)		((x) & 0xff)
#define GII_UNICODE(x)		((x) < 0xE000 || (x) >= 0xF900)

/* types */

#define GII_KT_LATIN1	0x00
#define GII_KT_SPEC	0xE0
#define GII_KT_FN	0xE1
#define GII_KT_PAD	0xE2
#define GII_KT_MOD	0xE3
#define GII_KT_DEAD	0xE4
#define GII_KT_RC	0xE5

/* modifiers */

#define GII_KM_SHIFT	0x00
#define GII_KM_CTRL	0x01
#define GII_KM_ALT	0x02
#define GII_KM_META	0x03
#define GII_KM_SUPER	0x04
#define GII_KM_HYPER	0x05
#define GII_KM_ALTGR	0x06
#define GII_KM_CAPS	0x07
#define GII_KM_NUM	0x08
#define GII_KM_SCROLL	0x09

#define GII_KM_MASK	0x0f
#define GII_KM_RIGHT	0x40	/* additive */
#define GII_KM_LOCK	0x80	/*  - " -   (only used for labels) */

/* Bits in the "modifiers" field */

#define GII_MOD_SHIFT	(1 << GII_KM_SHIFT)
#define GII_MOD_CTRL	(1 << GII_KM_CTRL)
#define GII_MOD_ALT	(1 << GII_KM_ALT)
#define GII_MOD_META	(1 << GII_KM_META)
#define GII_MOD_SUPER	(1 << GII_KM_SUPER)
#define GII_MOD_HYPER	(1 << GII_KM_HYPER)
#define GII_MOD_ALTGR	(1 << GII_KM_ALTGR)
#define GII_MOD_CAPS	(1 << GII_KM_CAPS)
#define GII_MOD_NUM	(1 << GII_KM_NUM)
#define GII_MOD_SCROLL	(1 << GII_KM_SCROLL)

/* function keys */

#define GIIK_F0			GII_KEY(GII_KT_FN, 0)
#define GIIK_F1			GII_KEY(GII_KT_FN, 1)
#define GIIK_F2			GII_KEY(GII_KT_FN, 2)
#define GIIK_F3			GII_KEY(GII_KT_FN, 3)
#define GIIK_F4			GII_KEY(GII_KT_FN, 4)
#define GIIK_F5			GII_KEY(GII_KT_FN, 5)
#define GIIK_F6			GII_KEY(GII_KT_FN, 6)
#define GIIK_F7			GII_KEY(GII_KT_FN, 7)
#define GIIK_F8			GII_KEY(GII_KT_FN, 8)
#define GIIK_F9			GII_KEY(GII_KT_FN, 9)
#define GIIK_F10		GII_KEY(GII_KT_FN, 10)
#define GIIK_F11		GII_KEY(GII_KT_FN, 11)
#define GIIK_F12		GII_KEY(GII_KT_FN, 12)
#define GIIK_F13		GII_KEY(GII_KT_FN, 13)
#define GIIK_F14		GII_KEY(GII_KT_FN, 14)
#define GIIK_F15		GII_KEY(GII_KT_FN, 15)
#define GIIK_F16		GII_KEY(GII_KT_FN, 16)
#define GIIK_F17		GII_KEY(GII_KT_FN, 17)
#define GIIK_F18		GII_KEY(GII_KT_FN, 18)
#define GIIK_F19		GII_KEY(GII_KT_FN, 19)
#define GIIK_F20		GII_KEY(GII_KT_FN, 20)
#define GIIK_F21		GII_KEY(GII_KT_FN, 21)
#define GIIK_F22		GII_KEY(GII_KT_FN, 22)
#define GIIK_F23		GII_KEY(GII_KT_FN, 23)
#define GIIK_F24		GII_KEY(GII_KT_FN, 24)
#define GIIK_F25		GII_KEY(GII_KT_FN, 25)
#define GIIK_F26		GII_KEY(GII_KT_FN, 26)
#define GIIK_F27		GII_KEY(GII_KT_FN, 27)
#define GIIK_F28		GII_KEY(GII_KT_FN, 28)
#define GIIK_F29		GII_KEY(GII_KT_FN, 29)
#define GIIK_F30		GII_KEY(GII_KT_FN, 30)
#define GIIK_F31		GII_KEY(GII_KT_FN, 31)
#define GIIK_F32		GII_KEY(GII_KT_FN, 32)
#define GIIK_F33		GII_KEY(GII_KT_FN, 33)
#define GIIK_F34		GII_KEY(GII_KT_FN, 34)
#define GIIK_F35		GII_KEY(GII_KT_FN, 35)
#define GIIK_F36		GII_KEY(GII_KT_FN, 36)
#define GIIK_F37		GII_KEY(GII_KT_FN, 37)
#define GIIK_F38		GII_KEY(GII_KT_FN, 38)
#define GIIK_F39		GII_KEY(GII_KT_FN, 39)
#define GIIK_F40		GII_KEY(GII_KT_FN, 40)
#define GIIK_F41		GII_KEY(GII_KT_FN, 41)
#define GIIK_F42		GII_KEY(GII_KT_FN, 42)
#define GIIK_F43		GII_KEY(GII_KT_FN, 43)
#define GIIK_F44		GII_KEY(GII_KT_FN, 44)
#define GIIK_F45		GII_KEY(GII_KT_FN, 45)
#define GIIK_F46		GII_KEY(GII_KT_FN, 46)
#define GIIK_F47		GII_KEY(GII_KT_FN, 47)
#define GIIK_F48		GII_KEY(GII_KT_FN, 48)
#define GIIK_F49		GII_KEY(GII_KT_FN, 49)
#define GIIK_F50		GII_KEY(GII_KT_FN, 50)
#define GIIK_F51		GII_KEY(GII_KT_FN, 51)
#define GIIK_F52		GII_KEY(GII_KT_FN, 52)
#define GIIK_F53		GII_KEY(GII_KT_FN, 53)
#define GIIK_F54		GII_KEY(GII_KT_FN, 54)
#define GIIK_F55		GII_KEY(GII_KT_FN, 55)
#define GIIK_F56		GII_KEY(GII_KT_FN, 56)
#define GIIK_F57		GII_KEY(GII_KT_FN, 57)
#define GIIK_F58		GII_KEY(GII_KT_FN, 58)
#define GIIK_F59		GII_KEY(GII_KT_FN, 59)
#define GIIK_F60		GII_KEY(GII_KT_FN, 60)
#define GIIK_F61		GII_KEY(GII_KT_FN, 61)
#define GIIK_F62		GII_KEY(GII_KT_FN, 62)
#define GIIK_F63		GII_KEY(GII_KT_FN, 63)
#define GIIK_F64		GII_KEY(GII_KT_FN, 64)

/* special keys */

#define GIIK_VOID		GII_KEY(GII_KT_SPEC, 0)

/* GIIK_Enter and GIIK_Delete are equal to GIIUC_Return
 * and GIIUC_Delete, but they get #defined far below
 * from here. Thus use the hardcoded ASCII values. */
#define GIIK_Enter		0x0d
#define GIIK_Delete		0x7f

#define GIIK_Break		GII_KEY(GII_KT_SPEC, 5)

#define GIIK_ScrollForw		GII_KEY(GII_KT_SPEC, 10)
#define GIIK_ScrollBack		GII_KEY(GII_KT_SPEC, 11)

#define GIIK_Boot		GII_KEY(GII_KT_SPEC, 12)
#define GIIK_Compose		GII_KEY(GII_KT_SPEC, 14)
#define GIIK_SAK		GII_KEY(GII_KT_SPEC, 15)

#define GIIK_Undo		GII_KEY(GII_KT_SPEC, 23)
#define GIIK_Redo		GII_KEY(GII_KT_SPEC, 24)
#define GIIK_Menu		GII_KEY(GII_KT_SPEC, 25)
#define GIIK_Cancel		GII_KEY(GII_KT_SPEC, 26)
#define GIIK_PrintScreen	GII_KEY(GII_KT_SPEC, 27)
#define GIIK_Execute		GII_KEY(GII_KT_SPEC, 28)
#define GIIK_Find		GII_KEY(GII_KT_SPEC, 30)
#define GIIK_Begin		GII_KEY(GII_KT_SPEC, 31)
#define GIIK_Clear		GII_KEY(GII_KT_SPEC, 32)
#define GIIK_Insert		GII_KEY(GII_KT_SPEC, 34)
#define GIIK_Select		GII_KEY(GII_KT_SPEC, 35)
#define GIIK_Macro		GII_KEY(GII_KT_SPEC, 38)
#define GIIK_Help		GII_KEY(GII_KT_SPEC, 39)
#define GIIK_Do			GII_KEY(GII_KT_SPEC, 40)
#define GIIK_Pause		GII_KEY(GII_KT_SPEC, 41)
#define GIIK_Stop		GIIK_Pause
#define GIIK_SysRq		GII_KEY(GII_KT_SPEC, 42)
#define GIIK_ModeSwitch		GII_KEY(GII_KT_SPEC, 43)

#define GIIK_Up			GII_KEY(GII_KT_SPEC, 50)
#define GIIK_Down		GII_KEY(GII_KT_SPEC, 51)
#define GIIK_Left		GII_KEY(GII_KT_SPEC, 52)
#define GIIK_Right		GII_KEY(GII_KT_SPEC, 53)
#define GIIK_Prior		GII_KEY(GII_KT_SPEC, 54)
#define GIIK_PageUp		GIIK_Prior
#define GIIK_Next		GII_KEY(GII_KT_SPEC, 55)
#define GIIK_PageDown		GIIK_Next
#define GIIK_Home		GII_KEY(GII_KT_SPEC, 56)
#define GIIK_End		GII_KEY(GII_KT_SPEC, 57)

/* keys on the numeric keypad */

#define GIIK_P0			GII_KEY(GII_KT_PAD, '0')
#define GIIK_P1			GII_KEY(GII_KT_PAD, '1')
#define GIIK_P2			GII_KEY(GII_KT_PAD, '2')
#define GIIK_P3			GII_KEY(GII_KT_PAD, '3')
#define GIIK_P4			GII_KEY(GII_KT_PAD, '4')
#define GIIK_P5			GII_KEY(GII_KT_PAD, '5')
#define GIIK_P6			GII_KEY(GII_KT_PAD, '6')
#define GIIK_P7			GII_KEY(GII_KT_PAD, '7')
#define GIIK_P8			GII_KEY(GII_KT_PAD, '8')
#define GIIK_P9			GII_KEY(GII_KT_PAD, '9')
#define GIIK_PA			GII_KEY(GII_KT_PAD, 'A')
#define GIIK_PB			GII_KEY(GII_KT_PAD, 'B')
#define GIIK_PC			GII_KEY(GII_KT_PAD, 'C')
#define GIIK_PD			GII_KEY(GII_KT_PAD, 'D')
#define GIIK_PE			GII_KEY(GII_KT_PAD, 'E')
#define GIIK_PF			GII_KEY(GII_KT_PAD, 'F')

#define GIIK_PPlus		GII_KEY(GII_KT_PAD, '+')
#define GIIK_PMinus		GII_KEY(GII_KT_PAD, '-')
#define GIIK_PSlash		GII_KEY(GII_KT_PAD, '/')
#define GIIK_PAsterisk		GII_KEY(GII_KT_PAD, '*')
#define GIIK_PStar		GIIK_PAsterisk
#define GIIK_PEqual		GII_KEY(GII_KT_PAD, '=')
#define GIIK_PSeparator		GII_KEY(GII_KT_PAD, ',')
#define GIIK_PDecimal		GII_KEY(GII_KT_PAD, '.')
#define GIIK_PParenLeft		GII_KEY(GII_KT_PAD, '(')
#define GIIK_PParenRight	GII_KEY(GII_KT_PAD, ')')
#define GIIK_PSpace		GII_KEY(GII_KT_PAD, ' ')
#define GIIK_PEnter		GII_KEY(GII_KT_PAD, '\r')
#define GIIK_PTab		GII_KEY(GII_KT_PAD, '\t')

#define GIIK_PPlusMinus		GII_KEY(GII_KT_PAD, 0x80)
#define GIIK_PBegin		GII_KEY(GII_KT_PAD, 0x81)

#define GIIK_PF1		GII_KEY(GII_KT_PAD, 0x91)
#define GIIK_PF2		GII_KEY(GII_KT_PAD, 0x92)
#define GIIK_PF3		GII_KEY(GII_KT_PAD, 0x93)
#define GIIK_PF4		GII_KEY(GII_KT_PAD, 0x94)
#define GIIK_PF5		GII_KEY(GII_KT_PAD, 0x95)
#define GIIK_PF6		GII_KEY(GII_KT_PAD, 0x96)
#define GIIK_PF7		GII_KEY(GII_KT_PAD, 0x97)
#define GIIK_PF8		GII_KEY(GII_KT_PAD, 0x98)
#define GIIK_PF9		GII_KEY(GII_KT_PAD, 0x99)

/* Remote control, shortcut, and digi keys.  Note: corresponds to linux's
 * linux-input, which is likely to be the dominant system eventually,
 * given most people are too lazy to make their own keymaps and lirc doesn't
 * have a base keymap, just some key symbol names.
 *
 * So, try to keep a simple mapping to linux-input if possible when
 * adding keys.
 *
 * Current mapping against linux/input.h:
 * "keys" 0x140-0x19f are mapped to GII_KT_RC | (0x10 to 0x6f)
 * "keys" 0x70 and up are mapped to their code | GII_KT_RC, except
 * for those which existed prior to adding the linux-input keys.
 *
 * Note that while the GII_KT_RC codes may appear in mainstream
 * sources they are not considered to be formally part of this
 * version of LibGII; they will become formally valid in the next
 * release of LibGII (when this comment will hopefully be deleted :-)
 *
 */

#define GIIK_Digi		GII_KEY(GII_KT_RC,(0x140 - 0x130))
#define GIIK_Tool_Pen		GII_KEY(GII_KT_RC,(0x140 - 0x130))
#define GIIK_Tool_Rubber	GII_KEY(GII_KT_RC,(0x141 - 0x130))
#define GIIK_Tool_Brush		GII_KEY(GII_KT_RC,(0x142 - 0x130))
#define GIIK_Tool_Pencil	GII_KEY(GII_KT_RC,(0x143 - 0x130))
#define GIIK_Tool_Airbrush	GII_KEY(GII_KT_RC,(0x144 - 0x130))
#define GIIK_Tool_Finger	GII_KEY(GII_KT_RC,(0x145 - 0x130))
#define GIIK_Tool_Mouse		GII_KEY(GII_KT_RC,(0x146 - 0x130))
#define GIIK_Tool_Lens		GII_KEY(GII_KT_RC,(0x147 - 0x130))
#define GIIK_Touch		GII_KEY(GII_KT_RC,(0x14a - 0x130))
#define GIIK_Stylus		GII_KEY(GII_KT_RC,(0x14b - 0x130))
#define GIIK_Stylus2		GII_KEY(GII_KT_RC,(0x14c - 0x130))
#define GIIK_Tool_DoubleTap	GII_KEY(GII_KT_RC,(0x14d - 0x130))
#define GIIK_Tool_TripleTap	GII_KEY(GII_KT_RC,(0x14e - 0x130))
#define GIIK_Ok			GII_KEY(GII_KT_RC,(0x160 - 0x130))
#define GIIK_Goto		GII_KEY(GII_KT_RC,(0x162 - 0x130))
#define GIIK_Power2		GII_KEY(GII_KT_RC,(0x164 - 0x130))
#define GIIK_Option		GII_KEY(GII_KT_RC,(0x165 - 0x130))
#define GIIK_Info		GII_KEY(GII_KT_RC,(0x166 - 0x130))
#define GIIK_Time		GII_KEY(GII_KT_RC,(0x167 - 0x130))
#define GIIK_Vendor		GII_KEY(GII_KT_RC,(0x168 - 0x130))
#define GIIK_Archive		GII_KEY(GII_KT_RC,(0x169 - 0x130))
#define GIIK_Program		GII_KEY(GII_KT_RC,(0x16a - 0x130))
#define GIIK_Channel		GII_KEY(GII_KT_RC,(0x16b - 0x130))
#define GIIK_Favorites		GII_KEY(GII_KT_RC,(0x16c - 0x130))
#define GIIK_Epg		GII_KEY(GII_KT_RC,(0x16d - 0x130))
#define GIIK_Pvr		GII_KEY(GII_KT_RC,(0x16e - 0x130))
#define GIIK_Mhp		GII_KEY(GII_KT_RC,(0x16f - 0x130))
#define GIIK_Language		GII_KEY(GII_KT_RC,(0x170 - 0x130))
#define GIIK_Title		GII_KEY(GII_KT_RC,(0x171 - 0x130))
#define GIIK_Subtitle		GII_KEY(GII_KT_RC,(0x172 - 0x130))
#define GIIK_Angle		GII_KEY(GII_KT_RC,(0x173 - 0x130))
#define GIIK_Zoom		GII_KEY(GII_KT_RC,(0x174 - 0x130))
#define GIIK_Mode		GII_KEY(GII_KT_RC,(0x175 - 0x130))
#define GIIK_Keyboard		GII_KEY(GII_KT_RC,(0x176 - 0x130))
#define GIIK_Screen		GII_KEY(GII_KT_RC,(0x177 - 0x130))
#define GIIK_Vga		GII_KEY(GII_KT_RC,(0x178 - 0x130))
#define GIIK_Tv			GII_KEY(GII_KT_RC,(0x179 - 0x130))
#define GIIK_Tv2		GII_KEY(GII_KT_RC,(0x17a - 0x130))
#define GIIK_Vcr		GII_KEY(GII_KT_RC,(0x17b - 0x130))
#define GIIK_Vcr2		GII_KEY(GII_KT_RC,(0x17c - 0x130))
#define GIIK_Sat		GII_KEY(GII_KT_RC,(0x17d - 0x130))
#define GIIK_Sat2		GII_KEY(GII_KT_RC,(0x17e - 0x130))
#define GIIK_Cd			GII_KEY(GII_KT_RC,(0x17f - 0x130))
#define GIIK_Tape		GII_KEY(GII_KT_RC,(0x180 - 0x130))
#define GIIK_Radio		GII_KEY(GII_KT_RC,(0x181 - 0x130))
#define GIIK_Tuner		GII_KEY(GII_KT_RC,(0x182 - 0x130))
#define GIIK_Player		GII_KEY(GII_KT_RC,(0x183 - 0x130))
#define GIIK_Text		GII_KEY(GII_KT_RC,(0x184 - 0x130))
#define GIIK_Dvd		GII_KEY(GII_KT_RC,(0x185 - 0x130))
#define GIIK_Aux		GII_KEY(GII_KT_RC,(0x186 - 0x130))
#define GIIK_Mp3		GII_KEY(GII_KT_RC,(0x187 - 0x130))
#define GIIK_Audio		GII_KEY(GII_KT_RC,(0x188 - 0x130))
#define GIIK_Video		GII_KEY(GII_KT_RC,(0x189 - 0x130))
#define GIIK_Directory		GII_KEY(GII_KT_RC,(0x18a - 0x130))
#define GIIK_List		GII_KEY(GII_KT_RC,(0x18b - 0x130))
#define GIIK_Memo		GII_KEY(GII_KT_RC,(0x18c - 0x130))
#define GIIK_Calendar		GII_KEY(GII_KT_RC,(0x18d - 0x130))
#define GIIK_Red		GII_KEY(GII_KT_RC,(0x18e - 0x130))
#define GIIK_Green		GII_KEY(GII_KT_RC,(0x18f - 0x130))
#define GIIK_Yellow		GII_KEY(GII_KT_RC,(0x190 - 0x130))
#define GIIK_Blue		GII_KEY(GII_KT_RC,(0x191 - 0x130))
#define GIIK_ChannelUp		GII_KEY(GII_KT_RC,(0x192 - 0x130))
#define GIIK_ChannelDown	GII_KEY(GII_KT_RC,(0x193 - 0x130))
#define GIIK_First		GII_KEY(GII_KT_RC,(0x194 - 0x130))
#define GIIK_Last		GII_KEY(GII_KT_RC,(0x195 - 0x130))
#define GIIK_Ab			GII_KEY(GII_KT_RC,(0x196 - 0x130))
#define GIIK_Restart		GII_KEY(GII_KT_RC,(0x198 - 0x130))
#define GIIK_Slow		GII_KEY(GII_KT_RC,(0x199 - 0x130))
#define GIIK_Shuffle		GII_KEY(GII_KT_RC,(0x19a - 0x130))
#define GIIK_Previous		GII_KEY(GII_KT_RC,(0x19c - 0x130))
#define GIIK_Digits		GII_KEY(GII_KT_RC,(0x19d - 0x130))
#define GIIK_Teen		GII_KEY(GII_KT_RC,(0x19e - 0x130))
#define GIIK_Twen		GII_KEY(GII_KT_RC,(0x19f - 0x130))
#define GIIK_Mute		GII_KEY(GII_KT_RC,113)
#define GIIK_VolumeDown		GII_KEY(GII_KT_RC,114)
#define GIIK_VolumeUp		GII_KEY(GII_KT_RC,115)
#define GIIK_Power		GII_KEY(GII_KT_RC,116)
#define GIIK_Again		GII_KEY(GII_KT_RC,129)
#define GIIK_Props		GII_KEY(GII_KT_RC,130)
#define GIIK_Front		GII_KEY(GII_KT_RC,132)
#define GIIK_Copy		GII_KEY(GII_KT_RC,133)
#define GIIK_Open		GII_KEY(GII_KT_RC,134)
#define GIIK_Paste		GII_KEY(GII_KT_RC,135)
#define GIIK_Cut		GII_KEY(GII_KT_RC,137)
#define GIIK_Calc		GII_KEY(GII_KT_RC,140)
#define GIIK_Setup		GII_KEY(GII_KT_RC,141)
#define GIIK_Sleep		GII_KEY(GII_KT_RC,142)
#define GIIK_Wakeup		GII_KEY(GII_KT_RC,143)
#define GIIK_File		GII_KEY(GII_KT_RC,144)
#define GIIK_SendFile		GII_KEY(GII_KT_RC,145)
#define GIIK_DeleteFile		GII_KEY(GII_KT_RC,146)
#define GIIK_Xfer		GII_KEY(GII_KT_RC,147)
#define GIIK_Prog1		GII_KEY(GII_KT_RC,148)
#define GIIK_Prog2		GII_KEY(GII_KT_RC,149)
#define GIIK_Www		GII_KEY(GII_KT_RC,150)
#define GIIK_Msdos		GII_KEY(GII_KT_RC,151)
#define GIIK_Coffee		GII_KEY(GII_KT_RC,152)
#define GIIK_Direction		GII_KEY(GII_KT_RC,153)
#define GIIK_CycleWindows	GII_KEY(GII_KT_RC,154)
#define GIIK_Mail		GII_KEY(GII_KT_RC,155)
#define GIIK_Bookmarks		GII_KEY(GII_KT_RC,156)
#define GIIK_Computer		GII_KEY(GII_KT_RC,157)
#define GIIK_Back		GII_KEY(GII_KT_RC,158)
#define GIIK_Forward		GII_KEY(GII_KT_RC,159)
#define GIIK_CloseCd		GII_KEY(GII_KT_RC,160)
#define GIIK_EjectCd		GII_KEY(GII_KT_RC,161)
#define GIIK_EjectCloseCd	GII_KEY(GII_KT_RC,162)
#define GIIK_NextSong		GII_KEY(GII_KT_RC,163)
#define GIIK_PlayPause		GII_KEY(GII_KT_RC,164)
#define GIIK_PreviousSong	GII_KEY(GII_KT_RC,165)
#define GIIK_StopCd		GII_KEY(GII_KT_RC,166)
#define GIIK_Record		GII_KEY(GII_KT_RC,167)
#define GIIK_Rewind		GII_KEY(GII_KT_RC,168)
#define GIIK_Phone		GII_KEY(GII_KT_RC,169)
#define GIIK_Iso		GII_KEY(GII_KT_RC,170)
#define GIIK_Config		GII_KEY(GII_KT_RC,171)
#define GIIK_Homepage		GII_KEY(GII_KT_RC,172)
#define GIIK_Refresh		GII_KEY(GII_KT_RC,173)
#define GIIK_Exit		GII_KEY(GII_KT_RC,174)
#define GIIK_Move		GII_KEY(GII_KT_RC,175)
#define GIIK_Edit		GII_KEY(GII_KT_RC,176)
#define GIIK_ScrollUp		GII_KEY(GII_KT_RC,177)
#define GIIK_ScrollDown		GII_KEY(GII_KT_RC,178)
#define GIIK_PlayCd		GII_KEY(GII_KT_RC,200)
#define GIIK_PauseCd		GII_KEY(GII_KT_RC,201)
#define GIIK_Prog3		GII_KEY(GII_KT_RC,202)
#define GIIK_Prog4		GII_KEY(GII_KT_RC,203)
#define GIIK_Suspend		GII_KEY(GII_KT_RC,205)
#define GIIK_Close		GII_KEY(GII_KT_RC,206)
#define GIIK_Play		GII_KEY(GII_KT_RC,207)
#define GIIK_FastForward	GII_KEY(GII_KT_RC,208)
#define GIIK_BassBoost		GII_KEY(GII_KT_RC,209)
#define GIIK_Print		GII_KEY(GII_KT_RC,210)
#define GIIK_Hp			GII_KEY(GII_KT_RC,211)
#define GIIK_Camera		GII_KEY(GII_KT_RC,212)
#define GIIK_Sound		GII_KEY(GII_KT_RC,213)
#define GIIK_Question		GII_KEY(GII_KT_RC,214)
#define GIIK_Email		GII_KEY(GII_KT_RC,215)
#define GIIK_Chat		GII_KEY(GII_KT_RC,216)
#define GIIK_Search		GII_KEY(GII_KT_RC,217)
#define GIIK_Connect		GII_KEY(GII_KT_RC,218)
#define GIIK_Finance		GII_KEY(GII_KT_RC,219)
#define GIIK_Sport		GII_KEY(GII_KT_RC,220)
#define GIIK_Shop		GII_KEY(GII_KT_RC,221)
#define GIIK_Alterase		GII_KEY(GII_KT_RC,222)
#define GIIK_BrightnessDown	GII_KEY(GII_KT_RC,224)
#define GIIK_BrightnessUp	GII_KEY(GII_KT_RC,225)
#define GIIK_Media		GII_KEY(GII_KT_RC,226)

/* modifier keys */

#define GIIK_Shift		GII_KEY(GII_KT_MOD, GII_KM_SHIFT)
#define GIIK_Ctrl		GII_KEY(GII_KT_MOD, GII_KM_CTRL)
#define GIIK_Alt		GII_KEY(GII_KT_MOD, GII_KM_ALT)
#define GIIK_Meta		GII_KEY(GII_KT_MOD, GII_KM_META)
#define GIIK_Super		GII_KEY(GII_KT_MOD, GII_KM_SUPER)
#define GIIK_Hyper		GII_KEY(GII_KT_MOD, GII_KM_HYPER)
#define GIIK_AltGr		GII_KEY(GII_KT_MOD, GII_KM_ALTGR)
#define GIIK_Caps		GII_KEY(GII_KT_MOD, GII_KM_CAPS)
#define GIIK_Num		GII_KEY(GII_KT_MOD, GII_KM_NUM)
#define GIIK_Scroll		GII_KEY(GII_KT_MOD, GII_KM_SCROLL)

/* modifier _labels_ */

#define GIIK_ShiftL		(GIIK_Shift  | 0)
#define GIIK_ShiftR		(GIIK_Shift  | GII_KM_RIGHT)
#define GIIK_CtrlL		(GIIK_Ctrl   | 0)
#define GIIK_CtrlR		(GIIK_Ctrl   | GII_KM_RIGHT)
#define GIIK_AltL		(GIIK_Alt    | 0)
#define GIIK_AltR		(GIIK_Alt    | GII_KM_RIGHT)
#define GIIK_MetaL		(GIIK_Meta   | 0)
#define GIIK_MetaR		(GIIK_Meta   | GII_KM_RIGHT)
#define GIIK_SuperL		(GIIK_Super  | 0)
#define GIIK_SuperR		(GIIK_Super  | GII_KM_RIGHT)
#define GIIK_HyperL		(GIIK_Hyper  | 0)
#define GIIK_HyperR		(GIIK_Hyper  | GII_KM_RIGHT)

#define GIIK_ShiftLock		(GIIK_Shift  | GII_KM_LOCK)
#define GIIK_CtrlLock		(GIIK_Ctrl   | GII_KM_LOCK)
#define GIIK_AltLock		(GIIK_Alt    | GII_KM_LOCK)
#define GIIK_MetaLock		(GIIK_Meta   | GII_KM_LOCK)
#define GIIK_SuperLock		(GIIK_Super  | GII_KM_LOCK)
#define GIIK_HyperLock		(GIIK_Hyper  | GII_KM_LOCK)
#define GIIK_AltGrLock		(GIIK_AltGr  | GII_KM_LOCK)
#define GIIK_CapsLock		(GIIK_Caps   | GII_KM_LOCK)
#define GIIK_NumLock		(GIIK_Num    | GII_KM_LOCK)
#define GIIK_ScrollLock		(GIIK_Scroll | GII_KM_LOCK)

/* miscellaneous */

#define GIIK_NIL	0xffff	/* used to indicate "not mapped yet" */
#define GII_BUTTON_NIL	0xff	/* used for pseudo keys (composed ones) */

/* ASCII keys */
#define GIIUC_Nul		0x00
#define GIIUC_BackSpace		0x08
#define GIIUC_Tab		0x09
#define GIIUC_Linefeed		0x0a
#define GIIUC_Return		0x0d
#define GIIUC_Escape		0x1b
#define GIIUC_Delete		0x7f

#define GIIUC_Space		0x20
#define GIIUC_Exclamation	0x21
#define GIIUC_Exclam		GIIUC_Exclamation
#define GIIUC_DoubleQuote	0x22
#define GIIUC_QuoteDbl		GIIUC_DoubleQuote
#define GIIUC_NumberSign	0x23
#define GIIUC_Hash		GIIUC_NumberSign
#define GIIUC_Dollar		0x24
#define GIIUC_Percent		0x25
#define GIIUC_Ampersand		0x26
#define GIIUC_Apostrophe	0x27
#define GIIUC_ParenLeft		0x28
#define GIIUC_ParenRight	0x29
#define GIIUC_Asterisk		0x2a
#define GIIUC_Star		GIIUC_Asterisk
#define GIIUC_Plus		0x2b
#define GIIUC_Comma		0x2c
#define GIIUC_Minus		0x2d
#define GIIUC_Period		0x2e
#define GIIUC_Slash		0x2f
#define GIIUC_0			0x30
#define GIIUC_1			0x31
#define GIIUC_2			0x32
#define GIIUC_3			0x33
#define GIIUC_4			0x34
#define GIIUC_5			0x35
#define GIIUC_6			0x36
#define GIIUC_7			0x37
#define GIIUC_8			0x38
#define GIIUC_9			0x39
#define GIIUC_Colon		0x3a
#define GIIUC_Semicolon		0x3b
#define GIIUC_Less		0x3c
#define GIIUC_Equal		0x3d
#define GIIUC_Greater		0x3e
#define GIIUC_Question		0x3f
#define GIIUC_At		0x40
#define GIIUC_A			0x41
#define GIIUC_B			0x42
#define GIIUC_C			0x43
#define GIIUC_D			0x44
#define GIIUC_E			0x45
#define GIIUC_F			0x46
#define GIIUC_G			0x47
#define GIIUC_H			0x48
#define GIIUC_I			0x49
#define GIIUC_J			0x4a
#define GIIUC_K			0x4b
#define GIIUC_L			0x4c
#define GIIUC_M			0x4d
#define GIIUC_N			0x4e
#define GIIUC_O			0x4f
#define GIIUC_P			0x50
#define GIIUC_Q			0x51
#define GIIUC_R			0x52
#define GIIUC_S			0x53
#define GIIUC_T			0x54
#define GIIUC_U			0x55
#define GIIUC_V			0x56
#define GIIUC_W			0x57
#define GIIUC_X			0x58
#define GIIUC_Y			0x59
#define GIIUC_Z			0x5a
#define GIIUC_BracketLeft	0x5b
#define GIIUC_BackSlash		0x5c
#define GIIUC_BracketRight	0x5d
#define GIIUC_Circumflex	0x5e
#define GIIUC_Hat		GIIUC_Circumflex
#define GIIUC_Underscore	0x5f
#define GIIUC_Grave		0x60
#define GIIUC_a			0x61
#define GIIUC_b			0x62
#define GIIUC_c			0x63
#define GIIUC_d			0x64
#define GIIUC_e			0x65
#define GIIUC_f			0x66
#define GIIUC_g			0x67
#define GIIUC_h			0x68
#define GIIUC_i			0x69
#define GIIUC_j			0x6a
#define GIIUC_k			0x6b
#define GIIUC_l			0x6c
#define GIIUC_m			0x6d
#define GIIUC_n			0x6e
#define GIIUC_o			0x6f
#define GIIUC_p			0x70
#define GIIUC_q			0x71
#define GIIUC_r			0x72
#define GIIUC_s			0x73
#define GIIUC_t			0x74
#define GIIUC_u			0x75
#define GIIUC_v			0x76
#define GIIUC_w			0x77
#define GIIUC_x			0x78
#define GIIUC_y			0x79
#define GIIUC_z			0x7a
#define GIIUC_BraceLeft		0x7b
#define GIIUC_Bar		0x7c
#define GIIUC_Pipe		GIIUC_Bar
#define GIIUC_BraceRight	0x7d
#define GIIUC_Tilde		0x7e

#define GIIUC_NoBreakSpace	0xa0
#define GIIUC_NBSP		GIIUC_NoBreakSpace
#define GIIUC_ExclamDown	0xa1
#define GIIUC_Cent		0xa2
#define GIIUC_Sterling		0xa3
#define GIIUC_Pound		GIIUC_Sterling
#define GIIUC_Currency		0xa4
#define GIIUC_Yen		0xa5
#define GIIUC_BrokenBar		0xa6
#define GIIUC_Section		0xa7
#define GIIUC_Diaeresis		0xa8
#define GIIUC_Umlaut		GIIUC_Diaeresis
#define GIIUC_Copyright		0xa9
#define GIIUC_OrdFeminine	0xaa
#define GIIUC_GuillemotLeft	0xab
#define GIIUC_NotSign		0xac
#define GIIUC_SoftHyphen	0xad
#define GIIUC_Registered	0xae
#define GIIUC_Macron		0xaf
#define GIIUC_Degree		0xb0
#define GIIUC_PlusMinus		0xb1
#define GIIUC_TwoSuperior	0xb2
#define GIIUC_ThreeSuperior	0xb3
#define GIIUC_Acute		0xb4
#define GIIUC_Mu		0xb5
#define GIIUC_Micro		GIIUC_Mu
#define GIIUC_Paragraph		0xb6
#define GIIUC_Pilcrow		GIIUC_Paragraph
#define GIIUC_PeriodCentered	0xb7
#define GIIUC_MiddleDot		GIIUC_PeriodCentered
#define GIIUC_Cedilla		0xb8
#define GIIUC_OneSuperior	0xb9
#define GIIUC_mKuline		0xba
#define GIIUC_GuillemotRight	0xbb
#define GIIUC_OneQuarter	0xbc
#define GIIUC_OneHalf		0xbd
#define GIIUC_ThreeQuarters	0xbe
#define GIIUC_QuestionDown	0xbf
#define GIIUC_Agrave		0xc0
#define GIIUC_Aacute		0xc1
#define GIIUC_Acircumflex	0xc2
#define GIIUC_Atilde		0xc3
#define GIIUC_Adiaeresis	0xc4
#define GIIUC_Aumlaut		GIIUC_Adiaeresis
#define GIIUC_Aring		0xc5
#define GIIUC_AE		0xc6
#define GIIUC_Ccedilla		0xc7
#define GIIUC_Egrave		0xc8
#define GIIUC_Eacute		0xc9
#define GIIUC_Ecircumflex	0xca
#define GIIUC_Ediaeresis	0xcb
#define GIIUC_Eumlaut		GIIUC_Ediaeresis
#define GIIUC_Igrave		0xcc
#define GIIUC_Iacute		0xcd
#define GIIUC_Icircumflex	0xce
#define GIIUC_Idiaeresis	0xcf
#define GIIUC_Iumlaut		GIIUC_Idiaeresis
#define GIIUC_ETH		0xd0
#define GIIUC_Ntilde		0xd1
#define GIIUC_Ograve		0xd2
#define GIIUC_Oacute		0xd3
#define GIIUC_Ocircumflex	0xd4
#define GIIUC_Otilde		0xd5
#define GIIUC_Odiaeresis	0xd6
#define GIIUC_Oumlaut		GIIUC_Odiaeresis
#define GIIUC_Multiply		0xd7
#define GIIUC_Ooblique		0xd8
#define GIIUC_Ugrave		0xd9
#define GIIUC_Uacute		0xda
#define GIIUC_Ucircumflex	0xdb
#define GIIUC_Udiaeresis	0xdc
#define GIIUC_Uumlaut		GIIUC_Udiaeresis
#define GIIUC_Yacute		0xdd
#define GIIUC_THORN		0xde
#define GIIUC_ssharp		0xdf
#define GIIUC_agrave		0xe0
#define GIIUC_aacute		0xe1
#define GIIUC_acircumflex	0xe2
#define GIIUC_atilde		0xe3
#define GIIUC_adiaeresis	0xe4
#define GIIUC_aumlaut		GIIUC_adiaeresis
#define GIIUC_aring		0xe5
#define GIIUC_ae		0xe6
#define GIIUC_ccedilla		0xe7
#define GIIUC_egrave		0xe8
#define GIIUC_eacute		0xe9
#define GIIUC_ecircumflex	0xea
#define GIIUC_ediaeresis	0xeb
#define GIIUC_eumlaut		GIIUC_ediaeresis
#define GIIUC_igrave		0xec
#define GIIUC_iacute		0xed
#define GIIUC_icircumflex	0xee
#define GIIUC_idiaeresis	0xef
#define GIIUC_iumlaut		GIIUC_idiaeresis
#define GIIUC_eth		0xf0
#define GIIUC_ntilde		0xf1
#define GIIUC_ograve		0xf2
#define GIIUC_oacute		0xf3
#define GIIUC_ocircumflex	0xf4
#define GIIUC_otilde		0xf5
#define GIIUC_odiaeresis	0xf6
#define GIIUC_oumlaut		GIIUC_odiaeresis
#define GIIUC_Division		0xf7
#define GIIUC_oslash		0xf8
#define GIIUC_ugrave		0xf9
#define GIIUC_uacute		0xfa
#define GIIUC_ucircumflex	0xfb
#define GIIUC_udiaeresis	0xfc
#define GIIUC_uumlaut		GIIUC_udiaeresis
#define GIIUC_yacute		0xfd
#define GIIUC_thorn		0xfe
#define GIIUC_ydiaeresis	0xff
#define GIIUC_yumlaut		GIIUC_ydiaeresis

/* Dead keys */
#define GIIK_DeadRing			GII_KEY(GII_KT_DEAD, 0x00)
#define GIIK_DeadCaron			GII_KEY(GII_KT_DEAD, 0x01)
#define GIIK_DeadOgonek			GII_KEY(GII_KT_DEAD, 0x02)
#define GIIK_DeadIota			GII_KEY(GII_KT_DEAD, 0x03)
#define GIIK_DeadDoubleAcute		GII_KEY(GII_KT_DEAD, 0x04)
#define GIIK_DeadBreve			GII_KEY(GII_KT_DEAD, 0x05)
#define GIIK_DeadAboveDot		GII_KEY(GII_KT_DEAD, 0x06)
#define GIIK_DeadBelowDot		GII_KEY(GII_KT_DEAD, 0x07)
#define GIIK_DeadVoicedSound		GII_KEY(GII_KT_DEAD, 0x08)
#define GIIK_DeadSemiVoicedSound	GII_KEY(GII_KT_DEAD, 0x09)

#define GIIK_DeadAcute			GII_KEY(GII_KT_DEAD, GIIUC_Acute)
#define GIIK_DeadCedilla		GII_KEY(GII_KT_DEAD, GIIUC_Cedilla)
#define GIIK_DeadCircumflex		GII_KEY(GII_KT_DEAD, GIIUC_Circumflex)
#define GIIK_DeadDiaeresis		GII_KEY(GII_KT_DEAD, GIIUC_Diaeresis)
#define GIIK_DeadGrave			GII_KEY(GII_KT_DEAD, GIIUC_Grave)
#define GIIK_DeadTilde			GII_KEY(GII_KT_DEAD, GIIUC_Tilde)
#define GIIK_DeadMacron			GII_KEY(GII_KT_DEAD, GIIUC_Macron)

#endif /* _GII_KEYBOARD_H */
