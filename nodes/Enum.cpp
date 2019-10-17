#include "Enum.hpp"
#include "utils.hpp"

using namespace cimporter;

Enum::Enum(CXCursor cursor) : Decl(cursor)
{
    _name    = getCursorName(_cursor);
    _isAnonymous = _name.empty();
}

const std::vector<std::shared_ptr<EnumDecl>> Enum::getEnumList() const
{
    return _decls;
}

void Enum::addToList(const std::shared_ptr<EnumDecl> node)
{
    _decls.push_back(node);
}

void Enum::parseDecl()
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
        
        CXCursorKind cursorKind = clang_getCursorKind(cursor);

        if (cursorKind ==  CXCursor_EnumConstantDecl) {
            Enum* e = reinterpret_cast<Enum*>(clientData);
            e->addToList( std::make_shared<EnumDecl>(cursor) );
        }

        return CXChildVisit_Continue;
    }, 
    this);
}
