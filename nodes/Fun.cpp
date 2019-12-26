#include "Fun.hpp"
#include "FunParam.hpp"
#include "Type.hpp"
#include "utils.hpp"

using namespace cimporter;

Fun::Fun(CXCursor cursor)
    : Decl(cursor)
{
    _name        = getCursorName(_cursor);
}

void Fun::parseDecl()
{
    auto cursorType = clang_getCursorType(_cursor);
    auto retType = clang_getResultType(cursorType);

    _retType = std::make_shared<Type>(retType);
    _retType->parseType();

    if(clang_Cursor_getNumArguments(_cursor) > 0)
	{
		clang_visitChildren(_cursor,
        [] (CXCursor cursor, CXCursor parent, CXClientData clientData) -> CXChildVisitResult
        {
            CXCursorKind cursorKind = clang_getCursorKind(cursor);
            if (cursorKind == CXCursor_ParmDecl)
            {
                Fun* f = reinterpret_cast<Fun*>(clientData);
                auto funParam = std::make_shared<FunParam>(cursor);
                funParam->parseDecl();
                f->_paramList.push_back(funParam);                
            }

            return CXChildVisit_Continue;
        }, this);
	}
}

const std::vector<std::shared_ptr<FunParam>>& Fun::getParamList() const {
    return _paramList;
}

const std::shared_ptr<Type> Fun::getRetType() const {
    return _retType;
}

void Fun::addToList(std::shared_ptr<FunParam> node)
{
    _paramList.push_back(node);
}

void Fun::SetType(std::shared_ptr<Type> retType)
{
    _retType = retType;
}
