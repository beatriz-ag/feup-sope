#include <stdio.h>
#include <stdlib.h>

//Functions purpose is to show that upon an exec call, user changes
int main()
{
    printf("\nUSER: %s\n", getenv("USER"));
    return 0;
}