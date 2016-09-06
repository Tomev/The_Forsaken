#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Statements : public SyntaxTree
	{
	public:
		
		Statements(SyntaxTree* Instruction, SyntaxTree *Statements)
		{
			children.push_back(Instruction);
			children.push_back(Statements);
		}

		virtual ~Statements()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "";

			for(SyntaxTree *node : children)
			{
				if(node != nullptr)	
					code += node->toCode();
			}

			return code;
		}


	protected:

	private:

	};
}