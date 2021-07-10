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

int main(int argc, char * argv[])
{
	long_parameter_list(ReallySuperExtraLongClassName(1),
	                    ReallySuperExtraLongClassName(2),
	                    ReallySuperExtraLongClassName(3),
	                    ReallySuperExtraLongClassName(4));

	switch (argc) {
	case 1: long_parameter_list(1, 2, 3, 4); break;
	case 2: long_parameter_list(5, 6, 7, 8); break;
	case 4: {
		long_parameter_list(1, 2, 3, 4);
	} break;
	case 3:
		long_parameter_list(ReallySuperExtraLongClassName(1),
		                    ReallySuperExtraLongClassName(2),
		                    ReallySuperExtraLongClassName(3),
		                    ReallySuperExtraLongClassName(4));
		break;
	default:;
	}

	return 0;
}

void long_parameter_list(int parameter_1, int parameter_2, int parameter_3, int parameter_4)
{
	(void) parameter_1;
	(void) parameter_2;
	(void) parameter_3;
	(void) parameter_4;
}
