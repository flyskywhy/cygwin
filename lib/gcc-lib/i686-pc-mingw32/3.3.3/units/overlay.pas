{ Dummy BP compatible overlay unit for GPC

  Copyright (C) 1998-2004 Free Software Foundation, Inc.

  Author: Frank Heckenbach <frank@pascal.gnu.de>

  This file is part of GNU Pascal.

  GNU Pascal is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 2, or (at your
  option) any later version.

  GNU Pascal is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with GNU Pascal; see the file COPYING. If not, write to the
  Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
  02111-1307, USA.

  As a special exception, if you link this file with files compiled
  with a GNU compiler to produce an executable, this does not cause
  the resulting executable to be covered by the GNU General Public
  License. This exception does not however invalidate any other
  reasons why the executable file might be covered by the GNU
  General Public License. }

{$gnu-pascal,I-}
{$if __GPC_RELEASE__ < 20030412}
{$error This unit requires GPC release 20030412 or newer.}
{$endif}

unit Overlay;

interface

const
  OvrOK = 0;
  OvrError = -1;
  OvrNotFound = -2;
  OvrNoMemory = -3;
  OvrIOError = -4;
  OvrNoEMSDriver = -5;
  OvrNoEMSMemory = -6;

const
  OvrEmsPages: Word = 0;
  OvrTrapCount: Word = 0;
  OvrLoadCount: Word = 0;
  OvrFileMode: Byte = 0;

type
  OvrReadFunc = function (OvrSeg: Word): Integer;

var
  OvrReadBuf: OvrReadFunc;
  OvrResult: Integer = 0;

procedure OvrInit (aFileName: String); attribute (name = '_p_OvrInit');
procedure OvrInitEMS;                  attribute (name = '_p_OvrInitEMS');
procedure OvrSetBuf (Size: LongInt);   attribute (name = '_p_OvrSetBuf');
function  OvrGetBuf: LongInt;          attribute (name = '_p_OvrGetBuf');
procedure OvrSetRetry (Size: LongInt); attribute (name = '_p_OvrSetRetry');
function  OvrGetRetry: LongInt;        attribute (name = '_p_OvrGetRetry');
procedure OvrClearBuf;                 attribute (name = '_p_OvrClearBuf');

implementation

procedure OvrInit (aFileName: String);
var Dummy: Integer;
begin
  Dummy := Length (aFileName);
  OvrResult := OvrOK
end;

procedure OvrInitEMS;
begin
  OvrResult := OvrNoEMSDriver
end;

procedure OvrSetBuf (Size: LongInt);
var Dummy: Integer;
begin
  Dummy := Size
end;

function OvrGetBuf: LongInt;
begin
  OvrGetBuf := 0
end;

procedure OvrSetRetry (Size: LongInt);
var Dummy: Integer;
begin
  Dummy := Size
end;

function OvrGetRetry: LongInt;
begin
  OvrGetRetry := 0
end;

procedure OvrClearBuf;
begin
end;

end.
