#pragma once

#include <vector>
#include <string>
#include <memory>
#include <clang-c/Index.h>

#include "utils.hpp"
#include "../ICimpVisitor.hpp"

namespace cimporter
{

class Type
{
public:
    Type(CXType cxType);
	void parseType();

	const dataType getType() const 	{ return _dataType; }
	const std::shared_ptr<Type> getChild() const { return _child; }
    
    void accept(ICimpVisitor& visitor) { visitor.visit(*this); }

private:
	std::shared_ptr<Type> _child;
    CXType      	_cxType;
    dataType    	_dataType;

public:
    std::string 	_data;
	unsigned int	_arrayLen;

    //std::shared_ptr<Type>  _child;
    // std::vector<FunParam*> paramList;
};

}