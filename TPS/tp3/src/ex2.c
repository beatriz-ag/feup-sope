/*
*	EXEC: 1st example of typical usage!
*
* Note:	execve is the syscal!
*	execv, execvp, execvpe, execl, execlp, execle are library functions.
*
* Exercise:
* 	change this code to show that USER was changed after the exec.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// preparation for execve:
const char *cmdline[] = {"sleep 30"};
char *newenviron[] = {"USER=Linus", NULL};

int ex2a()
{
    pid_t id;
    setbuf(stdout, NULL); // to make sure printf() have no buffer so, nodelay!

    printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));

    id = fork();
    switch (id)
    {
    case -1:
        perror("fork()");
        exit(1);
    case 0: // child
        printf("\nChild: %d. USER=%s", getpid(), getenv("USER"));
        printf("\nChild: check that following exec was succeful with: \"ps x | grep sleep\"\n");
        if (execle("/bin/sleep", *cmdline, NULL, newenviron) == -1)
            perror("execve");
        printf("\nYou will not see this unless execve() fails! Know why?...\n");
        break; // if execve fails...
    default:
        printf("\nParent still: %d. USER=%s", getpid(), getenv("USER"));
    }
    return 0;
}

char *cmdline2[] = {"sleep", "30", (void *)0};
int ex2b()
{
    pid_t id;
    int status;

    setbuf(stdout, NULL); // to make sure printf() have no buffer so, nodelay!

    printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));

    id = fork();

    switch (id)
    {
    case -1:
        perror("fork()");
        exit(1);
    case 0: // child
        printf("\nChild: %d. USER=%s", getpid(), getenv("USER"));
        printf("\nChild: check that following exec was succeful with: \"ps x | grep sleep\"\n");

        if (execve("/bin/sleep", cmdline2, newenviron) == -1)
            perror("execve");
        printf("\nYou will not see this unless execve() fails! Know why?...\n");
        exit(0); // if execve fails..

    default:
        wait(&id);

        status = WEXITSTATUS(status);
        printf("In parent : Termination code: %d", status);
    }
    return 0;
}

int ex2c()
{
    pid_t id;
    setbuf(stdout, NULL); // to make sure printf() have no buffer so, nodelay!

    printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));

    id = fork();
    switch (id)
    {
    case -1:
        perror("fork()");
        exit(1);
    case 0: // child
        printf("\nChild: %d. USER=%s", getpid(), getenv("USER"));

        if (execve("./ex2aux", NULL, newenviron) == -1)
            perror("execve");

        exit(0);
    default:
        wait(&id);

        printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));
    }
    return 0;
}
int main()
{
    ex2c();
}