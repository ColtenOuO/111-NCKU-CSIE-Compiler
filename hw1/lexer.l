/*

    filename: lexer.l

*/



/* Definition section */

%{

    #include <stdio.h>

    #include <stdlib.h>

    #include <string.h>



    #undef yywrap

    #define YY_NO_UNPUT

    #define YY_NO_INPUT

    #define print_token(token) \
         printf("%-8s \t %s\n", strcmp(token, "NEWLINE")? yytext: "", token)



    int line_num = 0;

    int comment_num = 0;

    int last_comment_line = -1;

%}



%option noyywrap

%x COMMENT

%x muti

%x QUOTA

%x ENDmuti





/* Define regular expression label */

letter [a-zA-Z_]

digit [0-9]





/* Rules section */

%%



">="         { print_token("GEQ"); }

"<="         { print_token("LEQ"); }

"=="         { print_token("EQL"); }

"!="         { print_token("NEQ"); }

"="          { print_token("ASSIGN"); }

"+="         { print_token("ADD_ASSIGN"); }

"-="         { print_token("SUB_ASSIGN"); }

"*="         { print_token("MUL_ASSIGN"); }

"/="          { print_token("QUO_ASSIGN"); }

"%="          { print_token("REM_ASSIGN"); }

"&"          { print_token("BAND"); }

"|"          { print_token("BOR"); }

"~"          { print_token("BNOT"); }

">>"          { print_token("RSHIFT"); }

"<<"          { print_token("LSHIFT"); }

"&&"          { print_token("LAND"); }

"||"          { print_token("LOR"); }

"!"          { print_token("NOT"); }

"("          { print_token("LPAREN"); }

")"          { print_token("RPAREN"); }

"["          { print_token("LBRACK"); }

"]"          { print_token("RBRACK"); }

"{"          { print_token("LBRACE"); }

"}"          { print_token("RBRACE"); }

";"          { print_token("SEMICOLON"); }

","          { print_token("COMMA"); }

":"          { print_token("COLON"); }

"->"          { print_token("ARROW"); }

"print"          { print_token("PRINT"); }

"println"          { print_token("PRINTLN"); }

"if"          { print_token("IF"); }

"else"          { print_token("ELSE"); }

"for"          { print_token("FOR"); }

"i32"          { print_token("INT"); }

"f32"          { print_token("FLOAT"); }

".."          { print_token("DOTDOT"); }

"bool"          { print_token("BOOL"); }

"true"          { print_token("TRUE"); }

"false"          { print_token("FALSE"); }

"let"          { print_token("LET"); }

"mut"          { print_token("MUT"); }

"fn"          { print_token("FUNC"); }

"return"          { print_token("RETURN"); }

"break"          { print_token("BREAK"); }

"as"          { print_token("AS"); }

"in" { print_token("IN"); }

"while" { print_token("WHILE"); }

"loop" { print_token("LOOP"); }

"*" { print_token("MUL"); }

"/" { print_token("QUO"); }

"%" { print_token("REM"); }

">" { print_token("GTR"); }

"<" { print_token("LSS"); }

"+" { print_token("ADD"); }

"-" { print_token("SUB"); }

[0-9]+ { print_token("INT_LIT"); }

[0-9]+.[0-9]+ { print_token("FLOAT_LIT"); }

\" { print_token("QUOTA"); BEGIN(QUOTA); }

<QUOTA>[^"]* { print_token("STRING_LIT"); }

<QUOTA>\" { print_token("QUOTA"); BEGIN(INITIAL); }

\n { print_token("NEWLINE"); line_num++; }

[a-zA-Z_0-9]+ { print_token("IDENT"); }



\/\/[^\r\n]* { print_token("COMMENT"); comment_num++; }





\/\* { if( line_num != last_comment_line ) comment_num++;  BEGIN(muti); printf("%s",yytext ); }

<muti>\n {  printf("%s",yytext ); comment_num++; line_num++;  }

<muti>[^*/\r\n]* { printf("%s",yytext ); }

<muti>\*\/ { print_token("MUTI_LINE_COMMENT"); BEGIN(INITIAL); last_comment_line=line_num;   }



<<EOF>> { line_num++; yyterminate(); return 0;  }

[ \t]+ {;}

. {;}





%%

/*  C Code section */

int yywrap()

{

    return 1;

}



int main(int argc, char *argv[])

{

    if (argc == 2) {

        yyin = fopen(argv[1], "r");

    } else {

        yyin = stdin;

    }

    yylex();

    printf("\nFinish scanning,\n");

    printf("total line: %d\n", line_num);

    printf("comment line: %d\n", comment_num);

    fclose(yyin);

    return 0;

}
