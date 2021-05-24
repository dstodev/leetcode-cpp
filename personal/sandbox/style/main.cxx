void long_parameter_list(int parameter_1, int parameter_2, int parameter_3, int parameter_4);

struct ReallySuperExtraLongClassName
{
	explicit ReallySuperExtraLongClassName(int value)
	    : value(value)
	{}
	~ReallySuperExtraLongClassName() = default;

	operator int() const
	{
		return value;
	}

	int value;
};

int main()
{
	long_parameter_list(ReallySuperExtraLongClassName(1),
	                    ReallySuperExtraLongClassName(2),
	                    ReallySuperExtraLongClassName(3),
	                    ReallySuperExtraLongClassName(4));
}

void long_parameter_list(int parameter_1, int parameter_2, int parameter_3, int parameter_4)
{
	(void) parameter_1;
	(void) parameter_2;
	(void) parameter_3;
	(void) parameter_4;
}
