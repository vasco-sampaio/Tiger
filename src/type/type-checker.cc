/**
 ** \file type/type-checker.cc
 ** \brief Implementation for type/type-checker.hh.
 */

#include <memory>

#include <ast/all.hh>
#include <range/v3/view/iota.hpp>
#include <type/type-checker.hh>
#include <type/types.hh>

namespace type
{
  namespace
  {
    // Try to cast the type into a nil type.
    // If it's not actually a `type::Nil`, return `nullptr`.
    // This allows us to write more clear code like:
    // if (auto nil = to_nil(e.type_get())
    // ...
    const Nil* to_nil(const Type& type)
    {
      return dynamic_cast<const Nil*>(&type.actual());
    }

  } // namespace

  TypeChecker::TypeChecker()
    : super_type()
    , error_()
  {}

  const Type* TypeChecker::type(ast::Typable& e)
  {
    // DONE: Some code was deleted here.
    e.accept(*this);
    return e.type_get();
  }

  const Record* TypeChecker::type(const ast::fields_type& e)
  {
    Record res;
    // DONE: Some code was deleted here.
    for (ast::Field* field : e)
    {
      res.field_add(field->name_get(), *field->type_name_get().type_get());
    }
    return &res;
  }

  const Record* TypeChecker::type(const ast::VarChunk& e)
  {
    auto res = new Record;
    for (const auto& var : e)
      res->field_add(var->name_get(), *type(*var));

    return res;
  }

  const misc::error& TypeChecker::error_get() const { return error_; }

  /*-----------------.
  | Error handling.  |
  `-----------------*/

  void TypeChecker::error(const ast::Ast& ast, const std::string& msg)
  {
    error_ << misc::error::error_type::type << ": " << msg
           << std::endl;
  }

  void TypeChecker::type_mismatch(const ast::Ast& ast,
                                  const std::string& exp1,
                                  const Type& type1,
                                  const std::string& exp2,
                                  const Type& type2)
  {
    error_ << misc::error::error_type::type
           << ": type mismatch" << misc::incendl << exp1 << " type: " << type1
           << misc::iendl << exp2 << " type: " << type2 << misc::decendl;
  }

  void TypeChecker::check_types(const ast::Ast& ast,
                                const std::string& exp1,
                                const Type& type1,
                                const std::string& exp2,
                                const Type& type2)
  {
    // DONE: Some code was deleted here.
    if (!type1.compatible_with(type2))
      type_mismatch(ast, exp1, type1, exp2, type2);
  }

  void TypeChecker::check_types(const ast::Ast& ast,
                                const std::string& exp1,
                                ast::Typable& type1,
                                const std::string& exp2,
                                ast::Typable& type2)
  {
    // Ensure evaluation order.
    auto t1 = type(type1);
    auto t2 = type(type2);
    if (!t1->compatible_with(*t2))
      type_mismatch(ast, exp1, *t1, exp2, *t2);
    // DONE: Some code was deleted here (Check types).
  }

  /*--------------------------.
  | The core of the visitor.  |
  `--------------------------*/

  /*-----------------.
  | Visiting /Var/.  |
  `-----------------*/

  void TypeChecker::operator()(ast::SimpleVar& e)
  {
    // DONE: Some code was deleted here.
    e.type_set(e.def_get()->type_get());
  }
  void TypeChecker::operator()(ast::FieldVar& e)
  {
    // DONE: Some code was deleted here.
    e.type_set(e.var_get().type_get());
  }
  void TypeChecker::operator()(ast::SubscriptVar& e)
  {
    // DONE: Some code was deleted here.
    e.type_set(e.var_get().type_get());
  }


  // FIXME: Some code was deleted here.

  /*-----------------.
  | Visiting /Exp/.  |
  `-----------------*/

  // Literals.
  void TypeChecker::operator()(ast::NilExp& e)
  {
    auto nil_ptr = std::make_unique<Nil>();
    type_default(e, nil_ptr.get());
    created_type_default(e, nil_ptr.release());
  }

