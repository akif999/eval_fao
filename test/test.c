#include <stdio.h>
#include <stdbool.h>
#include "../tokenize.h"

char *user_input;
Token *token;

bool consume ( char op )
{
    if ( ( token->kind != TK_RESERVED ) || ( token->str[0] != op ) )
    {
        return false;
    }
    token = token->next;
    return true;
}

int expect_number ( void )
{
    if ( token->kind != TK_NUM )
    {
        error_at ( user_input, token->str, "not a value" );
    }
    int val = token->val;
    token = token->next;
    return ( val );
}

bool at_eof ( void )
{
    bool ret;

    ret = token->kind == TK_EOF;

    return ( ret );
}

int main ( int argc, char **argv )
{
    if ( argc != 2 )
    {
        fprintf ( stderr, "argument required\n");
    }
    user_input = argv[1];

    token = tokenize( user_input );

    while ( !at_eof() )
    {
        if ( token->kind == TK_RESERVED )
        {
            if ( consume ('+') )
            {
                printf ("[+] " );
            }
            else if ( consume ('-') )
            {
                printf ("[-] " );
            }
            else
            {
                // nothing
            }
        }
        else
        {
            printf ("[%d] ", expect_number() );
        }
    }
    printf ("\n");

    return ( 0 );
}

