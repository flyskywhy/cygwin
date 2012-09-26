/* $Id: events.h,v 1.5 2005/07/31 15:31:11 soyt Exp $
******************************************************************************

   LibGII event definitions

   Copyright (C) 1995-1997	Steffen Seeger	[seeger@ggi-project.org]
   Copyright (C) 1998		Andrew Apted	[andrew@ggi-project.org]
   Copyright (C) 1998		Andreas Beck	[becka@ggi-project.org]

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

#ifndef _GII_EVENTS_H
#define	_GII_EVENTS_H

#include <ggi/system.h>
#include <ggi/keyboard.h>

typedef enum {

	evNothing = 0,	/* event is not valid. (must be zero)	*/

	evCommand,	/* report command/do action		*/
	evInformation,	/* notification of new information	*/

	evExpose,	/* exposure event			*/
	/* empty slot */

	evKeyPress=5,	/* key has been pressed			*/
	evKeyRelease,	/* key has been released		*/
	evKeyRepeat,	/* automatically repeated keypress	*/

	evPtrRelative,	/* pointer movements reported relative	*/
	evPtrAbsolute,	/* pointer movements reported absolute	*/
	evPtrButtonPress,	/* pointer button pressed	*/
	evPtrButtonRelease,	/* pointer button released	*/

	evValRelative,	/* valuator change (reported relative)	*/
	evValAbsolute,	/* valuator change (reported absolute)	*/

	evLast		/* must be less than 33			*/

}  gii_event_type;

#define	EVMASK(x)	em ## x = (1 << ev ## x)
typedef enum {

	EVMASK(Nothing),

	EVMASK(Command),
	EVMASK(Information),
	EVMASK(Expose),

	EVMASK(KeyPress),
	EVMASK(KeyRelease),
	EVMASK(KeyRepeat),
	emKey		= emKeyPress | emKeyRelease | emKeyRepeat,
	emKeyboard	= emKey,

	EVMASK(PtrRelative),
	EVMASK(PtrAbsolute),
	EVMASK(PtrButtonPress),
	EVMASK(PtrButtonRelease),
	emPtrMove	= emPtrRelative | emPtrAbsolute,
	emPtrButton	= emPtrButtonPress | emPtrButtonRelease,
	emPointer	= emPtrMove | emPtrButton,

	EVMASK(ValRelative),
	EVMASK(ValAbsolute),
	emValuator	= emValRelative | emValAbsolute,

	emZero  = 0,
	emAll	= ((1 << evLast) - 1) & ~emNothing

} gii_event_mask;
#undef EVMASK


#define GII_EV_ORIGIN_NONE	0x00000000	/* Anonymous */
#define GII_EV_ORIGIN_SENDEVENT	0x80000000	/* Event was due to
						   SendEvent call */
#define GII_EV_ORIGIN(id)	(id)		/* Otherwise, it's an id */

#define GII_EV_TARGET_ALL	0x00000000	/* Broadcast event */
#define GII_EV_TARGET_QUEUE	0x80000000	/* Just queue the event */


#define	COMMON_DATA  \
	uint8_t	  size;		/* size of event in bytes	*/\
	uint8_t	  type;		/* type of this event		*/\
	int16_t   error;		/* error (for replies)		*/\
	uint32_t  origin;		/* origin device (etc)		*/\
	uint32_t  target;		/* target device (etc)		*/\
	struct timeval time	/* timestamp			*/


/*	This information is reported with all events. Use the <any> field
**	in a gii_event structure to access these fields.
*/
typedef struct {

	COMMON_DATA;

} gii_any_event;


/*
******************************************************************************
 Command/Information events
******************************************************************************
*/

#define GII_CMDFLAG_NODATA	((uint32_t)(1<<31))	/* Event has no data */
#define GII_CMDFLAG_PRIVATE	((uint32_t)(1<<30))	 /* The code is specific to a certain
							   inputlib */
