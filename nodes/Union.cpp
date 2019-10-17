#include "Union.hpp"

using namespace cimporter;

Union::Union(CXCursor cursor)
    : Decl(cursor)
{
    // Empty
}

void Union::addToList(const std::shared_ptr<StructField> node)
{
    _fieldList.push_back(node);
}

const std::vector<std::shared_ptr<StructField>>& Union::getFieldList() const
{
    return _fieldList;
}

void Union::parseDecl()
{
    clang_visitChildren(
        _cursor, 
        [] (CXCursor cursor, CXCursor parent, CXClientData clientData) -> CXChildVisitResult
    {
        CXSourceLocation location = clang_getCursorLocation(cursor);
        if( clang_Location_isFromMainFile( location ) == 0 )
        {
            return CXChildVisit_Continue;
        }
        
        Union* s = reinterpret_cast<Union*>(clientData);
        CXCursorKind cursorKind = clang_getCursorKind(cursor);

        if (cursorKind ==  CXCursor_FieldDecl) {
            auto structField = std::make_shared<StructField>(cursor);
            structField->parseStructField();
            s->_fieldList.push_back(structField);
        }

        return CXChildVisit_Continue;
    }, 
    this);
}