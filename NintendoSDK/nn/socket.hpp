/**
 * @file socket.h
 * @brief Functions for opening sockets for wireless communication.
 */

#pragma once

#include <nn/types.h>
#include <nn/util.h>

struct in_addr {
    u32 s_addr;
};
struct sockaddr_in {
    u8 sin_len;
    u8 sin_family;
    u16 sin_port;
    in_addr sin_addr;
    char sin_zero[8];
};

struct sockaddr {
    u8 sa_len;
    u8 sa_family;
    char sa_data[14];
};

struct hostent {
    char* h_name;
    char** h_aliases;
    int h_addrtype;
    int h_length;
    char** h_addr_list;
};

struct addrinfo {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    u32 ai_addrlen;
    char* ai_canonname;
    sockaddr* ai_addr;
    addrinfo* ai_next;
};

struct pollfd {
    int fd;
    short events;
    short revents;
};

struct timeval {
    u64 tv_sec;   // seconds
    u64 tv_usec; // microseconds
};

// Constants
#define AF_INET 2
#define SOCK_STREAM 1
#define SOCK_DGRAM 2
#define IPPROTO_IP 0
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17
#define TCP_NODELAY 1
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#define SOL_SOCKET 0xFFFF
#define SO_SNDTIMEO 0x1005
#define SO_RCVTIMEO 0x1006
#define SO_ERROR 0x1007

// Flags
#define MSG_DONTWAIT 0x80

namespace nn::socket {

    struct ResourceStatistics;

#if NN_SDK_VER >= NN_MAKE_VER(7, 0, 0)
    struct InAddr {
        u32 addr;
    };
#else
    using InAddr = ::in_addr;
#endif

    enum class Errno : s32 {
        EBadF = 9,
        EAgain = 11,
        EWouldBlock = EAgain,
        EInval = 22,
        EConnReset = 54,
        EMsgSize = 90,
        ENoProtoOpt = 92,
        EAddrNotAvail = 99,
        ENetUnreach = 101,
        EConnResetPeer = 104,
        ETimedOut = 110,
        EConnRefused = 111,
    };

    enum FcntlCommand : s32 {
        F_GetFl = 3,
        F_SetFl = 4,
    };

    enum FcntlFlag : s32 {
        O_NonBlock = 0x800,
    };

    enum PollEvent : s16 {
        PollIn = 0x1,
    };

    Result Initialize(void* pool, ulong poolSize, ulong allocPoolSize, int concurLimit);
    Result Finalize();

    s32 Socket(s32 domain, s32 type, s32 protocol);
    s32 SocketExempt(s32, s32, s32);
    s32 DuplicateSocket(s32, ulong);
    Result Close(s32 socket);
    s32 Shutdown(s32, s32);
    s32 ShutdownAllSockets(bool);

    s32 Connect(s32 socket, const sockaddr* addr, u32 addrLen);
    s32 Bind(s32 socket, const sockaddr* addr, u32 addrLen);
    s32 Listen(s32 socket, s32 backlog);
    s32 Accept(s32 socket, sockaddr* addrOut, u32* addrLenOut);

    s32 Send(s32 socket, const void* buffer, u64 bufferLength, s32 flags);
    s32 SendTo(s32, const void*, ulong, s32, const sockaddr*, u32);
    s32 Recv(s32 socket, void* out, ulong outLen, s32 flags);
    s32 RecvFrom(s32, void*, ulong, s32, sockaddr*, u32*);
    s32 Write(s32, const void*, ulong);
    s32 Read(s32, void*, ulong);

    s32 SetSockOpt(s32 socket, s32 socketLevel, s32 option, const void*, u32 len);
    void GetSockOpt(s32, s32, s32, void*, u32*);
    s32 GetPeerName(s32, sockaddr*, u32*);
    s32 GetSockName(s32, sockaddr*, u32*);
    s32 SockAtMark(s32);
    s32 Fcntl(s32 socket, s32 command, ...);
    s32 Ioctl(s32, u32, void*, ulong);
    s32 Poll(pollfd*, ulong, s32);
    s32 Open(const char*, s32);

    s32 InetPton(s32, const char*, void*);
    const char* InetNtop(s32 af, const void* src, char* dst, u32 size);
    s32 InetAton(const char* addressStr, InAddr* addressOut);
    char* InetNtoa(InAddr);
    u16 InetHtons(u16);
    u32 InetHtonl(u32);
    u16 InetNtohs(u16);
    u32 InetNtohl(u32);

    s32 GetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**);
    s32 GetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**, s32);
    s32 FreeAddrInfo(addrinfo*);
    s32 GetNameInfo(const sockaddr*, u32, char*, u32, char*, u32, s32);
    hostent* GetHostByName(const char* name);
    hostent* GetHostByName(const char*, s32);
    hostent* GetHostByAddr(const void*, u32, s32);

    s32 GetLastErrno();
    void SetLastErrno(s32);
    s32 GetHErrno();
    s32 RequestCancelHandle();
    s32 Cancel(s32);
    s32 Sysctl(s32*, ulong, void*, ulong*, void*, ulong);
    s32 GetResourceStatistics(ResourceStatistics*, ulong);
}
