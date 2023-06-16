/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    #define MAX_SCOPE 20
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    
    typedef struct Node
    {
        char name[20];
        char type[20];
        int address;
        int lineno;
        int mut;
        char element_type[20];
    } NODE;
    
    
    static void create_symbol();
    static int insert_symbol(char* name, char* type, char* element_type);
    static NODE lookup_symbol(char* name, int flag);
    static void dump_symbol(int scope);

    /* Global variables */

    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
    bool HAS_ERROR = false;

    int as_type = 0;
    int cs_idx = -1;

    int table_len[MAX_SCOPE] = {}; // each table len
    NODE table[MAX_SCOPE][50]; // symbol table
    int address = 0;  
    int type = 0;
    char now_type[10] = "none";
    char now_op[10] = "none";
    char now_id[10] = "none";
    NODE *global_node , node_saving;

    char variable_name[20] = {};
    int variable_address = 0;
    int cmp_num = 1;
    int if_num = 1;
    int num_if_exit = 1 , level_if = 0 , prev_if = 0, now_if = 0 , loop_num;

    int array_data[105][105];
    int array_address[105][105];
    int queue[105] , queue_index = 0 , loop_break_address = 0 , foreach = 0;
    char str_saving[105];
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
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : FunctionDeclStmt
;

Func_opt
    : Func_opt Func_opt
    | ID
    | INT
    | FLOAT
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
        create_symbol();
        insert_symbol($2,"func",""); } 
    '(' Func_opt Block { dump_symbol(cs_idx); }
    | PrintStmt ';'
    | Stmt { ; } ';'  // 宣告變數
    | Simpile_stmt ';'
    | if_stmt
    | while_stmt
    | array_stmt ';'
    | break_stmt ';'
    | for_stmt
    | func_stmt
    | return_stmt ';'
    | expr ';'
    | Block
;
func_stmt
    : FUNC ID { create_symbol() , insert_symbol($2,"func",""); } '('  ID ':' INT ',' ID ':' INT  ')' func_element Block { dump_symbol(cs_idx); }
    | FUNC ID { create_symbol() , insert_symbol($2,"func",""); } '(' ')' Block { dump_symbol(cs_idx); }
    | FUNC ID { create_symbol() , insert_symbol($2,"func",""); } '(' func_element ')' ARROW BOOL Block { dump_symbol(cs_idx); }
;
func_element
    : func_element func_element
    | ':'
    | ','
    | ID INT { insert_symbol($1,"i32","-1"); }
    | ID FLOAT { insert_symbol($1,"f32","-1"); }
;

break_stmt
    : BREAK '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$3);
        
        CODEGEN("\tldc \"%s\"\n",$3);
        CODEGEN("\tastore %d\n",loop_break_address);
        
    }
;

array_stmt
    : LET ID ':' '[' INT ';' INT_LIT { printf("INT_LIT %d\n",$7); } ']' '=' '[' INT_LIT { printf("INT_LIT %d\n",$12);
    
        queue[queue_index++] = $12;
        strcpy(now_id,$2); 
    }
    | array_stmt array_stmt
    | new_element
    | array_stmt_again
;
array_stmt_again
    : ']' { insert_symbol(now_id,"array","0"); 
        node_saving = lookup_symbol(now_id,1);
        int ouo = 0;
        for(int i=0;i<queue_index;i++)
        {
            array_data[node_saving.address][i] = queue[i];
            array_address[node_saving.address][i] = address;
            CODEGEN("\tldc %d\n",queue[i]);
            CODEGEN("\tistore %d\n",address);
            address++;
        }
        
        queue_index = 0;
    }
;
new_element
    : ',' INT_LIT { 
        printf("INT_LIT %d\n",$2);
        queue[queue_index++] = $2;
    }
    | ',' FLOAT_LIT { printf("FLOAT %f\n",$2); }
;

