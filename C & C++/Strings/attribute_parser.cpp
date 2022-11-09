#include <algorithm>
#include <iostream>
#include <list>
#include <locale>
#include <regex>
#include <sstream>
#include <string>

namespace string
{
	// left trim
	static std::string& ltrim(std::string& s)
	{
		s.erase(s.begin(), std::ranges::find_if(s, [](const auto ch)
			{
				return !std::isspace(ch, std::locale::classic());
			}));
		return s;
	}
	// right trim
	static std::string& rtrim(std::string& s)
	{
		s.erase(std::find_if(s.rbegin(), s.rend(), [](const auto ch)
			{
				return !std::isspace(ch, std::locale::classic());
			}).base(), s.end());
		return s;
	}
	// trim from both ends (in place)
	static std::string& trim(std::string& s)
	{
		return rtrim(ltrim(s));
	}
}

class attribute
{
public:
	std::string name;
	std::string value;
};

class node
{
	std::string tag_name_;
	std::list<attribute> attributes_;
	std::list<node> children_;

public:
	friend node parse(std::list<std::string>& hrml);

	friend std::string query_tree(std::list<node>& nodes, std::string& query);
};

node parse(std::list<std::string>& hrml)
{
	node root;
	// Read tag-name and attributes
	std::istringstream ss{ hrml.front().substr(1, hrml.front().length() - 2) };
	std::getline(ss, root.tag_name_, ' ');
	attribute attr;
	while (std::getline(ss, attr.name, '='))
	{
		string::trim(attr.name);
		std::string aux;
		std::getline(ss, aux, '"');
		std::getline(ss, attr.value, '"');
		root.attributes_.push_back(attr);
	}
	// Remove opening and closing tags
	hrml.pop_front();
	auto closing_tag = "</" + root.tag_name_ + '>';
	auto close_it = std::ranges::find_if(hrml,
		[&](const auto& s) { return s == closing_tag; });
	if (close_it != hrml.begin())
	{
		// Parse children
		auto it = hrml.begin();
		while (it != close_it)
		{
			auto node = parse(hrml);
			root.children_.push_back(node);
			it = hrml.begin();
		}
	}
	hrml.erase(close_it);
	return root;
}

std::string query_tree(std::list<node>& nodes, std::string& query)
{
	auto not_found = "Not Found!";
	const std::regex re(R"([\.~])");
	const std::sregex_token_iterator first{ query.begin(), query.end(), re, -1 }, last;
	std::vector<std::string> tokens;
	std::copy(first, last, std::back_inserter(tokens));
	auto it = std::ranges::find_if(nodes,
		[&](const auto& n) { return n.tag_name_ == tokens[0]; });
	if (it == nodes.end())
		return not_found;
	for (auto& token : tokens)
	{
		if (&token == &tokens.back())
		{
			const auto attr_it = std::ranges::find_if((*it).attributes_,
				[&](const attribute& attr) { return attr.name == token; });
			return attr_it != (*it).attributes_.end() ? (*attr_it).value : not_found;
		}
		else
		{
			auto temp_it = std::ranges::find_if((*it).children_,
				[&](const node& n) { return n.tag_name_ == token; });
			if (temp_it == (*it).children_.end())
				return not_found;
			it = temp_it;
		}
	}
	return not_found;
}

int main()
{
	int n, q;
	std::string aux;
	std::cin >> n >> q;
	std::cin.ignore();
	std::list<std::string> hrml;
	while (n--)
	{
		std::getline(std::cin, aux);
		hrml.push_back(aux);
	}
	std::list<node> nodes;
	while (!hrml.empty())
	{
		nodes.push_back(parse(hrml));
	}
	std::list<std::string> queries;
	while (q--)
	{
		std::getline(std::cin, aux);
		queries.push_back(aux);
	}
	for (auto& query : queries)
	{
		auto result = query_tree(nodes, query);
		std::cout << result << std::endl;
	}
	return 0;
}