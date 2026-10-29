#ifndef BITCOINEXCHANGE
# define BITCOINEXCHANGE

# include <fstream>
# include <map>

#define PATH_DATA "./data.csv"
#define LIMIT_BTC 1000.0f

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(std::string pathToInputFile, char sep_in='|',
					std::string pathToDataFile= PATH_DATA, char sep_data=',');
	BitcoinExchange(const BitcoinExchange &);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &other);

	std::map<long, float>		  get_dataMap();
	void						  exec_file();
	static float				  exchangeRate(std::map<long int, float> dataM,
												std::string &date, float qty);

	static std::map<long, float>  createMapData(std::ifstream &in, char sep);

	class FileLoadingException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

protected:
	float					  exchangeRate(std::string &date, float qty);
	void					  load_data();
	std::map<long int, float> _data;
	std::ifstream			  _dataIf;
	std::string				  _dataPath;
	char					  _dataSep;

	std::ifstream			  _inputIf;
	std::string				  _inputPath;
	char					  _inputSep;

};


long int	string2timestamp(const std::string &str);
std::string timestamp2string(long int ts);

#endif