Simpile_stmt
    : ID ADD_ASSIGN expr { printf("ADD_ASSIGN\n"); 

        node_saving = lookup_symbol($<s_val>1,1);

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);
        
        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiadd\n");
        else CODEGEN("\tfadd\n");
        
       if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
       else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
    | ID SUB_ASSIGN expr { printf("SUB_ASSIGN\n"); 
        node_saving = lookup_symbol($<s_val>1,1);

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);

        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tisub\n");
        else CODEGEN("\tfsub\n");

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
    | ID MUL_ASSIGN expr { printf("MUL_ASSIGN\n"); 
        
        node_saving = lookup_symbol($<s_val>1,1);
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);

        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\timul\n");
        else CODEGEN("\tfmul\n");
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
    | ID REM_ASSIGN expr { printf("REM_ASSIGN\n"); 
        
        node_saving = lookup_symbol($<s_val>1,1);
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);
        
        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tirem\n");
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
    | ID DIV_ASSIGN expr { printf("DIV_ASSIGN\n"); 
        
        node_saving = lookup_symbol($<s_val>1,1);
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);
        
        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tidiv\n");
        else CODEGEN("\tfdiv\n");

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
    | ID '=' ID LSHIFT ID {
        node_saving = lookup_symbol($<s_val>3,1) , printf("IDENT (name=%s, address=%d)\n",$3,node_saving.address);
        node_saving = lookup_symbol($<s_val>5,1) , printf("IDENT (name=%s, address=%d)\n",$5,node_saving.address);
        
        printf("error:%d: invalid operation: LSHIFT (mismatched types i32 and f32)\n",yylineno+1);
        printf("LSHIFT\n");
        printf("ASSIGN\n");
    }
    | ID '=' expr {
        node_saving = lookup_symbol($1,1);
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,$1);
        else printf("ASSIGN\n"); 
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 || type == 1 )
        {
            CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
            type = 0;
        }
        else if( strcmp(node_saving.type,"str") ) CODEGEN("\tastore %d\n",node_saving.address);
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存

    }
    | ID '=' '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$4);

        CODEGEN("\tldc \"%s\"\n",$4);
        CODEGEN("\tastore %d\n",node_saving.address);

        printf("ASSIGN\n"); 
    }
    | ID '=' '\"' '\"' { // 空字串 
        printf("STRING LIT \"\"\n");
        printf("ASSIGN\n"); 
    }
;

if_stmt
    : IF { if_num++; if( level_if == 1 ) { prev_if = if_num;} }
    expr { CODEGEN("\tifeq L%d_if_false \n",if_num); } // if_false 判斷 if 是否成立，不成立則跳開 ( ifeq == false )
    if_continue 
    
;
if_continue
    : Block { CODEGEN("\tgoto L%d_if_exit\n", num_if_exit); } ELSE { CODEGEN("L%d_if_false:\n",if_num); } else_stmt
    | Block { 
        
        CODEGEN("\tgoto L%d_if_exit\n", num_if_exit); 
    
        if( level_if == 1 ) CODEGEN("L%d_if_false:\n",prev_if);
        else { CODEGEN("L%d_if_false:\n", if_num);
        
            if( loop_break_address != 0 ) CODEGEN("\tgoto loop_begin\n");
            CODEGEN("L%d_if_exit:\n", num_if_exit); // if_exit 離開 if block
            num_if_exit++;
            level_if--;
        }
    }
;
else_stmt
    : if_stmt
    | Block  {  CODEGEN("L%d_if_exit:\n", num_if_exit);
        num_if_exit++;
        level_if--;

       // if( loop_break_address != 0 ) CODEGEN("\tgoto loop_begin\n");
    }
;

while_stmt
    : WHILE {
        CODEGEN("while_begin:\n");
    } expr {

        CODEGEN("\tifeq while_false\n"); // expr 內的判斷式已經將 true/false 的結果放到 stack 了
       // CODEGEN
    } Block {
        CODEGEN("\tgoto while_begin\n");
        CODEGEN("while_false:\n");
    }
;

