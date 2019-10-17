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

	void setFunPtrTrue();
	bool isFunPtr();
	void addToList(const std::shared_ptr<FunParam> decl);
    const std::vector<std::shared_ptr<FunParam>>& getParamList() const;

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    bool _isFunctionPointer;
    std::vector<std::shared_ptr<FunParam>> _paramList;
};

}
