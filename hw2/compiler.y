/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h"  //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    typedef struct Node
    {
        char name[50];
        char type[50];
        int address;
        int lineno;
        int mut;
        char element_type[50];
    } NODE;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static int insert_symbol(char* name, char* type, char* element_type);
    static NODE lookup_symbol(char* name, int flag);
    static void dump_symbol(int scope);

    /* Global variables */
    bool HAS_ERROR = false;

    int cs_idx = -1;

    int table_len[50] = {}; 
    NODE table[50][50];
    int address = 0;  
    int type = 0;
    char now_type[10] = "none";
    char now_op[10] = "none";
    char now_id[10] = "none";
    NODE *global_node , node_saving;

    char variable_name[20] = {};
    int variable_address = 0;
    int block_create = 0;
    bool func_first = 1;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ID ARROW AS IN DOTDOT RSHIFT LSHIFT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> ID '(' ')'

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type
%type <s_val> unary_op
%type <s_val> FunctionDeclStmt Block
%type <s_val> string_stmt math_stmt Stmt_opt

%left LOR
%left LAND
%left '>' '<' EQL NEQ LEQ GEQ
%left '+' '-'
%left '*' '/' '%'
%left AS

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : GlobalStatementList
    | GlobalStatementList GlobalStatementList
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
    | GlobalStatementList GlobalStatementList 
    | NEWLINE
;

GlobalStatement
    : FunctionDeclStmt
    | FunctionDeclStmt FunctionDeclStmt
    | Block
    | NEWLINE
;

Func_opt
    : Func_opt Func_opt
    | ID ':' INT { insert_symbol($1,"i32","-1"); }
    | ID ':' FLOAT { insert_symbol($1,"f32","-1"); }
    | BOOL
    | ARROW
    | ':'
    | ','
    | ')'
;
return_stmt
    : RETURN INT
    | RETURN FLOAT
    | RETURN TRUE
    | RETURN FALSE
;

FunctionDeclStmt
    : FUNC ID {
        if( func_first == 1 )
        {
            create_symbol();
            insert_symbol($2,"func","");
            func_first = 0;
        }
        else
        {
            insert_symbol($2,"func","");
            create_symbol();
            block_create = 1;
        } 
    } 
    '(' Func_opt Block { dump_symbol(cs_idx); }
    | PrintStmt ';'
    | Stmt { ; } ';'  // 宣告變數
    | Simpile_stmt ';'
    | if_stmt
    | while_stmt
    | array_stmt ';'
    | break_stmt ';'
    | for_stmt
    | FunctionDeclStmt FunctionDeclStmt
    | return_stmt ';'
    | expr ';'
    | expr
;
func_element
    : func_element func_element
    | ':'
    | ','
    | ID ':' INT { insert_symbol($1,"i32","-1"); }
    | ID ':' FLOAT { insert_symbol($1,"f32","-1"); }
;

break_stmt
    : BREAK '\"' STRING_LIT '\"' { printf("STRING_LIT \"%s\"\n",$3); }
;

array_stmt
    : LET ID ':' '[' INT ';' INT_LIT { printf("INT_LIT %d\n",$7); } ']' '=' '[' INT_LIT { printf("INT_LIT %d\n",$12) , strcpy(now_id,$2); }
    | array_stmt array_stmt
    | new_element
    | array_stmt_again
;
array_stmt_again
    : ']' { insert_symbol(now_id,"array","0"); }
;
new_element
    : ',' INT_LIT { printf("INT_LIT %d\n",$2); }
    | ',' FLOAT_LIT { printf("FLOAT %f\n",$2); }
;

