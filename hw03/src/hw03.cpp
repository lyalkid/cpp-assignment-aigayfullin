#include <hw03.h>

#include <cstring>

void hw03(char* str, const char* pattern) {
    if (!str || !pattern || !*pattern) { // проверяем входные данные
        return;
    }

    const size_t str_len = std::strlen(str);
    const size_t pattern_len = std::strlen(pattern);

    if (pattern_len > str_len) { // если pattern длиннее str, то в str его точно нет
        return;
    }

    char* p = std::strstr(str, pattern); // ищем первое вхождение pattern в str

    if (!p) { // если pattern не найден, то возвращаем str без изменений
        return;
    }

    std::memmove(p, p + pattern_len, str_len - pattern_len + 1); // удаляем pattern из str
}
