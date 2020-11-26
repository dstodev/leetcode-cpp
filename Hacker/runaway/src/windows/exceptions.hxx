#ifndef CPPKATA_EXCEPTIONS_HXX
#define CPPKATA_EXCEPTIONS_HXX

/*
 * These exceptions and their descriptions come from:
 *     https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2
 *
 * (retrieved 11/25/2020)
 */

#include <winsock2.h>
#include <exception>

using std::exception;

void map_to_exception(int status);

#define WinsockException(Type, message) \
class Type : public exception { \
public: \
    virtual const char *what() const noexcept override { \
        return message; \
    } \
}

WinsockException(WsaInvalidHandle,
                 "Specified event object handle is invalid.\nAn application attempts to use an event object, but the specified handle is not valid.");

WinsockException(WsaNotEnoughMemory,
                 "Insufficient memory available.\nAn application used a Windows Sockets function that directly maps to a Windows function. The Windows function is indicating a lack of required memory resources.");

WinsockException(WsaInvalidParameter,
                 "One or more parameters are invalid.\nAn application used a Windows Sockets function which directly maps to a Windows function. The Windows function is indicating a problem with one or more parameters.");

WinsockException(WsaOperationAborted,
                 "Overlapped operation aborted.\nAn overlapped operation was canceled due to the closure of the socket, or the execution of the SIO_FLUSH command in WSAIoctl.");

WinsockException(WsaIoIncomplete,
                 "Overlapped I/O event object not in signaled state.\nThe application has tried to determine the status of an overlapped operation which is not yet completed. Applications that use WSAGetOverlappedResult (with the fWait flag set to FALSE) in a polling mode to determine when an overlapped operation has completed, get this error code until the operation is complete.");

WinsockException(WsaIoPending,
                 "Overlapped operations will complete later.\nThe application has initiated an overlapped operation that cannot be completed immediately. A completion indication will be given later when the operation has been completed.");

WinsockException(WsaEIntr,
                 "Interrupted function call.\nA blocking operation was interrupted by a call to WSACancelBlockingCall.");

WinsockException(WsaEBadF,
                 "File handle is not valid.\nThe file handle supplied is not valid.");

WinsockException(WsaEAcces,
                 "Permission denied.\nAn attempt was made to access a socket in a way forbidden by its access permissions. An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST).\nAnother possible reason for the WSAEACCES error is that when the bind function is called (on Windows NT 4.0 with SP4 and later), another application, service, or kernel mode driver is bound to the same address with exclusive access. Such exclusive access is a new feature of Windows NT 4.0 with SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option.");

WinsockException(WsaEFault,
                 "Bad address.\nThe system detected an invalid pointer address in attempting to use a pointer argument of a call. This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small. For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr).");

WinsockException(WsaEInval,
                 "Invalid argument.\nSome invalid argument was supplied (for example, specifying an invalid level to the setsockopt function). In some instances, it also refers to the current state of the socket—for instance, calling accept on a socket that is not listening.");

WinsockException(WsaEMFile,
                 "Too many open files.\nToo many open sockets. Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread.");

WinsockException(WsaEWouldBlock,
                 "Resource temporarily unavailable.\nThis error is returned from operations on nonblocking sockets that cannot be completed immediately, for example recv when no data is queued to be read from the socket. It is a nonfatal error, and the operation should be retried later. It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, since some time must elapse for the connection to be established.");

WinsockException(WsaEInProgress,
                 "Operation now in progress.\nA blocking operation is currently executing. Windows Sockets only allows a single blocking operation—per- task or thread—to be outstanding, and if any other function call is made (whether or not it references that or any other socket) the function fails with the WSAEINPROGRESS error.");

WinsockException(WsaEAlready,
                 "Operation already in progress.\nAn operation was attempted on a nonblocking socket with an operation already in progress—that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request (WSAAsyncGetXbyY) that has already been canceled or completed.");

WinsockException(WsaENotSock,
                 "Socket operation on nonsocket.\nAn operation was attempted on something that is not a socket. Either the socket handle parameter did not reference a valid socket, or for select, a member of an fd_set was not valid.");

WinsockException(WsaEDestAddrReq,
                 "Destination address required.\nA required address was omitted from an operation on a socket. For example, this error is returned if sendto is called with the remote address of ADDR_ANY.");

