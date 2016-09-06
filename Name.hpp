#pragma once
#include "SyntaxTree.hpp"

namespace compiler
{
	class Name : public SyntaxTree
	{
	public:
		
		Name(const std::string &name)
		:
			name(name)
		{}

		virtual ~Name() = default;

		virtual std::string toCode() const
		{
			return name;
		}

	protected:

	private:
		std::string name;

	};
}