#include <iostream>
#include <string>
using namespace std;

void computeLPS(string pat, int* lps) 
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void IsKPeriodic(int K, const string& txt) // функция проверки кратности на основе алгоритма КМП
{
    string pat; // формируем подстрку, беря начальные символы строки по колличеству К
    for (int i = 0; i < K; ++i)
    {
            pat.push_back(txt[i]);
    }
       
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);
    
    int i = 0;
    int j = 0;
    int value = 0;

    while (i < txt.size())
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) 
        {
            value++;
            j = lps[j - 1];
        }

        else if (i < txt.size() && pat[j] != txt[i]) 
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }

    if (K * value == txt.size()) 
    {
        cout << txt << " кратен / is multiple " << K << endl;
    }
    else
    {
        cout << txt << " не кратен / isn't multiple " << K << endl; // иначе не кратна
    }
}

int main()
{
	setlocale(LC_ALL, "");

    string text;
	int k;

	cout << "Введите текст (на английском) / Enter text (English only)" << endl;
    cin >> text;

    do
    {
        cout << "Укажите кратность для проверки / Specify the multiplicity to check" << endl;
        cin >> k;

        if (k <= 0)
        {
            cout << "Укажите число, больше 0 / Enter a number greater than 0" << endl;
        }
    } while (k <= 0);

	IsKPeriodic(k, text);

	return 0;
}