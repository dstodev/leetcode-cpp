#ifndef CPPKATA_ISOCKET_HXX
#define CPPKATA_ISOCKET_HXX


template <typename fd_t>
class ISocket
{
public:
	// Pure virtual forces child classes to implement the destructor, and forces this class to be abstract.
	// Pure virtual does NOT mean "no implementation in this class". It ONLY means "derived classes must implement
	// this."
	virtual ~ISocket() = 0;

	virtual ISocket<fd_t> & operator=(const fd_t & fd) = 0;
	virtual operator fd_t() const = 0;

	virtual void fd(fd_t fd) = 0;
	virtual fd_t fd() const = 0;

	/** @brief Set the socket to blocking or non-blocking mode.
	 * @param[in] mode @c true for blocking mode,
	 *                 @c false for non-blocking mode.
	 */
	virtual void blocking(bool mode) = 0;
	virtual bool blocking() const = 0;
};

// Must be inlined to avoid multiple definitions; if this header is included in multiple translation units,
// multiple definitions would otherwise occur.
template <typename fd_t>
inline ISocket<fd_t>::~ISocket() = default;

#endif  // CPPKATA_ISOCKET_HXX
