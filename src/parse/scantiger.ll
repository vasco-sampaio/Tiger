%option c++
%option nounput
%option debug
%option batch

%{

#include <cerrno>
#include <climits>
#include <regex>
#include <string>

#include <sstream>

#include <boost/lexical_cast.hpp>

#include <misc/contract.hh>
  // Using misc::escape is very useful to quote non printable characters.
  // For instance
  //
  //    std::cerr << misc::escape('\n') << '\n';
  //
  // reports about `\n' instead of an actual new-line character.
#include <misc/escape.hh>
#include <misc/symbol.hh>
#include <parse/parsetiger.hh>
#include <parse/tiger-parser.hh>

  // DONE: Some code was deleted here.
  static std::string grown_string;
  static std::string grown_comment;
  std::stringstream sstream;
  int nested = 0;
  int finished = 1;

// Convenient shortcuts.
#define TOKEN_VAL(Type, Value)                  \
  parser::make_ ## Type(Value, tp.location_)

#define TOKEN(Type)                             \
  parser::make_ ## Type(tp.location_)


// Flex uses `0' for end of file.  0 is not a token_type.
#define yyterminate() return TOKEN(EOF)

# define CHECK_EXTENSION()                              \
  do {                                                  \
    if (!tp.enable_extensions_p_)                       \
      tp.error_ << misc::error::error_type::scan        \
                << tp.location_                         \
                << ": invalid identifier: `"            \
                << misc::escape(yytext) << "'\n";       \
  } while (false)

  # define CHECK_OBJECT()                               \
  do {                                                  \
    if (!tp.enable_object_extensions_p_)                \
      tp.error_ << misc::error::error_type::scan        \
                << tp.location_                         \
                << ": objects not activated: `"         \
                << misc::escape(yytext) << "'\n";       \
  } while (false)

YY_FLEX_NAMESPACE_BEGIN
%}

%x SC_COMMENT SC_STRING

/* Abbreviations.  */
int             [0-9]+
/* DONE: Some code was deleted here. */

blank           [ \t]+
endofline       [\n\r]+
letter          [a-zA-Z]
digit           [0-9]
%%
%{
  // DONE: Some code was deleted here (Local variables).
  // Each time yylex is called.

  tp.location_.columns(yyleng);
  tp.location_.step();
  
 
%}

 /* The rules.  */

{int}         {
                int val = 0;
  // DONE: Some code was deleted here (Decode, and check the value).
                try
                {
                  val = std::stoi(yytext, 0, 10);
                }
                catch(const std::out_of_range&)
                {
                    do {                                                  
                        tp.error_ << misc::error::error_type::scan        
                        << tp.location_                         
                        << ": int too big\n";     
                    } while (false);
                }
                return TOKEN_VAL(INT, val);
              }

  /* DONE: Some code was deleted here. */
{blank}
{endofline} {
  tp.location_.columns(yyleng);
  tp.location_.step();
  tp.location_.lines();
  }

"array"     {return TOKEN(ARRAY);}
"if"        {return TOKEN(IF);}
"then"      {return TOKEN(THEN);}
"else"      {return TOKEN(ELSE);}
"while"     {return TOKEN(WHILE);}
"for"       {return TOKEN(FOR);}
"to"        {return TOKEN(TO);}
"do"        {return TOKEN(DO);}
"let"       {return TOKEN(LET);}
"in"        {return TOKEN(IN);}
"end"       {return TOKEN(END);}
"of"        {return TOKEN(OF);}
"break"     {return TOKEN(BREAK);}
"nil"       {return TOKEN(NIL);}
"function"  {return TOKEN(FUNCTION);}
"var"       {return TOKEN(VAR);}
"type"      {return TOKEN(TYPE);}
"import"    {return TOKEN(IMPORT);}
"primitive" {return TOKEN(PRIMITIVE);}
"class"     {CHECK_OBJECT(); return TOKEN(CLASS);}
"extends"   {CHECK_OBJECT(); return TOKEN(EXTENDS);}
"method"    {CHECK_OBJECT(); return TOKEN(METHOD);}
"new"       {CHECK_OBJECT(); return TOKEN(NEW);}
","         {return TOKEN(COMMA);}
":"         {return TOKEN(COLON);}
";"         {return TOKEN(SEMI);}
"("         {return TOKEN(LPAREN);}
")"         {return TOKEN(RPAREN);}
"{"         {return TOKEN(LBRACE);}
"}"         {return TOKEN(RBRACE);}
"["         {return TOKEN(LBRACK);}
"]"         {return TOKEN(RBRACK);}
"+"         {return TOKEN(PLUS);}
"."         {return TOKEN(DOT);}
"-"         {return TOKEN(MINUS);}
"*"         {return TOKEN(TIMES);}
"/"         {return TOKEN(DIVIDE);}
"="         {return TOKEN(EQ);}
"<>"        {return TOKEN(NE);}
"<"         {return TOKEN(LT);}
"<="        {return TOKEN(LE);}
">"         {return TOKEN(GT);}
">="        {return TOKEN(GE);}
"&"         {return TOKEN(AND);}
"|"         {return TOKEN(OR);}
":="        {return TOKEN(ASSIGN);}
"_chunks"   {CHECK_EXTENSION(); return TOKEN(CHUNKS);}
"_namety"   {CHECK_EXTENSION(); return TOKEN(NAMETY);}
"_exp"      {CHECK_EXTENSION(); return TOKEN(EXP);}
"_lvalue"   {CHECK_EXTENSION(); return TOKEN(LVALUE);}
"_cast"     {CHECK_EXTENSION(); return TOKEN(CAST);}


