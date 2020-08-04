#pragma once

#include "ASTExpr.h"

//! \brief Class for input expression.
class ASTInputExpr : public ASTExpr {
public:
  ASTInputExpr() {}
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;
};
