#include <stdio.h>

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

uint8_t bcc(uint8_t *data, int len)
{
    uint8_t xor = data[0];
    for(int i=1; i<len;i++)
    {
        xor ^= data[i];
    }
    return xor;
}
void test_bcc()
{
    uint8_t buf[] = {0x10, 0x23, 0x04, 0x50, 0x67, 0x08, 0x90, 0xab, 0x0c, 0xd0, 0xef};
    uint8_t xor = bcc(buf, sizeof(buf)-1);
    printf("%d->xor[%d]\n",xor,buf[sizeof(buf)-1]);

}
int main()
{
  test_bcc();
  return 0;
}