#include<bits/stdc++.h>
using namespace std;

#define inputfile "in.txt"

string getstringzerospadded( unsigned int zerolength )
{
	string zero(zerolength , '0' );
return zero;
}
unsigned int getpaddedzeros(unsigned int inputlength )
{
return 512 - ( inputlength + 64 + 1 ) % 512 ;
}

string stringtobin( unsigned int a , unsigned int bits )
{
	string binary_chunk;
while(a)
{
binary_chunk += a&1 ? '1' : '0' ;
a>>=1;
}

reverse( binary_chunk.begin() , binary_chunk.end() );

unsigned int extrazero = bits - binary_chunk.length();

string bin( extrazero , '0');
bin.append( binary_chunk );

return bin ;

}

unsigned int leftrotate (unsigned int x , unsigned int c)
{

    return ((x << c) | (x >> (32-c)));
}


unsigned int binarytoint(string s)
{
	unsigned int len = s.length() , num = 0;
	for(int i = 0 ; i < len ; i++ )
	{
		if(s[i] == '1')
		num += 1 << ( len - i - 1 );	
	}
return num;	
}


void md5generate(vector <string> bucket)
{

unsigned int a0 = 0x67452301;  //A
unsigned int b0 = 0xefcdab89;   //B
unsigned int c0 = 0x98badcfe;  //C
unsigned int d0 = 0x10325476; //D

vector<unsigned int> s(64) , k(64);

s[0] = s[4] = s[8] = s[12] = 7; 
s[1] = s[5] = s[9] = s[13] = 12;
s[2] = s[6] = s[10] = s[14] = 17;
s[3] = s[7] = s[11] = s[15] = 22;

s[16] = s[20] = s[24] = s[28] = 5;
s[17] = s[21] = s[25] = s[29] = 9;
s[18] = s[22] = s[26] = s[30] = 14;
s[19] = s[23] = s[27] = s[31] = 20;

s[32] = s[36] = s[40] = s[44] = 4;
s[33] = s[37] = s[41] = s[45] = 11;
s[34] = s[38] = s[42] = s[46] = 16;
s[35] = s[39] = s[43] = s[47] = 23;

s[48] = s[52] = s[56] = s[60] = 6;
s[49] = s[53] = s[57] = s[61] = 10;
s[50] = s[54] = s[58] = s[62] = 15;
s[51] = s[55] = s[59] = s[63] = 21;


for(unsigned int i = 0 ; i < 64 ; i++ )
{
	k[i] = 4294967296 * abs(sin( i + 1 ) );
}



unsigned int F , g , dTemp ,bitnum;

//cout<<"the size is : "<<bucket.size()<<endl;
	
	for( unsigned int i = 0 ; i < bucket.size() ; i++ )
	{
		cout<<"Considering Bucket : "<<bucket[i]<<endl;
		
	vector<unsigned int> M;	
	string chunk(bucket[i]) , bitword;

	for(unsigned int j = 0 ; j < chunk.length(); j+=32 )
	{
		bitword.assign( chunk , j , 32 );
		bitnum = binarytoint( bitword );
		M.push_back(bitnum);
	}
	
	for(unsigned int j = 0 ;j < M.size();j++)
	cout<<"\t\tSmaller chunk : " << M[j] <<endl;
		
    unsigned int A = a0;
    unsigned int B = b0;
    unsigned int C = c0;
    unsigned int D = d0;
		
		  for(unsigned int it = 0 ;it <= 63 ; it++ )
		  {
		  
           if( it >= 0 && it <= 15)
           {
            F = (B & C) | ((! B) & D);
            g = it;
           }
           else if ( it >= 16 && it <= 31)
           {
            F = (D & B) | ((! D) & C);
            g = (5 * it + 1) % 16;
           }
	       else if ( it >= 32 && it <= 47)
           {
            F = B ^ C ^ D ;
            g = (3 * it + 5) % 16 ;
           }
           else if ( it >= 48 && it <= 63)
           {
            F = C ^ (B | (! D));
            g = ( 7 * it ) % 16;
           }
           dTemp = D;
           D = C;
           C = B;
           B = B + leftrotate((A + F + k[it] + M[g]), s[it]);
           A = dTemp;
          }		
    a0 += A;
    b0 += B;
    c0 += C;
    d0 += D;
	}
	
	cout<<"\nChaining Variables are : \n";
	cout<<"A: "<< hex << a0 <<endl;
	cout<<"B: "<< hex << b0 <<endl;
	cout<<"C: "<< hex << c0 <<endl;
	cout<<"D: "<< hex << d0 <<endl;
	
	
	stringstream md5;
	md5<<hex<<a0<<hex<<b0<<hex<<c0<<hex<<d0;
	cout<<"\n\t MD5 Stream is : "<<md5.str()<<endl; 
	
}



int main()
{
	char c;
	ifstream inf(inputfile);
	string inputString;
	unsigned int byte_count = 0;

     while( (c = inf.get())!= EOF){
        inputString += c;
        byte_count += 1;
    }

//printf("I am here\n");    
//    inputString.erase( remove( inputString.begin(), inputString.end(),'\n') );

unsigned int bit_count = byte_count * 8 ;
string bitstring;


for(unsigned int i = 0 ; inputString[i] ; i++)
{
	c = inputString[i];
bitstring += stringtobin(c , 8);

}

cout<<"Input String in bytes : " << inputString << endl;
cout<<"Input String in binary : " << bitstring << endl;
cout<<"No. of bytes in input string : " << byte_count << endl;
cout<<"No. of bits in input string : " << bit_count << endl;
cout<<"Length to be padded with zeroes : " << getpaddedzeros( bit_count ) << endl;

inputString = bitstring ;
inputString.append("1");
inputString += getstringzerospadded( getpaddedzeros( bit_count ) );
cout<<"Input String after zeros and 1 padding : " << inputString << endl;

string lengthbinary = stringtobin( bit_count , 64 );

inputString += lengthbinary;
cout<<"Input String after length padding : " << inputString << endl;

vector< string > bucket;
string bitchunk;

for(unsigned int i = 0 ; i < inputString.length() ; i+= 512 )
{
	bitchunk.assign(inputString , i , 512);
  bucket.push_back(bitchunk);
}

md5generate(bucket);

inf.close();

return 0;
}
