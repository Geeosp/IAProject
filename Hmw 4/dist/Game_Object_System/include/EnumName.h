#ifndef ENUM_NAME_H
#define ENUM_NAME_H


struct EnumName
{
	enum Name
	{
		Stubb // needed for overloading
	};

	bool operator == (EnumName tmp)
	{
		return (this->value == tmp.value);
	}

	int value;
};

#endif