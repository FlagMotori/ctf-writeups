# dh-talk

## Solution

به ما فایل `dh.pcap` داده شده است، آن را در Wireshark باز میکنیم.  
روی یکی از پکت های tcp کلیک و سپس Follow -> TCP Stream رو انتخاب میکنیم :

```console
Are you ready for a key exchange?
Yep.
P: 22953686867719691230002707821868552601124472329079
G: 11
My chosen number: 65321321
Oh, no! You shoudn't send your chosen number.
No problem.
My public key: 22765143677454692215350940273371681210671460017738
Got the shared key?
Yes.
Send your message.
VTJGc2RHVmtYMThyZU5jSGlNbTVEQmRhdlFjcFdUYk1EUmF2TVNabUJRVEFIUzJQRWp6dndTTHJ2MXVXUFJNSQpES2xzRHFyUGZOelVZZUxLd3l0d3lBPT0K
How can I read it?
cat in.txt | base64 -d | openssl aes-256-cbc -d -a -pbkdf2 -k our_shared_key
Thanks!
```

در ادامه کافیست our_shared_key رو محاسبه کنیم
```python
P = 22953686867719691230002707821868552601124472329079
G = 11
a = 65321321
PublicKey = pow(G,b,P) = 22765143677454692215350940273371681210671460017738

our_shared_key = pow(PublicKey, a, P)
= 16477643432539305193820212134537114955092883848262
```

- [Diffie–Hellman key exchange](https://en.wikipedia.org/wiki/Diffie%E2%80%93Hellman_key_exchange)

در انتها کافیست دستورات گفته شده را بزنیم تا فلگ را بدست بیاوریم :

```bash
echo "VTJGc2RHVmtYMThyZU5jSGlNbTVEQmRhdlFjcFdUYk1EUmF2TVNabUJRVEFIUzJQRWp6dndTTHJ2MXVXUFJNSQpES2xzRHFyUGZOelVZZUxLd3l0d3lBPT0K" | base64 -d | openssl aes-256-cbc -d -a -pbkdf2 -k 16477643432539305193820212134537114955092883848262
```


---

## Flag

`queraCTF{D1FfIe_HeLlMaN_WA$_N0T_T0O_HarD}`
