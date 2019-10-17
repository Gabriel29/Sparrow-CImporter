#include "Struct.hpp"

using namespace cimporter;

Struct::Struct(CXCursor cursor)
    : Decl(cursor)
{
    _name        = getCursorName(_cursor);
    _isAnonymous = _name.empty();
}

void Struct::addToList(const std::shared_ptr<StructField> node)
{
    _fieldList.push_back(node);
}

const std::vector<std::shared_ptr<StructField>>& Struct::getFieldList() const
{
    return _fieldList;
}

void Struct::parseDecl()
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
        
        Struct* s = reinterpret_cast<Struct*>(clientData);
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
