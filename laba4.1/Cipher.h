/**
* @file Cipher.h
* @author Селуков Е.В.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @date 20.11.2024
*/
#pragma once
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

/**
 * @class Cipher
 * @brief Реализует простой шифр с числовым ключом.
 * 
 * Класс предоставляет методы для шифрования и расшифровки текста с использованием заданного числового ключа.
 */
class Cipher
{
private:
    int key; /**< Целочисленный ключ для шифра */

    /**
     * @brief Проверяет и возвращает допустимый ключ.
     * @param key Входной ключ.
     * @param Text Текст для проверки.
     * @return Допустимый числовой ключ.
     */
    inline int getValidKey(int key, const string& Text);

    /**
     * @brief Проверяет и обрабатывает открытый текст.
     * @param s Открытый текст для проверки и преобразования.
     * @return Обработанный открытый текст в виде строки.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    inline string getValidOpenText(string& s);

    /**
     * @brief Проверяет и обрабатывает зашифрованный текст.
     * @param s Зашифрованный текст для проверки.
     * @param open_text Открытый текст для сопоставления.
     * @return Обработанный зашифрованный текст в виде строки.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    inline string getValidCipherText(string& s, string& open_text);

public:
    /**
     * @brief Удаленный конструктор по умолчанию — инициализация ключа обязательна.
     */
    Cipher() = delete;

    /**
     * @brief Конструктор, инициализирующий шифр с заданным ключом и текстом.
     * @param skey Целочисленный ключ шифрования.
     * @param text Текст для проверки и инициализации.
     */
    Cipher(int skey, string text);

    /**
     * @brief Шифрует переданный текст с использованием текущего ключа.
     * @param text Текст для шифрования.
     * @return Зашифрованный текст.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    string encryption(string& text);

    /**
     * @brief Расшифровывает переданный текст, используя исходный открытый текст для проверки.
     * @param text Зашифрованный текст для расшифровки.
     * @param open_text Оригинальный открытый текст для сопоставления.
     * @return Расшифрованный текст.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    string transcript(string& text, string& open_text);
};

/**
 * @class cipher_error
 * @brief Класс исключений для обработки ошибок, связанных с шифром.
 * 
 * Наследуется от std::invalid_argument для предоставления детализированных сообщений об ошибках,
 * возникающих в классе Cipher.
 */
class cipher_error : public invalid_argument
{
public:
    /**
     * @brief Создает объект cipher_error с указанным сообщением об ошибке.
     * @param what_arg Сообщение об ошибке в виде строки.
     */
    explicit cipher_error(const string& what_arg)
        : invalid_argument(what_arg)
    {
    }

    /**
     * @brief Создает объект cipher_error с указанным сообщением об ошибке.
     * @param what_arg Сообщение об ошибке в виде C-строки.
     */
    explicit cipher_error(const char* what_arg)
        : invalid_argument(what_arg)
    {
    }
};
