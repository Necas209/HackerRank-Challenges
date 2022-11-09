#include <iostream>

class a
{
	int call_a_;

	void inc()
	{
		call_a_++;
	}

protected:
	void func(int& a)
	{
		a = a * 2;
		inc();
	}

public:
	a() { call_a_ = 0; }

	[[nodiscard]] int get_a() const { return call_a_; }
};

class b
{
	int call_b_;

	void inc()
	{
		call_b_++;
	}

protected:
	void func(int& a)
	{
		a = a * 3;
		inc();
	}

public:
	b() { call_b_ = 0; }

	[[nodiscard]] int get_b() const { return call_b_; }
};

class c
{
	int call_c_;

	void inc()
	{
		call_c_++;
	}

protected:
	void func(int& a)
	{
		a = a * 5;
		inc();
	}

public:
	c() { call_c_ = 0; }

	[[nodiscard]] int get_c() const { return call_c_; }
};

class d
	: public a,
	public b,
	public c
{
	int val_;

public:
	d() { val_ = 1; }

	void update_val(int new_val)
	{
		while (new_val % 2 == 0)
		{
			a::func(val_);
			new_val /= 2;
		}
		while (new_val % 3 == 0)
		{
			b::func(val_);
			new_val /= 3;
		}
		while (new_val % 5 == 0)
		{
			c::func(val_);
			new_val /= 5;
		}
	}

	void check(int);
};

void d::check(const int new_val)
{
	update_val(new_val);
	std::cout << "Value = " << val_ << std::endl;
	std::cout << "A's func called " << get_a() << " times " << std::endl;
	std::cout << "B's func called " << get_b() << " times" << std::endl;
	std::cout << "C's func called " << get_c() << " times" << std::endl;
}

int main()
{
	d d;
	int new_val;
	std::cin >> new_val;
	d.check(new_val);
}