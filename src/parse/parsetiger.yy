                                                                // -*- C++ -*-
%require "3.0"
%language "C++"
// Set the namespace name to `parse', instead of `yy'.
%define api.prefix {parse}
%define api.value.type variant
%define api.token.constructor

// We use a GLR parser because it is able to handle Shift-Reduce and
// Reduce-Reduce conflicts by forking and testing each way at runtime. GLR
// permits, by allowing few conflicts, more readable and maintainable grammars.
%glr-parser
%skeleton "glr2.cc"

// In TC, we expect the GLR to resolve one Shift-Reduce and zero Reduce-Reduce
// conflict at runtime. Use %expect and %expect-rr to tell Bison about it.
  // DONE: Some code was deleted here (Other directives).

%expect 0
%expect-rr 1

%define parse.error verbose
%defines
%debug
// Prefix all the tokens with TOK_ to avoid colisions.
%define api.token.prefix {TOK_}

/* We use pointers to store the filename in the locations.  This saves
   space (pointers), time (no deep copy), but leaves the problem of
   deallocation.  This would be a perfect job for a misc::symbol
   object (passed by reference), however Bison locations require the
   filename to be passed as a pointer, thus forcing us to handle the
   allocation and deallocation of this object.

   Nevertheless, all is not lost: we can still use a misc::symbol
   object to allocate a flyweight (constant) string in the pool of
   symbols, extract it from the misc::symbol object, and use it to
   initialize the location.  The allocated data will be freed at the
   end of the program (see the documentation of misc::symbol and
   misc::unique).  */
%define api.filename.type {const std::string}
%locations

// The parsing context.
%param { ::parse::TigerParser& tp }

/*---------------------.
| Support for tokens.  |
`---------------------*/
%code requires
{
#include <string>
#include <misc/algorithm.hh>
#include <misc/separator.hh>
#include <misc/symbol.hh>
#include <parse/fwd.hh>

  // Pre-declare parse::parse to allow a ``reentrant'' parsing within
  // the parser.
  namespace parse
  {
    ast_type parse(Tweast& input);
  }
}

%code provides
{
  // Announce to Flex the prototype we want for lexing (member) function.
  # define YY_DECL_(Prefix)                               \
    ::parse::parser::symbol_type                          \
    (Prefix parselex)(::parse::TigerParser& tp)
  # define YY_DECL YY_DECL_(yyFlexLexer::)
}

%printer { yyo << $$; } <int> <std::string> <misc::symbol>;

%token <std::string>    STRING "string"
%token <misc::symbol>   ID     "identifier"
%token <int>            INT    "integer"


/*--------------------------------.
| Support for the non-terminals.  |
`--------------------------------*/

%code requires
{
# include <ast/fwd.hh>
// Provide the declarations of the following classes for the
// %destructor clauses below to work properly.
# include <ast/exp.hh>
# include <ast/var.hh>
# include <ast/ty.hh>
# include <ast/name-ty.hh>
# include <ast/field.hh>
# include <ast/field-init.hh>
# include <ast/function-dec.hh>
# include <ast/type-dec.hh>
# include <ast/var-dec.hh>
# include <ast/chunk.hh>
# include <ast/chunk-list.hh>
}

  // FIXME: Some code was deleted here (Printers and destructors).


/*-----------------------------------------.
| Code output in the implementation file.  |
`-----------------------------------------*/

%code
{
# include <parse/scantiger.hh>
# include <parse/tweast.hh>
# include <misc/separator.hh>
# include <misc/symbol.hh>
# include <ast/all.hh>
# include <ast/libast.hh>
# include <parse/tiger-driver.hh>

  namespace
  {

    /// Get the metavar from the specified map.
    template <typename T>
    T*
    metavar(parse::TigerParser& tp, unsigned key)
    {
      parse::Tweast* input = tp.input_;
      return input->template take<T>(key);
    }

  }

  /// Use our local scanner object.
  inline
  ::parse::parser::symbol_type
  parselex(parse::TigerParser& tp)
  {
    return tp.scanner_->parselex(tp);
  }
}

