#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Instruction : public SyntaxTree
	{
	public:
		
		Instruction(SyntaxTree* name, SyntaxTree* statements)
		{
			children.push_back(name);
			children.push_back(statements);
		}

		virtual ~Instruction()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "";

			for(SyntaxTree *node : children)
				code += node->toCode();

			return code;
		}

	protected:

	private:

	};
}