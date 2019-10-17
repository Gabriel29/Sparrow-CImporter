#pragma once

#include <string>
#include <vector>
#include <memory>
#include <clang-c/Index.h>
#include "../ICimpVisitor.hpp"

#include "Decl.hpp"
#include "StructField.hpp"
#include "utils.hpp"

namespace cimporter
{

class Union : public Decl
{
public:
    Union(CXCursor cursor);
    
    void addToList(const std::shared_ptr<StructField> node);
    const std::vector<std::shared_ptr<StructField>>& getFieldList() const;

    void parseDecl() override;
    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    bool _isAnonymous;
    std::vector<std::shared_ptr<StructField>> _fieldList;
};

}