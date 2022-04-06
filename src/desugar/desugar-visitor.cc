/**
 ** \file desugar/desugar-visitor.cc
 ** \brief Implementation of desugar::DesugarVisitor.
 */

#include <ast/all.hh>
#include <ast/libast.hh>
#include <desugar/desugar-visitor.hh>
#include <misc/algorithm.hh>
#include <misc/symbol.hh>
#include <parse/libparse.hh>
#include <parse/tweast.hh>

using namespace ast;

namespace desugar
{
  DesugarVisitor::DesugarVisitor(bool desugar_for_p, bool desugar_string_cmp_p)
    : super_type()
    , desugar_for_p_(desugar_for_p)
    , desugar_string_cmp_p_(desugar_string_cmp_p)
  {}

  /*-----------------------------.
  | Desugar string comparisons.  |
  `-----------------------------*/
  void DesugarVisitor::operator()(const ast::OpExp& e)
  {
    // DONE: Some code was deleted here.
    auto op = e.oper_get();
    ast::Exp* left = recurse(e.left_get());
    ast::Exp* right = recurse(e.right_get());
    if (left->type_get() == &type::String::instance() && right->type_get() == &type::String::instance())
    {
      std::vector<ast::Exp*> exps({left, right});
      if (op == ast::OpExp::Oper::eq)
      {
        result_ = new ast::CallExp(e.location_get(), "streq", &exps);
      }
      else
      {
        auto call = new ast::CallExp(e.location_get(), "strcmp", &exps);
        result_ = new ast::OpExp(e.location_get(), call, op, new ast::IntExp(e.location_get(), 0));
      }
    }
  }

  /*----------------------.
  | Desugar `for' loops.  |
  `----------------------*/

  /*<<-
    Desugar `for' loops as `while' loops:

       for i := lo to hi do
         body

     is transformed as:

       let
         var _lo := lo
         var _hi := hi
         var i := _lo
       in
         if i <= _hi then
           while 1 do
             (
               body;
               if i = _hi then
                 break;
               i := i + 1
             )
       end

     Notice that:

     - a `_hi' variable is introduced so that `hi' is evaluated only
       once;

     - a `_lo' variable is introduced to prevent `i' from being in the
       scope of `_hi';

     - a first test is performed before entering the loop, so that the
       loop condition becomes `i < _hi' (instead of `i <= _hi'); this
       is done to prevent overflows on INT_MAX.
       ->>*/

  void DesugarVisitor::operator()(const ast::ForExp& e)
  {
    // DONE: Some code was deleted here.
    const Location& location = e.location_get();
    VarDec* vardec = recurse(e.vardec_get());
    Exp* hi = recurse(e.hi_get());
    Exp* body = recurse(e.body_get());

    VarDec* lo = new VarDec(location, "_lo", vardec->type_name_get(), vardec->init_get());
    VarDec* new_hi = new VarDec(location, "_hi", vardec->type_name_get(), hi);
    VarDec* i_ = new VarDec(location, "i", vardec->type_name_get(), lo->init_get());

    SimpleVar* simple_i = new SimpleVar(location, "i");
    simple_i->def_set(i_);

    SimpleVar* simple_hi = new SimpleVar(location, "_hi");
    simple_i->def_set(new_hi);
    OpExp* test = new OpExp(location, simple_i, ast::OpExp::Oper::le, simple_hi);

    BreakExp* break_exp = new BreakExp(location);
    AssignExp* assign = new AssignExp(location, simple_i, 
      new ast::OpExp(location, simple_i, ast::OpExp::Oper::add, new IntExp(location, 1)));
    
    OpExp* comp = new ast::OpExp(location, simple_i, ast::OpExp::Oper::eq, simple_hi);
    IfExp* ifexp = new IfExp(location, comp, break_exp, nullptr);

    auto tmp = std::vector<ast::Exp*>({body, ifexp, assign});
    SeqExp* seq = new SeqExp(location, &tmp);
    WhileExp* whileExp = new WhileExp(location, new IntExp(location, 1), seq);

    IfExp* finalIf = new IfExp(location, test, whileExp, nullptr);

    ChunkList* decs = new ChunkList(location);
    decs->emplace_back(lo);
    decs->emplace_back(new_hi);
    decs->emplace_back(i_);
    result_ = new LetExp(location, decs, finalIf);
  }

} // namespace desugar
