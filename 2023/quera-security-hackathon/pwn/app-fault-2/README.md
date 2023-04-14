# app-fault-2

تنها تفاوت دو تابع در count_vowels_and_consonants حرف 'I' شمارش نمیشود.    
کافیست ورودی `I` به برنامه بدهیم.


```console
Enter a string: I
0 1 2 1
Congrats! You found a bug.
Here is the flag: queraCTF{...}
```

---

check value store in pointer :  
+ right: `*ptr == 'I'`  
+ wrong: `ptr == 'I'`   


