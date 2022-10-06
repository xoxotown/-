
#include "cryptopp/rsa.h"
#include "cryptopp/osrng.h"
#include "cryptopp/filters.h"
#include "cryptopp/hex.h"

using namespace CryptoPP;

int main(int argc, char* argv[])
{
    AutoSeededRandomPool prng;

    InvertibleRSAFunction params;
    params.GenerateRandomWithKeySize(prng, 3072);

    RSA::PrivateKey privateKey(params);
    RSA::PublicKey publicKey(params);

    std::string plaintext = "this is a test";
    std::string ciphertext;

    RSAES_OAEP_SHA_Encryptor e(publicKey);

    StringSource ss1(plaintext, true,
        new PK_EncryptorFilter(prng, e,
            new StringSink(ciphertext)
        ) // PK_EncryptorFilter
    ); // StringSource

    return 0;
}
