#pragma once

#include <memory>
#include <vector>
#include <clang-c/Index.h>

#include "CXBase.hpp"
#include "FunParam.hpp"
#include "Type.hpp"

#include "utils.hpp"


namespace cimporter
{

class FunPtr : public CXBase
{
public:
	FunPtr(CXCursor cursor);

	const std::vector<std::shared_ptr<FunParam>> getParamList() const;
	const std::shared_ptr<Type> getRetType() const;
	void addParameter(std::shared_ptr<FunParam> param);

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    std::shared_ptr<Type> _retType;
    std::vector<std::shared_ptr<FunParam>> _paramList;
};

}