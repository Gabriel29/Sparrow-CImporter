#include <stdio.h>

#include "nodes/File.hpp"
#include "DumpSparrow.hpp"
#include "nodes/utils.hpp"

using namespace cimporter;

void DumpSparrow::visit(const File& file)
{
    auto declList = file.getDeclList();
    for(auto decl : declList)
        decl->accept(*this);
}

void DumpSparrow::visit(const Decl& decl)
{   
    //decl->accept(*this);

    // switch(decl.getNodeType())
    // {
    //     case cimp_UnionDecl:
    //         decl.getUnion()->accept(*this);
    //         break;
    //     case cimp_StructDecl:
    //         decl.getStruct()->accept(*this);
    //         break;
    //     case cimp_EnumDecl:
    //         decl.getEnum()->accept(*this);
    //         break;

    //     default:
    //         break;
    // }
}

void DumpSparrow::visit(const Struct& node)
{
    std::cout << "datatype " << node.getName() << std::endl;
    for(auto field : node.getFieldList())
    {
        auto type = field->getType();
        std::cout << field->getName() << " : ";
        type->accept(*this);
        std::cout << std::endl;
    }
}

void DumpSparrow::visit(const StructField& node)
{

}

void DumpSparrow::visit(const Enum& node)
{
    for(auto e : node.getEnumList())
    {
        std::cout << e->getName() << " : " << e->getValue() << std::endl;
    }
}

void DumpSparrow::visit(const Union& unionNode)
{
    
}

void getSparrowType(const Type& node);

void DumpSparrow::visit(const Type& node)
{
    getSparrowType(node);
}

void DumpSparrow::visit(const EnumDecl& node)
{
    // Empty
}

void DumpSparrow::visit(const Typedef& node)
{
    // Empty
}

void DumpSparrow::visit(const Fun& node)
{
    std::cout << "[native(\"";
    std::cout << node.getName();
    std::cout << "\")]" << "\n";

    std::cout << "fun " << node.getName();
    if(node.getParamList().size() > 0)
    {
        bool firstParameter = true;
        std::cout << "(";
        
        for(auto e : node.getParamList())
        {
            if(firstParameter == false)
                std::cout << ", ";
            
            std::cout << e->getName() << " : ";
            e->getType()->accept(*this);

            firstParameter = false;
        }

        std::cout << ")";
    }

    auto retType = node.getRetType();
    if(retType->getType() != cimp_Void)
    {
        std::cout << " : ";
        retType->accept(*this);
    }
    
    std::cout << '\n';
}

void DumpSparrow::visit(const FunParam& node)
{
    // Empty
}

void DumpSparrow::visit(const FunPtr& node)
{
    // Empty
}

void DumpSparrow::getSparrowType(const Type& node)
{
    switch(node.getType())
    {
    case cimp_Bool:
        std::cout << "BOOL";
        break;

    case cimp_Int:
        std::cout << "Int";
        break;

    case cimp_ULong:
        std::cout << "ULong";
        break;

    case cimp_Long:
        std::cout << "Long";
        break;

    case cimp_Float:
        std::cout << "Float";
        break;

    case cimp_Double:
        std::cout << "Double";
        break;

    case cimp_Char:
        std::cout << "Char";
        break;

    case cimp_Pointer:
    case cimp_IncArray:
        std::cout << "Ptr(";
        node.getChild()->accept(*this);
        std::cout << ")";
        break;

    case cimp_CtArray:
        std::cout << "StaticArray(";
        node.getChild()->accept(*this);
        std::cout << ", " << node._arrayLen << ")";
        break;

    case cimp_Void:
        std::cout << "";
        break;
    
    default:
        break;
    }
}