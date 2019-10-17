#pragma once

#include <memory>
#include <clang-c/Index.h>
#include "utils.hpp"

#include "../ICimpVisitor.hpp"

namespace cimporter
{

class CXBase
{
public:
    CXBase(CXCursor cursor)
        : _cursor(cursor) { }

    CXBase(std::string name, CXCursor cursor)
        : _name(name), _cursor(cursor) { }

    const std::string& getName() const  { return _name; };
    const CXCursor getCursor() const    { return _cursor; };

    virtual void accept(ICimpVisitor& visitor) = 0;

protected:
    CXCursor        _cursor;
    std::string     _name;
};

}