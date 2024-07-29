#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) { // estrutura da função obrigatoria da classe no leetcode
    if (n == 0)
      return tasks.size();

    vector<int> count(26);

    for (const char task : tasks)
      ++count[task - 'A'];

    const int maxFreq = *max_element(count.begin(), count.end());
    // colocoar tarefa mais frequente primeiro
    const int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
    const int nMaxFreq = count_if(count.begin(), count.end(), [maxFreq](int c) { return c == maxFreq; });
    return max(maxFreqTaskOccupy + nMaxFreq, static_cast<int>(tasks.size()));
  }
};

// a função main não é necessária para juízes eletrônicos
// foi colocada aqui apenas para fim de testes manuais via terminal

int main() {
  int numTasks, n;
  cout << "Digite o número de tarefas: ";
  cin >> numTasks;
  vector<char> tasks(numTasks);
  cout << "Digite as tarefas (letras de A a Z): ";
  for (int i = 0; i < numTasks; ++i)
    cin >> tasks[i];

  cout << "Digite o tempo de resfriamento n: ";
  cin >> n;

  Solution sol;
  int result = sol.leastInterval(tasks, n);

  cout << "O número mínimo de intervalos necessários é: " << result << endl;

  return 0;
}
