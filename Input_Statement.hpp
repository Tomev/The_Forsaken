#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Input_Statement : public SyntaxTree
	{
	public:
		
		Input_Statement(SyntaxTree* Expression)
		{
			children.push_back(Expression);
		}

		virtual ~Input_Statement()
		{

		}

		virtual std::string toCode() const
		{
			std::string code = "std::cin >> ";

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