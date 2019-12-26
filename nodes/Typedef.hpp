#pragma once

#include <string>
#include <vector>
#include <memory>
#include <clang-c/Index.h>

#include "CXBase.hpp"
#include "FunParam.hpp"
#include "utils.hpp"

namespace cimporter
{

class Typedef : CXBase
{
public:
	Typedef(CXCursor cursor);

    void parseTypedef();
    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    std::shared_ptr<Type> _type;
};

}
