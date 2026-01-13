#include <stdio.h>
#include <stdlib.h>


int main(){
    int i = 1;
    for(;;)
    {
	    if(i <= 10)
	    {
		    printf("  %d", i++);
		    continue;
	    }
	    else
    	{
		    break;
	    }
    return 0

    }
}