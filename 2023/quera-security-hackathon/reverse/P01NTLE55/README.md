# P01NTLE55

## Description

برنامه ورودی کاربر را بوسیله کد زیر انکد کرده و نمایش میدهد 


```c
buf = (uint8_t *)malloc(0xa00000);
output = (char *)malloc(0x2800000);
while( true ) {
    lengh = read(0, buf, 0xa00000);
    if (lengh == 0) break;
    if (lengh < 0) {
        uVar8 = 0xffffffff;
        fwrite("read error\n", 1, 0xb, _stderr);
        goto code_r0x000011e9;
    }
    tmp_output = output;
    tmp_buf = buf;
    do {
        uVar1 = *tmp_buf;
        tmp_buf = tmp_buf + 1;
        cVar2 = "\t\n\r "[uVar1 >> 6];
        *tmp_output = "\t\n\r "[uVar1 & 3];
        tmp_output[3] = cVar2;
        cVar2 = "\t\n\r "[(int32_t)(uint32_t)uVar1 >> 2 & 3];
        tmp_output[2] = "\t\n\r "[(int32_t)(uint32_t)uVar1 >> 4 & 3];
        tmp_output[1] = cVar2;
        tmp_output = tmp_output + 4;
    } while (buf + lengh != tmp_buf);
    lengh = write(1, output, (int64_t)((int32_t)lengh << 2));
    if (lengh < 0) {
        fwrite("write error\n", 1, 0xc, _stderr);
    }
}
```

---

## Solution

برای دیکد کردن رشته اند شده در فایل `pointless_thing` کافیست تکه کد بالا در main یا تابع sym.ws_encode در زیر را ریورس کنیم


```c
int64_t ws_encode(uint64_t arg1, int64_t arg2, int64_t arg3)
{
    uint8_t *puVar1;
    uint8_t *puVar2;
    
    if (0 < arg3) {
        puVar1 = (uint8_t *)arg1;
        do {
            puVar2 = puVar1 + 1;
            *(char *)arg2 = "\t\n\r "[*puVar1 & 3];
            *(char *)(arg2 + 1) = "\t\n\r "[(int32_t)(uint32_t)*puVar1 >> 2 & 3];
            *(char *)(arg2 + 2) = "\t\n\r "[(int32_t)(uint32_t)*puVar1 >> 4 & 3];
            *(char *)(arg2 + 3) = "\t\n\r "[*puVar1 >> 6];
            arg2 = (int64_t)(arg2 + 4);
            puVar1 = puVar2;
        } while ((uint8_t *)(arg1 + arg3) != puVar2);
        return (int64_t)((int32_t)arg3 << 2);
    }
    return 0;
}
```

python code :
```python
with open("pointless_thing", 'rb') as f :
    c = f.read()

for i in range(0,len(c),4):
    a0 = b"\t\n\r ".index(c[i+0])
    a1 = b"\t\n\r ".index(c[i+1])<<2
    a2 = b"\t\n\r ".index(c[i+2])<<4
    a3 = b"\t\n\r ".index(c[i+3])<<6
    res = a0+a1+a2+a3
    print(f"{chr(res)}", end='')
```

## Flag
> `queraCTF{WHITESPACER_IS_TOO_POINTLESS_@#%Werbisfo}`