  void TypeChecker::operator()(ast::IntExp& e)
  {
    // DONE: Some code was deleted here.
    type_default(e, &Int::instance());
  }

  void TypeChecker::operator()(ast::StringExp& e)
  {
    // DONE: Some code was deleted here.
    type_default(e, &String::instance());
  }

  // Complex values.

  void TypeChecker::operator()(ast::RecordExp& e)
  {
    // If no error occured, check for nil types in the record initialization.
    // If any error occured, there's no need to set any nil types.
    // If there are any record initializations, set the `record_type_`
    // of the `Nil` to the expected type.
    // DONE: Some code was deleted here.
    bool set = false;
    for (auto& x : created_types_)
    {
      if (x->name_get() == e.type_name_get().name_get())
      {
        auto dec = dynamic_cast<ast::RecordTy*>(&(x->ty_get()));
        if (dec == nullptr) 
          continue;
        if (!set)
        {
          e.type_set(dec->type_get());
          set = true;
        }
        if (e.fields_get().size() != dec->fields_get().size())
          continue;
        for (size_t i = 0; i < e.fields_get().size(); i++)
        {
          e.fields_get().at(i)->init_get().accept(*this);
          check_types(e, "fieldDec", *dec->fields_get().at(i)->type_name_get().type_get(), "fieldActual", *e.fields_get().at(i)->init_get().type_get());
          if (error_)
            break;
        }
        break;
      }
    }
  }

  void TypeChecker::operator()(ast::OpExp& e)
  {
    // DONE: Some code was deleted here.

    // Strings dubious
    e.left_get().accept(*this);
    e.right_get().accept(*this);

    check_types(e, "left op", *e.left_get().type_get(), "right op", *e.right_get().type_get());
    // If any of the operands are of type Nil, set the `record_type_` to the
    // type of the opposite operand.
    if (!error_)
      {
        // DONE: Some code was deleted here.
        auto leftNil = dynamic_cast<const Nil*>(e.left_get().type_get());
        if (leftNil)
          leftNil->record_type_set(*(e.right_get().type_get()));

        auto rightNil = dynamic_cast<const Nil*>(e.right_get().type_get());
        if (rightNil)
          rightNil->record_type_set(*(e.left_get().type_get()));
      }
    e.type_set(&Int::instance());
  }

    // FIXME: Some code was deleted here.
    void TypeChecker::operator()(ast::IfExp& e) 
    {
      e.test_get().accept(*this);
      e.then_clause_get().accept(*this);
      if (e.else_clause_get() != nullptr)
        e.else_clause_get()->accept(*this);
      check_types(e, "condition", *e.test_get().type_get(), "expected", Int::instance());
      if (e.else_clause_get() == nullptr)
        check_types(e, "then clause", *e.then_clause_get().type_get(), "else clause default", Void::instance());
      else if (!error_)
        check_types(e, "then clause", *e.then_clause_get().type_get(), "else clause", *e.else_clause_get()->type_get());
      e.type_set(e.then_clause_get().type_get());
    }

    void TypeChecker::operator()(ast::ArrayExp& e) 
    {
      e.type_name_get().accept(*this);
      e.init_get().accept(*this);
      e.size_get().accept(*this);

      bool set = false;
      for (auto& x : created_types_)
      {
        if (x->name_get() == e.type_name_get().name_get())
        {
          auto dec = dynamic_cast<ast::ArrayTy*>(&(x->ty_get()));
          if (dec == nullptr) 
            continue;
          if (!set)
          {
            e.type_set(dec->type_get());
            set = true;
          }
          check_types(e, "array", *e.init_get().type_get(), "arrtype", *dec->base_type_get().type_get());
          break;
        }
      }
    }

