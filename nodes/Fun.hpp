#pragma once

#include <vector>
#include "Decl.hpp"

namespace cimporter
{

 class FunParam;
 class Type;

class Fun : public Decl
{

public:
    Fun(CXCursor cursor);

    void parseDecl() override;
    
    void SetType(std::shared_ptr<Type> retType);
	const std::vector<std::shared_ptr<FunParam>>& getParamList() const;
	const std::shared_ptr<Type> getRetType() const;
	void addToList(std::shared_ptr<FunParam> node);

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    std::shared_ptr<Type>                   _retType;
    std::vector<std::shared_ptr<FunParam>>  _paramList;
};

}