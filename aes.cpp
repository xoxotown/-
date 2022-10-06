#include <iostream>
#include <string>
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/modes.h"

using namespace std;
using namespace CryptoPP;

int main(int argc, char* argv[])
{
string plaintext = "Hello, world!";
byte key[AES::DEFAULT_KEYLENGTH];
byte iv[AES::BLOCKSIZE];

memset(key, 0x00, AES::DEFAULT_KEYLENGTH);
memset(iv, 0x00, AES::BLOCKSIZE);

CFB_Mode<AES>::Encryption cfbEncryption(key, AES::DEFAULT_KEYLENGTH, iv);
cfbEncryption.ProcessData((byte*)plaintext.data(), (byte*)plaintext.data(), plaintext.size());

cout << "Ciphertext: " << plaintext << endl;

CFB_Mode<AES>::Decryption cfbDecryption(key, AES::DEFAULT_KEYLENGTH, iv);
cfbDecryption.ProcessData((byte*)plaintext.data(), (byte*)plaintext.data(), plaintext.size());

cout << "Plaintext: " << plaintext << endl;

return 0;
}
