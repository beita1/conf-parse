#include "setting.h"
#include "common.h"

void Setting::Init(int argc, char* argv[])
{
	try
	{
		options_description opts("DataCollector Allowed Options");

		//所有配置都需要加入opts中，以此来有效控制配置;
		opts.add_options()
			("help", value<string>(), "just a help info")
			("mode", value<char>(), "test: test mode, dev: dev mode; eg: --mode=test")

			//user_configuration.txt中的配置，需要在这里定义
			("ip", value<string>(), "server ip")
			("port", value<string>(), "server port")
			;

		store(parse_command_line(argc, argv, opts), _config_map); //解析命令行参数;
		store(parse_config_file<char>(CONFIG_FILE_NAME.c_str(), opts, true), _config_map);//解析文件中的参数,true时允许配置文件中出现未定义的选项;

		if (_config_map.count("help"))
		{
			cout << opts << endl;
			system("pause");

			exit(1);
		}
	}
	catch (...)
	{
		cout << "setting init error,may exist config param not be allowed or style is error,please start with --help for help" << endl;
		LoggerRecord::WriteLog(L"setting init error,may exist config param not be allowed or style is error,please start with --help for help", LogLevel::ERR);
		system("pause");

		exit(1);
	}
}

int Setting::GetInt(string key)
{
	if (_config_map.count(key) > 0)
	{
		return _config_map[key].as<int>();
	}

	return -1;
}

std::string Setting::GetString(string key)
{
	if (_config_map.count(key) > 0)
	{
		return _config_map[key].as<string>();
	}

	return "";
}

char Setting::GetChar(string key)
{
	if (_config_map.count(key) > 0)
	{
		return _config_map[key].as<char>();
	}

	return 0;
}

std::wstring Setting::GetWstring(string key)
{
	if (_config_map.count(key) > 0)
	{
		return _config_map[key].as<wstring>();
	}

	return L"";
}

