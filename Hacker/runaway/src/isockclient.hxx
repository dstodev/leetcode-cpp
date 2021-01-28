#ifndef CPPKATA_ISOCKCLIENT_HXX
#define CPPKATA_ISOCKCLIENT_HXX


class ISockClient
{
public:
	// Pure virtual forces child classes to implement the destructor, and forces this class to be abstract.
	// Pure virtual does NOT mean "no implementation in this class". It ONLY means "derived classes must implement
	// this."
	virtual ~ISockClient() = 0;
};


// Must be inlined to avoid multiple definitions; if this header is included in multiple translation units,
// multiple definitions would otherwise occur.
inline ISockClient::~ISockClient() = default;


#endif  // CPPKATA_ISOCKCLIENT_HXX
