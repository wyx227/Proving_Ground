#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
/* typedef unsigned __int32 uint32_t; /* => für MS-VS */

#define CRC32MASK   0x04C11DB7        /* CRC-32 Bitmaske */

int      bitstream[] = { 1,0,0,0,1,1,0,0 };
int      bitcount    = 8;
uint32_t crc32       = 0;             /* Schieberegister */

int main ()
{
    int i;
    for (i = 0; i < bitcount; i++)
    {
        if ( ((crc32 >> 31) & 1) != bitstream[i])
            crc32 = (crc32 << 1) ^ CRC32MASK;
        else
            crc32 = (crc32 << 1);
    }
    printf ("%u\n", crc32);
	getchar();
    return EXIT_SUCCESS;
}