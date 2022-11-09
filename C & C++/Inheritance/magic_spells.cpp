#include <iostream>
#include <vector>
#include <string>

class spell
{
	std::string scroll_name_;

protected:
	int power_ = 0;

public:
	explicit spell(const int power) : power_(power) {}

	explicit spell(const std::string& name)
	{
		scroll_name_ = name;
	}

	virtual ~spell() = default;

	[[nodiscard]] std::string reveal_scroll_name() const { return scroll_name_; }
};

class fireball final : public spell
{
public:
	explicit fireball(const int power) : spell(power) {}

	void reveal_firepower() const
	{
		std::cout << "Fireball: " << power_ << std::endl;
	}
};

class frostbite final : public spell
{
public:
	explicit frostbite(const int power) : spell(power) {}

	void reveal_frostpower() const
	{
		std::cout << "Frostbite: " << power_ << std::endl;
	}
};

class thunderstorm final : public spell
{
public:
	explicit thunderstorm(const int power) : spell(power) {}

	void reveal_thunderpower() const
	{
		std::cout << "Thunderstorm: " << power_ << std::endl;
	}
};

class waterbolt final : public spell
{
public:
	explicit waterbolt(const int power) : spell(power) {}

	void reveal_waterpower() const
	{
		std::cout << "Waterbolt: " << power_ << std::endl;
	}
};

class spell_journal
{
public:
	static std::string journal;

	static std::string read() { return journal; }
};

std::string spell_journal::journal;

int lcs(const std::string& x, const std::string& y)
{
	const auto m = x.length(), n = y.length();
	// allocate storage for one-dimensional arrays, `curr` and `prev`
	const auto curr = new int[n + 1];
	const auto prev = new int[n + 1];
	// fill the lookup table in a bottom-up manner
	for (size_t i = 0; i <= m; i++)
	{
		for (size_t j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				curr[j] = 0;
			}
			else
			{
				// if the current character of `X` and `Y` matches
				if (x[i - 1] == y[j - 1])
					curr[j] = prev[j - 1] + 1;
				// otherwise, if the current character of `X` and `Y` don't match
				else
					curr[j] = std::max(prev[j], curr[j - 1]);
			}
		}
		// replace contents of the previous array with the current array
		for (size_t j = 0; j <= n; j++)
		{
			prev[j] = curr[j];
		}
	}
	// LCS will be the last entry in the lookup table
	return curr[n];
}

void counterspell(spell* spell)
{
	if (const auto fire = dynamic_cast<fireball*>(spell))
	{
		return fire->reveal_firepower();
	}
	if (const auto frost = dynamic_cast<frostbite*>(spell))
	{
		return frost->reveal_frostpower();
	}
	if (const auto thunder = dynamic_cast<thunderstorm*>(spell))
	{
		return thunder->reveal_thunderpower();
	}
	if (const auto water = dynamic_cast<waterbolt*>(spell))
	{
		return water->reveal_waterpower();
	}
	if (spell != nullptr)
	{
		std::cout << lcs(spell->reveal_scroll_name(), spell_journal::read()) << std::endl;
	}
}

class wizard
{
public:
	static spell* cast()
	{
		spell* spell;
		std::string s;
		std::cin >> s;
		int power;
		std::cin >> power;
		if (s == "fire")
		{
			spell = new fireball(power);
		}
		else if (s == "frost")
		{
			spell = new frostbite(power);
		}
		else if (s == "water")
		{
			spell = new waterbolt(power);
		}
		else if (s == "thunder")
		{
			spell = new thunderstorm(power);
		}
		else
		{
			spell = new ::spell(s);
			std::cin >> spell_journal::journal;
		}
		return spell;
	}
};

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		spell* spell = wizard::cast();
		counterspell(spell);
	}
	return 0;
}