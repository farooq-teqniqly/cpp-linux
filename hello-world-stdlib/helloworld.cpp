#include <unistd.h>

int main()
{
    char *msg = "Hello world\n";
    write(1, msg, 13);
    _exit(0);
}
