#pragma once

#include <clang-c/Index.h>
#include <string>

typedef enum dataType
{
	cimp_Bool = 0,
	cimp_Int, 
	cimp_Long,
	cimp_ULong,
	cimp_Char,
	cimp_Void,
	cimp_Float,
	cimp_Double,
	cimp_Pointer,
	cimp_CtArray,
	cimp_IncArray,
	cimp_Other,
} dataType;

typedef enum declType
{
	cimp_EnumDecl = 0,
	cimp_UnionDecl,
	cimp_TypeDefDecl,	
	cimp_StructDecl,
	cimp_FunctionDecl,
} declType;

std::string getFilePath(const std::string& filePath);
std::string removeFileExtension(const std::string& fileCt);
std::string getCursorName(const CXCursor& cursor);
std::string getStructName(CXType type);