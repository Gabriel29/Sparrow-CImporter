#pragma once

#include <string>
#include <vector>
#include <memory>
#include <clang-c/Index.h>

#include "Decl.hpp"
#include "EnumDecl.hpp"
#include "utils.hpp"

namespace cimporter
{

class Enum : public Decl
{
public:
	Enum(CXCursor cursor);
	
    void parseDecl() override;

	const std::vector<std::shared_ptr<EnumDecl>> getEnumList() const;
	void addToList(const std::shared_ptr<EnumDecl> node);

    void accept(ICimpVisitor& visitor) override { visitor.visit(*this); }

private:
    bool _isAnonymous;
    std::vector<std::shared_ptr<EnumDecl>> _decls;
    

};

}