    void TypeChecker::operator()(ast::CallExp& e) 
    {
      for (auto& x : e.args_get())
        x->accept(*this);
      auto def = dynamic_cast<const ast::FunctionDec*>(e.def_get());
      size_t i = 0;
      const ast::VarChunk& formals = def->formals_get();
      for (auto& arg : e.args_get())
      {
        auto x = formals.decs_get().at(i++);
        check_types(e, "arg", *arg->type_get(), "arg def", *x->type_get());
      }
      e.type_set(def->type_get());
    }

    void TypeChecker::operator()(ast::ForExp& e) 
    {
      e.vardec_get().accept(*this);
      var_read_only_.insert(&e.vardec_get());
      e.hi_get().accept(*this);
      e.body_get().accept(*this);
      if (!error_)
        check_types(e, "var dec", *e.vardec_get().type_get(), "expected", Int::instance());
      if (!error_)
        check_types(e, "high", *e.hi_get().type_get(), "expected", Int::instance());
      if (!error_)
        check_types(e, "forbody", *e.body_get().type_get(), "expected", Void::instance());
    }

    void TypeChecker::operator()(ast::WhileExp& e) 
    {
      e.test_get().accept(*this);
      e.body_get().accept(*this);
      check_types(e, "condition", *e.test_get().type_get(), "expected", Int::instance());
      if (!error_)
        check_types(e, "body", *e.body_get().type_get(), "expected", Void::instance());
      e.type_set(&Void::instance());
    }

    void TypeChecker::operator()(ast::SeqExp& e) {

      for (auto& x : e.exps_get())
        x->accept(*this);
      if (e.exps_get().size() > 0)
        e.type_set(e.exps_get().at(e.exps_get().size() - 1)->type_get());
      else
        e.type_set(&Void::instance());
    }

    void TypeChecker::operator()(ast::AssignExp& e)
    {
      e.var_get().accept(*this);
      e.exp_get().accept(*this);
      for (auto& x : var_read_only_)
      {
        auto var = dynamic_cast<ast::SimpleVar*>(&e.var_get());
        if (var == nullptr)
          break;
        if (x == var->def_get())
          error(e, "Variable is read only");
      }
      check_types(e, "vardec", *e.var_get().type_get(), "exp", *e.exp_get().type_get());
      e.type_set(&Void::instance());
    }

    void TypeChecker::operator()(ast::LetExp& e)
    {
      e.decs_get()->accept(*this);
      if (e.body_get() != nullptr)
      {
        e.body_get()->accept(*this);
        e.type_set(e.body_get()->type_get());
      }
      else
        e.type_set(&Void::instance());
    }


    void TypeChecker::operator()(ast::BreakExp& e)
    {
      e.type_set(&Void::instance());
    }

    void TypeChecker::operator()(ast::MethodCallExp& e) {}
    void TypeChecker::operator()(ast::ObjectExp& e) {}
  

  /*-----------------.
  | Visiting /Dec/.  |
  `-----------------*/

  /*------------------------.
  | Visiting FunctionChunk. |
  `------------------------*/

  void TypeChecker::operator()(ast::FunctionChunk& e)
  {
    chunk_visit<ast::FunctionDec>(e);
  }

  void TypeChecker::operator()(ast::FunctionDec&)
  {
    // We must not be here.
    unreachable();
  }

  // Store the type of this function.
  template <>
  void TypeChecker::visit_dec_header<ast::FunctionDec>(ast::FunctionDec& e)
  {
    // DONE: Some code was deleted here.
    e.formals_get().accept(*this);

    if (e.result_get() != nullptr)
    {
      e.result_get()->accept(*this);
      e.type_set(e.result_get()->type_get());
    }
  }

