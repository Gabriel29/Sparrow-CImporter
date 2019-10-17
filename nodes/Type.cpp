#include <vector>

#include "Type.hpp"

using namespace cimporter;

Type::Type(CXType cxType) 
    : _cxType(cxType)
{
    switch(cxType.kind)
    {
    case CXType_Bool:
        _dataType = cimp_Bool;
		break;

	case CXType_Int:
        _dataType = cimp_Int;
		break;

	case CXType_UInt:
	case CXType_ULong:
	case CXType_ULongLong:
        _dataType = cimp_ULong;
		break;

	case CXType_Long:
	case CXType_LongLong:
        _dataType = cimp_Long;
		break;

	case CXType_Float:
        _dataType = cimp_Float;
		break;

	case CXType_Double:
        _dataType = cimp_Double;
		break;

	case CXType_Char_S:
        _dataType = cimp_Char;
		break;

	case CXType_Pointer:
        _dataType = cimp_Pointer;
		break;

	case CXType_ConstantArray:
        _dataType = cimp_CtArray;
		break;

	case CXType_IncompleteArray:
        _dataType = cimp_IncArray;
		break;

	case CXType_Void:
        _dataType = cimp_Void;
		break;

    // TODO
	case CXType_Enum:
	case CXType_Typedef:
	case CXType_Elaborated:
		break;
	
	case CXType_Unexposed:
		break;

	case CXType_FunctionNoProto:
	case CXType_FunctionProto:
        break;

    default:
        break;
    }
}

void Type::parseType()
{
    if(_dataType == cimp_Pointer)
    {
        auto pointee = clang_getPointeeType(_cxType);
        _child = std::make_shared<Type>(pointee);
        _child->parseType();
    }
    else if(_dataType == cimp_CtArray)
    {
        auto elementType = clang_getArrayElementType(_cxType);
        _arrayLen = clang_getArraySize(_cxType);
        _child = std::make_shared<Type>(elementType);
        _child->parseType();
    }
    else if(_dataType == cimp_IncArray)
    {
        auto elementType = clang_getArrayElementType(_cxType);
        _child = std::make_shared<Type>(elementType);
        _child->parseType();
    }

}