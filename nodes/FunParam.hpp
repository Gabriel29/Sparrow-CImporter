#pragma once

#include <string>
#include <memory>
#include <clang-c/Index.h>

#include "Decl.hpp"
#include "Type.hpp"
#include "utils.hpp"

namespace cimporter
{

class FunParam : public Decl
{
public:
	FunParam(CXCursor cursor);

    void parseDecl() override;
    std::shared_ptr<Type> getType() const { return _type; }

    void SetType(std::shared_ptr<Type> type);
    
    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    std::shared_ptr<Type> _type;
};

}