#pragma once

namespace cimporter
{

class File;
class Decl;
class Enum;
class Struct;
class Union;
class Type;
class StructField;
class EnumDecl;
class Typedef;
class Fun;
class FunParam;
class FunPtr;

struct ICimpVisitor
{
    virtual ~ICimpVisitor() = default;

    virtual void visit(const File&)     = 0;
    virtual void visit(const Decl&)     = 0;
    virtual void visit(const Struct&)   = 0;
    virtual void visit(const Enum&)     = 0;
    virtual void visit(const Union&)    = 0;
    virtual void visit(const StructField&)     = 0;
    virtual void visit(const EnumDecl&)     = 0;
    virtual void visit(const Typedef&)      = 0;
    virtual void visit(const Fun&)          = 0;
    virtual void visit(const FunParam&)     = 0;
    virtual void visit(const FunPtr&)       = 0;

    virtual void visit(const Type&)     = 0;
};

}