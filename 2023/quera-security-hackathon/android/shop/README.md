# shop

توی این سوال یه فایل apk داده شده اول برنامه روی شبیه ساز نصب می کنیم , از ما Email و Password میخواد

![img1.png](https://github.com/FlagMotori/ctf-writeups/raw/main/2023/quera-security-hackathon/android/shop/images/img1.png)

بعد از یکمی گشتن داخل سورس برنامه با استفاده از jadx-gui تابع getUserCreds رو پیدا کنیم که توش usernameوpassword وجود داره

`com.insecureshop.util.Util`

```
private final HashMap<String, String> getUserCreds() {
    HashMap userCreds = new HashMap();
    userCreds.put("shopuser", "!ns3csh0p");
    return userCreds;
}
```

بعد از وارد شدن به برنامه میتونیم دو تا  رشته عجیب `pRlVJX0J1VFQwTiR9` و `cXVlcmFDVEZ7YkVBdXR` رو ببینیم و اگه اونا رو به هم وصل کنیم و با ‌Base64 دیکد کنیم به فلگ میرسیم

flag: `queraCTF{bEAutiFUI_BuTT0N$}`