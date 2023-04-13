# Blinker

```
Blinker
Points: 200
Assets: Yes
Extract the flag from the video.
The flag is in queraCTF{something} format. something is a text containing lowercase letters and
_.
```

توی این سوال به ما یه ویدیوی داده شده که  لوگوی کوئرا  فقط چشمک میزنه و frame rate ویدیو ۱۰ هستش و بنظر میاد که کد مورس باشه

با کد پایین میتونیم هر فریم رو از ویدیو بگیریم و به ۰ و ۱ تبدیلش کنیم

```
import numpy as np
import pandas as pd
import cv2

cap = cv2.VideoCapture("./blinker.mp4")
while not cap.isOpened():
    cap = cv2.VideoCapture("./blinker.mp4")
    cv2.waitKey(1000)
    print("Wait for the header")

res = ""
pos_frame = cap.get(cv2.CAP_PROP_POS_FRAMES)
while True:
    flag, frame = cap.read()
    if flag:
        res += '1' if frame.sum() > 100000000 else '0'
        pos_frame = cap.get(cv2.CAP_PROP_POS_FRAMES)
    else:
        cap.set(cv2.CAP_PROP_POS_FRAMES, pos_frame-1)
        print("frame is not ready")
        cv2.waitKey(1000)
    if cv2.waitKey(10) == 27:
        break
    if cap.get(cv2.CAP_PROP_POS_FRAMES) == cap.get(cv2.CAP_PROP_FRAME_COUNT):
        break
```

بعد از این کار یه رشته از ۰ و ۱ داریم که با کد پایین به مورس تبدیلش میکنیم

```
fin = ""
for i in range(0,len(res),10):
    fin+=res[i]
fin = fin.replace("0000","/")
fin = fin.replace("11","-")
fin = fin.replace("0","")
fin = fin.replace("1",".")
print(fin)
```

خروجی رو به [cyberchef](https://gchq.github.io/CyberChef/#recipe=From_Morse_Code%28%27Space%27,%27Forward%20slash%27%29Remove_whitespace%28true,true,true,true,true,false%29&input=LS0vLS0tLy4tLi8uLi4vLi8tLi0uLy0tLS8tLi4vLi8uLi8uLi4vLi4uLS8uLy4tLi8tLi0tLy0tLi8tLS0vLS0tLy0uLi8uLS4tLi0vLS8uLi4uLy4tLy4vLi0uLi8uLS8uLi4vLS8uLi4vLi8tLi8tLy4vLS4vLS4tLi8uLy4uLy0uLy0vLi4uLi8uLi8uLi4vLS8uLy0uLi0vLS8uLi8uLi4vLS8uLi4uLy4vLi4uLi8uLi8tLi4vLS4uLy4vLS4vLi4tLi8uLS4uLy4tLy0tLi8uLS4tLi0vLi4tLy4uLi8uLy4uLy0vLS8tLS0vLS0uLy4vLS8tLy4uLi4vLi8uLi4vLS4tLi8tLS0vLi0uLy4vLS0tLy4uLS4vLS8uLi4uLy4vLS4tLi8uLi4uLy4tLy4tLi4vLi0uLi8uLy0uLy0tLi8uLy4tLi0uLS8tLS8tLS0vLi0uLy4uLi8uLy4uLS0uLS8uLi4tLy4uLy0uLi8uLy0tLS8uLi0tLi0vLi4vLi4uLy4uLS0uLS8uLi4tLy4vLi0uLy0uLS0vLi4tLS4tLy0tLi8uLS4vLi8uLS8tCg "https://gchq.github.io/CyberChef/#recipe=From_Morse_Code%28'Space','Forward%20slash'%29Remove_whitespace%28true,true,true,true,true,false%29&input=LS0vLS0tLy4tLi8uLi4vLi8tLi0uLy0tLS8tLi4vLi8uLi8uLi4vLi4uLS8uLy4tLi8tLi0tLy0tLi8tLS0vLS0tLy0uLi8uLS4tLi0vLS8uLi4uLy4tLy4vLi0uLi8uLS8uLi4vLS8uLi4vLi8tLi8tLy4vLS4vLS4tLi8uLy4uLy0uLy0vLi4uLi8uLi8uLi4vLS8uLy0uLi0vLS8uLi8uLi4vLS8uLi4uLy4vLi4uLi8uLi8tLi4vLS4uLy4vLS4vLi4tLi8uLS4uLy4tLy0tLi8uLS4tLi0vLi4tLy4uLi8uLy4uLy0vLS8tLS0vLS0uLy4vLS8tLy4uLi4vLi8uLi4vLS4tLi8tLS0vLi0uLy4vLS0tLy4uLS4vLS8uLi4uLy4vLS4tLi8uLi4uLy4tLy4tLi4vLi0uLi8uLy0uLy0tLi8uLy4tLi0uLS8tLS8tLS0vLi0uLy4uLi8uLy4uLS0uLS8uLi4tLy4uLy0uLi8uLy0tLS8uLi0tLi0vLi4vLi4uLy4uLS0uLS8uLi4tLy4vLi0uLy0uLS0vLi4tLS4tLy0tLi8uLS4vLi8uLS8tCg") میدیم

flag: `queraCTF{MORSE_VIDEO_IS_VERY_GREAT}`