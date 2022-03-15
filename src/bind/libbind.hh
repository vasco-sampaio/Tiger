/**
 ** \file bind/libbind.hh
 ** \brief Interface of the bind module.
 */

// DONE: Some code was deleted here.

#pragma once

#include <ast/chunk-list.hh>
#include <ast/libast.hh>
#include <bind/libbind.hh>
#include <parse/libparse.hh>

namespace bind {
    misc::error bind(ast::ChunkList c);
}