#include <iostream>
#include <ELFIO.h>

void main()
{
    // Create a ELFI reader
    IELFI* pReader;
    g_pELFIOBuilder->CreateELFI( &pReader );

    // Initialize it
    char* filename = "ELFDump.o";
    pReader->Load( filename );
    
    // Get encoding of the file
    unsigned char encoding = pReader->GetEncoding();
    if ( ELFDATA2LSB == encoding ) {
        std::cout << "Little endian encoding" << std::endl;
    }
    else {
        std::cout << "Big endian encoding" << std::endl;
    }
    std::cout << std::endl;

    // List all sections of the file
    int i;
    int nSecNo = pReader->GetSectionsNum();
    for ( i = 0; i < nSecNo; ++i ) {    // For all sections
        const IELFISection* pSec = pReader->GetSection( i );
        std::cout << "Sec. name: " << pSec->GetName() << std::endl
                  << "Sec. size: " << pSec->GetSize() << std::endl;
        pSec->Release();
    }
    std::cout << std::endl;
    
    // Get symbol section
    const IELFISection* pSec = pReader->GetSection( ".symtab" );

    // Create symbol table reader
    IELFISymbolTable* pSymTbl = 0;
    pReader->CreateSectionReader( IELFI::ELFI_SYMBOL,
                                  pSec,
                                  (void**)&pSymTbl );

    // Print all symbol names
    int nSymNo = pSymTbl->GetSymbolNum();
    if ( 0 < nSymNo ) {
        std::string   name;
        Elf32_Addr    value;
        Elf32_Word    size;
        unsigned char bind;
        unsigned char type;
        Elf32_Half    section;

        for ( i = 0; i < nSymNo; ++i ) {
            pSymTbl->GetSymbol( i, name, value, size,
                                bind, type, section );
            std::cout << "[" << i << "] " << name << std::endl;
        }
    }
    std::cout << std::endl;

    pSymTbl->Release();
    pSec->Release();
    
    // Free resources
    pReader->Release();
}
