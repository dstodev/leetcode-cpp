#ifndef IMPL_PRIVATE_H
#define IMPL_PRIVATE_H

class Intermediate
{
public:
	void func_one() const;
};


class ImplPrivate
{
public:
	~ImplPrivate() = default;

	const Intermediate & getIntermediate() const;

	Intermediate _intermediate;
};

#endif  // IMPL_PRIVATE_H
