#include <string>
#include <iostream>
#include <cctype>

void ft_amplified(std::string &str)
{
	int	i;

	i = -1;
	while (++i < str.length())
		str[i] = std::toupper(str[i]);
}

int main(int argc, char **argv)
{
	std::string str;
	int i = 0;
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	str = argv[1];
	while (++i < argc - 1)
	{
		str += " ";
		str += argv[i + 1];
	}
	ft_amplified(str);
	std::cout << str << std::endl;
	return (0);
}
