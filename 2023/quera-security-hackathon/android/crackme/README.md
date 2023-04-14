# CrackMe

## Description

برنامه از ما دو ورودی username و password میگیرد، سپس دو شرط زیر را چک میکند :
```console
Base64(username) = "R3JleWhhdEluWW91ckFyZWE="
Md5(password) = "d23b3bc1dc24919d2439219ad6072d33"
```

```java
void Login() {
        this.et_username = (EditText) findViewById(R.id.et_username);
        this.et_password = (EditText) findViewById(R.id.et_password);
        Button button = (Button) findViewById(R.id.btn_login);
        this.btn_login = button;
        button.setOnClickListener(new View.OnClickListener() { // from class: com.example.logmein.Login.1
            @Override // android.view.View.OnClickListener
            public void onClick(View view) {
                String encodeToString = Base64.getEncoder().encodeToString(Login.this.et_username.getText().toString().getBytes());
                String md5 = Login.getMd5(Login.this.et_password.getText().toString());
                if (encodeToString.equals("R3JleWhhdEluWW91ckFyZWE=") && md5.equals("d23b3bc1dc24919d2439219ad6072d33")) {
                    Toast.makeText(Login.this, "Username and Password is correct", 0).show();
                    Login.this.startActivity(new Intent(Login.this, User.class));
                    return;
                }
                Toast.makeText(Login.this, "Username or Password is incorrect", 0).show();
            }
        });
    }
```

---

## Solution
for base64 decode we can use [CyberChef](https://gchq.github.io/CyberChef)
- username: `GreyhatInYourArea`

for crack md5 we can use [CrackStation](https://crackstation.net)
- password: `monkeyfish`

---

## Flag
> `queraCTF{GreyhatInYourArea_monkeyfish}`
