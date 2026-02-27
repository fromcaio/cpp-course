#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // criando uma hash que informamos o valor e encontramos o index
        std::unordered_map<int, int> index_by_value; // value -> index

        // vamos iterar a quantidade de numeros que tivermos
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            // x recebe um numero
            int x = nums[i];
            // vemos quanto precisamos para chegar no ideal
            int need = target - x;

            // encontramos o indice do numero que precisamos
            auto it = index_by_value.find(need);

            // se fizer parte da hash
            if (it != index_by_value.end()) {
                // retornamos o valor e o indice
                return {it->second, i};
            }

            index_by_value[x] = i;
        }

        return {}; // unreachable if exactly one solution exists
    }
};