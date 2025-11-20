#include <cassert>
#include <sstream>
#include <iostream>
#include <array>
#include <cstdint>
#include <string>

class IPv4 {
private:
    std::array<std::uint8_t, 4> address;

    std::uint32_t toUint32() const {
        std::uint32_t result = 0;
        result |= static_cast<std::uint32_t>(address[0]) << 24;
        result |= static_cast<std::uint32_t>(address[1]) << 16;
        result |= static_cast<std::uint32_t>(address[2]) << 8;
        result |= static_cast<std::uint32_t>(address[3]);
        return result;
    }

    void fromUint32(std::uint32_t value) {
        address[0] = static_cast<std::uint8_t>((value >> 24) & 0xFF);
        address[1] = static_cast<std::uint8_t>((value >> 16) & 0xFF);
        address[2] = static_cast<std::uint8_t>((value >> 8) & 0xFF);
        address[3] = static_cast<std::uint8_t>(value & 0xFF);
    }

public:
    IPv4() : address({0, 0, 0, 0}) {}

    IPv4(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d) 
        : address({a, b, c, d}) {}

    IPv4& operator++() {
        std::uint32_t val = toUint32();
        fromUint32(val + 1);
        return *this;
    }

    IPv4 operator++(int) {
        IPv4 temp = *this;
        ++(*this);
        return temp;
    }

    IPv4& operator--() {
        std::uint32_t val = toUint32();
        fromUint32(val - 1);
        return *this;
    }

    IPv4 operator--(int) {
        IPv4 temp = *this;
        --(*this);
        return temp;
    }

    friend bool operator==(const IPv4& lhs, const IPv4& rhs);
    friend bool operator!=(const IPv4& lhs, const IPv4& rhs);
    friend bool operator<(const IPv4& lhs, const IPv4& rhs);
    friend bool operator>(const IPv4& lhs, const IPv4& rhs);
    friend bool operator<=(const IPv4& lhs, const IPv4& rhs);
    friend bool operator>=(const IPv4& lhs, const IPv4& rhs);
    friend std::ostream& operator<<(std::ostream& os, const IPv4& ip);
    friend std::istream& operator>>(std::istream& is, IPv4& ip);
};

bool operator==(const IPv4& lhs, const IPv4& rhs) {
    return lhs.toUint32() == rhs.toUint32();
}

bool operator!=(const IPv4& lhs, const IPv4& rhs) {
    return !(lhs == rhs);
}

bool operator<(const IPv4& lhs, const IPv4& rhs) {
    return lhs.toUint32() < rhs.toUint32();
}

bool operator>(const IPv4& lhs, const IPv4& rhs) {
    return rhs < lhs;
}

bool operator<=(const IPv4& lhs, const IPv4& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const IPv4& lhs, const IPv4& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const IPv4& ip) {
    std::stringstream ss;
    ss << static_cast<int>(ip.address[0]) << "."
       << static_cast<int>(ip.address[1]) << "."
       << static_cast<int>(ip.address[2]) << "."
       << static_cast<int>(ip.address[3]);
    return os << ss.str();
}

std::istream& operator>>(std::istream& is, IPv4& ip) {
    std::string input;
    is >> input;
    
    std::stringstream ss(input);
    int a, b, c, d;
    char dot1, dot2, dot3;
    
    if (ss >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d &&
        dot1 == '.' && dot2 == '.' && dot3 == '.' &&
        a >= 0 && a <= 255 &&
        b >= 0 && b <= 255 &&
        c >= 0 && c <= 255 &&
        d >= 0 && d <= 255) {
        ip.address[0] = static_cast<std::uint8_t>(a);
        ip.address[1] = static_cast<std::uint8_t>(b);
        ip.address[2] = static_cast<std::uint8_t>(c);
        ip.address[3] = static_cast<std::uint8_t>(d);
    } else {
        is.setstate(std::ios_base::failbit);
    }
    
    return is;
}

void testDefaultConstructor() {
    IPv4 ip;
    assert(ip == IPv4(0, 0, 0, 0));
}

void testConstructor() {
    IPv4 ip(192, 168, 1, 1);
    std::stringstream ss;
    ss << ip;
    assert(ss.str() == "192.168.1.1");
}

void testIncrementPrefix() {
    IPv4 ip(192, 168, 1, 1);
    ++ip;
    assert(ip == IPv4(192, 168, 1, 2));
    
    IPv4 ip2(255, 255, 255, 255);
    ++ip2;
    assert(ip2 == IPv4(0, 0, 0, 0));
}

void testIncrementPostfix() {
    IPv4 ip(192, 168, 1, 1);
    IPv4 ip2 = ip++;
    assert(ip2 == IPv4(192, 168, 1, 1));
    assert(ip == IPv4(192, 168, 1, 2));
}

void testDecrementPrefix() {
    IPv4 ip(192, 168, 1, 1);
    --ip;
    assert(ip == IPv4(192, 168, 1, 0));
    
    IPv4 ip2(0, 0, 0, 0);
    --ip2;
    assert(ip2 == IPv4(255, 255, 255, 255));
}

void testDecrementPostfix() {
    IPv4 ip(192, 168, 1, 1);
    IPv4 ip2 = ip--;
    assert(ip2 == IPv4(192, 168, 1, 1));
    assert(ip == IPv4(192, 168, 1, 0));
}

void testComparison() {
    IPv4 ip1(192, 168, 1, 1);
    IPv4 ip2(192, 168, 1, 2);
    IPv4 ip3(192, 168, 1, 1);
    
    assert(ip1 == ip3);
    assert(ip1 != ip2);
    assert(ip1 < ip2);
    assert(ip2 > ip1);
    assert(ip1 <= ip2);
    assert(ip1 <= ip3);
    assert(ip2 >= ip1);
    assert(ip1 >= ip3);
}

void testInputOutput() {
    IPv4 ip;
    std::stringstream ss("192.168.1.1");
    ss >> ip;
    
    assert(ip == IPv4(192, 168, 1, 1));
    
    std::stringstream ss2;
    ss2 << ip;
    assert(ss2.str() == "192.168.1.1");
}

int main() {
    testDefaultConstructor();
    testConstructor();
    testIncrementPrefix();
    testIncrementPostfix();
    testDecrementPrefix();
    testDecrementPostfix();
    testComparison();
    testInputOutput();
    return 0;
}