Simpile_stmt
    : ID ADD_ASSIGN expr { printf("ADD_ASSIGN\n"); }
    | ID SUB_ASSIGN expr { printf("SUB_ASSIGN\n"); }
    | ID MUL_ASSIGN expr { printf("MUL_ASSIGN\n"); }
    | ID REM_ASSIGN expr { printf("REM_ASSIGN\n"); }
    | ID DIV_ASSIGN expr { printf("DIV_ASSIGN\n"); }
    | ID '=' ID LSHIFT ID {
        node_saving = lookup_symbol($<s_val>3,1) , printf("IDENT (name=%s, address=%d)\n",$3,node_saving.address);
        node_saving = lookup_symbol($<s_val>5,1) , printf("IDENT (name=%s, address=%d)\n",$5,node_saving.address);
        
        printf("error:%d: invalid operation: LSHIFT (mismatched types i32 and f32)\n",yylineno+1);
        printf("LSHIFT\n");
        printf("ASSIGN\n");
    }
    | ID '=' expr {
        node_saving = lookup_symbol($1,"1");
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,$1);
        else printf("ASSIGN\n"); 
    }
    | ID '=' '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$4);
        printf("ASSIGN\n"); 
    }
    | ID '=' '\"' '\"' { // 空字串 
        printf("STRING LIT \"\"\n");
        printf("ASSIGN\n"); 
    }
;

if_stmt
    : IF expr
    | ELSE
;
while_stmt
    : WHILE expr
;
for_stmt
    : FOR ID IN ID { 
        node_saving = lookup_symbol($<s_val>4,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
        create_symbol();
        insert_symbol($2,"i32","-1");
    } for_block
;
for_block
    : '{' GlobalStatementList  { dump_symbol(cs_idx); } '}'
    | GlobalStatementList for_block
;

math_stmt 
    : math_stmt math_stmt
    | ID { node_saving = lookup_symbol($<s_val>1,1) , printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address); }
    | math_stmt '+' ID {  node_saving = lookup_symbol($<s_val>3,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address) , printf("ADD\n");  }
    | math_stmt '-' ID { node_saving = lookup_symbol($<s_val>3,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address)  , printf("SUB\n"); }
    | math_stmt '*' ID { node_saving = lookup_symbol($<s_val>3,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address)  , printf("MUL\n"); } 
    | math_stmt '/' ID { node_saving = lookup_symbol($<s_val>3,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address)  , printf("DIV\n"); }
    | math_stmt '%' ID { node_saving = lookup_symbol($<s_val>3,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address)  , printf("REM\n"); }
;

expr: term
    | expr '+'  expr { printf("ADD\n"); }
    | expr '-'  expr { printf("SUB\n"); }
    | expr '>' expr { 
        if( HAS_ERROR == true ) printf("error:%d: invalid operation: GTR (mismatched types undefined and i32)\n",yylineno+1);    
        printf("GTR\n"); 
    }
    | term AS factor
    | expr '<' expr { printf("LSS\n"); }
    | expr LOR expr { printf("LOR\n") , strcpy(node_saving.type,"bool"); }
    | expr LAND expr { printf("LAND\n") , strcpy(node_saving.type,"bool"); }
    | expr GEQ expr { printf("GEQ\n"); }
    | expr LEQ expr { printf("LEQ\n"); }
    | expr EQL expr { printf("EQL\n"); }
    | expr NEQ expr { printf("NEQ\n"); }
    | term
;
term: term '*'  factor { printf("MUL\n"); }
    | term '/'  factor { printf("DIV\n"); }
    | term '%'  factor { printf("REM\n"); }
    | factor
;
factor:
    '(' expr ')' 
    | ID { 
        node_saving = lookup_symbol($<s_val>1,1);
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,$1) , HAS_ERROR = true;
        else printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
    }
    | '-' factor { printf("NEG\n"); }
    | '!' factor { printf("NOT\n"); }
    | ValueStmt
;
ValueStmt
    : TRUE { printf("bool TRUE\n"); }
    | FALSE { printf("bool FALSE\n"); }
    | INT_LIT { strcpy(node_saving.type,"i32") ,  printf("INT_LIT %d\n",$1); } 
    | FLOAT_LIT { strcpy(node_saving.type,"f32" ) ,  printf("FLOAT_LIT %f\n",$1); }
    | INT { printf("f2i\n"); }
    | FLOAT { printf("i2f\n"); }
;


Block
    : '{' { 
        if( block_create == 0 ) create_symbol();
        else block_create = 0;
    }  
        GlobalStatementList  { dump_symbol(cs_idx); } '}'
    | GlobalStatementList Block
