#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])

{
    int code = 0;

    if (argc < 2) {
        printf("Error: No code provided.\n");
        return 1;
    }

    code = atoi(argv[1]);

    switch(code)
    {
        case 353:
            printf("Ireland\n");
            break;
        
        case 44:
            printf("United Kingdom\n");
            break;

        case 33:
            printf("France\n");
            break;

        case 34:
            printf("Spain\n");
            break;
    }

    return(0);
}