WinsockException(WsaEMsgSize,
                 "Message too long.\nA message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself.");

WinsockException(WsaEProtoType,
                 "Protocol wrong type for socket.\nA protocol was specified in the socket function call that does not support the semantics of the socket type requested. For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM.");

WinsockException(WsaENoProtoOpt,
                 "Bad protocol option.\nAn unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call.");

WinsockException(WsaEProtoNoSupport,
                 "Protocol not supported.\nThe requested protocol has not been configured into the system, or no implementation for it exists. For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol.");

WinsockException(WsaESockTNoSupport,
                 "Socket type not supported.\nThe support for the specified socket type does not exist in this address family. For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all.");

WinsockException(WsaEOpNotSupp,
                 "Operation not supported.\nThe attempted operation is not supported for the type of object referenced. Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket.");

WinsockException(WsaEPFNoSupport,
                 "Protocol family not supported.\nThe protocol family has not been configured into the system or no implementation for it exists. This message has a slightly different meaning from WSAEAFNOSUPPORT. However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT.");

WinsockException(WsaEAFNoSupport,
                 "Address family not supported by protocol family.\nAn address incompatible with the requested protocol was used. All sockets are created with an associated address family (that is, AF_INET for Internet Protocols) and a generic protocol type (that is, SOCK_STREAM). This error is returned if an incorrect protocol is explicitly requested in the socket call, or if an address of the wrong family is used for a socket, for example, in sendto.");

WinsockException(WsaEAddrInUse,
                 "Address already in use.\nTypically, only one usage of each socket address (protocol/IP address/port) is permitted. This error occurs if an application attempts to bind a socket to an IP address/port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing. For server applications that need to bind multiple sockets to the same port number, consider using setsockopt (SO_REUSEADDR). Client applications usually need not call bind at all—connect chooses an unused port automatically. When bind is called with a wildcard address (involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed. This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf.");

WinsockException(WsaEAddrNotAvail,
                 "Cannot assign requested address.\nThe requested address is not valid in its context. This normally results from an attempt to bind to an address that is not valid for the local computer. This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port is not valid for a remote computer (for example, address or port 0).");

WinsockException(WsaENetDown,
                 "Network is down.\nA socket operation encountered a dead network. This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself.");

WinsockException(WsaENetUnreach,
                 "Network is unreachable.\nA socket operation was attempted to an unreachable network. This usually means the local software knows no route to reach the remote host.");

WinsockException(WsaENetReset,
                 "Network dropped connection on reset.\nThe connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed.");

WinsockException(WsaEConnAborted,
                 "Software caused connection abort.\nAn established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error.");

WinsockException(WsaEConnReset,
                 "Connection reset by peer.\nAn existing connection was forcibly closed by the remote host. This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close (see setsockopt for more information on the SO_LINGER option on the remote socket). This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET.");

WinsockException(WsaENoBufS,
                 "No buffer space available.\nAn operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.");

WinsockException(WsaEIsConn,
                 "Socket is already connected.\nA connect request was made on an already-connected socket. Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket (for SOCK_STREAM sockets, the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence.");

WinsockException(WsaENotConn,
                 "Socket is not connected.\nA request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied. Any other type of operation might also return this error—for example, setsockopt setting SO_KEEPALIVE if the connection has been reset.");

WinsockException(WsaEShutdown,
                 "Cannot send after socket shutdown.\nA request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued.");

WinsockException(WsaETooManyRefs,
                 "Too many references.\nToo many references to some kernel object.");

WinsockException(WsaETimedOut,
                 "Connection timed out.\nA connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond.");

WinsockException(WsaEConnRefused,
                 "Connection refused.\nNo connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host—that is, one with no server application running.");

WinsockException(WsaELoop,
                 "Cannot translate name.\nCannot translate a name.");

WinsockException(WsaENameTooLong,
                 "Name too long.\nA name component or a name was too long.");

WinsockException(WsaEHostDown,
                 "Host is down.\nA socket operation failed because the destination host is down. A socket operation encountered a dead host. Networking activity on the local host has not been initiated. These conditions are more likely to be indicated by the error WSAETIMEDOUT.");

WinsockException(WsaEHostUnreach,
                 "No route to host.\nA socket operation was attempted to an unreachable host. See WSAENETUNREACH.");

