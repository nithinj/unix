#include<stdio.h>
#include<stdlib.h>

enum operator {PLUS, MINUS, MULT, DIV};

void
add(int x, int y)
{
    printf("sum=%d\n", x + y);
}

void
sub(int x, int y)
{
    printf("sub=%d\n", x - y);
}

void
mult(int x, int y)
{
    printf("prod=%ld\n", (long)x * y);
}

void
divn(int x, int y)
{
    if (y) {
        printf("div=%f\n", (float)x / y);
    }
}

void (*func[])(int, int) = {&add, &sub, &mult, &divn};

void
dispatch(int x, int y, enum operator op)
{
    func[op](x, y);
}

int main()
{
    int a, b, op;

    scanf("%d\n%d\n%d", &a, &b, &op);
    dispatch(a, b, op);
    return 0;
}