;
PrintStmt
    : PrintStmt PrintStmt
    | PRINT '(' string_stmt ')' { printf("PRINT str\n"); }
    | PRINTLN '(' string_stmt ')' { printf("PRINTLN str\n"); }
    | PRINT '(' expr ')' {
        
        printf("PRINT %s\n",node_saving.type); }
    | PRINTLN '(' expr ')' { 
        
        printf("PRINTLN %s\n",node_saving.type) ; }
    
    | PRINTLN '(' ID { node_saving = lookup_symbol($<s_val>3,1) , printf("IDENT (name=%s, address=%d)\n",$3,node_saving.address); } '[' INT_LIT { printf("INT_LIT %d\n",$6); } ']' ')' { printf("PRINTLN array\n"); }
    | PRINT '(' ID { node_saving = lookup_symbol($<s_val>3,1) , printf("IDENT (name=%s, address=%d)\n",$3,node_saving.address); } '[' INT_LIT { printf("INT_LIT %d\n",6); }  ']' ')' { printf("PRINT array\n"); }
;
string_stmt
    : '\"' STRING_LIT { printf("STRING_LIT \"%s\"\n",$2); } '\"' { $$ = $2;  }
;
Stmt // 宣告變數
    : LET ID ':' Stmt_opt '=' INT_LIT {
        printf("INT_LIT %d\n",$6);
        insert_symbol($2,"i32","-1");
    }
    | LET ID ':' Stmt_opt {
        if( type == 1 ) insert_symbol($2,"i32","-1");
        if( type == 2 ) insert_symbol($2,"f32","-1");
    }

    | LET ID ':' Stmt_opt '=' FLOAT_LIT { 

        printf("FLOAT_LIT %f\n",$6);
        int index = insert_symbol($2,"f32","-1");
    }

    | LET ID ':' Stmt_opt '=' TRUE {
        printf("bool TRUE\n");
        int index = insert_symbol($2,"bool","-1");
    }
    | LET ID ':' Stmt_opt '=' FALSE{
        printf("bool FALSE\n");
        int index = insert_symbol($2,"bool","-1");
    }
    | LET ID ':' Stmt_opt STR '=' '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$8); 
        int index = insert_symbol($2,"str","-1");
    }
    | LET ID ':' Stmt_opt STR '=' '\"' '\"' { // 空字串
        printf("STRING_LIT \"\"\n"); 
        int index = insert_symbol($2,"str","-1");
    }

    // 有 mut

    | LET MUT ID ':' Stmt_opt '=' INT_LIT {
        printf("INT_LIT %d\n",$7);
        int index = insert_symbol($3,"i32","1");
    }
    | LET MUT ID ':' Stmt_opt '=' FLOAT_LIT { 

        printf("FLOAT_LIT %f\n",$7);
        int index = insert_symbol($3,"f32","1");
    }
    | LET MUT ID ':' Stmt_opt '=' TRUE {
        printf("bool TRUE\n");
        int index = insert_symbol($3,"bool","1");
    }
    | LET MUT ID ':' Stmt_opt '=' FALSE{
        printf("bool FALSE\n");
        int index = insert_symbol($3,"bool","1");
    }
    | LET MUT ID ':' Stmt_opt STR '=' '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$9); 
        int index = insert_symbol($3,"str","1");
    }
    | LET MUT ID ':' Stmt_opt STR '=' '\"' '\"' { // 空字串
        printf("STRING_LIT \"\"\n"); 
        int index = insert_symbol($3,"str","1");
    }
    | LET MUT ID ':' Stmt_opt {
        if( type == 1 ) insert_symbol($3,"i32","1");
        if( type == 2 ) insert_symbol($3,"f32","1");
    }
    
    | LET MUT ID '=' INT_LIT {
        printf("INT_LIT %d\n",$5);
        insert_symbol($3,"i32","1");
    }
    | LET MUT ID '=' FLOAT_LIT {
        printf("FLOAT_LIT %f\n",$5);
        insert_symbol($3,"f32","1");
    }

    | LET ID '=' INT_LIT{
        printf("INT_LIT %d\n",$4);
        insert_symbol($2,"i32","-1");
    }
    | LET ID '=' FLOAT_LIT{
        printf("FLOAT_LIT %f\n",$4);
        insert_symbol($2,"f32","-1");
    }
    | LET ID '=' TRUE {
        printf("bool TRUE\n");
        insert_symbol($2,"bool","-1");
    }
    | LET ID '=' FALSE {
        printf("bool FALSE\n");
        insert_symbol($2,"bool","-1");
    }
    
    | LET ID ':' Stmt_opt STR '=' LOOP Block {  insert_symbol($2,"str","-1"); }
    | LET MUT ID ':' Stmt_opt STR '=' LOOP Block {  insert_symbol($3,"str","1"); }

    | LET ID ':' Stmt_opt STR '=' '&' ID  '[' INT_LIT DOTDOT INT_LIT ']'
        {  
            node_saving = lookup_symbol($8,"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",$10);
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",$12);
            insert_symbol($2,"str","-1"); 
        }
    | LET ID ':' Stmt_opt STR '=' '&' ID  '[' DOTDOT INT_LIT ']'
        {   node_saving = lookup_symbol($8,"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",$11);
            insert_symbol($2,"str","-1"); 
        }
    | LET ID ':' Stmt_opt STR '=' '&' ID  '[' INT_LIT DOTDOT ']'
        {   
            node_saving = lookup_symbol($8,"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",$10);
            printf("DOTDOT\n");
            insert_symbol($2,"str","-1"); 
        }