#define GII_CMDFLAG_EXTERNAL	((uint32_t)(1<<29))	/* Event is sent to/from an external
							   system (like LibGGI) */


/*	These are used internally or to/from the application.
	The same event is used for both Command and Information	events.
	The recipient must not store references to the data. If	the data
	information is needed afterwards, copy it!
*/

typedef struct {

	COMMON_DATA;

	uint32_t  code;		/* command/request code		*/

} gii_cmd_nodata_event;


#define GII_CMD_DATA_MAX  (248-sizeof(gii_cmd_nodata_event))
typedef struct {

	COMMON_DATA;

	uint32_t  code;	        /* command/request code */
	uint8_t	  data[GII_CMD_DATA_MAX];	/* command related data */

} gii_cmd_event;


/* This one is posted, if at least one event has been lost due to queue
   overflow: */
#define GII_CMDCODE_EVENTLOST		((uint32_t)0x01 | GII_CMDFLAG_NODATA)

/* This event tell inputlibs that the application prefer absolute pointer
   events. */
#define GII_CMDCODE_PREFER_ABSPTR	((uint32_t)0x02 | GII_CMDFLAG_NODATA)

/* This event tell inputlibs that the application prefer relative pointer
   events. */
#define GII_CMDCODE_PREFER_RELPTR	((uint32_t)0x03 | GII_CMDFLAG_NODATA)

/* This event is sent/received to require/get the capabilities of a device
 * as specified in target/origin.
 * An event stating num_buttons=num_axes=0 says, that the device is inactive,
 * unplugged, whatever. Devices automatically report (detectable) state
 * changes via devinfo. But you need to re-query the valinfo records.
 */
#define GII_CMDCODE_GETDEVINFO	((uint32_t)0x01)
typedef struct {

	char		longname[75];
	char		shortname[5];

	gii_event_mask	can_generate;

	uint32_t	num_buttons;	/* Maximum number of buttons. */
	uint32_t	num_axes;	/* Maximum number of axes. */
} gii_cmddata_getdevinfo;
#define GII_NUM_MAX		0xfffeffff /* If num_buttons or num_axes is
					      more than this they should not
					      be interpreted as absolute
					      values (see below for what they
					      mean). */
#define GII_NUM_UNKNOWN		0xffffffff /* Number is unknown. */


typedef struct gii_valrange {
	int32_t		min, center, max;
} gii_valrange;

typedef enum {
	GII_PT_UNKNOWN,			/* unknown */
	GII_PT_TIME,			/* base unit s */
	GII_PT_FREQUENCY,		/* base unit 1/s (Hz) */
	GII_PT_LENGTH,			/* base unit m */
	GII_PT_VELOCITY,		/* base unit m/s */
	GII_PT_ACCELERATION,		/* base unit m/s^2 */
	GII_PT_ANGLE,			/* base unit radian */
	GII_PT_ANGVELOCITY,		/* base unit radian/s */
	GII_PT_ANGACCELERATION,		/* base unit radian/s^2 */
	GII_PT_AREA,			/* base unit m^2 */
	GII_PT_VOLUME,			/* base unit m^3 */
	GII_PT_MASS,			/* base unit kg */
	GII_PT_FORCE,			/* base unit N (kg*m/s^2) */
	GII_PT_PRESSURE,		/* base unit N/m^2 (Pa) */
	GII_PT_TORQUE,			/* base unit Nm */
	GII_PT_ENERGY,			/* base unit Nm, VAs, J */
	GII_PT_POWER,			/* base unit Nm/s, VA, W */
	GII_PT_TEMPERATURE,		/* base unit K */
	GII_PT_CURRENT,			/* base unit A */
	GII_PT_VOLTAGE,			/* base unit V (kg*m^2/(As^3)) */
	GII_PT_RESISTANCE,		/* base unit V/A (Ohm) */
	GII_PT_CAPACITY,		/* base unit As/V (Farad) */
	GII_PT_INDUCTIVITY,		/* base unit Vs/A (Henry) */
	GGI_PT_LAST
} gii_phystype;

