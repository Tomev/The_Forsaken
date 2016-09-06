#pragma once
#include <cstring>
#include "SyntaxTree.hpp"
#include "Conditional_Statement.hpp"

namespace compiler
{
	class Exit_Statement : public SyntaxTree
	{
	public:
		
		Exit_Statement(SyntaxTree* Int)
		{
			children.push_back(Int);
		}

		virtual ~Exit_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "exit(";
			
			for(SyntaxTree *node : children)
			{				
				if(node != nullptr)
				{
					code += node->toCode();
				}
			}
			
			code += ")";
			
			return code;
		}


	protected:

	private:

	};
}