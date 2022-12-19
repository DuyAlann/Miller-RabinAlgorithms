#include <iostream>
#include <cstring>
#include <cstdlib>
#define ll long long
using namespace std;

//Calculates (a * b) % mod 
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
      if (b % 2 == 1)
      {    
      x = (x + y) % mod;
      }
      y = (y * 2) % mod;
      b /= 2;
    }
    return x % mod;
}

//Calculates A^B % mod
ll modulo(ll A, ll B, ll mod)
{
    ll x = 1;
    ll y = A;
    while (B > 0)
    {
      if (B % 2 == 1){
            x = (x * y) % mod;
      }
      y = (y * y) % mod;
      B = B / 2;
    }
    return x % mod;
}


//Giải thuật
//Input số tự nhiên lẻ n
//Output Số nguyên tố: True/False
//1. Phân tích n - 1 = 2^s * m (Trong đó s > 1 và m là số tự nhiên lẻ)
//2. Chọn ngẫu nhiên số tự nhiên a thuộc {2,...., n-1}
//3. Đặt b = a^m (mod n)
//4. Nếu b%n = 1 thì trả về True. Kết thúc.
//5. Cho k chạy từ 0 đến s-1:
      //1. Nếu b mod n = -1 thì trả về True. Kết thúc.
      //2. thay b:= b^2 (mod n)
//6. Trả lời False. Kết thúc.
bool Miller(long long p,int iteration) 
{
    if (p < 2) return false; 

    if (p != 2 && p % 2==0) return false; 
    
    long long s = p - 1; 

    while (s % 2 == 0){ 
      s /= 2; 
    } 

    for (int i = 0; i < iteration; i++) { 
        long long a = rand() % (p - 1) + 1, temp = s; 
        long long mod = modulo(a, temp, p); 

        while (temp != p - 1 && mod != 1 && mod != p - 1) { 
            mod = mulmod(mod, mod, p); 
            temp *= 2; 
        } 

        if (mod != p - 1 && temp % 2 == 0) { 
            return false; 
        } 
    } 
    return true; 
} 


int main() {
      ll number = 118901521;
      int iteration = 3;
      if(Miller(number, iteration) == true){
            cout<<"The number is the prime number";
      }
      else cout<<"The number is not the prime number";

      return 0;
}
//Test case
//number = 1105 ==> Not prime number
//number = 294409 ==> Not prime number
//number = 118901509 ==> Prime number
//number = 118901521  ==> Not prime number
//number = 118901527  ==> Prime number
//number = 118915387  ==> Not prime number


