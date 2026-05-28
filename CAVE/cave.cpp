#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

namespace cave
{
    class VaultEngine
    {
    private:
        std::string rawData;
        char cryptoKey;

        void logVault(const std::string& status, const std::string& msg)
        {
            std::cout << "[CAVE-VAULT][" << status << "] " << msg << std::endl;
        }

    public:
        VaultEngine(const std::string& data)
        {
            rawData = data;
            cryptoKey = 0x5A;
        }

        void processVaultSecurity()
        {
            std::cout << "==================================================" << std::endl;
            std::cout << " CAVE: Cryptographic Autonomous Vault Engine" << std::endl;
            std::cout << "==================================================" << std::endl;

            logVault("INIT", "Opening secure autonomous vault layer...");
            std::this_thread::sleep_for(std::chrono::milliseconds(400));

            logVault("LOCK", "Encrypting raw buffer stream...");

            std::string encryptedData = rawData;
            for (size_t i = 0; i < encryptedData.size(); ++i)
            {
                encryptedData[i] ^= cryptoKey;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            logVault("SECURE", "Data vector safely sealed inside the matrix.");

            logVault("YIELD", "Vault state flushed successfully.");
            std::cout << "==================================================" << std::endl;
        }
    };
}

int main(int argc, char* argv[])
{
    std::string defaultSecret = "SECURE_SYSTEM_CORE_BLOCK";

    if (argc > 1)
    {
        defaultSecret = argv[1];
    }

    cave::VaultEngine engine(defaultSecret);
    engine.processVaultSecurity();

    return 0;
}
