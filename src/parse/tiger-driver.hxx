#pragma once
#include <parse/tiger-driver.hh>

namespace parse
{
  inline ast::IntExp* TigerDriver::make_IntExp(const location& location,
                                               int num) const
  {
    return new ast::IntExp(location, num);
  }

  inline ast::StringExp* TigerDriver::make_StringExp(const location& location,
                                                     std::string string) const
  {
    // FIXME: Some code was deleted here (Constructor of StringExp).
  }

  inline ast::ObjectExp*
  TigerDriver::make_ObjectExp(const location& location,
                              ast::NameTy* type_name) const
  {
    // FIXME: Some code was deleted here (Constructor of Object).
  }

  inline ast::CallExp* TigerDriver::make_CallExp(const location& location,
                                                 misc::symbol name,
                                                 ast::exps_type* args) const
  {
    // FIXME: Some code was deleted here (Constructor of CallExp).
  }

  inline ast::MethodCallExp*
  TigerDriver::make_MethodCallExp(const location& location,
                                  misc::symbol name,
                                  ast::exps_type* args,
                                  ast::Var* object) const
  {
    // FIXME: Some code was deleted here (Constructor of MethodCallExp).
  }

  inline ast::RecordExp*
  TigerDriver::make_RecordExp(const location& location,
                              ast::NameTy* type_name,
                              ast::fieldinits_type* fields) const
  {
    // FIXME: Some code was deleted here (Constructor of RecordExp).
  }

  inline ast::ArrayExp* TigerDriver::make_ArrayExp(const location& location,
                                                   ast::NameTy* type_name,
                                                   ast::Exp* size,
                                                   ast::Exp* init) const
  {
    // FIXME: Some code was deleted here (Constructor of ArrayExp).
  }

  inline ast::NilExp* TigerDriver::make_NilExp(const location& location) const
  {
    return new ast::NilExp(location);
  }

  inline ast::SeqExp* TigerDriver::make_SeqExp(const location& location,
                                               ast::exps_type* exps) const
  {
    // FIXME: Some code was deleted here (Constructor of SeqExp).
  }

  inline ast::AssignExp* TigerDriver::make_AssignExp(const location& location,
                                                     ast::Var* var,
                                                     ast::Exp* exp) const
  {
    // FIXME: Some code was deleted here (Constructor of AssignExp).
  }

  inline ast::IfExp* TigerDriver::make_IfExp(const location& location,
                                             ast::Exp* test,
                                             ast::Exp* thenclause,
                                             ast::Exp* elseclause) const
  {
    // FIXME: Some code was deleted here (Constructor of IfExp).
  }

  inline ast::IfExp* TigerDriver::make_IfExp(const location& location,
                                             ast::Exp* test,
                                             ast::Exp* thenclause) const
  {
    // FIXME: Some code was deleted here (Constructor of IfExp).
  }

  inline ast::WhileExp* TigerDriver::make_WhileExp(const location& location,
                                                   ast::Exp* test,
                                                   ast::Exp* body) const
  {
    return new ast::WhileExp(location, test, body);
  }

  inline ast::ForExp* TigerDriver::make_ForExp(const location& location,
                                               ast::VarDec* vardec,
                                               ast::Exp* hi,
                                               ast::Exp* body) const
  {
    return new ast::ForExp(location, vardec, hi, body);
  }

  inline ast::BreakExp*
  TigerDriver::make_BreakExp(const location& location) const
  {
    // FIXME: Some code was deleted here (Constructor of BreakExp).
  }

  inline ast::LetExp* TigerDriver::make_LetExp(const location& location,
                                               ast::ChunkList* decs,
                                               ast::Exp* body) const
  {
    // FIXME: Some code was deleted here (Constructor of LetExp).
  }

  inline ast::OpExp* TigerDriver::make_OpExp(const location& location,
                                             ast::Exp* left,
                                             ast::OpExp::Oper oper,
                                             ast::Exp* right) const
  {
    return new ast::OpExp(location, left, oper, right);
  }

  inline ast::CastExp* TigerDriver::make_CastExp(const location& location,
                                                 ast::Exp* exp,
                                                 ast::Ty* ty) const
  {
    return new ast::CastExp(location, exp, ty);
  }

