
/**
 Замечание1 - вероятность обнаружения коллизии 16 разрядным алгоритмом = 1 - (1 / 2 ^ 16) * 100% ~ 99.99847%
 Замечание2 - байт - архитектурно зависимая единица, в контексте передачи данных следует использовать термин "октет"
*/
#include <stdio.h>

int CRC16(unsigned char* buf, int len, unsigned char crc_1, unsigned char crc_2) {
	unsigned char crc_orig_1 = 0;
	unsigned char crc_orig_2 = 0;

	unsigned char carry;
	int i;

    while (len--) {
        crc_orig_2 ^= *buf++;
        for (i = 0; i < 8; ++i)  {
        	carry = crc_orig_1 & 1 ? 0x80 : 0;
        	if (crc_orig_2 & 1) {
        		crc_orig_2 = (crc_orig_2 >> 1 | carry) ^ 0x01;
        		crc_orig_1 = (crc_orig_1 >> 1 ) ^ 0xa0;
        	} else {
        		crc_orig_2 = (crc_orig_2 >> 1 | carry);
        		crc_orig_1 = (crc_orig_1 >> 1 );
        	}
        }
    }

	return (crc_orig_1 == crc_1 && crc_orig_2 == crc_2) ? 1 : 0;
}


int main(int argc, char const *argv[]) {
	unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
	printf("original: %d\n", CRC16(data,6,0xC6,0xBA));
	data[3] = 0xff;
	printf("brocken: %d\n", CRC16(data,6,0xC6,0xBA));

	return 0;
}