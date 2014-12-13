#include <bits/stdc++.h>
using namespace std;
namespace bitstr {
/**
 * bit_string class consists of method to add, subtract, multiply
 * and compare string of bits.
 *
 * Your Task: try to implement signum and modify subtract method
 * to support a - b where a < b
 */
class bit_string {
	char *bits;
	int len;
	int signum;
public:
	bit_string(string b) {
		int l = b.length(), i = 0, n;
		for (; i < l && b[i] == '0'; i++)
			;
		n = i;
		bits = new char[l - n + 1];
		for (; i < l; i++) {
			char c = b[i];
			if (c == '1' || c == '0') {
				bits[i - n] = c;
			} else {
				throw "Invalid pattern";
			}
		}
		bits[l - n] = '\0';
		signum = 1;
		len = l - n;
	}

	int operator[](int a) {
		if (a >= 0 && a < len)
			return bits[a] - '0';
		else if (a < 0)
			return (len + a >= 0 ? bits[len + a] : '0') - '0';
		else
			throw "invalid access";
	}

	bit_string operator <<(int n) {
		if (len == 0)
			return bit_string("0");
		else {
			int l = len + n, i = 0;
			char *b = new char[l + 1];
			b[l] = '\0';
			for (; i < len; i++)
				b[i] = bits[i];
			for (; i < l; i++)
				b[i] = '0';
			bit_string bs(b);
			delete b;
			return bs;
		}
	}

	bool operator <(bit_string b) {
		if (this->len < b.len)
			return true;
		else if (this->len > b.len)
			return false;
		else {
			for (int i = 0; i < b.len; i++)
				if (this->bits[i] < b.bits[i])
					return true;
			return false;
		}
	}

	bool operator <=(bit_string b) {
		if (this->len < b.len)
			return true;
		else if (this->len > b.len)
			return false;
		else {
			for (int i = 0; i < b.len; i++)
				if (this->bits[i] > b.bits[i])
					return false;
			return true;
		}
	}

	bool operator ==(bit_string b) {
		if (this->len == b.len) {
			for (int i = 0; i < len; i++)
				if (this->bits[i] != b.bits[i])
					return false;
			return true;
		} else
			return false;
	}

	bool operator >(bit_string b) {
		return !(*this <= b);
	}

	bool operator >=(bit_string b) {
		return !(*this < b);
	}

	bool operator !=(bit_string b) {
		return !(*this == b);
	}

	bit_string operator+(bit_string n) {
		int k = this->len > n.len ? this->len : n.len;
		int c = 0, a;
		char *b = new char[k + 2];
		b[k + 1] = '\0';
		for (int i = 1; i <= k; i++) {
			a = (*this)[-i] + n[-i] + c;
			c = a > 1;
			b[k - i + 1] = a & 1 ? '1' : '0';
		}
		b[0] = c + '0';
		bit_string bs(b);
		delete b;
		return bs;
	}

	bit_string operator -(bit_string n) {
		if ((*this) == n)
			return bit_string("0");
		else if ((*this) > n) {
			char *b = new char[this->len + 1];
			b[this->len] = '\0';
			int br = 0, x, y;
			for (int i = 1; i <= this->len; i++) {
				x = (*this)[-i];
				y = n[-i];
				if (br) {
					br = x - 1 < y;
					x = x ? 0 : 1;
				} else {
					br = x < y;
					x = br ? 2 + x : x;
				}
				b[this->len - i] = '0' + (x - y);
			}
			bit_string bs(b);
			delete b;
			return bs;
		} else {
			throw "not implemented yet";
		}
	}

	bit_string operator *(bit_string n) {
		bit_string b1 = *this, b2 = n, b3("0");
		if (n.len > this->len) {
			b1 = n;
			b2 = *this;
		}
		for (int i = 0; i < b2.len; i++)
			if (b2.bits[i] == '1')
				b3 = b3 + (b1 << (b2.len - i - 1));
		return b3;
	}

	void display() {
		printf("[%d]%s\n", len, bits);
	}
};
}
