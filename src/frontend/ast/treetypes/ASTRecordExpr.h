#pragma once

#include "ASTExpr.h"
#include "ASTFieldExpr.h"

//! \brief Class for defining a record.
class ASTRecordExpr : public ASTExpr {
  std::vector<std::unique_ptr<ASTFieldExpr>> FIELDS;
public:
  ASTRecordExpr(std::vector<std::unique_ptr<ASTFieldExpr>> FIELDS)
      : FIELDS(std::move(FIELDS)) {}
  std::vector<ASTFieldExpr*> getFields();
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;
};
