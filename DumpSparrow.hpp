#pragma once

#include "ICimpVisitor.hpp"

namespace cimporter
{
    class DumpSparrow : public ICimpVisitor
    {
        void visit(const File& file) override;
        void visit(const Decl& decl) override;
        void visit(const Struct& node) override;
        void visit(const Enum& node) override;        
        void visit(const Union& unionNode) override;
        void visit(const Type& node) override;
        void visit(const StructField& node) override;
        void visit(const EnumDecl& node) override;
        void visit(const Typedef& node) override;
        void visit(const Fun& node) override;
        void visit(const FunParam& node) override;
        void visit(const FunPtr& node) override;

        void getSparrowType(const Type& node);
    };
}