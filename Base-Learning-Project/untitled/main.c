#include <stdio.h>

int main() {
    char x='2',y='2',z;
    printf("%c\n", x);
    z=(y<<1)&(x<<1);
    printf("%d\n",z);
}