/* This event is sent/received to require/get detailed data about valuator
 * axis.
 */
#define GII_CMDCODE_GETVALINFO	((uint32_t)0x02)
typedef struct {

	uint32_t	number;		/* Number of the valuator */
/* You may send this to get all valuators at once. Not recommended. */
#define GII_VAL_QUERY_ALL 0xffffffff

	char		longname[75];
	char		shortname[5];

	gii_valrange	range;
	gii_phystype	phystype;

	/* The SI value can be computed using the values below
	 * and the following formula (unless SI_mul is 0, which
	 * means the device is non-linear or the factor is unknown).
	 *
	 *   float SI;
	 *
	 *   SI = (float) (SI_add + value[n]) * (float) SI_mul
	 *        / (float) SI_div * pow(2.0, SI_shift);
	 */

	int32_t	        SI_add,SI_mul,SI_div,SI_shift;

} gii_cmddata_getvalinfo;


/*
******************************************************************************
 Other events
******************************************************************************
*/

/*	Exposure events give rectangles that need to be refreshed.
*/
typedef struct {

	COMMON_DATA;

	uint32_t	x,y;
	uint32_t	h,w;

} gii_expose_event;


/*	key events should be used to report events obtained from keys and
**	other switches.
*/
typedef struct {

	COMMON_DATA;

	uint32_t  modifiers;	/* current modifiers in effect */
	uint32_t  sym;		/* meaning of key	*/
	uint32_t  label;	/* label on key		*/
	uint32_t  button;	/* button number	*/

} gii_key_event;

/*	This is used to report change of pointer position.
**	Depending on the event type, the values are either absolute
**	or relative.
*/
typedef struct {

	COMMON_DATA;

	int32_t  x, y;		/* absolute/relative position	*/
	int32_t  z, wheel;

} gii_pmove_event;

/*	Button events are sent to report a change in pointer button
**	state.  Depending on the event type, the button is either being
**	pressed or released.
*/
typedef struct {

	COMMON_DATA;

	uint32_t  button;	/* button number. This is a number, NOT a mask */

} gii_pbutton_event;

#define GII_PBUTTON_(x)		(x)	/* Generic button access */

#define GII_PBUTTON_NONE	0	/* Dummy */

#define GII_PBUTTON_LEFT	1	/* Left or primary button */
#define GII_PBUTTON_PRIMARY	1
#define GII_PBUTTON_FIRST	1

#define GII_PBUTTON_RIGHT	2	/* Right/Secondary button */
#define GII_PBUTTON_SECONDARY	2
#define GII_PBUTTON_SECOND	2

#define GII_PBUTTON_MIDDLE	3	/* Middle or tertiary  */
#define GII_PBUTTON_TERTIARY	3
#define GII_PBUTTON_THIRD	3

/*	Valuator events report a change of up to 32 of the
**	input device valuators. Only a range of 32 valuators beginning
**	from first can be reported with one event.
*/
typedef struct {

	COMMON_DATA;

	uint32_t	first;		/* first valuator reported	*/
	uint32_t	count;		/* number reported		*/
	int32_t	        value[32];	/* absolute/relative values	*/

} gii_val_event;

typedef union {

	uint8_t			size;		/* size of this event	*/

	gii_any_event		any;		/* access COMMON_DATA	*/
	gii_cmd_event		cmd;		/* command/information	*/
	gii_expose_event	expose;		/* exposure event	*/
	gii_val_event		val;		/* valuator change	*/
	gii_key_event		key;		/* key press/release	*/
	gii_pmove_event		pmove;		/* pointer move		*/
	gii_pbutton_event	pbutton;	/* pointer buttons	*/

} gii_event;

#endif	/* #ifdef _GII_EVENTS_H */
