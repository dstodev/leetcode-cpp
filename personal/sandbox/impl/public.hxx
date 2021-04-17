#ifndef IMPL_PUBLIC_H
#define IMPL_PUBLIC_H

class ImplPrivate;


class ImplPublic
{
public:
	ImplPublic();
	virtual ~ImplPublic();

	void func_one() const;

private:
	ImplPrivate * _impl;
};

#endif  // IMPL_PUBLIC_H
