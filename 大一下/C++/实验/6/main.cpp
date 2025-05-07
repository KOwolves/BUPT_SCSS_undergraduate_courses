#include <iostream>
#include <string>
using namespace std;

// 基础加密解密类
class BaseEncryptDecrypt {
public:
    virtual ~BaseEncryptDecrypt() {}

    // 虚函数，用于加密
    virtual string encrypt(const string& plaintext, string key) = 0;

    // 虚函数，用于解密
    virtual string decrypt(const string& ciphertext, string key) = 0;

    // 虚函数，用于输出
    virtual void print(const string& message, bool flag) = 0;

};

// 公有派生异或加密类
class PublicXOREncrypt : public BaseEncryptDecrypt {
public:
    string encrypt(const string& plaintext, string key) {
        // 异或加密实现
        string ciphertext;
        for (int i = 0; i < plaintext.size(); i++) {
            ciphertext += plaintext[i] ^ key[i%key.size()];
        }
        return ciphertext;
    }

    string decrypt(const string& ciphertext, string key) {
        // 由于是异或，解密和加密是一样的
        return encrypt(ciphertext, key);
    }

    // 重写输出函数
    void print(const string& message, bool flag) {
        if (flag) {
            cout << "PublicXOREncrypt: Encrypted: ";
            for (int i = 0; i < message.size(); i++) {
                cout.fill('0');
                cout.width(2);
                cout << hex << (int)message[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "PublicXOREncrypt: Decrypted: " << message << endl;
        }
    }
};

// 私有派生异或加密类（外部不能直接访问或重写私有基类的成员函数）
class PrivateXOREncrypt : private BaseEncryptDecrypt {
public:
    string encrypt(const string& plaintext, string key) {
        string ciphertext;
        for (int i = 0; i < plaintext.size(); i++) {
            ciphertext += plaintext[i] ^ key[i % key.size()];
        }
        return ciphertext;
    }

    string decrypt(const string& ciphertext, string key) {
        string plaintext;
        for (int i = 0; i < ciphertext.size(); i++) {
            plaintext += ciphertext[i] ^ key[i % key.size()];
        }
        return plaintext;
    }

    void print(const string& message, bool flag) {
        if (flag) {
            cout << "PrivateXOREncrypt: Encrypted: ";
            for (int i = 0; i < message.size(); i++) {
                cout.fill('0');
                cout.width(2);
                cout << hex << (int)message[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "PrivateXOREncrypt: Decrypted: " << message << endl;
        }
    }

};

int main() {
    BaseEncryptDecrypt* publicXor = new PublicXOREncrypt();
    BaseEncryptDecrypt* privateXor = reinterpret_cast<BaseEncryptDecrypt*>(new PrivateXOREncrypt());

    string plaintext;
    string key;

    // 输入明文与密钥
    cout << "请输入明文与密钥：" << endl;
    cin >> plaintext >> key;

    // 调用公有派生类的加密、解密和输出函数
    string ciphertext = publicXor->encrypt(plaintext, key);
    string decryptedText = publicXor->decrypt(ciphertext, key);
    publicXor->print(ciphertext, true);
    publicXor->print(decryptedText, false);

    // 输入明文与密钥
    cout << "请输入明文与密钥：" << endl;
    cin >> plaintext >> key;

    // 调用私有派生类的加密、解密和输出函数
    string encrypted = privateXor->encrypt(plaintext, key);
    string decrypted = privateXor->decrypt(encrypted, key);
    privateXor->print(encrypted, true);
    privateXor->print(decrypted, false);

    // 释放内存
    delete publicXor;
    delete privateXor;

    return 0;
}
