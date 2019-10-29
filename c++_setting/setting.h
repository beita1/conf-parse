/********************************************************************
	Created:		2019-01-02
	Author:			chips;
	Version:		1.0.0(版本号);
	Description:	用于初始化项目配置;
----------------------------------------------------------------------------

----------------------------------------------------------------------------
  Remark         :
----------------------------------------------------------------------------
  Change History :
  <Date>     | <Version> | <Author>       | <Description>
----------------------------------------------------------------------------
  2018/01/02 |	1.0.0	 |	chips		  | Create file
----------------------------------------------------------------------------
*********************************************************************/


#pragma once

#include <iostream>
#include <boost/program_options.hpp>

#include "assist_marco.h"

using namespace std;
using namespace boost::program_options;

class Setting
{
private:
	Setting(void) {};
	~Setting(void) {};
	Setting(const Setting&);
	Setting& operator=(const Setting&);
private:
	variables_map _config_map;
public:
	static Setting& GetInstance()
	{
		static Setting instance;
		return instance;
	}

	void Init(int argc, char* argv[]);

	DEFINE_PROPERTY_READONLY(char, test_mode);
	DEFINE_PROPERTY_REF_READONLY(string, test_file_path);

	//效率问题
	//int GetInt(string key);//无key或者value返回-1;
	//string GetString(string key);//无key或者value返回空字符串;
	//char GetChar(string key);//无key或者value返回空字符;
	//wstring GetWstring(string key);
};