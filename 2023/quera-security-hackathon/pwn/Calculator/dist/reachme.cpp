#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <cstdio>

using namespace std;

void setup()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void unreachable() {
    system("/bin/sh");
}

typedef unsigned long long u64;
typedef u64 (*opfn)(u64 a, u64 b);

u64 read_u64(const char* prompt) {
    puts(prompt);
    char buf[0x20];
    read(0, buf, 0x20);
    return strtoull(buf, NULL, 10);
}

u64 fac(u64 n) {
    u64 ret = n;
    while(--n) ret *= n;
    return ret;
}

void calc() {

    opfn op;

    puts("1: +");
    puts("2: -");
    puts("3: *");
    puts("4: /");
    puts("5: %");
    puts("6: nCr");
    puts("7: nPr");

    switch (read_u64("calc >> ")) {
        case 1:
            op = [](u64 a, u64 b) { return a + b; };
            break;
        case 2:
            op = [](u64 a, u64 b) { return a - b; };
            break;
        case 3:
            op = [](u64 a, u64 b) { return a * b; };
            break;
        case 4:
            op = [](u64 a, u64 b) { return a / b; };
            break;
        case 5:
            op = [](u64 a, u64 b) { return a % b; };
            break;
        case 6:
            op = [](u64 a, u64 b) { return fac(a) / (fac(a - b) * fac(b)); };
            break;
        case 7:
            op = [](u64 a, u64 b) { return fac(a) / fac(a - b); };
            break;
    }

    u64 a = read_u64("a >> ");
    u64 b = read_u64("b >> ");
    printf("result: %lld\n", op(a, b));
}

void banner() {
    puts("1: calc");
    puts("0: exit");
}

int main() {
    setup();
    banner();
    while (read_u64("opt >> ")) {
        calc();
    }
    return 0;
}
