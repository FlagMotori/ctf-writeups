# Simple Wasm

توی این سوال به ما سه تا فایل داده شده که یکی از اونا فایل web assembly هست و احتمالا فلگ داخل اون مخفی شده.

میتونیم از [wasm2c](https://webassembly.github.io/wabt/doc/wasm2c.1.html) برای تبدیل فایل بانری به c استفاده کنیم و داخل اون دنبال فلگ بگردیم

`$ wasm2c main.wasm -o main.c`

بعد از یکم گشتن داخل فایل main.c یه تابع جالب پیدا می کنیم که به نظر میاد داخل اون رشته ورودی رو با فلگ چک میکنه

به تابع `main.check` توی بخش sources گوگل کروم breakpoint اضافه میکنیم تا ببینیم مرحله به مرحله چه اتفاقی می افته

بعد اینکه یه ورودی دادیم و اونو submit کردیم میتونیم ببینیم که هر متغیر به چه آدرسی توی مموری اشاره میکنه و با memory inspector میتونیم مقادیر داخل مموری رو ببینیم

![2023-04-14_17-22.png](https://github.com/FlagMotori/ctf-writeups/raw/main/2023/quera-security-hackathon/web/simple-wasm/images/img1.png)

اگه آدرسی که  `$global2` به اون اشاره میکنه رو توی memory inspector قرار بدیم یکم قبل از اون میتونیم فلگ رو ببینیم

![2023-04-14_17-28.png](https://github.com/FlagMotori/ctf-writeups/raw/main/2023/quera-security-hackathon/web/simple-wasm/images/img2.png)

flag: `queraCTF{wasm_is_changing_the_world}`