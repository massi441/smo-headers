/**
 * @file ssl.h
 * @brief SSL implementation.
 */

#pragma once

#include <nn/types.h>

namespace nn::ssl {

enum CertificateFormat { PEM = 0x01, DER = 0x02 };

class Context {
public:
    enum SslVersion { Auto = 0x01, v10 = 0x08, v11 = 0x10, v12 = 0x20 };

    Context();
    Result Create(nn::ssl::Context::SslVersion version);

    Result ImportServerPki(u64*, char const* certData, u32 certSize, nn::ssl::CertificateFormat certFormat);
    Result Destroy();

    Result GetContextId(u64* outId);

    ~Context();
};

class Connection {
public:
    /**
     * A bit mask for how certificates should be verified
     */
    enum VerifyOption { None = 0x0, PeerCa = 0x1, HostName = 0x2, DateCheck = 0x4 };

    Connection();
    Connection* Create(nn::ssl::Context* ctx);

    Result SetSocketDescriptor(s32 socket);
    Result SetHostName(const char* hostName, u32 hostNameLen);
    Result SetVerifyOption(VerifyOption option);
    Result DoHandshake();
    Result Write(const char* buffer, u32 size);
    Result Write(const char* buffer, u32 size, s32* outBytesWritten);
    Result Read(char* buffer, u32 size);
    Result Read(char* buffer, u32 size, s32* outBytesRead);
    Result Destroy();

    Result GetContextId(u64* outId);

    ~Connection();
};

Result Initialize();
Result Finalize();

}