/**
 ** \file bind/libbind.cc
 ** \brief Define exported bind functions.
 */

// DONE: Some code was deleted here.

#include <ast/chunk-list.hh>
#include <ast/libast.hh>
#include <bind/libbind.hh>
#include <parse/libparse.hh>
#include "binder.hh"

namespace bind {
    misc::error bind(ast::ChunkList& c)
    {
        Binder binder;
        binder(c);
    }
}