WinsockException(WsaENotEmpty,
                 "Directory not empty.\nCannot remove a directory that is not empty.");

WinsockException(WsaEProcLim,
                 "Too many processes.\nA Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously. WSAStartup may fail with this error if the limit has been reached.");

WinsockException(WsaEUsers,
                 "User quota exceeded.\nRan out of user quota.");

WinsockException(WsaEDQuot,
                 "Disk quota exceeded.\nRan out of disk quota.");

WinsockException(WsaEStale,
                 "Stale file handle reference.\nThe file handle reference is no longer available.");

WinsockException(WsaERemote,
                 "Item is remote.\nThe item is not available locally.");

WinsockException(WsaSysNotReady,
                 "Network subsystem is unavailable.\nThis error is returned by WSAStartup if the Windows Sockets implementation cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Users should check:\nThat the appropriate Windows Sockets DLL file is in the current path.\nThat they are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded.\nThe Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly.");

WinsockException(WsaVerNotSupported,
                 "Winsock.dll version out of range.\nThe current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. Check that no old Windows Sockets DLL files are being accessed.");

WinsockException(WsaNotInitialized,
                 "Successful WSAStartup not yet performed.\nEither the application has not called WSAStartup or WSAStartup failed. The application may be accessing a socket that the current active task does not own (that is, trying to share a socket between tasks), or WSACleanup has been called too many times.");

WinsockException(WsaEDiscon,
                 "Graceful shutdown in progress.\nReturned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence.");

WinsockException(WsaENoMore,
                 "No more results.\nNo more results can be returned by the WSALookupServiceNext function.");

WinsockException(WsaECancelled,
                 "Call has been canceled.\nA call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.");

WinsockException(WsaEInvalidProcTable,
                 "Procedure call table is invalid.\nThe service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. This is usually caused by one or more of the function pointers being NULL.");

WinsockException(WsaEInvalidProvider,
                 "Service provider is invalid.\nThe requested service provider is invalid. This error is returned by the WSCGetProviderInfo and WSCGetProviderInfo32 functions if the protocol entry specified could not be found. This error is also returned if the service provider returned a version number other than 2.0.");

WinsockException(WsaEProviderFailedInit,
                 "Service provider failed to initialize.\nThe requested service provider could not be loaded or initialized. This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) or the provider's WSPStartup or NSPStartup function failed.");

WinsockException(WsaSysCallFailure,
                 "System call failure.\nA system call that should never fail has failed. This is a generic error code, returned under various conditions.\nReturned when a system call that should never fail does fail. For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol/namespace catalogs.\nReturned when a provider does not return SUCCESS and does not provide an extended error code. Can indicate a service provider implementation error.");

WinsockException(WsaServiceNotFound,
                 "Service not found.\nNo such service is known. The service cannot be found in the specified name space.");

WinsockException(WsaTypeNotFound,
                 "Class type not found.\nThe specified class was not found.");

WinsockException(WsaENoMore2,
                 "No more results.\nNo more results can be returned by the WSALookupServiceNext function.");

WinsockException(WsaECancelled2,
                 "Call was canceled.\nA call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled.");

WinsockException(WsaERefused,
                 "Database query was refused.\nA database query failed because it was actively refused.");

WinsockException(WsaHostNotFound,
                 "Host not found.\nNo such host is known. The name is not an official host name or alias, or it cannot be found in the database(s) being queried. This error may also be returned for protocol and service queries, and means that the specified name could not be found in the relevant database.");

WinsockException(WsaTryAgain,
                 "Nonauthoritative host not found.\nThis is usually a temporary error during host name resolution and means that the local server did not receive a response from an authoritative server. A retry at some time later may be successful.");

WinsockException(WsaNoRecovery,
                 "This is a nonrecoverable error.\nThis indicates that some sort of nonrecoverable error occurred during a database lookup. This may be because the database files (for example, BSD-compatible HOSTS, SERVICES, or PROTOCOLS files) could not be found, or a DNS request was returned by the server with a severe error.");

WinsockException(WsaNoData,
                 "Valid name, no data record of requested type.\nThe requested name is valid and was found in the database, but it does not have the correct associated data being resolved for. The usual example for this is a host name-to-address translation attempt (using gethostbyname or WSAAsyncGetHostByName) which uses the DNS (Domain Name Server). An MX record is returned but no A record—indicating the host itself exists, but is not directly reachable.");

