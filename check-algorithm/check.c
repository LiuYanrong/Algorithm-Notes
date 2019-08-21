#include <stdio.h>

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

/* BCC校验(异或校验函数),返回校验值 */
uint8_t bcc(uint8_t *data, int len)
{
    uint8_t xor = data[0];
    for(int i=1; i<len;i++)
    {
        xor ^= data[i];
    }
    return xor;
}

/* LRC校验(纵向冗余校验) */
uint8_t lrc(uint8_t *data, int len)
{
    uint32_t sum = data[0];
    uint32_t mod=0;
    for(int i=1; i<len; ++i)
    {
      sum += data[i];
    }
    mod = sum % 0x100;

    return (0x100 - mod);
}

/* LRC校验(纵向冗余校验) 模取反加1*/
uint8_t lrc2(uint8_t *data, int len)
{
    uint32_t sum = data[0];
    uint32_t mod=0;
    for(int i=1; i<len; ++i)
    {
      sum += data[i];
    }
    mod = sum % 0x100;
    
    return (~mod + 1);
}

void test_bcc()
{
    uint8_t buf[] = {0x10, 0x23, 0x04, 0x50, 0x67, 0x08, 0x90, 0xab, 0x0c, 0xd0, 0xef};
    uint8_t xor = bcc(buf, sizeof(buf)-1);
    printf("%d->xor[%d]\n",xor,buf[sizeof(buf)-1]);
}

void test_lrc()
{
    uint8_t buf[] = {0x10, 0x23, 0x04, 0x50, 0x67, 0x08, 0x90, 0xab, 0x0c, 0xd0, 0xef};
    uint8_t xor = lrc(buf, sizeof(buf));
    printf("%d->xor[%d]\n",xor,4);
    xor = lrc2(buf, sizeof(buf));
    printf("%d->xor[%d]\n",xor,0);
}

int main()
{
  //test_bcc();
  test_lrc();
  return 0;
}