// Definition of the tokens, and their pretty-printing.
%token AND          "&"
       ARRAY        "array"
       ASSIGN       ":="
       BREAK        "break"
       CAST         "_cast"
       CLASS        "class"
       COLON        ":"
       COMMA        ","
       DIVIDE       "/"
       DO           "do"
       DOT          "."
       ELSE         "else"
       END          "end"
       EQ           "="
       EXTENDS      "extends"
       FOR          "for"
       FUNCTION     "function"
       GE           ">="
       GT           ">"
       IF           "if"
       IMPORT       "import"
       IN           "in"
       LBRACE       "{"
       LBRACK       "["
       LE           "<="
       LET          "let"
       LPAREN       "("
       LT           "<"
       MINUS        "-"
       METHOD       "method"
       NE           "<>"
       NEW          "new"
       NIL          "nil"
       OF           "of"
       OR           "|"
       PLUS         "+"
       PRIMITIVE    "primitive"
       RBRACE       "}"
       RBRACK       "]"
       RPAREN       ")"
       SEMI         ";"
       THEN         "then"
       TIMES        "*"
       TO           "to"
       TYPE         "type"
       VAR          "var"
       WHILE        "while"
       EOF 0        "end of file"

%type <ast::Exp*>             exp
%type <ast::ChunkList*>       chunks

%type <ast::TypeChunk*>       tychunk
%type <ast::TypeDec*>         tydec
%type <ast::NameTy*>          typeid
%type <ast::Ty*>              ty

%type <ast::Field*>           tyfield 
%type <ast::fields_type*>     tyfields tyfields.1 record_creation
  // DONE: Some code was deleted here (More %types).

  // DONE: Some code was deleted here (Priorities/associativities).
%precedence CHUNKS
%precedence TYPE

%precedence CLASS
%precedence DO OF

%precedence THEN
%precedence ELSE

%left OR
%left AND
%nonassoc GE LE EQ NE LT GT
%left PLUS MINUS
%left TIMES DIVIDE
%precedence UMINUS
%precedence ASSIGN


// Solving conflicts on:
// let type foo = bar
//     type baz = bat
// which can be understood as a list of two TypeChunk containing
// a unique TypeDec each, or a single TypeChunk containing two TypeDec.
// We want the latter.

  // DONE: Some code was deleted here (Other declarations).

%start program

%%
program:
  /* Parsing a source program.  */
  exp         { tp.ast_ = $1; }
| /* Parsing an imported file.  */
  chunks      { tp.ast_ = $1; }
;

rec_exps:
  %empty
| SEMI exps
;

exps:
    exp rec_exps
|   %empty
;

record_creation:
  %empty 
| typeid EQ exp
| typeid EQ exp record_init
;

record_init:
  COMMA ID EQ exp
| COMMA ID EQ exp record_init
;

function_param:
  exp
| exp COMMA function_param
;

method_call:
    COMMA exp
|   %empty
;

exp:
    INT         { $$ = tp.td_.make_IntExp(@$, $1); }
  // DONE: Some code was deleted here (More rules).
|   NIL         { $$ = tp.td_.make_NilExp(@$); }
|   STRING      { $$ = tp.td_.make_StringExp(@$, $1); }
|   typeid LBRACK exp RBRACK OF exp   { $$ = tp.td_.make_ArrayExp(@$, $1, $3, $6); }
|   typeid LBRACE record_creation RBRACE //{ $$ = tp.td_.make_RecordExp(@$, $1, $3); }
|   lvalue      
|   ID LPAREN RPAREN    
|   ID LPAREN function_param RPAREN
|   MINUS exp                      %prec UMINUS
|   exp PLUS exp      { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::add, $3); }
|   exp MINUS exp     { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::sub, $3); }
|   exp TIMES exp     { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::mul, $3); }
|   exp DIVIDE exp    { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::div, $3); }
|   exp EQ exp        { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::eq, $3); }
|   exp NE exp        { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::ne, $3); }
|   exp GT exp        { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::gt, $3); }
|   exp LT exp        { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::lt, $3); }
|   exp GE exp        { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::ge, $3); }
|   exp LE exp        { $$ = tp.td_.make_OpExp(@$, $1, ast::OpExp::Oper::le, $3); }
|   exp AND exp
|   exp OR exp
|   LPAREN exps RPAREN
|   lvalue ASSIGN exp
|   IF exp THEN exp  { $$ = tp.td_.make_IfExp(@$, $2, $4); }
|   IF exp THEN exp ELSE exp { $$ = tp.td_.make_IfExp(@$, $2, $4, $6); }
|   WHILE exp DO exp
|   FOR ID ASSIGN exp TO exp DO exp
|   BREAK
|   LET chunks IN exps END
|   NEW typeid
|   lvalue DOT ID LPAREN RPAREN
|   lvalue DOT ID LPAREN exp method_call RPAREN
;

