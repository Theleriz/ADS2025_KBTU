#include <vector>
#include <string>
using namespace std;

// Находит все начальные позиции (0-based) вхождений pattern в text
// pi — префикс-функция для pattern (должна быть длины pattern.size())
vector<int> kmp_search(const string& text, const string& pattern, const vector<int>& pi) {
    vector<int> occurrences;
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return occurrences;

    int j = 0; // длина текущего совпадения
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            // Нашли вхождение, начинающееся с позиции i - m + 1
            occurrences.push_back(i - m + 1); // 0-based индекс начала
            j = pi[j - 1]; // для поиска перекрывающихся вхождений
        }
    }
    return occurrences;
}