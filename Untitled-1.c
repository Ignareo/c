#include <stdio.h>
int main()
{
    char*p = malloc(5);
    free(p);
    strcpy(p, "abc");
    printf("%s", p);

}
    