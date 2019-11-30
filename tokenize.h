#ifndef TOKENIZE_H
#define TOKENIZE_H

typedef enum
{
    TK_RESERVED,
    TK_NUM,
    TK_EOF
} TokenKind;

typedef struct _Token Token;

struct _Token {
    TokenKind  kind;
    Token     *next;
    int         val;
    char       *str;
};

Token *tokenize ( char *p );
void error_at ( char *input, char *loc, char *fmt, ... );

#endif