lvalue:
    ID
|   lvalue DOT ID
|   lvalue LBRACK exp RBRACK
;

vardec:
  VAR ID ASSIGN exp
| VAR ID COLON typeid ASSIGN exp
;

fundec:
    FUNCTION ID LPAREN tyfields RPAREN EQ exp
|   FUNCTION ID LPAREN tyfields RPAREN COLON typeid EQ exp
|   PRIMITIVE ID LPAREN tyfields RPAREN
|   PRIMITIVE ID LPAREN tyfields RPAREN COLON typeid
;

/*---------------.
| Declarations.  |
`---------------*/

%token CHUNKS "_chunks";
chunks:
  /* Chunks are contiguous series of declarations of the same type
     (TypeDec, FunctionDec...) to which we allow certain specfic behavior like
     self referencing.
     They are held by a ChunkList, that can be empty, like in this case:
        let
        in
            ..
        end
     which is why we end the recursion with a %empty. */
  %empty                  { $$ = tp.td_.make_ChunkList(@$); }
| tychunk   chunks        { $$ = $2; $$->push_front($1); }
  // DONE: Some code was deleted here (More rules).
| fundec  chunks
| vardec    chunks
| IMPORT STRING chunks
;

/*--------------------.
| Type Declarations.  |
`--------------------*/

tychunk:
  /* Use `%prec CHUNKS' to do context-dependent precedence and resolve a
     shift-reduce conflict. */
  tydec %prec CHUNKS  { $$ = tp.td_.make_TypeChunk(@1); $$->push_front(*$1); }
| tydec tychunk       { $$ = $2; $$->push_front(*$1); }
;


tydec:
  "type" ID "=" ty { $$ = tp.td_.make_TypeDec(@$, $2, $4); }
| CLASS ID LBRACE classfields RBRACE
| CLASS ID EXTENDS typeid LBRACE classfields RBRACE
;

ty:
  typeid               { $$ = $1; }
| "{" tyfields "}"     { $$ = tp.td_.make_RecordTy(@$, $2); }
| "array" "of" typeid  { $$ = tp.td_.make_ArrayTy(@$, $3); }
| CLASS LBRACE classfields RBRACE
| CLASS EXTENDS typeid LBRACE classfields RBRACE
;

classfields:
  %empty
| vardec classfields
| METHOD ID LPAREN tyfields RPAREN EQ exp classfields
| METHOD ID LPAREN tyfields RPAREN COLON typeid EQ exp classfields
;

tyfields:
  %empty               { $$ = tp.td_.make_fields_type(); }
| tyfields.1           { $$ = $1; }
;

tyfields.1:
  tyfields.1 "," tyfield { $$ = $1; $$->emplace_back($3); }
| tyfield                { $$ = tp.td_.make_fields_type($1); }
;

tyfield:
  ID ":" typeid     { $$ = tp.td_.make_Field(@$, $1, $3); }
;

%token NAMETY "_namety";
typeid:
  ID                    { $$ = tp.td_.make_NameTy(@$, $1); }
  /* This is a metavariable. It it used internally by TWEASTs to retrieve
     already parsed nodes when given an input to parse. */
| NAMETY "(" INT ")"    { $$ = metavar<ast::NameTy>(tp, $3); }
;

%%

void
parse::parser::error(const location_type& l, const std::string& m)
{
  // DONE: Some code was deleted here.

      tp.error_ << misc::error::error_type::parse
                << l
                << ": "
                << m
                << '\n';

}