  inline ast::SimpleVar* TigerDriver::make_SimpleVar(const location& location,
                                                     misc::symbol name) const
  {
    return new ast::SimpleVar(location, name);
  }

  inline ast::FieldVar* TigerDriver::make_FieldVar(const location& location,
                                                   ast::Var* var,
                                                   misc::symbol name) const
  {
    // FIXME: Some code was deleted here (Constructor of FieldVar).
  }

  inline ast::SubscriptVar*
  TigerDriver::make_SubscriptVar(const location& location,
                                 ast::Var* var,
                                 ast::Exp* index) const
  {
    return new ast::SubscriptVar(location, var, index);
  }

  /* Use expansion parameter pack to handle one or empty arguments */
  template <class... T>
  inline ast::exps_type* TigerDriver::make_exps_type(T... exps) const
  {
    return new ast::exps_type{exps...};
  }

  inline ast::ChunkList*
  TigerDriver::make_ChunkList(const location& location) const
  {
    return new ast::ChunkList(location);
  }

  inline ast::TypeChunk*
  TigerDriver::make_TypeChunk(const location& location) const
  {
    return new ast::TypeChunk(location);
  }

  inline ast::TypeDec* TigerDriver::make_TypeDec(const location& location,
                                                 misc::symbol name,
                                                 ast::Ty* ty)
  {
    return new ast::TypeDec(location, name, ty);
  }

  inline ast::RecordTy* TigerDriver::make_RecordTy(const location& location,
                                                   ast::fields_type* fields)
  {
    // FIXME: Some code was deleted here (Constructor of RecordTy).
  }

  inline ast::ArrayTy* TigerDriver::make_ArrayTy(const location& location,
                                                 ast::NameTy* base_type) const
  {
    return new ast::ArrayTy(location, base_type);
  }

  template <class... T>
  inline ast::fields_type* TigerDriver::make_fields_type(T... types) const
  {
    return new ast::fields_type{types...};
  }

  inline ast::Field* TigerDriver::make_Field(const location& location,
                                             misc::symbol name,
                                             ast::NameTy* type_name) const
  {
    return new ast::Field(location, name, type_name);
  }

  inline ast::NameTy* TigerDriver::make_NameTy(const location& location,
                                               misc::symbol name) const
  {
    return new ast::NameTy(location, name);
  }

  template <class... T>
  inline ast::fieldinits_type*
  TigerDriver::make_fieldinits_type(T... inits_types) const
  {
    return new ast::fieldinits_type{inits_types...};
  }

  inline ast::FieldInit* TigerDriver::make_FieldInit(const location& location,
                                                     misc::symbol name,
                                                     ast::Exp* init) const
  {
    return new ast::FieldInit(location, name, init);
  }

  inline ast::ClassTy* TigerDriver::make_ClassTy(const location& location,
                                                 ast::NameTy* super,
                                                 ast::ChunkList* decs) const
  {
    return new ast::ClassTy(location, super, decs);
  }

  inline ast::VarChunk*
  TigerDriver::make_VarChunk(const location& location) const
  {
    return new ast::VarChunk(location);
  }

  inline ast::VarDec* TigerDriver::make_VarDec(const location& location,
                                               misc::symbol name,
                                               ast::NameTy* type_name,
                                               ast::Exp* init) const
  {
    return new ast::VarDec(location, name, type_name, init);
  }

  inline ast::MethodChunk*
  TigerDriver::make_MethodChunk(const location& location) const
  {
    return new ast::MethodChunk(location);
  }

  inline ast::MethodDec* TigerDriver::make_MethodDec(const location& location,
                                                     misc::symbol name,
                                                     ast::VarChunk* formals,
                                                     ast::NameTy* result,
                                                     ast::Exp* body) const
  {
    return new ast::MethodDec(location, name, formals, result, body);
  }

  inline ast::FunctionDec*
  TigerDriver::make_FunctionDec(const location& location,
                                misc::symbol name,
                                ast::VarChunk* formals,
                                ast::NameTy* result,
                                ast::Exp* body) const
  {
    return new ast::FunctionDec(location, name, formals, result, body);
  }

  template <class... T>
  inline ast::FunctionChunk* TigerDriver::make_FunctionChunk(T... args)
  {
    return new ast::FunctionChunk(args...);
  }
} // namespace parse
