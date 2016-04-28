#include <stdio.h>
#include <string.h>

void select_sort( char* x, int n );

void main( )
{	
	char sBuf[] = "zwieofuiopfjdlfjkdfhfasfkadfktkdgj";	
	printf( "%s\n\n", sBuf );	
	select_sort( sBuf, strlen(sBuf) );	
	printf( "%s\n", sBuf );	
}

void select_sort( char* x, int n )
{	
    int i, j, t, min;	
    for ( i = 0; i < n; i++ )		
    {		
        min = i;		
        for ( j = n-1; j > i; j-- )			
        {			
            if ( x[j] < x[min] )				
            {				
               min = j;				
            }			
        }		
        if ( min != i )			
        {			
            t = x[min];			
            x[min] = x[i];			
            x[i] = t;			
        }		
    }	
}
