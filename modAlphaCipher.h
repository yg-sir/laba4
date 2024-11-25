/**
* @file modAlphaCipher.h
* @author Селуков Е.В.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @date 20.11.2024
*/
#pragma once
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

/**
 * @class modAlphaCipher
 * @brief Реализует шифрование на основе модифицированного алфавита.
 * Класс предоставляет методы для шифрования и дешифрования текста с использованием заданного ключа,
 * основанного на предопределенном кириллическом алфавите.
 */
class modAlphaCipher
{
private:
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; /**< Кириллический алфавит, используемый для шифра */
    map<char, int> alphaNum; /**< Отображает каждую букву в её числовую позицию в алфавите */
    vector<int> key; /**< Числовое представление ключа шифрования */

    /**
     * @brief Преобразует строку в вектор чисел на основе позиций в алфавите.
     * @param s Строка для преобразования.
     * @return Вектор чисел, представляющих позиции каждого символа.
     */
    vector<int> convert(const string& s);

    /**
     * @brief Преобразует вектор чисел в строку на основе позиций в алфавите.
     * @param v Вектор чисел для преобразования.
     * @return Строка, сформированная из позиций чисел.
     */
    string convert(const vector<int>& v);

    /**
     * @brief Проверяет и обрабатывает ключ.
     * @param s Ключ для проверки и преобразования.
     * @return Обработанный ключ в виде строки.
     * @throws cipher_error если ключ недопустим.
     */
    string getValidKey(const string& s);

    /**
     * @brief Проверяет и обрабатывает открытый текст.
     * @param s Открытый текст для проверки и преобразования.
     * @return Обработанный открытый текст в виде строки.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    string getValidOpenText(const string& s);

    /**
     * @brief Проверяет и обрабатывает зашифрованный текст.
     * @param s Зашифрованный текст для проверки и преобразования.
     * @return Обработанный зашифрованный текст в виде строки.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    string getValidCipherText(const string& s);

public:
    /**
     * @brief Удаленный конструктор по умолчанию для обеспечения обязательной инициализации ключа.
     */
    modAlphaCipher() = delete;

    /**
     * @brief Строит шифр с конкретным ключом.
     * @param skey Строка-ключ, используемая для шифрования и дешифрования.
     * @throws cipher_error если ключ недопустим.
     */
    modAlphaCipher(const string& skey);

    /**
     * @brief Шифрует строку открытого текста с использованием текущего ключа.
     * @param open_text Простая строка для шифрования.
     * @return Зашифрованный текст в виде строки.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    string encrypt(const string& open_text);

    /**
     * @brief Дешифрует строку зашифрованного текста с использованием текущего ключа.
     * @param cipher_text Зашифрованная строка для дешифрования.
     * @return Дешифрованный текст в виде строки.
     * @throws cipher_error если текст содержит недопустимые символы.
     */
    string decrypt(const string& cipher_text);
};

/**
 * @class cipher_error
 * @brief Класс исключений для обработки ошибок, связанных с шифром.
 * 
 * Наследуется от std::invalid_argument для предоставления детализированных сообщений об ошибках,
 * возникающих в классе modAlphaCipher.
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
