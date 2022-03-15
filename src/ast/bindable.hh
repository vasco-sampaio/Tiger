#pragma once

#include <ast/exp.hh>

namespace ast
{
    class Bindable
    {
        public:
            Bindable()
                : def_(nullptr)
            {}

            void def_set(ast::Dec* def)
            {
                def_ = def;
            }

            ast::Dec* def_get() const
            {
                return def_;
            }
            ast::Dec* def_get()
            {
                return def_;
            }
        protected:
            ast::Dec* def_;
    };
} // namespace ast