# Login

## Description

برنامه را در jadx باز میکنیم، در `com.example.myapplication.MainActivity2` مشاهده میکنیم که دو شرط زیر بررسی میشود :

```console
user = s2 + s3
pass = s5 + s4
```

```java
public static final void onCreate$lambda$0(EditText $user, MainActivity2 this$0, EditText $pass, View it) {
    Intrinsics.checkNotNullParameter(this$0, "this$0");
    if (Intrinsics.areEqual($user.getText().toString(), this$0.getString(R.string.s2) + this$0.getString(R.string.s3)) && Intrinsics.areEqual($pass.getText().toString(), this$0.getString(R.string.s5) + this$0.getString(R.string.s4))) {
        this$0.startActivity(new Intent(this$0, EmptyActivity.class));
    }
}
```
---

## Solution
کافیست در `Resources`در `resources.arsc`فایل `res/values/strings.xml` رو بررسی کنیم :    

```xml
<string name="s1">111t</string>
<string name="s2">ereh</string>
<string name="s3">asghjk</string>
<string name="s4">asgsshjk</string>
<string name="s5">asghuuhjk</string>
<string name="s6">FzeV9wZWFzeV9B</string>
<string name="s7">cXVlcmFDVEZ7ZW</string>
<string name="s8">TkRSMDFEX0No</string>
<string name="s9">NExMRU5nZX0</string>
```
در نتیجه :   
```console
user = erehasghjk
pass = asghuuhjkasgsshjk
```

که پس از وارد کردن یوزر و پسورد، در خروجی رشته زیر برای ما نمایش داده میشود که بعد از base64 دیکد به فلگ میرسیم  
> `cXVlcmFDVEZ7ZWFzeV9wZWFzeV9BTkRSMDFEX0NoNExMRU5nZX0`

---

## Flag
> `queraCTF{easy_peasy_ANDR01D_Ch4LLENge}`
