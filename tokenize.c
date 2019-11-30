#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"

void error_at ( char *input, char *loc, char *fmt, ... )
{
    va_list ap;
    va_start ( ap, fmt );

    int pos = loc -input;

    fprintf ( stderr, "%s\n", input );
    fprintf ( stderr, "%*s", pos, " " );
    fprintf ( stderr, "^ " );
    vfprintf ( stderr, fmt, ap );
    fprintf ( stderr, "\n" );

    exit ( 1 );
}
Token *new_token ( TokenKind kind, Token *cur, char *str )
{
    Token *tok = calloc (1, sizeof (Token) );
    tok->kind = kind;
    tok->str = str;
    cur->next = tok;
    return tok;
}

Token *tokenize ( char *p )
{
    char *input = p;
    Token head;
    head.next = NULL;
    Token *cur = &head;

    while ( *p )
    {
        if ( isspace ( *p ) )
        {
            p++;
            continue;
        }

        if ( *p == '+' || *p == '-' )
        {
            cur = new_token ( TK_RESERVED, cur, p++ );
            continue;
        }

        if ( isdigit ( *p ) )
        {
            cur = new_token ( TK_NUM, cur, p );
            cur->val = strtol ( p, &p, 10 );
            continue;
        }

        error_at ( input, p, "tokenize failed" );
    }

    new_token ( TK_EOF, cur, p );
    return head.next;
}