for_stmt
    : FOR ID IN ID { 
        node_saving = lookup_symbol($<s_val>4,1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
        create_symbol();
        CODEGEN("\tldc 0\n");
        insert_symbol($2,"i32","-1");

        node_saving = lookup_symbol($4,1);
        
        foreach = 1;

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
    | expr '+'  expr { printf("ADD\n"); 
        if( type == 1 ) CODEGEN("\tiadd\n");
        else CODEGEN("\tfadd\n");
    }
    | expr '-'  expr { 
        printf("SUB\n");
        if( type == 1 ) CODEGEN("\tisub\n");
        else CODEGEN("\tfsub\n"); 
    }
    | expr '>' expr { 
        if( HAS_ERROR == true ) printf("error:%d: invalid operation: GTR (mismatched types undefined and i32)\n",yylineno+1);    
        printf("GTR\n");

        if( type == 1 ){
            CODEGEN("\tisub\n");
            CODEGEN("\tifgt L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }else{
            CODEGEN("\tfcmpl\n");
            CODEGEN("\tifgt L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }

    }
    | expr '<' expr { printf("LSS\n"); 
    
        CODEGEN("\tisub\n");
        CODEGEN("\tiflt L%d_cmp_0\n", cmp_num); // 相減判斷是否 < 0 來判斷 LSS
        CODEGEN("\ticonst_0\n");
        CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
        CODEGEN("L%d_cmp_0:\n", cmp_num);
        CODEGEN("\ticonst_1\n");
        CODEGEN("L%d_cmp_1:\n", cmp_num);
    }
    | expr LOR expr { printf("LOR\n") , strcpy(node_saving.type,"bool"); 
        CODEGEN("\tior\n");
    }
    | expr LAND expr { printf("LAND\n");
        strcpy(node_saving.type,"bool");
        CODEGEN("\tiand\n"); 
    }
    | expr GEQ expr { printf("GEQ\n"); }
    | expr LEQ expr { printf("LEQ\n"); }
    | expr EQL expr { 
        
        printf("EQL\n"); 
        if( type != 2 )
        {
            CODEGEN("\tisub\n"); // 透過減法判斷是否相等
            CODEGEN("\tifeq L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }
        else // float
        {
            CODEGEN("\tfcmpl\n"); 
            CODEGEN("\tifeq L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }
    }
    | expr NEQ expr { 
        
        CODEGEN("\tisub\n");
        CODEGEN("\tifne L%d_cmp_0\n",cmp_num); // if not equal to zero
        CODEGEN("\ticonst_0\n");
        CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
        CODEGEN("L%d_cmp_0:\n", cmp_num);
        CODEGEN("\ticonst_1\n");
        CODEGEN("L%d_cmp_1:\n", cmp_num);

        cmp_num++;

        printf("NEQ\n"); 
    }
    
    | term AS factor
    | term
;
term: term '*'  factor { 
        printf("MUL\n");
        if( type == 1 ) CODEGEN("\timul\n");
        else CODEGEN("\tfmul\n");
    }
    | term '/'  factor { 
        printf("DIV\n");
        if( type == 1 ) CODEGEN("\tidiv\n");
        else CODEGEN("\tfdiv\n");
    }
    | term '%'  factor { 
        printf("REM\n"); 
        CODEGEN("\tirem\n");
    }
    | factor
;
factor:
    '(' expr ')' 
    | ID { 
        node_saving = lookup_symbol($<s_val>1,1);
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,$1) , HAS_ERROR = true;
        else printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);

        if( strcmp(node_saving.type,"i32") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else if( strcmp(node_saving.type,"f32") == 0 ) CODEGEN("\tfload %d\n",node_saving.address);
        else if( strcmp(node_saving.type,"str") == 0 ) CODEGEN("\taload %d\n",node_saving.address);
        else CODEGEN("\tiload %d\n",node_saving.address);

        if( strcmp(node_saving.type,"i32") == 0 ) type = 1 , as_type = 1;
        else as_type = 2 , type = 2;
    }
    | ValueStmt
    | '-' factor { printf("NEG\n");
        if( type == 1 ) CODEGEN("\tineg\n");
        else CODEGEN("\tfneg\n"); 
    }
    | '!' factor { 
        printf("NOT\n");
        CODEGEN("\ticonst_1\n"); // 用 1 去 xor 做出 NOT 的效果
        CODEGEN("\tixor\n"); 
    }
;
ValueStmt
    : TRUE { printf("bool TRUE\n"); 
        CODEGEN("\ticonst_1\n");
    }
    | FALSE { printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n"); 
    }
    | INT_LIT { strcpy(node_saving.type,"i32") ,  printf("INT_LIT %d\n",$1); 
        CODEGEN("\tldc %d\n",$1);
        type = 1;
        as_type = 1;
    } 
    | FLOAT_LIT { strcpy(node_saving.type,"f32" ) ,  printf("FLOAT_LIT %f\n",$1) , type = 2; 
        CODEGEN("\tldc %f\n",$1);
        as_type = 2;
    }
    | INT {
         CODEGEN("\tf2i\n");
         printf("f2i\n");
         type = 1;
    }
    | FLOAT { 
        CODEGEN("\ti2f\n");
        printf("i2f\n");
        type = 2; 
    }
;


Block
    : '{' {create_symbol();} GlobalStatementList  { dump_symbol(cs_idx); } '}'
;
PrintStmt
    : PrintStmt PrintStmt
    | PRINT '(' string_stmt ')' { printf("PRINT str\n"); }
    | PRINTLN '(' string_stmt ')' { 
        
        print_j("str",1);
        printf("PRINTLN str\n"); 
    }
    | PRINT '(' expr ')' {
        
        printf("PRINT %s\n",node_saving.type); 

        if( strcmp(node_saving.type,"i32") == 0 )  print_j("i32",0);
        else if( strcmp(node_saving.type,"f32") == 0 ) print_j("f32",0);
        else if( strcmp(node_saving.type,"bool") == 0 ) print_j("bool",0);
        else print_j("str",0);
    }
    | PRINTLN '(' expr ')' { 
        
        printf("PRINTLN %s\n",node_saving.type) ;

        if( foreach == 1 )
        {
            int array_id = node_saving.address;
            for(int i=0;i<5;i++)
            {
                CODEGEN("\tiload %d\n",array_address[0][i]);
                print_j("i32",1);
            }

            foreach = 0;
        }
        else if( strcmp(node_saving.type,"i32") == 0 )  print_j("i32",1);
        else if( strcmp(node_saving.type,"f32") == 0 ) print_j("f32",1);
        else if( strcmp(node_saving.type,"bool") == 0 ) print_j("bool",1);
        else print_j("str",1);
    }
    
    | PRINTLN '(' ID { node_saving = lookup_symbol($<s_val>3,1) , printf("IDENT (name=%s, address=%d)\n",$3,node_saving.address); } '[' INT_LIT { printf("INT_LIT %d\n",$6); } ']' ')' { 
        printf("PRINTLN array\n");
        int array_id = node_saving.address;
        
        int idx = 0;
        
        CODEGEN("\tiload %d\n",array_address[array_id][$6]);
        print_j("i32",1);
    }
    | PRINT '(' ID { node_saving = lookup_symbol($<s_val>3,1) , printf("IDENT (name=%s, address=%d)\n",$3,node_saving.address); } '[' INT_LIT { printf("INT_LIT %d\n",6); }  ']' ')' { 
        
        int array_id = node_saving.address;
        CODEGEN("\tiload %d\n",array_address[array_id][$6]);
        print_j("i32",1);
        printf("PRINT array\n"); }
;
string_stmt
    : '\"' STRING_LIT { CODEGEN("\tldc \"%s\"\n", $2);
     printf("STRING_LIT \"%s\"\n",$2); } '\"' { $$ = $2;  }
;
Stmt // 宣告變數
    : LET ID ':' Stmt_opt '=' INT_LIT {
        printf("INT_LIT %d\n",$6);
        CODEGEN("\tldc %d\n",$6);
        insert_symbol($2,"i32","-1");
    }
    | LET ID ':' Stmt_opt {
        if( type == 1 )
        {
            CODEGEN("\tldc %d\n",0);
            insert_symbol($2,"i32","-1");
        }
        if( type == 2 )
        {
            CODEGEN("\tldc %f\n",0.0);
            insert_symbol($2,"f32","-1");
        }
    }

    | LET ID ':' Stmt_opt '=' FLOAT_LIT { 

        printf("FLOAT_LIT %f\n",$6);
        CODEGEN("\tldc %f\n",$6);
        
        int index = insert_symbol($2,"f32","-1");

    }

    | LET ID ':' Stmt_opt '=' TRUE {
        printf("bool TRUE\n");
        CODEGEN("\ticonst_1\n");;
        int index = insert_symbol($2,"bool","-1");
    }
    | LET ID ':' Stmt_opt '=' FALSE{
        printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n");
        int index = insert_symbol($2,"bool","-1");
    }
    | LET ID ':' Stmt_opt STR '=' '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$8); 
        CODEGEN("\tldc \"%s\"\n",$8);
        int index = insert_symbol($2,"str","-1");
        strcpy(str_saving,$8);
    }
    | LET ID ':' Stmt_opt STR '=' '\"' '\"' { // 空字串
        printf("STRING_LIT \"\"\n"); 
        int index = insert_symbol($2,"str","-1");
    }

    // 有 mut

    | LET MUT ID ':' Stmt_opt '=' INT_LIT {
        printf("INT_LIT %d\n",$7);
        CODEGEN("\tldc %d\n",$7);
        int index = insert_symbol($3,"i32","1");
    }
    | LET MUT ID ':' Stmt_opt '=' FLOAT_LIT { 

        printf("FLOAT_LIT %f\n",$7);
        CODEGEN("\tldc %f\n",$7);
        int index = insert_symbol($3,"f32","1");
    }
    | LET MUT ID ':' Stmt_opt '=' TRUE {
        printf("bool TRUE\n");
        CODEGEN("\ticonst_1\n");
        int index = insert_symbol($3,"bool","1");
    }
    | LET MUT ID ':' Stmt_opt '=' FALSE{
        printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n");
        int index = insert_symbol($3,"bool","1");
    }
    | LET MUT ID ':' Stmt_opt STR '=' '\"' STRING_LIT '\"' { 
        printf("STRING_LIT \"%s\"\n",$9); 
        CODEGEN("\tldc \"%s\"\n",$9);
        int index = insert_symbol($3,"str","1");
    }
    | LET MUT ID ':' Stmt_opt STR '=' '\"' '\"' { // 空字串
        printf("STRING_LIT \"\"\n"); 

        CODEGEN("\tldc \"\"\n");

        int index = insert_symbol($3,"str","1");
    }
    | LET MUT ID ':' Stmt_opt {
        if( type == 1 ){
            CODEGEN("\tldc %d\n",0);
            insert_symbol($3,"i32","1");
        }
        if( type == 2 ){
            CODEGEN("\tldc %f\n",0.0);
            insert_symbol($3,"f32","1");
        }
    }
    
    | LET MUT ID '=' INT_LIT {
        printf("INT_LIT %d\n",$5);

        CODEGEN("\tldc %d\n",$5);
        insert_symbol($3,"i32","1");
    }
    | LET MUT ID '=' FLOAT_LIT {
        printf("FLOAT_LIT %f\n",$5);
        insert_symbol($3,"f32","1");
    }

    | LET ID '=' INT_LIT{
        printf("INT_LIT %d\n",$4);
        CODEGEN("\tldc %d\n",$4);
        insert_symbol($2,"i32","-1");
    }
    | LET ID '=' FLOAT_LIT{
        printf("FLOAT_LIT %f\n",$4);
        CODEGEN("\tldc %f\n",$4);
        insert_symbol($2,"f32","-1");
    }
    | LET ID '=' TRUE {
        printf("bool TRUE\n");
        CODEGEN("\ticonst_1\n");
        insert_symbol($2,"bool","-1");
    }
    | LET ID '=' FALSE {
        printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n");
        insert_symbol($2,"bool","-1");
    }
    
    | LET ID ':' Stmt_opt STR '=' LOOP { 
        
        CODEGEN("ldc \"init\"\n");
        loop_break_address = insert_symbol($2,"str","-1"); 
        CODEGEN("\tgoto loop_begin\n");
        CODEGEN("loop_begin:\n");
    
    } Block

    | LET MUT ID ':' Stmt_opt STR '=' LOOP Block {  insert_symbol($3,"str","1"); }

    | LET ID ':' Stmt_opt STR '=' '&' ID  '[' INT_LIT DOTDOT INT_LIT ']'
        {  
            node_saving = lookup_symbol($8,"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",$10);
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",$12);
            
            char u[100] = {};
            int idx = 0;
            for(int i=$10;i<$12;i++) u[idx++] = str_saving[i];

            CODEGEN("\tldc \"%s\"\n",u); 
            
            insert_symbol($2,"str","-1"); 
        }
    | LET ID ':' Stmt_opt STR '=' '&' ID  '[' DOTDOT INT_LIT ']'
        {   node_saving = lookup_symbol($8,"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",$11);

            char u[100] = {};
            int idx = 0;
            for(int i=0;i<$11;i++) u[idx++] = str_saving[i];
            CODEGEN("\tldc \"%s\"\n",u); 


            insert_symbol($2,"str","-1"); 
        }
    | LET ID ':' Stmt_opt STR '=' '&' ID  '[' INT_LIT DOTDOT ']'
        {   
            node_saving = lookup_symbol($8,"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",$10);
            printf("DOTDOT\n");

            char u[100] = {};
            int idx = 0;
            for(int i=$10;i<strlen(str_saving);i++) u[idx++] = str_saving[i];
            CODEGEN("\tldc \"%s\"\n",u); 

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
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
    CODEGEN(".method public static main([Ljava/lang/String;)V\n");
    CODEGEN(".limit stack 100 ; Define your storage size.\n");
    CODEGEN(".limit locals 100 ; Define your local space number.\n\n");

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    /* Symbol table dump */
    // Add your code
    CODEGEN("\treturn\n.end method\n");
	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }

    yylex_destroy();
    return 0;
}

static void create_symbol() {
    cs_idx++;
    printf("> Create symbol table (scope level %d)\n", cs_idx );
}

static int insert_symbol(char* name, char* type, char* element_type) {
    
    NODE tmp = lookup_symbol(name, 0);
    if(tmp.address != -1){
        printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, name, tmp.lineno);
        return -1;
    }

    strcpy(table[cs_idx][table_len[cs_idx]].name, name);
    strcpy(table[cs_idx][table_len[cs_idx]].type, type);
    table[cs_idx][table_len[cs_idx]].address = address;
    table[cs_idx][table_len[cs_idx]].lineno = yylineno + 1;
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


    if( 0==strcmp(type, "str") ) CODEGEN("\tastore %d\n", address);
    else if( 0==strcmp(type, "i32") ) CODEGEN("\tistore %d\n", address);
    else if( 0==strcmp(type, "f32") ) CODEGEN("\tfstore %d\n", address);
    else if( 0==strcmp(type, "bool") ) CODEGEN("\tistore %d\n", address);

    if( strcmp(type,"func") != 0 ) address++;

    return address - 1;
}

static NODE lookup_symbol(char* name, int flag) {
    if(flag == 0){
        for(int j=0; j<table_len[cs_idx]; ++j){
            if(0 == strcmp(table[cs_idx][j].name, name))
                return table[cs_idx][j];
        }
        NODE node;
        node.address = -1;
        return node;
    }
    else{
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

void print_j(char *type,int newline) // newline = 要不要換行
{
    if( strcmp(type,"str") == 0 )
    {
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");
    }
    if( strcmp(type,"i32") == 0 )
    {
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(I)V\n\n");
    }
    if( strcmp(type,"f32") == 0 )
    {
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(F)V\n\n");
    }
    if( strcmp(type,"bool") == 0 )
    {
        CODEGEN("\tifne L%d_cmp_0\n", cmp_num); // ifne = if not equal to 0
        CODEGEN("\tldc \"false\"\n");
        CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
        CODEGEN("L%d_cmp_0:\n", cmp_num);
        CODEGEN("\tldc \"true\"\n");
        CODEGEN("L%d_cmp_1:\n", cmp_num);
        
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");
        cmp_num++;
    }
}