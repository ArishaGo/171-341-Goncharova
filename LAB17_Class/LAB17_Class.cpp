// LAB17_Class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSl 
#include <openssl/evp.h> // ���� ����������������� ������� 
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� ����������� 
#include <fstream>
#include <openssl/aes.h>

// � �a������ VC++ ��������� ���� � �����������, �� ������ ����� ����� ���������!!! �� ������� ���� �� ���������!!! 
// �� � ���� ������ �� ��������� ����� .lib, .dll 

using namespace std;


int main()
{
	// ��������� - ��� ������ 

	// ��� �������, � ������� ���������� ��������� ������������ ��� �������� ������ ������ 
	// �� ����� � �������� � �������������/������������ 

	struct name_of_my_struct // ������ ������ 
	{
		name_of_my_struct()
		{

		}
		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};

	unsigned char *plaintext = (unsigned char *)"Some text Some text Some text Some text"; // �������� ����� 
	int plaintext_len = strlen((char *)plaintext); // ����� ������ 
	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����) 
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������ 
	unsigned char cryptedtext[256]; // ������������� ��������� 
	unsigned char decryptedtext[256]; // �������������� ��������� 

									  // 1. �������� ��������� �� �������������� ��������� 
	EVP_CIPHER_CTX *ctx; // structure 

						 // 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.) 
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������ 

								// 3. ��������� EVP_CIPHER_CTX ����������� ����������� 
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � �������� 

															   // 4. ��� ������� ���������� - ������� EVP_EncryptUpdate 
	int len;
	EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len); // ����������, ���������� 
	int cryptedtext_len = len;

	// 5. ����������� �������� ���������� 
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	// 6. �������� ��������� 
	EVP_CIPHER_CTX_free(ctx);
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	// BIO_dump_fp(stdout, (char*)cryptedtext, cryptedtext_len-1); 


	// 1. 
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������ 

								// 2. 
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � �������� 

															   // 3.  
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len); // ����������, ���������� 

																			   // 4. 
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5. 
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;

	// AES_cfb128_encrypt()



	/*
	// ���������� �����  
	// ������������ ����� ��� ��, �� ��������, � ����� 

	fstream f0, f_encrypted;
	f0.open("f0.txt", std::fstream::in);
	f_encrypted.open("f_encrypted.txt", std::fstream::out | std::fstream::trunc);
	unsigned int number_of_bytes = 0;
	unsigned int filesize = 0;
	char buffer[AES_BLOCK_SIZE] = { 0 };
	char out_buf[AES_BLOCK_SIZE] = { 0 };
	AES_KEY aes_key;
	AES_set_encrypt_key(key, 128, &aes_key);
	while (true) // ����������� ���� ���������� ������ �����, ���������� � ������ � ������ ���� 
	{

		// ���������� 
		f_encrypted.read(buffer, AES_BLOCK_SIZE);
		number_of_bytes += AES_BLOCK_SIZE;

		// ���������� 
		AES_cfb128_encrypt((unsigned char *)buffer,
			(unsigned char *)out_buf,
			AES_BLOCK_SIZE,
			&aes_key, iv, 0,
			AES_ENCRYPT);
		f_encrypted.write(out_buf, AES_BLOCK_SIZE);
		// ������ 

		if (number_of_bytes == filesize) break;
	}
	f_encrypted.close();
	f0.close();*/

	// ---���������� �����
	// ������������ ����� �����, �� ��������, � �����
	//� �����
	/*
	1)�������� ������ � ��������� ���������� OpenSSL
	2) ���������� ������� �����
	3) while (���������_�������� > 0)
	{
	4) ���������� ����������
	5) ������ �������������� ������� � ����
	6) ���������� ���������� ���������
		}
		7)���������� �������������� �������
		8)������ �������������� ����� � ����
		9)�������� ������
	*/
	fstream f0, f_enctypted, f_decrypted;
	
	
	f0.open("f0.txt", std::fstream::in | std::fstream::binary); //���� � �������� �������

	//���� ��� ������������ ������
	f_enctypted.open("f_enctypted.txt",
		std::fstream::out | std::fstream::trunc | std::fstream::binary);
	char buffer[256] = { 0 };
	char out_buf[256] = { 0 };

	ctx = EVP_CIPHER_CIX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	len = 0
		f0.read(buffer, 256);
	while (f0.gcount() > 0) // ����, ���� �� ����� ���-�� ����������� (���� ������ ��������� ������ > 0) 
	{
		// ���������� ������ 
		EVP_EncryptUpdate(ctx, // ������ � ����������� 
			(unsigned char *)out_buf, // ������� ��������: ������, ���� �������� ������������� ������ 
			&len, // �������� ��������: ����� ����������� ����� 
			(unsigned char *)buffer, // ������� ��������: ��� ��������� 
			f0.gcount()); // ������� �������� : ����� ������� ������ 

						  // ����� ������������� ������ � ���� 
		f_enctypted.write(out_buf, len);

		// ���������� ��������� ������ 
		f0.read(buffer, 256);
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	f_enctypted.write(out_buf, len);
	f_enctypted.close();
	f0.close();

	memset(buffer, 0, sizeof(char) * 256);
	memset(out_buf, 0, sizeof(char) * 256);

	f_enctypted.open("f_enctypted.txt",
		std::fstream::in | std::fstream::binary);
	f_decrypted.open("f_decrypted.txt",
		std::fstream::in | std::fstream::out | std::fstream::trunc | std::fstream::binary);
	f_enctypted.read(buffer, 256);

	ctx = EVP_CIPHER_CTX_new();

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);


	while (f_enctypted.gcount() > 0)
	{
		// ����������� 
		EVP_DecryptUpdate(ctx,
			(unsigned char *)out_buf,
			&len,
			(unsigned char *)buffer,
			f_enctypted.gcount());

		// ������ ����������� � ���� 
		f_decrypted.write(out_buf, len);

		// ������ ��������� ������ 
		f_enctypted.read(buffer, 256);
	}

	EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	f_decrypted.write(out_buf, len);

	f_decrypted.close();
	f_enctypted.close();

	getchar();

	
	system("pause");
    return 0;
}

