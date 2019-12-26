#pragma once

#include <string>
#include <vector>
#include <memory>
#include <clang-c/Index.h>

#include "Decl.hpp"
#include "FunParam.hpp"
#include "utils.hpp"

namespace cimporter
{

class Typedef : public Decl
{
public:
	Typedef(CXCursor cursor);

    void parseDecl() override;
    std::shared_ptr<Type> getType() const { return _type; }

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    std::shared_ptr<Type> _type;
};

}
