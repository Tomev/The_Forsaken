#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

namespace compiler
{
	class SyntaxTree
	{
	public:
		
		SyntaxTree() = default;

		virtual ~SyntaxTree() = default;

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

		std::vector<SyntaxTree*> children;

	private:

		

	};
}