#include "stdcpp.h"

#ifndef LAB2_LAB1_H
#define LAB2_LAB1_H
// Константы для задач
#define N 20                // Количество итераций
#define precision double    // Тип данных
#define EPS 1.0e-9          // Точность
// 3 диапазона для случайных коэффициентов
#define coef1 100
#define coef2 ((100000000 - 10000000 + 1) + 10000000)
#define coef3 ((1000000000 - 100000000 + 1) + 100000000)
using namespace std;

class LAB1 {
public:
    void task1();
    void task2();
    void task3();

private:
    // task1
    precision etanol = 8779;                        // Значение точного результата
    vector<pair<precision, precision>> alfaBeta;    // Пары значений альфа и бета
    vector<precision> results;                      // Результаты
    vector<precision> deltas;                       // Погрешности

    // task2
    vector<int> a, b, c;                            // Значения a, b, c в уравнении
    vector<double> x1, x2, delta1, delta2;          // Значения x1, x2, f(x1), f(x2)
    int tmp_a, tmp_b, tmp_c;                        // Временные значения a, b, c

    //task3
    template<typename float_t, typename int_t>      // Шаблон типа данных
    float_t machine_eps();                          // Поиск эпсилон
};


#endif //LAB2_LAB1_H
