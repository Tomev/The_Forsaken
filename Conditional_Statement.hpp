#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Conditional_Statement : public SyntaxTree
	{
	public:
		
		Conditional_Statement() = default;

		virtual ~Conditional_Statement() = default;
		

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
	
		std::vector<SyntaxTree*> condition;

	private:

	};
}