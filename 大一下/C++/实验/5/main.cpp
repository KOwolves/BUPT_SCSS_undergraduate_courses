#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;



class XORCipher {
public:
    // 构造函数
    XORCipher(const string& plaintext) {
        int size = plaintext.size();
        data.resize(size);
        for (int i = 0; i < size; i++) {
            data[i] = plaintext[i];
        }
        flag = 1;
    }

    // 赋值运算符重载  
    XORCipher& operator=(const XORCipher& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // 下标运算符重载  
    char& operator[](int index) {
        return reinterpret_cast<char*>(&data[index])[0];
    }

    // 友元函数，用于重载输入运算符  
    friend istream& operator>>(istream& is, XORCipher& cipher);

    // 友元函数，用于重载输出运算符  
    friend ostream& operator<<(ostream& os, const XORCipher& cipher);

    // 加密（加法运算符重载，使用异或）  
    XORCipher operator+(const XORCipher& other) {
        XORCipher result(*this);
        int kSize = KEY.size();
        int dSize = result.data.size();
        for (int i = 0; i < dSize; i++) {
            result[i] = data[i] ^ KEY[i % kSize];
        }
        this->flag = 0;
        *this = result;
        return *this;
    }

    // 解密（减法运算符重载，也使用异或，因为异或两次相当于没有操作）  
    XORCipher operator-(const XORCipher& other) {
        // 解密实际上是再次加密，因为XOR操作是可逆的  
        XORCipher result(*this);
        int kSize = KEY.size();
        int dSize = result.data.size();
        for (int i = 0; i < dSize; i++) {
            result[i] = data[i] ^ KEY[i % kSize];
        }
        this->flag = 1;
        *this = result;
        return *this;
    }

private:
    vector<unsigned char> data; // 存储加密或解密后的数据
    bool flag;  // 表示数据状态，1为明文，0为密文
    const string KEY = "Kali";   // 密钥
};

// 输入运算符重载实现  
istream& operator>>(istream& is, XORCipher& cipher) {
    string plaintext;
    is >> plaintext;
    cipher.flag = 1;
    cipher = XORCipher(plaintext); // 使用构造函数进行初始化 
    return is;
}

// 输出运算符重载实现  
ostream& operator<<(ostream& os, const XORCipher& cipher) {
    int size = cipher.data.size();
    if (cipher.flag) {
        for (int i = 0; i < size; i++) {
            os << cipher.data[i];
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            os.fill('0');
            os.width(2);
            os << hex << (int)cipher.data[i] << " ";
        }
    }
    return os;
}

int main() {
    XORCipher cipher("Krrie Irving");
    cipher[1] = 'y';
    cout << "Original: " << cipher << endl;

    XORCipher encrypted = cipher + cipher; // 加密
    cout << "Encrypted: " << encrypted << endl;

    XORCipher decrypted = encrypted - cipher; // 解密
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
