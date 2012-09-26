{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program DPMIDemo;

{ Only for DJGPP }

{$X+}

{ `Byte' is `unsigned char' in C,
  `ShortCard' is `unsigned short' in C,
  `MedCard' is `unsigned long' in C,
  `Word' is `unsigned' in C,
  etc. (all these types are built-in). }

type
  TDpmiVersionRet = record
    Major     : Byte;
    Minor     : Byte;
    Flags     : ShortCard;
    CPU       : Byte;
    Master_PIC: Byte;
    Slave_PIC : Byte;
  end;

type
  TDpmiFreeMemInfo = record
    LargestAvailableFreeBlockInBytes,
    MaximumUnlockedPageAllocationInPages,
    MaximumLockedPageAllocationInPages,
    LinearAddressSpaceSizeInPages,
    TotalNumberOfUnlockedPages,
    TotalNumberOfFreePages,
    TotalNumberOfPhysicalPages,
    FreeLinearAddressSpaceInPages,
    SizeOfPagingFilePartitionInPages,
    Reserved1,
    Reserved2,
    Reserved3: MedCard;
  end;

function DpmiGetVersion (var Version: TDpmiVersionRet): Integer;
         external name '__dpmi_get_version';

function DpmiGetFreeMemoryInformation
         (var MemInfo: TDpmiFreeMemInfo): Integer;
         external name '__dpmi_get_free_memory_information';

var
  Version: TDpmiVersionRet;
  MemInfo: TDpmiFreeMemInfo;

begin
  if DpmiGetVersion (Version) = 0 then
    begin
      WriteLn ('CPU type:       ', Version.CPU, '86');
      WriteLn ('DPMI major:       ', Version.Major);
      WriteLn ('DPMI minor:       ', Version.Minor);
    end
  else
    WriteLn ('Error in DpmiGetVersion');
  if DpmiGetFreeMemoryInformation (MemInfo) = 0 then
    WriteLn ('Free DPMI memory: ',
             MemInfo.TotalNumberOfFreePages, ' pages.')
  else
    WriteLn ('Error in DpmiGetMemoryInformation');
end.