;
Stmt_opt
    : INT { type = 1; }
    | FLOAT { type = 2; }
    | BOOL
    | '&'
    | '*'
;


%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void dump_symbol(int scope) {
    // printf("> Dump symbol table (scope level: %d)\n", scope) , f = 1;
    printf("\n> Dump symbol table (scope level: %d)\n", scope);


    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Mut" , "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<table_len[scope]; ++i){
        
        int mut = 0;

        if( strcmp(table[scope][i].type,"func") == 0 ) mut = -1;

        if( mut == -1 )
        {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
            i, table[scope][i].name, mut, table[scope][i].type, table[scope][i].address, table[scope][i].lineno, "(V)V");
        }     
        else 
        {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
            i, table[scope][i].name, table[scope][i].mut, table[scope][i].type, table[scope][i].address, table[scope][i].lineno, "-");
        } 
    }
    table_len[cs_idx] = 0;
    cs_idx--;
}

static void create_symbol() {
    cs_idx++;
    printf("> Create symbol table (scope level %d)\n", cs_idx );
}

static int insert_symbol(char* name, char* type, char* element_type) {
    
    NODE tmp = lookup_symbol(name, 0);
    table[cs_idx][table_len[cs_idx]].address = address;
    table[cs_idx][table_len[cs_idx]].lineno = yylineno + 1;
    strcpy(table[cs_idx][table_len[cs_idx]].name, name);
    strcpy(table[cs_idx][table_len[cs_idx]].type, type);
    if( strcmp(element_type,"1") == 0 ) table[cs_idx][table_len[cs_idx]].mut = 1;  
    strcpy(table[cs_idx][table_len[cs_idx]].element_type, element_type);
    table_len[cs_idx]++;

    
    if( strcmp(type,"func") == 0 )
    {
        printf("func: %s\n",name); 
        printf("> Insert `%s` (addr: %d) to scope level %d\n", name, -1, cs_idx); 
        table[cs_idx][table_len[cs_idx-1]].address = -1;
      //  if( check_newline == 1 ) printf("\n");
        return -1;
    }
    else printf("> Insert `%s` (addr: %d) to scope level %d\n", name, address, cs_idx);

    if( strcmp(type,"func") != 0 ) address++;

    return address - 1;
}

static NODE lookup_symbol(char* name, int flag) {

    for(int i=cs_idx; i>=0; --i){
        for(int j=0; j<table_len[i]; ++j){
            if(0 == strcmp(table[i][j].name, name))
                return table[i][j];
        }
    }
    NODE node;
    node.address = 404; // 404 not found
    return node;
}