  // Type check this function's body.
  template <>
  void TypeChecker::visit_dec_body<ast::FunctionDec>(ast::FunctionDec& e)
  {
    if (e.body_get())
      {
        visit_routine_body<Function>(e);

        // Check for Nil types in the function body.
        if (!error_)
          {
            e.body_get()->accept(*this);
            // DONE: Some code was deleted here.

            if (e.result_get() != nullptr)
              check_types(e, "body", *e.body_get()->type_get(), "expected", *e.result_get()->type_get());
          }
        if (e.result_get() == nullptr)
          e.type_set(e.body_get()->type_get());
      }
      else if (e.result_get() == nullptr)
          e.type_set(&Void::instance());
  }

  /*---------------.
  | Visit VarDec.  |
  `---------------*/

  void TypeChecker::operator()(ast::VarDec& e)
  {
    // DONE: Some code was deleted here.
    // `type_name' might be omitted.
    if (e.type_name_get())
    {
      e.type_name_get()->accept(*this);
      e.type_set(e.type_name_get()->type_get());
    }

    // `init' can be null in case of formal parameter.
    if (e.init_get() == nullptr)
      return;
    e.init_get()->accept(*this);


    if (e.type_name_get() == nullptr)
      e.type_set(e.init_get()->type_get());

    if (e.type_name_get())
      check_types(e, "vartype", *e.type_name_get()->type_get(), "init type", *e.init_get()->type_get());
    else
      check_types(e, "vartype", Int::instance(), "init type", *e.init_get()->type_get());
  }

  /*--------------------.
  | Visiting TypeChunk. |
  `--------------------*/

  void TypeChecker::operator()(ast::TypeChunk& e)
  {
    chunk_visit<ast::TypeDec>(e);
  }

  void TypeChecker::operator()(ast::TypeDec&)
  {
    // We must not be here.
    unreachable();
  }

  // Store this type.
  template <> void TypeChecker::visit_dec_header<ast::TypeDec>(ast::TypeDec& e)
  {
    // We only process the head of the type declaration, to set its
    // name in E.  A declaration has no type in itself; here we store
    // the type declared by E.
    // DONE: Some code was deleted here.
    created_types_.push_back(&e);
  }

  // Bind the type body to its name.
  template <> void TypeChecker::visit_dec_body<ast::TypeDec>(ast::TypeDec& e)
  {
    // DONE: Some code was deleted here.
    e.ty_get().accept(*this);
  }

  /*------------------.
  | Visiting /Chunk/. |
  `------------------*/

  template <class D> void TypeChecker::chunk_visit(ast::Chunk<D>& e)
  {
    // DONE: Some code was deleted here.
    for (auto& elt : e.decs_get())
      {
        visit_dec_header(*elt);
        if (error_)
          return;
      }
    for (auto& elt : e.decs_get())
      {
        visit_dec_body(*elt);
        if (error_)
          return;
      }
  }

  /*-------------.
  | Visit /Ty/.  |
  `-------------*/

  void TypeChecker::operator()(ast::NameTy& e)
  {
    // DONE: Some code was deleted here (Recognize user defined types, and built-in types).
    if (e.name_get() == "int" || e.name_get() == "string" || e.name_get() == "void" || e.name_get() == "object")
      {
        if (e.name_get() == "int")
          e.type_set(&Int::instance());
        if (e.name_get() == "string")
          e.type_set(&String::instance());
        if (e.name_get() == "void")
          e.type_set(&Void::instance());
        return;
      }
    else if (e.def_get() != nullptr)
    {
      e.type_set(e.def_get()->ty_get().type_get());
      return;
    }
    error(e, "NameTy: Unrecognized type");
  }

  void TypeChecker::operator()(ast::RecordTy& e)
  {
    // DONE: Some code was deleted here.
    for (auto& field : e.fields_get())
    {
      field->accept(*this);
    }
    e.type_set(new Record());
  }

  void TypeChecker::operator()(ast::ArrayTy& e)
  {
    // DONE: Some code was deleted here.
    e.base_type_get().accept(*this);
    e.type_set(new Array(*e.base_type_get().type_get()));
  }

} // namespace type
