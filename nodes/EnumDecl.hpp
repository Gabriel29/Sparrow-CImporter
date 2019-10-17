#pragma once

#include <string>
#include <memory>
#include <clang-c/Index.h>

#include "CXBase.hpp"
#include "utils.hpp"

namespace cimporter
{

class EnumDecl : public CXBase
{

public:
	EnumDecl(CXCursor cursor);
	const long getValue() const;

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    long            _value;
};

}