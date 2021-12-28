#ifndef __STRING__
#define __STRING__

class String{
public:
	String(const char * = nullptr);
	String(const String& t_str);
	String& operator =(const String& str);
	~ String();
	char * get_c_str()const{
		return m_data;
	}
	friend ostream& operator <<(ostream& os, const String& str);
private:
	char * m_data;
};

String::String(const char * str)
{
	if (str != nullptr)
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	else{
		m_data = new char[1];
		m_data = '\0';
	}
}

String::~String()
{
	delete [] m_data;
}

String& String::operator =(const String& str)
{
	if(this!= &str)
	{
		delete []m_data;
		m_data = new char[strlen(str.m_data)+1];
		strcpy(m_data, str.m_data);
		return *this;
	}
	return *this;
}

String::String(const String& str)
{
	m_data = new char[strlen(str.m_data)+1];
	strcp(m_data,str.m_data);
}

ostream& String::operator <<( ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;
}