WinsockException(WsaQosReceivers,
                 "QoS receivers.\nAt least one QoS reserve has arrived.");

WinsockException(WsaQosSenders,
                 "QoS senders.\nAt least one QoS send path has arrived.");

WinsockException(WsaQosNoSenders,
                 "No QoS senders.\nThere are no QoS senders.");

WinsockException(WsaQosNoReceivers,
                 "QoS no receivers.\nThere are no QoS receivers.");

WinsockException(WsaQosRequestConfirmed,
                 "QoS request confirmed.\nThe QoS reserve request has been confirmed.");

WinsockException(WsaQosAdmissionFailure,
                 "QoS admission error.\nA QoS error occurred due to lack of resources.");

WinsockException(WsaQosPolicyFailure,
                 "QoS policy failure.\nThe QoS request was rejected because the policy system couldn't allocate the requested resource within the existing policy.");

WinsockException(WsaQosBadStyle,
                 "QoS bad style.\nAn unknown or conflicting QoS style was encountered.");

WinsockException(WsaQosBadObject,
                 "QoS bad object.\nA problem was encountered with some part of the filterspec or the provider-specific buffer in general.");

WinsockException(WsaQosTrafficCtrlError,
                 "QoS traffic control error.\nAn error with the underlying traffic control (TC) API as the generic QoS request was converted for local enforcement by the TC API. This could be due to an out of memory error or to an internal QoS provider error.");

WinsockException(WsaQosGenericError,
                 "QoS generic error.\nA general QoS error.");

WinsockException(WsaQosEServiceType,
                 "QoS service type error.\nAn invalid or unrecognized service type was found in the QoS flowspec.");

WinsockException(WsaQosEFlowspec,
                 "QoS flowspec error.\nAn invalid or inconsistent flowspec was found in the QOS structure.");

WinsockException(WsaQosEProvSpecBuf,
                 "Invalid QoS provider buffer.\nAn invalid QoS provider-specific buffer.");

WinsockException(WsaQosEFilterStyle,
                 "Invalid QoS filter style.\nAn invalid QoS filter style was used.");

WinsockException(WsaQosEFilterType,
                 "Invalid QoS filter type.\nAn invalid QoS filter type was used.");

WinsockException(WsaQosEFilterCount,
                 "Incorrect QoS filter count.\nAn incorrect number of QoS FILTERSPECs were specified in the FLOWDESCRIPTOR.");

WinsockException(WsaQosEObjLength,
                 "Invalid QoS object length.\nAn object with an invalid ObjectLength field was specified in the QoS provider-specific buffer.");

WinsockException(WsaQosEFlowCount,
                 "Incorrect QoS flow count.\nAn incorrect number of flow descriptors was specified in the QoS structure.");

WinsockException(WsaQosEUnknownPsObj,
                 "Unrecognized QoS object.\nAn unrecognized object was found in the QoS provider-specific buffer.");

WinsockException(WsaQosEPolicyObj,
                 "Invalid QoS policy object.\nAn invalid policy object was found in the QoS provider-specific buffer.");

WinsockException(WsaQosEFlowDesc,
                 "Invalid QoS flow descriptor.\nAn invalid QoS flow descriptor was found in the flow descriptor list.");

WinsockException(WsaQosEPsFlowspec,
                 "Invalid QoS provider-specific flowspec.\nAn invalid or inconsistent flowspec was found in the QoS provider-specific buffer.");

WinsockException(WsaQosEPsFilterSpec,
                 "Invalid QoS provider-specific filterspec.\nAn invalid FILTERSPEC was found in the QoS provider-specific buffer.");

WinsockException(WsaQosESDModeObj,
                 "Invalid QoS shape discard mode object.\nAn invalid shape discard mode object was found in the QoS provider-specific buffer.");

WinsockException(WsaQosEShapeRateObj,
                 "Invalid QoS shaping rate object.\nAn invalid shaping rate object was found in the QoS provider-specific buffer.");

WinsockException(WsaQosReservedPEType,
                 "Reserved policy QoS element type.\nA reserved policy element was found in the QoS provider-specific buffer.");

#endif  // CPPKATA_EXCEPTIONS_HXX
