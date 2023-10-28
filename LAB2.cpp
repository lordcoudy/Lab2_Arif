#include "LAB2.h"

void LAB1::task1() {
    // Установка зерна для генератора случайных чисел
    srand(time(0));

    // Генерация пар значений и добавление их в вектор alfaBeta
    for (int i = 0; i < N; ++i) {
        alfaBeta.push_back({i, i});
    }

    // Итерация по вектору alfaBeta
    for (size_t i = 0; i < alfaBeta.size(); ++i) {
        // Создание векторов x и y с определенными значениями
        vector<precision> x = {static_cast<precision>(pow(10.0, alfaBeta[i].first)),
                               1223,
                               static_cast<precision>(pow(10.0, alfaBeta[i].first - 1)),
                               static_cast<precision>(pow(10.0, alfaBeta[i].first - 2)),
                               3,
                               static_cast<precision>(-pow(10.0, alfaBeta[i].first - 5))
        };
        vector<precision> y = {static_cast<precision>(pow(10.0, alfaBeta[i].second)),
                               2,
                               static_cast<precision>(-pow(10.0, alfaBeta[i].second + 1)),
                               static_cast<precision>(pow(10.0, alfaBeta[i].second)),
                               2111,
                               static_cast<precision>(pow(10.0, alfaBeta[i].second + 3))
        };

        // Изменение размеров векторов results и deltas
        results.resize(N);
        deltas.resize(N);

        // Вычисление результатов и погрешностей
        for (size_t j = 0; j < x.size(); ++j) {
            results[i] += x[j] * y[j];
        }
        deltas[i] = abs(results[i] - etanol) / etanol * 100;
    }

    // Создание имени файла на основе типа переменных
    string filename = "./results";
    filename += typeid(etanol).name();
    filename += ".csv";

    // Открытие файла для записи
    ofstream of(filename);
    if (of.is_open()) {
        // Запись заголовка в файл
        of << "alfa, beta, result, delta" << endl;

        // Запись данных в файл
        for (size_t i = 0; i < alfaBeta.size(); ++i) {
            of << alfaBeta[i].first << "," << alfaBeta[i].second << "," << results[i] << "," << deltas[i] << endl;
        }
    } else {
        cout << "Не удалось открыть файл";
    }
}

void LAB1::task2() {
    int i = 0;
    srand(time(nullptr));
    while (i < N) {
        // Генерация случайных значений для tmp_a, tmp_b и tmp_c
        tmp_a = rand() % coef1;
        tmp_b = rand() % coef2;
        tmp_c = -rand() % coef3;
        // Вычисление дискриминанта
        double discriminant = (pow(tmp_b, 2) - 4 * tmp_a * tmp_c);
        // Сравнение дискриминанта с 0
        if (discriminant > 0) {
            // Вычисление корней уравнения и значений функции в корнях
            double r1 = (-tmp_b - sqrt(discriminant)) / (2 * tmp_a);
            double r2 = (-tmp_b + sqrt(discriminant)) / (2 * tmp_a);
            double r3 = pow(r1, 2) * tmp_a + tmp_b * r1 + tmp_c;
            double r4 = pow(r2, 2) * tmp_a + tmp_b * r2 + tmp_c;
            double d1 = abs(0.0 - r3);
            double d2 = abs(0.0 - r4);
            // Если погрешности достаточно велики
            if (d1 > EPS && d2 > EPS) {
                // Добавление значений в соответствующие векторы
                a.push_back(tmp_a);
                b.push_back(tmp_b);
                c.push_back(tmp_c);
                x1.push_back(r1);
                x2.push_back(r2);
                delta1.push_back(d1);
                delta2.push_back(d2);
                i++;
            }
        }
    }

    // Создание имени файла
    string filename = "./results2.csv";

    // Открытие файла для записи
    ofstream of(filename);
    if (of.is_open()) {
        // Запись заголовка в файл
        of << "a, b, c, x1, x2, f(x1), f(x2)" << endl;

        // Запись данных в файл
        for (size_t j = 0; j < a.size(); ++j) {
            of << a[j] << ", " << b[j] << ", " << c[j] << ", " << x1[j] << ", " << x2[j] << ", " << delta1[j] << ", "
               << delta2[j] << endl;
        }
    } else {
        cout << "Не удалось открыть файл";
    }
}

template<typename float_t, typename int_t>
float_t LAB1::machine_eps()
{
    // Объявление переменных
    float_t one, little, last_little, one_plus;

    // Инициализация переменных
    one    = 1.0;
    little = 1.0;
    last_little = little;

    // Цикл для вычисления машинного эпсилона
    while(true)
    {
        one_plus = one;
        one_plus += little;

        // Сравнение единицы с 1 + epsilon
        if( one != one_plus )
        {
            last_little = little;
            little /= 2.0;
        }
        else
        {
            return last_little;
        }
    }
}

void LAB1::task3() {
    // Открытие файла для записи
    ofstream of("./results3.csv");

    // Запись заголовка в файл
    of << "Тип переменной, Машинный эпсилон\n";

    // Запись данных в файл для типа float
    of << "float," << setprecision(18) << machine_eps<float, uint32_t>() << endl;

    // Запись данных в файл для типа double
    of << "double," << setprecision(18) << machine_eps<double, uint64_t>() << endl;
}