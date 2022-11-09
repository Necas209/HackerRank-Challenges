#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

class message
{
	int id_;
	std::string text_;

public:
	static int current_id;

	explicit message(const std::string& t)
	{
		id_ = current_id++;
		text_ = t;
	}
	const std::string& get_text()
	{
		return text_;
	}
	friend bool operator<(const message& m1, const message& m2);
};

int message::current_id = 0;

bool operator<(const message& m1, const message& m2)
{
	return m1.id_ < m2.id_;
}

class message_factory
{
public:
	static message create_message(const std::string& text)
	{
		return message(text);
	}
};

class recipient
{
public:
	void receive(const message& msg)
	{
		messages_.push_back(msg);
	}
	void print_messages()
	{
		fix_order();
		for (auto& msg : messages_)
		{
			std::cout << msg.get_text() << std::endl;
		}
		messages_.clear();
	}

private:
	void fix_order()
	{
		std::sort(messages_.begin(), messages_.end());
	}
	std::vector<message> messages_;
};

class network
{
public:
	static void send_messages(std::vector<message>& messages, recipient& recipient)
	{
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		std::random_device rd;
		std::mt19937 g(rd());
		std::ranges::shuffle(messages, g);
		for (auto& msg : messages)
		{
			recipient.receive(msg);
		}
	}
};

int main()
{
	recipient recipient;
	std::vector<message> messages;
	std::string text;
	while (std::getline(std::cin, text))
	{
		messages.push_back(message_factory::create_message(text));
	}
	network::send_messages(messages, recipient);
	recipient.print_messages();
}