"\""        grown_string.clear(); BEGIN SC_STRING;

<SC_STRING>{ /* Handling of the strings.  Initial " is eaten. */
  "\"" {
    BEGIN INITIAL; // Return to main context
    finished = 1;
    return TOKEN_VAL(STRING, grown_string);
  }

  "\\"[abfrntv] {
      finished = 0;
      grown_string.append(yytext);
    }

    "\\"[0-7]{3} {
      finished = 0;
      grown_string.push_back(std::stoi(++yytext, 0, 8));
    }

    "\\"[0-9]{3} {
      do {                                                  
      tp.error_ << misc::error::error_type::scan        
                << tp.location_                         
                << ": invalid octal escape\n";     
      } while (false);
    }

    "\\x"[0-9A-Fa-f]{2} {
      finished = 0;
      yytext += 2;
      grown_string.push_back(std::stoi(yytext, 0, 16));
    }

    "\\\\" {
      finished = 0;
      grown_string.append(yytext);
    }

    "\\\"" {
      finished = 0;
      grown_string.append(yytext);
    }

    "\\". {
      do {                                                 
        tp.error_ << misc::error::error_type::scan        
                  << tp.location_                         
                  << ": invalid escape\n";     
      } while (false);
    }

  . {
    finished = 0;
    grown_string.append(yytext);
  }
}

"/*"       grown_comment.clear(); BEGIN SC_COMMENT;
<SC_COMMENT>{ /* Handling of the strings.  Initial " is eaten. */
  "*/" {
    
    if (nested == 0)
    {
      grown_comment.clear();
      BEGIN INITIAL; // Return to main context
    }
    else
      nested -= 1;
  }
  
  "/*" {
    nested += 1;
  }

  <<EOF>>  {
    BEGIN INITIAL;
  }

  . {
    grown_comment.append(yytext);
  }
}
"_main" {return TOKEN_VAL(ID, misc::symbol(yytext));}
[a-zA-Z][a-zA-Z0-9_]* {return TOKEN_VAL(ID, misc::symbol(yytext));}
[_][a-zA-Z0-9_]+      {return TOKEN_VAL(ID, misc::symbol(yytext));}
<<EOF>>                 {
  if (grown_comment.size() > 0 || !finished)
{
  do {                                                  
      tp.error_ << misc::error::error_type::scan        
                << tp.location_                         
                << ": unexpected end of file in a comment or string\n";     
  } while (false);
}
return TOKEN(EOF);
}
.                     {
  do {                                                   
      tp.error_ << misc::error::error_type::scan        
                << tp.location_                         
                << ": unrecognized token\n";     
  } while (false);
}
%%

// Do not use %option noyywrap, because then flex generates the same
// definition of yywrap, but outside the namespaces, so it defines it
// for ::yyFlexLexer instead of ::parse::yyFlexLexer.
int yyFlexLexer::yywrap() { return 1; }

void
yyFlexLexer::scan_open_(std::istream& f)
{
  yypush_buffer_state(YY_CURRENT_BUFFER);
  yy_switch_to_buffer(yy_create_buffer(&f, YY_BUF_SIZE));
}

void
yyFlexLexer::scan_close_()
{
  yypop_buffer_state();
}

YY_FLEX_NAMESPACE_END