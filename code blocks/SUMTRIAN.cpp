#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include <stdint.h>
#include <unistd.h>
#define max(a,b) a>b?a:b

using namespace std;

/*inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}*/

class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};

class FastOutput {
	public:
		FastOutput() {
			m_dataOffset = 0;
		}
		~FastOutput() {
		}
		void Flush() {
			if (m_dataOffset) {
				if (write(1, m_data, m_dataOffset));
				m_dataOffset = 0;
			}
		}
		void PrintUint(uint32_t v, char d) {
			if (m_dataOffset + 11 > sizeof(m_data)) Flush();
			if (v < 100000) {
				if (v < 1000) {
					if (v < 10) {
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 1;
					} else if (v < 100) {
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 2;
					} else {
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 3;
					}
				} else {
					if (v < 10000) {
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 4;
					} else {
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 5;
					}
				}
			} else {
				if (v < 100000000) {
					if (v < 1000000) {
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 6;
					} else if (v < 10000000) {
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 7;
					} else {
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 8;
					}
				} else {
					if (v < 1000000000) {
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 9;
					} else {
						m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;

						m_data[m_dataOffset + 0] = v + 48;

						m_dataOffset += 10;
					}
				}
			}

			m_data[m_dataOffset++] = d;
		}

		void PrintChar(char d) {
			if (m_dataOffset + 1 > sizeof(m_data))
				Flush();
			m_data[m_dataOffset++] = d;
		}

		void ReplaceChar(int offset, char d) {
			m_data[m_dataOffset + offset] = d;
		}

	public:
		uint8_t m_data[32768];
		size_t m_dataOffset;

};



FastInput g_fi;

FastOutput g_fo;


int main()
{

    int t,n,i,j,k,b;
    int a[110][110];
    int dp[110][110];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                //scanf("%d",&a[i][j]);
                //fastRead_int(b);
                //printf("%d\n", b);
                uint32_t b = g_fi.ReadNext();
                a[i][j]=b;
            }
        }

        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<=i;j++)
            {
                if(i==(n-1)){dp[i][j]=a[i][j];}
                else
                {

                    int temp=max(dp[i+1][j],dp[i+1][j+1]);
                    dp[i][j]=a[i][j] + temp;

                }
            }

        }
        //uint32_t o =dp[0][0];
        //g_fo.PrintUint(o, '\n');
        printf("%d\n",dp[0][0]);
        //g_fo.Flush();
    }
	return 0;
}

