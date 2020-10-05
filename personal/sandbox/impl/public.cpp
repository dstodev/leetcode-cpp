#include "public.hpp"
#include "private.hpp"


ImplPublic::ImplPublic()
{
	_impl = new ImplPrivate;
}

ImplPublic::~ImplPublic()
{
	delete _impl;
}

void ImplPublic::funcOne() const
{
	_impl->getIntermediate().funcOne();
}
