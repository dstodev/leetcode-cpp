#include "public.hxx"
#include "private.hxx"


ImplPublic::ImplPublic()
{
	_impl = new ImplPrivate;
}

ImplPublic::~ImplPublic()
{
	delete _impl;
}

void ImplPublic::func_one() const
{
	_impl->getIntermediate().func_one();
}
