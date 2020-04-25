#ifndef PRETTYPRINTVISITOR_H
#define PRETTYPRINTVISITOR_H

#include "TIPtreeVisitor.h"
#include <ostream>
#include <iostream>
#include <string>

class PrettyPrintVisitor: public TIPtreeVisitor {
public:
  PrettyPrintVisitor() : os(std::cout), indentChar(' '), indentSize(2), printLines(true) {}
  PrettyPrintVisitor(std::ostream &os, char indentChar, int indentSize, bool printLines) :
          os(os), indentChar(indentChar), indentSize(indentSize), printLines(printLines) {}

  void visit(TIPtree::Program * element) override;
  void visit(TIPtree::Function * element) override;
  void visit(TIPtree::NumberExpr * element) override;
  void visit(TIPtree::VariableExpr * element) override;
  void visit(TIPtree::BinaryExpr * element) override;
  void visit(TIPtree::InputExpr * element) override;
  void visit(TIPtree::FunAppExpr * element) override;
  void visit(TIPtree::AllocExpr * element) override;
  void visit(TIPtree::RefExpr * element) override;
  void visit(TIPtree::DeRefExpr * element) override;
  void visit(TIPtree::NullExpr * element) override;
  void visit(TIPtree::FieldExpr * element) override;
  void visit(TIPtree::RecordExpr * element) override;
  void visit(TIPtree::AccessExpr * element) override;
  void visit(TIPtree::DeclStmt * element) override;
  void visit(TIPtree::AssignStmt * element) override;
  void visit(TIPtree::BlockStmt * element) override;
  void visit(TIPtree::WhileStmt * element) override;
  void visit(TIPtree::IfStmt * element) override;
  void visit(TIPtree::OutputStmt * element) override;
  void visit(TIPtree::ErrorStmt * element) override;
  void visit(TIPtree::ReturnStmt * element) override;

private:
  std::string indent() const;
  void safePrintLineNumber(int lineNumber) const;

  int indentLevel = 0;

  std::ostream &os;
  char indentChar;
  int indentSize;
  bool printLines;
};


#endif /* PRETTYPRINTVISITOR_H */
