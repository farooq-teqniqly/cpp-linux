#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }

    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(int x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: show [some number]\n");
        _exit(-1);
    }

    const char *arg = (const char *)argv[1];

    int val = atoi(arg);
    show_int(val);

    float fval = atof(arg);
    show_float(fval);

    int *pval = &val;
    show_pointer(pval);
}