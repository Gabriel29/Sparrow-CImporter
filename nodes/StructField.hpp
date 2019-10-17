#pragma once

#include <string>
#include <vector>
#include <memory>
#include <clang-c/Index.h>

#include "CXBase.hpp"
#include "Type.hpp"
#include "utils.hpp"
#include "../ICimpVisitor.hpp"

namespace cimporter
{

class StructField : public CXBase
{

public:
	StructField(CXCursor cursor);
    void parseStructField();

    std::shared_ptr<Type> getType() const { return _type; }
    void SetType(std::shared_ptr<Type> type);

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }
   
private:
    std::shared_ptr<Type> _type;
};

}