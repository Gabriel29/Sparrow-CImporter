#pragma once

#include <string>
#include <memory>
#include <clang-c/Index.h>

#include "CXBase.hpp"
#include "Type.hpp"
#include "utils.hpp"

namespace cimporter
{

class FunParam : public CXBase
{
public:
	FunParam(CXCursor cursor);

    void SetType(std::shared_ptr<Type> type);
    
    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    std::shared_ptr<Type> _type;
};

}